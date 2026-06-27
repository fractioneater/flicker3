/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

export module dotprinter;

import ast;
import type;

import std;

class DotTreeWalker {
  int id_counter_ {};
  int current_parent_id_ {};
  std::ostringstream out_ {};

  class StmtChildrenVisitor : public StmtVisitorVoid {
    DotTreeWalker& owner_;

    public:
    explicit StmtChildrenVisitor(DotTreeWalker& owner) : owner_ {owner} {}

    void visit_program_stmt(const Statements::Program& stmt) override {
      const int parent_id {owner_.current_parent_id_};
      for (const auto& item : stmt.items)
        owner_.walk(item, parent_id);
    }

    void visit_block_stmt(const Statements::Block& stmt) override {
      const int parent_id {owner_.current_parent_id_};
      for (const auto& inner_stmt : stmt.statements)
        owner_.walk(inner_stmt, parent_id);
    }

    void visit_expression_stmt(const Statements::Expression& stmt) override {
      owner_.walk(stmt.expression, owner_.current_parent_id_);
    }

    void visit_variable_stmt(const Statements::Variable& stmt) override {
      const int parent_id {owner_.current_parent_id_};
      owner_.walk(stmt.type, parent_id);
      owner_.walk(stmt.initializer, parent_id);
    }

    void visit_function_stmt(const Statements::Function& stmt) override {
      const int parent_id {owner_.current_parent_id_};
      for (const auto& [_, type, _1] : stmt.params)
        owner_.walk(type, parent_id);
      if (stmt.return_type)
        owner_.walk(stmt.return_type, parent_id);
      owner_.walk(stmt.body, parent_id);
    }

    void visit_initializer_stmt(const Statements::Initializer& stmt) override {
      const int parent_id {owner_.current_parent_id_};
      for (const auto& [_, type, _1] : stmt.params)
        owner_.walk(type, parent_id);
      owner_.walk(stmt.body, parent_id);
    }

    void visit_method_stmt(const Statements::Method& stmt) override {
      const int parent_id {owner_.current_parent_id_};
      for (const auto& [_, type, _1] : stmt.params)
        owner_.walk(type, parent_id);
      if (stmt.return_type)
        owner_.walk(stmt.return_type, parent_id);
      owner_.walk(stmt.body, parent_id);
    }

    void visit_class_stmt(const Statements::Class& stmt) override {
      const int parent_id {owner_.current_parent_id_};
      for (const auto& a : stmt.namespace_items)
        owner_.walk(a, parent_id);
      for (const auto& a : stmt.initializers)
        owner_.walk(a, parent_id);
      for (const auto& a : stmt.declarations)
        owner_.walk(a, parent_id);
    }

    void visit_namespace_stmt(const Statements::Namespace& stmt) override {
      for (const auto& decl : stmt.declarations)
        owner_.walk(decl, owner_.current_parent_id_);
    }

    void visit_import_stmt(const Statements::Import& stmt) override {}

    void visit_typealias_stmt(const Statements::Typealias& stmt) override {
      owner_.walk(stmt.type, owner_.current_parent_id_);
    }

    void visit_if_stmt(const Statements::If& stmt) override {
      const int parent_id {owner_.current_parent_id_};
      owner_.walk(stmt.condition, parent_id);
      owner_.walk(stmt.then_body, parent_id);
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt.else_body))
        owner_.walk(stmt.else_body, parent_id);
    }

    void visit_while_stmt(const Statements::While& stmt) override {
      const int parent_id {owner_.current_parent_id_};
      owner_.walk(stmt.condition, parent_id);
      owner_.walk(stmt.loop_body, parent_id);
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt.around_body))
        owner_.walk(stmt.around_body, parent_id);
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt.else_body))
        owner_.walk(stmt.else_body, parent_id);
    }

    void visit_each_stmt(const Statements::Each& stmt) override {
      const int parent_id {owner_.current_parent_id_};
      owner_.walk(stmt.iterator, parent_id);
      owner_.walk(stmt.loop_body, parent_id);
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt.around_body))
        owner_.walk(stmt.around_body, parent_id);
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt.else_body))
        owner_.walk(stmt.else_body, parent_id);
    }

    void visit_for_stmt(const Statements::For& stmt) override {
      const int parent_id {owner_.current_parent_id_};
      owner_.walk(stmt.begin, parent_id);
      owner_.walk(stmt.condition, parent_id);
      owner_.walk(stmt.end, parent_id);
      owner_.walk(stmt.loop_body, parent_id);
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt.around_body))
        owner_.walk(stmt.around_body, parent_id);
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt.else_body))
        owner_.walk(stmt.else_body, parent_id);
    }

    void visit_break_stmt(const Statements::Break& stmt) override {}
    void visit_continue_stmt(const Statements::Continue& stmt) override {}

    void visit_return_stmt(const Statements::Return& stmt) override {
      owner_.walk(stmt.value, owner_.current_parent_id_);
    }

    void visit_pass_stmt(const Statements::Pass& stmt) override {}
  };

  class ExprChildrenVisitor : public ExprVisitorVoid {
    DotTreeWalker& owner_;

    public:
    explicit ExprChildrenVisitor(DotTreeWalker& owner) : owner_ {owner} {}

    void visit_binary_expr(const Expressions::Binary& expr) override {
      const int parent_id {owner_.current_parent_id_};
      owner_.walk(expr.left, parent_id);
      owner_.walk(expr.right, parent_id);
    }

    void visit_logical_expr(const Expressions::Logical& expr) override {
      const int parent_id {owner_.current_parent_id_};
      owner_.walk(expr.left, parent_id);
      owner_.walk(expr.right, parent_id);
    }

    void visit_comparison_expr(const Expressions::Comparison& expr) override {
      const int parent_id {owner_.current_parent_id_};
      for (const auto& operand : expr.expressions) {
        owner_.walk(operand, parent_id);
      }
    }

    void visit_if_expr(const Expressions::If& expr) override {
      const int parent_id {owner_.current_parent_id_};
      owner_.walk(expr.then, parent_id);
      owner_.walk(expr.condition, parent_id);
      owner_.walk(expr.else_expr, parent_id);
    }

    void visit_assignment_expr(const Expressions::Assignment& expr) override {
      const int parent_id {owner_.current_parent_id_};
      owner_.walk(expr.target, parent_id);
      owner_.walk(expr.value, parent_id);
    }

    void visit_call_expr(const Expressions::Call& expr) override {
      const int parent_id {owner_.current_parent_id_};
      owner_.walk(expr.object, parent_id);
      for (const auto& arg : expr.arguments)
        owner_.walk(arg, parent_id);
    }

    void visit_subscript_expr(const Expressions::Subscript& expr) override {
      const int parent_id {owner_.current_parent_id_};
      owner_.walk(expr.object, parent_id);
      for (const auto& arg : expr.arguments)
        owner_.walk(arg, parent_id);
    }

    void visit_member_expr(const Expressions::Member& expr) override {
      owner_.walk(expr.object, owner_.current_parent_id_);
    }

    void visit_namespace_member_expr(const Expressions::NamespaceMember& expr) override {}

    void visit_unary_expr(const Expressions::Unary& expr) override {
      owner_.walk(expr.expr, owner_.current_parent_id_);
    }

    void visit_interpolation_expr(const Expressions::Interpolation& expr) override {
      const int parent_id {owner_.current_parent_id_};
      for (const auto& sub_expr : expr.expressions)
        owner_.walk(sub_expr, parent_id);
    }

    void visit_lambda_expr(const Expressions::Lambda& expr) override {
      const int parent_id {owner_.current_parent_id_};
      for (const auto& [_, type, _1] : expr.params)
        owner_.walk(type, parent_id);
      owner_.walk(expr.body, parent_id);
    }

    void visit_grouping_expr(const Expressions::Grouping& expr) override {
      owner_.walk(expr.expr, owner_.current_parent_id_);
    }

    void visit_list_expr(const Expressions::List& expr) override {
      const int parent_id {owner_.current_parent_id_};
      for (const auto& item : expr.items)
        owner_.walk(item, parent_id);
    }

    void visit_map_expr(const Expressions::Map& expr) override {
      const int parent_id {owner_.current_parent_id_};
      for (const auto& item : expr.values)
        owner_.walk(item, parent_id);
    }

    void visit_number_expr(const Expressions::Number& expr) override {}
    void visit_boolean_expr(const Expressions::Boolean& expr) override {}
    void visit_nil_expr(const Expressions::Nil& expr) override {}
    void visit_char_expr(const Expressions::Char& expr) override {}
    void visit_string_expr(const Expressions::String& expr) override {}
    void visit_variable_expr(const Expressions::Variable& expr) override {}
    void visit_this_expr(const Expressions::This& expr) override {}
    void visit_super_expr(const Expressions::Super& expr) override {}

    void visit_print_expr(const Expressions::Print& expr) override {
      owner_.walk(expr.expr, owner_.current_parent_id_);
    }
  };

  class StmtNameVisitor : public StmtVisitor<std::string> {
    [[maybe_unused]] DotTreeWalker& owner_;

    public:
    explicit StmtNameVisitor(DotTreeWalker& owner) : owner_ {owner} {}

    std::string visit_program_stmt(const Statements::Program& stmt) override { return "PROGRAM"; }
    std::string visit_block_stmt(const Statements::Block& stmt) override { return "BLOCK"; }
    std::string visit_expression_stmt(const Statements::Expression& stmt) override { return "EXPRESSION"; }

    std::string visit_variable_stmt(const Statements::Variable& stmt) override {
      std::string blah {stmt.is_mutable ? "var " : "val "};
      blah += stmt.identifier->src_string;
      blah += ": ... = ...";
      return blah;
    }

    std::string visit_function_stmt(const Statements::Function& stmt) override {
      std::string blah {"function "};
      blah += stmt.identifier->src_string;
      // Generic.
      if (!stmt.type_params.empty()) {
        blah += " for ";
        for (const auto& param : stmt.type_params) {
          blah += param->src_string;
          blah += " ";
        }
      }
      // Params.
      blah += "(";
      for (std::size_t i {0}; i < stmt.params.size(); ++i) {
        if (i > 0) blah += ", ";
        blah += stmt.params[i].identifier->src_string;
      }
      blah += ")";
      // Return type.
      if (stmt.return_type)
        blah += " -> ...";

      return blah;
    }

    std::string visit_initializer_stmt(const Statements::Initializer& stmt) override {
      std::string blah {"init "};
      blah += "(";
      for (std::size_t i {0}; i < stmt.params.size(); ++i) {
        if (i > 0) blah += ", ";
        blah += stmt.params[i].identifier->src_string;
      }
      blah += ")";

      return blah;
    }

    std::string visit_method_stmt(const Statements::Method& stmt) override {
      std::string blah {"method "};
      blah += stmt.identifier->src_string;
      // Params.
      blah += "(";
      for (std::size_t i {0}; i < stmt.params.size(); ++i) {
        if (i > 0) blah += ", ";
        blah += stmt.params[i].identifier->src_string;
      }
      blah += ")";
      // Return type.
      if (stmt.return_type)
        blah += " -> ...";

      return blah;
    }

    std::string visit_class_stmt(const Statements::Class& stmt) override {
      std::string blah {"class "};
      blah += stmt.identifier->src_string;
      // Type parameters.
      if (!stmt.type_params.empty()) {
        blah += " for";
        for (const auto& param : stmt.type_params) {
          blah += " ";
          blah += param->src_string;
        }
      }
      // Superclasses.
      if (!stmt.superclasses.empty()) {
        blah += " is ";
        for (int i {0}; i < stmt.superclasses.size(); ++i) {
          if (i > 0) blah += ", ";
          blah += stmt.superclasses[i]->src_string;
        }
      }
      return blah;
    }

    std::string visit_namespace_stmt(const Statements::Namespace& stmt) override { return "namespace " + std::string {stmt.identifier->src_string}; }

    std::string visit_import_stmt(const Statements::Import& stmt) override {
      std::string blah {"import " + std::string {stmt.path->src_string}};
      if (!stmt.imports.empty()) {
        blah += " for ";
        for (std::size_t i {0}; i < stmt.imports.size(); ++i) {
          if (i > 0) blah += ", ";
          blah += stmt.imports[i]->src_string;
        }
      }
      return blah;
    }

    std::string visit_typealias_stmt(const Statements::Typealias& stmt) override {
      std::string blah {"typealias "};
      blah += stmt.identifier->src_string;
      blah += " = ...";
      return blah;
    }

    std::string visit_if_stmt(const Statements::If& stmt) override {
      if (std::dynamic_pointer_cast<Statements::Pass>(stmt.else_body))
        return "if ... do ...";
      return "if ... do ... else ...";
    }

    std::string visit_while_stmt(const Statements::While& stmt) override {
      std::string blah {"while"};
      if (stmt.label) {
        blah += ":";
        blah += stmt.label->src_string;
      }
      blah += " ... do ...";
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt.around_body))
        blah += " around ...";
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt.else_body))
        blah += " else ...";
      return blah;
    }

    std::string visit_each_stmt(const Statements::Each& stmt) override {
      std::string blah {"each"};
      if (stmt.label) {
        blah += ":";
        blah += stmt.label->src_string;
      }
      blah += " ";
      blah += stmt.iter_var->src_string;
      if (stmt.index_var) {
        blah += "[";
        blah += stmt.index_var->src_string;
        blah += "]";
      }
      blah += " in ... do ...";
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt.around_body))
        blah += " around ...";
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt.else_body))
        blah += " else ...";
      return blah;
    }

    std::string visit_for_stmt(const Statements::For& stmt) override {
      std::string blah {"for"};
      if (stmt.label) {
        blah += ":";
        blah += stmt.label->src_string;
      }
      blah += " ...; ...; ... do ...";
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt.around_body))
        blah += " around ...";
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt.else_body))
        blah += " else ...";
      return blah;
    }

    std::string visit_break_stmt(const Statements::Break& stmt) override {
      std::string blah {"break"};
      if (stmt.label) {
        blah += ":";
        blah += stmt.label->src_string;
      }
      return blah;
    }

    std::string visit_continue_stmt(const Statements::Continue& stmt) override {
      std::string blah {"continue"};
      if (stmt.label) {
        blah += ":";
        blah += stmt.label->src_string;
      }
      return blah;
    }

    std::string visit_return_stmt(const Statements::Return& stmt) override { return "return ..."; }
    std::string visit_pass_stmt(const Statements::Pass& stmt) override { return "pass"; }
  };

  class ExprNameVisitor : public ExprVisitor<std::string> {
    [[maybe_unused]] DotTreeWalker& owner_;

    public:
    explicit ExprNameVisitor(DotTreeWalker& owner) : owner_ {owner} {}

    std::string visit_binary_expr(const Expressions::Binary& expr) override { return "binary " + std::string {expr.fn_name}; }
    std::string visit_logical_expr(const Expressions::Logical& expr) override { return std::string {expr.op->src_string}; }

    std::string visit_comparison_expr(const Expressions::Comparison& expr) override {
      std::string blah {"..."};
      for (const auto& [_, comparison] : expr.fn_names) {
        blah += " ";
        blah += comparison;
        blah += " ...";
      }
      return blah;
    }

    std::string visit_if_expr(const Expressions::If& expr) override { return "... if ... else ..."; }

    std::string visit_assignment_expr(const Expressions::Assignment& expr) override { return "... = ..."; }

    std::string visit_call_expr(const Expressions::Call& expr) override { return "...(...*)"; }

    std::string visit_subscript_expr(const Expressions::Subscript& expr) override { return "...[...*]"; }

    std::string visit_member_expr(const Expressions::Member& expr) override {
      const std::string blah {"(...)"};
      return blah + (expr.is_safe ? "?." : ".") + std::string {expr.member->src_string};
    }

    std::string visit_namespace_member_expr(const Expressions::NamespaceMember& expr) override {
      std::string blah {};
      for (const auto& name : expr.namespace_ids)
        blah += std::string {name->src_string} + "::";
      return blah + std::string {expr.member->src_string};
    }

    std::string visit_unary_expr(const Expressions::Unary& expr) override { return "unary " + std::string {expr.fn_name}; }

    std::string visit_interpolation_expr(const Expressions::Interpolation& expr) override {
      std::string blah {"\\\"" + expr.start};
      for (const auto& interpolation : expr.end_strings) {
        blah += "=(...)";
        blah += interpolation;
      }
      return blah + "\\\"";
    }

    std::string visit_lambda_expr(const Expressions::Lambda& expr) override {
      std::string blah {"lambda ("};
      if (!expr.params.empty()) {
        for (std::size_t i {0}; i < expr.params.size(); ++i) {
          if (i > 0) blah += ", ";
          blah += expr.params[i].identifier->src_string;
        }
      }
      blah += ") -> ...";
      return blah;
    }

    std::string visit_grouping_expr(const Expressions::Grouping& expr) override { return "()"; }

    std::string visit_list_expr(const Expressions::List& expr) override { return "[]"; }

    std::string visit_map_expr(const Expressions::Map& expr) override {
      std::string blah {"["};
      for (std::size_t i {0}; i < expr.keys.size(); ++i) {
        blah += expr.keys[i] + " -> ...";
        if (i + 1 < expr.keys.size())
          blah += ", ";
      }
      return blah + "]";
    }

    std::string visit_number_expr(const Expressions::Number& expr) override { return std::to_string(expr.value); }
    std::string visit_boolean_expr(const Expressions::Boolean& expr) override { return expr.value ? "true" : "false"; }
    std::string visit_nil_expr(const Expressions::Nil& expr) override { return "nil"; }
    std::string visit_char_expr(const Expressions::Char& expr) override { return std::string {expr.value}; }
    std::string visit_string_expr(const Expressions::String& expr) override { return "\\\"" + expr.value + "\\\""; }

    std::string visit_variable_expr(const Expressions::Variable& expr) override { return std::string {expr.identifier->src_string}; }

    std::string visit_this_expr(const Expressions::This& expr) override { return "this"; }
    std::string visit_super_expr(const Expressions::Super& expr) override { return "super"; }

    std::string visit_print_expr(const Expressions::Print& expr) override { return std::string {expr.fn_name}; }
  };

  StmtChildrenVisitor stmt_children_visitor_ {*this};
  ExprChildrenVisitor expr_children_visitor_ {*this};
  StmtNameVisitor stmt_name_visitor_ {*this};
  ExprNameVisitor expr_name_visitor_ {*this};

  void walk(const ExprNode& node, int parent_id) {
    const int my_id {id_counter_++};
    const std::string label {node->accept(expr_name_visitor_)};

    out_ << "  n" << my_id << " [label=\"" << label << "\", shape=box, color=royalblue, fontcolor=royalblue4];\n";
    out_ << "  n" << parent_id << " -> n" << my_id << ";\n";

    const int previous_parent {current_parent_id_};
    current_parent_id_ = my_id;
    node->accept(expr_children_visitor_);
    current_parent_id_ = previous_parent;
  }

  void walk(const StmtNode& node, int parent_id) {
    const int my_id {id_counter_++};
    const std::string label {node->accept(stmt_name_visitor_)};

    out_ << "  n" << my_id << " [label=\"" << label << "\", shape=box, color=indianred, fontcolor=maroon];\n";
    out_ << "  n" << parent_id << " -> n" << my_id << ";\n";

    const int previous_parent {current_parent_id_};
    current_parent_id_ = my_id;
    node->accept(stmt_children_visitor_);
    current_parent_id_ = previous_parent;
  }

  // Types aren't AST nodes, but they behave similarly. Instead of using a visitor pattern, they're just handled with a switch.
  void walk(const SyntacticTypePtr& type, int parent_id) {
    const int my_id {id_counter_++};

    if (!type) {
      out_ << "  n" << my_id << " [label=\"inferred\", shape=box, color=plum4, fontcolor=rebeccapurple];\n";
      out_ << "  n" << parent_id << " -> n" << my_id << ";\n";
      return;
    }

    std::string label {};
    switch (type->kind()) {
      case TypeKind::NAMED: {
        const auto named {std::dynamic_pointer_cast<NamedType>(type)};
        label = named && !named->name.empty() ? named->name : "named";
        break;
      }
      case TypeKind::APPLIED: label = "applied";
        break;
      case TypeKind::OPTIONAL: label = "optional";
        break;
      case TypeKind::FUNCTION: label = "function (...+) -> ...";
        break;
      case TypeKind::NAMESPACED: {
        const auto namespaced {std::dynamic_pointer_cast<NamespacedType>(type)};
        for (const auto& path_name : namespaced->namespace_path) {
          label += path_name;
          label += "::";
        }
        label += namespaced->name;
        break;
      }
    }

    out_ << "  n" << my_id << " [label=\"" << label << "\", shape=box, color=plum4, fontcolor=rebeccapurple];\n";
    out_ << "  n" << parent_id << " -> n" << my_id << ";\n";

    if (const auto applied {std::dynamic_pointer_cast<AppliedType>(type)}) {
      walk(applied->constructor, my_id);
      for (const auto& arg : applied->args) walk(arg, my_id);
    } else if (const auto optional {std::dynamic_pointer_cast<OptionalType>(type)}) {
      walk(optional->inner, my_id);
    } else if (const auto fn {std::dynamic_pointer_cast<FunctionType>(type)}) {
      for (const auto& param : fn->params) walk(param, my_id);
      walk(fn->return_type, my_id);
    }
  }

  public:
  std::string render(const std::vector<StmtNode>& tree) {
    out_.str("");
    out_.clear();
    out_ << "digraph Program {\n";
    out_ << "  rankdir=TB;\n";
    out_ << "  node [fontname=\"Iosevka Term SS09\"];\n";
    out_ << "  n0 [label=\"PROGRAM\", shape=box, color=darkorange2, fontcolor=black];\n";
    id_counter_        = 1;
    current_parent_id_ = 0;
    for (const auto& stmt : tree) walk(stmt, 0);
    out_ << "}\n";
    return out_.str();
  }
};

/**
 * Exports a  parse tree to GraphViz DOT format.
 * @param tree Parse tree to export
 * @return A string containing the DOT representation of the tree
 */
export std::string to_dot(const std::vector<StmtNode>& tree) {
  DotTreeWalker walker {};
  return walker.render(tree);
}
