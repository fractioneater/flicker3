#!/usr/bin/env python3

"""
Generate h/ast.h from a spec that lists statement and expression AST nodes and their fields.

Example:
{
  "includes": ["<any>", "<memory>", "\"lexer.h\""],
  "namespaces": { "statements": "Statements", "expressions": "Expressions" },
  "aliases": [
    "using StmtNode      = std::shared_ptr<Stmt>;",
    "using ExprNode      = std::shared_ptr<Expr>;",
    "using NamedFunction = std::string_view;"
  ],
  "statements": [
    {"name": "Block", "fields": [{"type": "std::vector<StmtNode>", "name": "statements", "move": true}]},
    {"name": "Expression", "fields": [{"type": "ExprNode", "name": "expression", "move": true}]}
  ],
  "expressions": [
    {"name": "Literal", "fields": [{"type": "std::any", "name": "value", "move": true}]}
  ]
}

Usage:
  python src/script/generate_ast.py --output h/ast.h --spec static/ast.types.json
If --spec is omitted, the current AST layout is used.

This script is way overkill. It's amazing.
"""

from __future__ import annotations

import argparse
import json
import re
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable, List, Optional

LICENSE = """/**
* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */
"""

@dataclass
class Field:
  type: str
  name: str
  move: bool = False
  ref: bool = False

  def ctor_param(self) -> str:
    param_type = f"const {self.type}&" if self.ref else f"const {self.type}" if self.type.endswith("*") else self.type
    return f"{param_type} {self.name}"

  def init_expr(self) -> str:
    return f"std::move({self.name})" if self.move else self.name

@dataclass
class NodeType:
  name: str
  fields: List[Field]

  @property
  def snake_name(self) -> str:
    return camel_to_snake(self.name)

@dataclass
class NodeCategory:
  label: str  # "Stmt" or "Expr"
  namespace: str
  suffix: str  # "stmt" or "expr"
  types: List[NodeType]

@dataclass
class Spec:
  includes: List[str]
  aliases: List[str]
  namespaces: dict
  statements: NodeCategory
  expressions: NodeCategory

  @property
  def categories(self) -> List[NodeCategory]:
    return [self.statements, self.expressions]

def camel_to_snake(name: str) -> str:
  return re.sub(r"(?<!^)(?=[A-Z])", "_", name).lower()

def parse_fields(raw_fields: Iterable[dict]) -> List[Field]:
  parsed = []
  for raw in raw_fields:
    if "type" not in raw or "name" not in raw:
      raise ValueError(f"Field entries must have 'type' and 'name': {raw}")
    parsed.append(
      Field(
        type=raw["type"],
        name=raw["name"],
        move=bool(raw.get("move", False)),
        ref=raw.get("ref"),
      )
    )
  return parsed

def parse_types(raw_types: Iterable[dict]) -> List[NodeType]:
  types = []
  for raw in raw_types:
    if "name" not in raw or "fields" not in raw:
      raise ValueError(f"Type entries must have 'name' and 'fields': {raw}")
    types.append(NodeType(name=raw["name"], fields=parse_fields(raw["fields"])))
  if not types:
    raise ValueError("At least one AST type is required.")
  return types

def load_spec(path: Optional[Path]) -> Spec:
  if path:
    with path.open("r", encoding="utf-8") as handle:
      raw = json.load(handle)
  else:
    raise ValueError("A spec file is required.")

  includes = raw.get("includes")
  aliases = raw.get("aliases")
  namespaces = raw.get("namespaces")

  statements = parse_types(raw.get("statements"))
  expressions = parse_types(raw.get("expressions"))

  stmt_category = NodeCategory(label="Stmt", namespace=namespaces["statements"], suffix="stmt", types=statements)
  expr_category = NodeCategory(label="Expr", namespace=namespaces["expressions"], suffix="expr", types=expressions)

  return Spec(includes=includes, aliases=aliases, namespaces=namespaces, statements=stmt_category, expressions=expr_category)

def render_includes(includes: List[str]) -> str:
  rendered = []
  previous_kind: Optional[str] = None
  for include in includes:
    kind = "local" if include.startswith('"') else "system"
    if rendered and kind != previous_kind:
      rendered.append("")
    rendered.append(f"#include {include}")
    previous_kind = kind
  return "\n".join(rendered)

def render_forward_declarations(categories: List[NodeCategory]) -> str:
  lines: List[str] = []
  for index, category in enumerate(categories):
    lines.append(f"namespace {category.namespace} {{")
    for t in category.types:
      lines.append(f"  class {t.name};")
    lines.append("}")
    if index != len(categories) - 1:
      lines.append("")
  return "\n".join(lines)

def visitor_method_suffix(node: NodeType, category: NodeCategory) -> str:
  base = node.snake_name
  return base if base.endswith(category.suffix) else f"{base}_{category.suffix}"

def render_void_visitors(categories: List[NodeCategory]) -> str:
  lines = [
    "// Non-returning visitor base classes --------------------------------------------------",
    "// std::any prefers a copy-constructible object, which void is not. So for a visitor that doesn't return anything, something like this is necessary.",
    "",
  ]
  for index, category in enumerate(categories):
    param_id = "stmt" if category.label == "Stmt" else "expr"
    lines.append(f"class {category.label}VisitorVoid {{")
    lines.append("  public:")
    for node in category.types:
      suffix = visitor_method_suffix(node, category)
      lines.append(f"  virtual void visit_{suffix}(std::shared_ptr<{category.namespace}::{node.name}> {param_id}) = 0;")
    lines.append(f"  virtual ~{category.label}VisitorVoid() = default;")
    lines.append("};")
    if index != len(categories) - 1:
      lines.append("")
  return "\n".join(lines)

def render_type_erased_visitors(categories: List[NodeCategory]) -> str:
  lines = [
    "// Type-erased visitor base classes --------------------------------------------------",
    "// These are type-erased so Stmt and Expr can accept any visitor; concrete visitors still type their result via StmtVisitor<R> or ExprVisitor<R>.",
    "// This class only serves to bridge between a concrete visitor and an Expr.",
    "",
  ]
  for index, category in enumerate(categories):
    param_id = "stmt" if category.label == "Stmt" else "expr"
    lines.append(f"class {category.label}VisitorAny {{")
    lines.append("  public:")
    for node in category.types:
      suffix = visitor_method_suffix(node, category)
      lines.append(f"  virtual std::any visit_{suffix}_any(std::shared_ptr<{category.namespace}::{node.name}> {param_id}) = 0;")
    lines.append(f"  virtual ~{category.label}VisitorAny() = default;")
    lines.append("};")
    if index != len(categories) - 1:
      lines.append("")
  return "\n".join(lines)

def render_concrete_visitors(categories: List[NodeCategory]) -> str:
  lines = [
    "// Concrete visitor base classes --------------------------------------------------",
    "// R is the return type for a concrete visitor. The _any member funcs adapt (dumb down) that typed visitor into the non-templated",
    "// StmtVisitorAny/ExprVisitorAny interface so Stmt/Expr can always dispatch via std::any, while the concrete visitor still works with its real return type.",
    "",
  ]
  for index, category in enumerate(categories):
    param_id = "stmt" if category.label == "Stmt" else "expr"
    lines.append("template <typename R>")
    lines.append(f"class {category.label}Visitor : public {category.label}VisitorAny {{")
    lines.append("  public:")
    for node in category.types:
      suffix = visitor_method_suffix(node, category)
      lines.append(f"  virtual R visit_{suffix}(std::shared_ptr<{category.namespace}::{node.name}> {param_id}) = 0;")
    lines.append("")
    lines.append("  private:")
    for idx, node in enumerate(category.types):
      suffix = visitor_method_suffix(node, category)
      lines.append(f"  std::any visit_{suffix}_any(std::shared_ptr<{category.namespace}::{node.name}> {param_id}) final {{")
      lines.append(f"    return visit_{suffix}(std::move({param_id}));")
      lines.append("  }")
      if idx != len(category.types) - 1:
        lines.append("")
    lines.append("};")
    if index != len(categories) - 1:
      lines.append("")
  return "\n".join(lines)

def render_base_nodes(categories: List[NodeCategory]) -> str:
  lines = ["// Base AST node classes --------------------------------------------------"]
  for category in categories:
    lines.extend(
      [
        f"class {category.label} {{",
        "  public:",
        f"  virtual std::any accept({category.label}VisitorAny& visitor) = 0;",
        f"  virtual void accept({category.label}VisitorVoid& visitor) = 0;",
        "",
        "  // To call a typed/concrete visitor without having to write the ugly std::any stuff.",
        "  template <typename R>",
        f"  R accept({category.label}Visitor<R>& visitor) {{",
        f"    return std::any_cast<R>(accept(static_cast<{category.label}VisitorAny&>(visitor)));",
        "  }",
        "",
        f"  virtual ~{category.label}() = default;",
        "};",
        "",
      ]
    )
  return "\n".join(lines).rstrip()

def render_aliases(aliases: List[str]) -> str:
  return "\n".join(aliases)

def render_node_class(category: NodeCategory, node: NodeType) -> str:
  params = ", ".join(field.ctor_param() for field in node.fields)
  initializers = ", ".join(f"{field.name} {{{field.init_expr()}}}" for field in node.fields)
  lines = [
    f"class {category.namespace}::{node.name} : public {category.label}, public std::enable_shared_from_this<{node.name}> {{",
    "  public:",
  ]
  ctor_prefix = "explicit " if len(node.fields) == 1 else ""
  if initializers:
    constructor = f"  {ctor_prefix}{node.name}({params}) : {initializers} {{}}"
  else:
    constructor = f"  {node.name}() = default;"
  lines.append(constructor)
  lines.append("")
  lines.append(f"  std::any accept({category.label}VisitorAny& visitor) override {{")
  suffix = visitor_method_suffix(node, category)
  lines.append(f"    return visitor.visit_{suffix}_any(shared_from_this());")
  lines.append("  }")
  lines.append("")
  lines.append(f"  void accept({category.label}VisitorVoid& visitor) override {{")
  lines.append(f"    visitor.visit_{suffix}(shared_from_this());")
  lines.append("  }")
  lines.append("")
  for field in node.fields:
    lines.append(f"  const {field.type} {field.name} {{}};")
  lines.append("};")
  return "\n".join(lines)

def render_nodes(category: NodeCategory) -> str:
  header = f"// {category.namespace} --------------------------------------------------"
  body = "\n\n".join(render_node_class(category, node) for node in category.types)
  return "\n".join([header, body])

def render_file(spec: Spec) -> str:
  sections = [
    LICENSE.rstrip(),
    "",
    "// This file is generated by src/script/generate_ast.py. Do not edit directly.",
    "",
    "#pragma once",
    "",
    render_includes(spec.includes),
    "",
    render_forward_declarations(spec.categories),
    "",
    render_void_visitors(spec.categories),
    "",
    render_type_erased_visitors(spec.categories),
    "",
    render_concrete_visitors(spec.categories),
    "",
    render_base_nodes(spec.categories),
    "",
    "// Aliases --------------------------------------------------",
    render_aliases(spec.aliases),
    "",
    render_nodes(spec.statements),
    "",
    render_nodes(spec.expressions),
    "",
  ]
  return "\n".join(sections)

def write_output(path: Path, content: str) -> None:
  path.parent.mkdir(parents=True, exist_ok=True)
  existing = path.read_text(encoding="utf-8") if path.exists() else ""
  if existing == content:
    return
  path.write_text(content, encoding="utf-8")

def main() -> None:
  parser = argparse.ArgumentParser(description="Generate h/ast.h from a JSON spec.")
  parser.add_argument("--spec", type=Path, help="Path to JSON specification file.")
  parser.add_argument("--output", type=Path, default=Path("h/ast.h"), help="Where to write ast.h.")
  args = parser.parse_args()

  spec = load_spec(args.spec)
  content = render_file(spec)
  write_output(args.output, content)

if __name__ == "__main__":
  main()
