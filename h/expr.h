/**
* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <any>
#include <memory>

#include "lexer.h"

class Binary;
class Unary;
class Grouping;
class Literal;

// Type-erased base so Expr can accept any visitor; concrete visitors still type their result via ExprVisitor<R>.
// This class only serves to bridge between a concrete visitor and an Expr.
class ExprVisitorAny {
public:
  virtual std::any visit_binary_expr_any(std::shared_ptr<Binary> expr) = 0;
  virtual std::any visit_unary_expr_any(std::shared_ptr<Unary> expr) = 0;
  virtual std::any visit_grouping_expr_any(std::shared_ptr<Grouping> expr) = 0;
  virtual std::any visit_literal_expr_any(std::shared_ptr<Literal> expr) = 0;
  virtual ~ExprVisitorAny() = default;
};

// R is the return type for a concrete visitor. The _any member funcs adapt (dumb down) that typed visitor into the non-templated
// ExprVisitorAny interface so Expr can always dispatch via std::any, while the concrete visitor still works with its real return type.
template <typename R>
class ExprVisitor : public ExprVisitorAny {
public:
  virtual R visit_binary_expr(std::shared_ptr<Binary> expr) = 0;
  virtual R visit_unary_expr(std::shared_ptr<Unary> expr) = 0;
  virtual R visit_grouping_expr(std::shared_ptr<Grouping> expr) = 0;
  virtual R visit_literal_expr(std::shared_ptr<Literal> expr) = 0;

private:
  std::any visit_binary_expr_any(std::shared_ptr<Binary> expr) final {
    return visit_binary_expr(std::move(expr));
  }

  std::any visit_unary_expr_any(std::shared_ptr<Unary> expr) final {
    return visit_unary_expr(std::move(expr));
  }

  std::any visit_grouping_expr_any(std::shared_ptr<Grouping> expr) final {
    return visit_grouping_expr(std::move(expr));
  }

  std::any visit_literal_expr_any(std::shared_ptr<Literal> expr) final {
    return visit_literal_expr(std::move(expr));
  }
};

class Expr {
public:
  virtual std::any accept(ExprVisitorAny& visitor) = 0;

  // To call a typed/concrete visitor without having to write the ugly std::any stuff.
  template <typename R>
  R accept(ExprVisitor<R>& visitor) {
    return std::any_cast<R>(accept(static_cast<ExprVisitorAny&>(visitor)));
  }

  virtual ~Expr() = default;
};

class Binary : public Expr, public std::enable_shared_from_this<Binary> {
public:
  Binary(const Token& op, std::shared_ptr<Expr> left, std::shared_ptr<Expr> right) : op {op}, left {std::move(left)}, right {std::move(right)} {}

  std::any accept(ExprVisitorAny& visitor) override {
    return visitor.visit_binary_expr_any(shared_from_this());
  }

  const Token op {};
  const std::shared_ptr<Expr> left {};
  const std::shared_ptr<Expr> right {};
};

class Unary : public Expr, public std::enable_shared_from_this<Unary> {
public:
  Unary(const Token& op, std::shared_ptr<Expr> expr) : op {op}, expr {std::move(expr)} {}

  std::any accept(ExprVisitorAny& visitor) override {
    return visitor.visit_unary_expr_any(shared_from_this());
  }

  Token op {};
  const std::shared_ptr<Expr> expr {};
};

class Grouping : public Expr, public std::enable_shared_from_this<Grouping> {
public:
  explicit Grouping(std::shared_ptr<Expr> expr) : expr {std::move(expr)} {}

  std::any accept(ExprVisitorAny& visitor) override {
    return visitor.visit_grouping_expr_any(shared_from_this());
  }

  const std::shared_ptr<Expr> expr {};
};

class Literal : public Expr, public std::enable_shared_from_this<Literal> {
public:
  explicit Literal(std::any value) : value {std::move(value)} {}

  std::any accept(ExprVisitorAny& visitor) override {
    return visitor.visit_literal_expr_any(shared_from_this());
  }

  const std::any value {};
};
