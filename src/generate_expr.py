#!/usr/bin/env python3

"""
Generates h/expr.h from a spec that lists expression AST nodes and their fields.

Example:
{
  "types": [
    {
      "name": "Binary",
      "fields": [
        {"type": "Token", "name": "op", "parameter": "const Token&"},
        {"type": "NamedFunction", "name": "fn", "parameter": "NamedFunction"},
        {"type": "Expression", "name": "left", "move": true},
        {"type": "Expression", "name": "right", "move": true}
      ]
    }
  ]
}

Usage:
  python gen/generate_expr.py --output h/expr.h --spec gen/expr.types.json
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

DEFAULT_SPEC = {
  "includes": ["<any>", "<memory>", "\"lexer.h\""],
  "aliases": [
    "using Expression    = std::shared_ptr<Expr>;",
    "using NamedFunction = std::string_view;",
  ],
  "types": [
    {
      "name": "Binary",
      "fields": [
        {"type": "Token", "name": "op", "parameter": "const Token&"},
        {"type": "NamedFunction", "name": "fn_name", "parameter": "NamedFunction"},
        {"type": "Expression", "name": "left", "move": True},
        {"type": "Expression", "name": "right", "move": True},
      ],
    },
    {
      "name": "Unary",
      "fields": [
        {"type": "Token", "name": "op", "parameter": "const Token&"},
        {"type": "NamedFunction", "name": "fn_name", "parameter": "NamedFunction"},
        {"type": "Expression", "name": "expr", "move": True},
      ],
    },
    {"name": "Grouping", "fields": [{"type": "Expression", "name": "expr", "move": True}]},
    {"name": "Literal", "fields": [{"type": "std::any", "name": "value", "move": True}]},
    {
      "name": "Print",
      "fields": [
        {"type": "Token", "name": "op", "parameter": "const Token&"},
        {"type": "Expression", "name": "expr", "move": True}
      ]
    },
  ],
}

@dataclass
class Field:
  type: str
  name: str
  move: bool = False
  parameter: Optional[str] = None

  def ctor_param(self) -> str:
    param_type = self.parameter if self.parameter else (self.type if self.move else f"const {self.type}&")
    return f"{param_type} {self.name}"

  def init_expr(self) -> str:
    return f"std::move({self.name})" if self.move else self.name

@dataclass
class ExprType:
  name: str
  fields: List[Field]

  @property
  def snake_name(self) -> str:
    return camel_to_snake(self.name)

@dataclass
class Spec:
  includes: List[str]
  aliases: List[str]
  types: List[ExprType]

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
        parameter=raw.get("parameter"),
      )
    )
  return parsed

def parse_types(raw_types: Iterable[dict]) -> List[ExprType]:
  types = []
  for raw in raw_types:
    if "name" not in raw or "fields" not in raw:
      raise ValueError(f"Type entries must have 'name' and 'fields': {raw}")
    types.append(ExprType(name=raw["name"], fields=parse_fields(raw["fields"])))
  if not types:
    raise ValueError("At least one expression type is required.")
  return types

def load_spec(path: Optional[Path]) -> Spec:
  if path:
    with path.open("r", encoding="utf-8") as handle:
      raw = json.load(handle)
  else:
    raw = DEFAULT_SPEC

  includes = raw.get("includes") or DEFAULT_SPEC["includes"]
  aliases = raw.get("aliases") or DEFAULT_SPEC["aliases"]
  types = parse_types(raw.get("types", []))
  return Spec(includes=includes, aliases=aliases, types=types)

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

def render_forward_declarations(types: List[ExprType]) -> str:
  return "\n".join(f"class {t.name};" for t in types)

def visitor_method_suffix(expr_type: ExprType) -> str:
  base = expr_type.snake_name
  return base if base.endswith("expr") else f"{base}_expr"

def render_visitors(types: List[ExprType]) -> str:
  lines = [
    "// Type-erased base so Expr can accept any visitor; concrete visitors still type their result via ExprVisitor<R>.",
    "// This class only serves to bridge between a concrete visitor and an Expr.",
    "class ExprVisitorAny {",
    "public:",
  ]

  for t in types:
    suffix = visitor_method_suffix(t)
    lines.append(f"  virtual std::any visit_{suffix}_any(std::shared_ptr<{t.name}> expr) = 0;")
  lines.append("  virtual ~ExprVisitorAny() = default;")
  lines.append("};")
  lines.append("")
  lines.append("// R is the return type for a concrete visitor. The _any member funcs adapt (dumb down) that typed visitor into the non-templated")
  lines.append("// ExprVisitorAny interface so Expr can always dispatch via std::any, while the concrete visitor still works with its real return type.")
  lines.append("template <typename R>")
  lines.append("class ExprVisitor : public ExprVisitorAny {")
  lines.append("public:")
  for t in types:
    suffix = visitor_method_suffix(t)
    lines.append(f"  virtual R visit_{suffix}(std::shared_ptr<{t.name}> expr) = 0;")
  lines.append("")
  lines.append("private:")
  for index, t in enumerate(types):
    suffix = visitor_method_suffix(t)
    lines.append(f"  std::any visit_{suffix}_any(std::shared_ptr<{t.name}> expr) final {{")
    lines.append(f"    return visit_{suffix}(std::move(expr));")
    lines.append("  }")
    if index != len(types) - 1:
      lines.append("")
  lines.append("};")
  return "\n".join(lines)

def render_expr_base() -> str:
  return "\n".join(
    [
      "class Expr {",
      "public:",
      "  virtual std::any accept(ExprVisitorAny& visitor) = 0;",
      "",
      "  // To call a typed/concrete visitor without having to write the ugly std::any stuff.",
      "  template <typename R>",
      "  R accept(ExprVisitor<R>& visitor) {",
      "    return std::any_cast<R>(accept(static_cast<ExprVisitorAny&>(visitor)));",
      "  }",
      "",
      "  virtual ~Expr() = default;",
      "};",
    ]
  )

def render_aliases(aliases: List[str]) -> str:
  return "\n".join(aliases)

def render_expr_class(expr_type: ExprType) -> str:
  params = ", ".join(field.ctor_param() for field in expr_type.fields)
  initializers = ", ".join(f"{field.name} {{{field.init_expr()}}}" for field in expr_type.fields)
  lines = [
    f"class {expr_type.name} : public Expr, public std::enable_shared_from_this<{expr_type.name}> {{",
    "public:",
  ]
  ctor_prefix = "explicit " if len(expr_type.fields) == 1 else ""
  if initializers:
    constructor = f"  {ctor_prefix}{expr_type.name}({params}) : {initializers} {{}}"
  else:
    constructor = f"  {expr_type.name}() = default;"
  lines.append(constructor)
  lines.append("")
  lines.append("  std::any accept(ExprVisitorAny& visitor) override {")
  suffix = visitor_method_suffix(expr_type)
  lines.append(f"    return visitor.visit_{suffix}_any(shared_from_this());")
  lines.append("  }")
  lines.append("")
  for field in expr_type.fields:
    lines.append(f"  const {field.type} {field.name} {{}};")
  lines.append("};")
  return "\n".join(lines)

def render_expr_classes(types: List[ExprType]) -> str:
  return "\n\n".join(render_expr_class(t) for t in types)

def render_file(spec: Spec) -> str:
  sections = [
    LICENSE.rstrip(),
    "",
    "// This file is generated by src/generate_expr.py. Do not edit directly.",
    "",
    "#pragma once",
    "",
    render_includes(spec.includes),
    "",
    render_forward_declarations(spec.types),
    "",
    render_visitors(spec.types),
    "",
    render_expr_base(),
    "",
    render_aliases(spec.aliases),
    "",
    render_expr_classes(spec.types),
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
  parser = argparse.ArgumentParser(description="Generate h/expr.h from a JSON spec.")
  parser.add_argument("--spec", type=Path, help="Path to JSON specification file.")
  parser.add_argument("--output", type=Path, default=Path("h/expr.h"), help="Where to write expr.h.")
  args = parser.parse_args()

  spec = load_spec(args.spec)
  content = render_file(spec)
  write_output(args.output, content)

if __name__ == "__main__":
  main()
