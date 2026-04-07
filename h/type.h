/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <memory>
#include <string>
#include <utility>
#include <vector>

/**
 * Identifies the kind (type-kind is easier to say than type-type) of a resolved type.
 *
 * - Named: A simple type or type alias. Example: String.
 * - Applied: Generic instantiation of a named constructor—like a container. Example: List of String.
 * - Optional: Wrapper to add possibility of nil value. Example: String?.
 * - Function: Callable type. Example: (String, String) -> String.
 * - TypeVar: A type parameter or inference variable. Example: A in `class Thing of A` or `fun do_something for A ().
 * - OverloadSet: A value with multiple callable signatures. Example: (Int) -> Int | (Double) -> Double.
 */
enum class TypeKind {
  NAMED,
  APPLIED,
  OPTIONAL,
  FUNCTION,
  TYPE_VAR,
  OVERLOAD_SET,
};

class Type {
  public:
  virtual ~Type() = default;
  [[nodiscard]] virtual TypeKind kind() const = 0;
};

using TypePtr = std::shared_ptr<Type>;

class NamedType final : public Type {
  std::string name_ {}; // TODO: We may want more than a name later.

  public:
  explicit NamedType(std::string name) : name_ {std::move(name)} {}

  [[nodiscard]] TypeKind kind() const override { return TypeKind::NAMED; }
  [[nodiscard]] const std::string& name() const { return name_; }
};

class AppliedType final : public Type {
  TypePtr constructor_ {};
  std::vector<TypePtr> args_ {};

  public:
  AppliedType(TypePtr constructor, std::vector<TypePtr> args) : constructor_ {std::move(constructor)}, args_ {std::move(args)} {}

  [[nodiscard]] TypeKind kind() const override { return TypeKind::APPLIED; }
  [[nodiscard]] const TypePtr& constructor() const { return constructor_; }
  [[nodiscard]] const std::vector<TypePtr>& args() const { return args_; }
};

class OptionalType final : public Type {
  TypePtr inner_ {};

  public:
  explicit OptionalType(TypePtr inner) : inner_ {std::move(inner)} {}

  [[nodiscard]] TypeKind kind() const override { return TypeKind::OPTIONAL; }
  [[nodiscard]] const TypePtr& inner() const { return inner_; }
};

class FunctionType final : public Type {
  std::vector<TypePtr> params_ {};
  TypePtr result_ {};

  public:
  FunctionType(std::vector<TypePtr> params, TypePtr result) : params_ {std::move(params)}, result_ {std::move(result)} {}

  [[nodiscard]] TypeKind kind() const override { return TypeKind::FUNCTION; }
  [[nodiscard]] const std::vector<TypePtr>& params() const { return params_; }
  [[nodiscard]] const TypePtr& result() const { return result_; }
};

class TypeVar final : public Type {
  std::string name_ {};

  public:
  explicit TypeVar(std::string name) : name_ {std::move(name)} {}

  [[nodiscard]] TypeKind kind() const override { return TypeKind::TYPE_VAR; }
  [[nodiscard]] const std::string& name() const { return name_; }
};

class OverloadSetType final : public Type {
  std::vector<TypePtr> functions_ {};

  public:
  explicit OverloadSetType(std::vector<TypePtr> functions) : functions_ {std::move(functions)} {}

  [[nodiscard]] TypeKind kind() const override { return TypeKind::OVERLOAD_SET; }
  [[nodiscard]] const std::vector<TypePtr>& functions() const { return functions_; }
};
