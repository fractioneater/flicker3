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

class ExprVisitor {
public:
  virtual std::any visit_binary_expr(std::shared_ptr<Binary> expr) = 0;
  virtual std::any visit_unary_expr(std::shared_ptr<Unary> expr) = 0;
  virtual std::any visit_grouping_expr(std::shared_ptr<Grouping> expr) = 0;
  virtual std::any visit_literal_expr(std::shared_ptr<Literal> expr) = 0;
  virtual ~ExprVisitor() = default;
};

class Expr {
public:
  virtual std::any accept(ExprVisitor& visitor) = 0;
  virtual ~Expr() = default;
};

class Binary : public Expr, public std::enable_shared_from_this<Binary> {
public:
  Binary(const Token& op, std::shared_ptr<Expr> left, std::shared_ptr<Expr> right) : op {op}, left {std::move(left)}, right {std::move(right)} {}

  std::any accept(ExprVisitor& visitor) override {
    return visitor.visit_binary_expr(shared_from_this());
  }

  const Token op {};
  const std::shared_ptr<Expr> left {};
  const std::shared_ptr<Expr> right {};
};

class Unary : public Expr, public std::enable_shared_from_this<Unary> {
public:
  Unary(const Token& op, std::shared_ptr<Expr> expr) : op {op}, expr {std::move(expr)} {}

  std::any accept(ExprVisitor& visitor) override {
    return visitor.visit_unary_expr(shared_from_this());
  }

  Token op {};
  const std::shared_ptr<Expr> expr {};
};

class Grouping : public Expr, public std::enable_shared_from_this<Grouping> {
public:
  explicit Grouping(std::shared_ptr<Expr> expr) : expr {std::move(expr)} {}

  std::any accept(ExprVisitor& visitor) override {
    return visitor.visit_grouping_expr(shared_from_this());
  }

  const std::shared_ptr<Expr> expr {};
};

class Literal : public Expr, public std::enable_shared_from_this<Literal> {
public:
  explicit Literal(std::any value) : value {std::move(value)} {}

  std::any accept(ExprVisitor& visitor) override {
    return visitor.visit_literal_expr(shared_from_this());
  }

  const std::any value {};
};
