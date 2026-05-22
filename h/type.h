/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <limits>
#include <memory>
#include <string>
#include <utility>
#include <variant>
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

// Syntactic (parser) types --------------------------------------------------

class SyntacticType {
  public:
  virtual ~SyntacticType() = default;
  [[nodiscard]] virtual TypeKind kind() const = 0;
};

using SyntacticTypePtr = std::shared_ptr<SyntacticType>;

class NamedType final : public SyntacticType {
  std::string name_ {};

  public:
  explicit NamedType(std::string name) : name_ {std::move(name)} {}

  [[nodiscard]] TypeKind kind() const override { return TypeKind::NAMED; }
  [[nodiscard]] const std::string& name() const { return name_; }
};

class AppliedType final : public SyntacticType {
  SyntacticTypePtr constructor_ {};
  std::vector<SyntacticTypePtr> args_ {};

  public:
  AppliedType(SyntacticTypePtr constructor, std::vector<SyntacticTypePtr> args) : constructor_ {std::move(constructor)}, args_ {std::move(args)} {}

  [[nodiscard]] TypeKind kind() const override { return TypeKind::APPLIED; }
  [[nodiscard]] const SyntacticTypePtr& constructor() const { return constructor_; }
  [[nodiscard]] const std::vector<SyntacticTypePtr>& args() const { return args_; }
};

class OptionalType final : public SyntacticType {
  SyntacticTypePtr inner_ {};

  public:
  explicit OptionalType(SyntacticTypePtr inner) : inner_ {std::move(inner)} {}

  [[nodiscard]] TypeKind kind() const override { return TypeKind::OPTIONAL; }
  [[nodiscard]] const SyntacticTypePtr& inner() const { return inner_; }
};

class FunctionType final : public SyntacticType {
  std::vector<SyntacticTypePtr> params_ {};
  SyntacticTypePtr result_ {};

  public:
  FunctionType(std::vector<SyntacticTypePtr> params, SyntacticTypePtr result) : params_ {std::move(params)}, result_ {std::move(result)} {}

  [[nodiscard]] TypeKind kind() const override { return TypeKind::FUNCTION; }
  [[nodiscard]] const std::vector<SyntacticTypePtr>& params() const { return params_; }
  [[nodiscard]] const SyntacticTypePtr& result() const { return result_; }
};

class TypeVar final : public SyntacticType {
  std::string name_ {};

  public:
  explicit TypeVar(std::string name) : name_ {std::move(name)} {}

  [[nodiscard]] TypeKind kind() const override { return TypeKind::TYPE_VAR; }
  [[nodiscard]] const std::string& name() const { return name_; }
};

class OverloadSetType final : public SyntacticType {
  std::vector<SyntacticTypePtr> functions_ {};

  public:
  explicit OverloadSetType(std::vector<SyntacticTypePtr> functions) : functions_ {std::move(functions)} {}

  [[nodiscard]] TypeKind kind() const override { return TypeKind::OVERLOAD_SET; }
  [[nodiscard]] const std::vector<SyntacticTypePtr>& functions() const { return functions_; }
};

// Semantic (analyzer) types --------------------------------------------------

struct TypeId {
  uint32_t value {};

  static constexpr uint32_t invalid = std::numeric_limits<uint32_t>::max();

  constexpr TypeId() : value {invalid} {}
  constexpr explicit TypeId(uint32_t value) : value {value} {}

  constexpr bool operator==(const TypeId& other) const { return value == other.value; }
  constexpr bool operator!=(const TypeId& other) const { return value != other.value; }
  constexpr explicit operator bool() const { return value != invalid; }
};

struct Named {
  TypeId def {};
};

struct TypeParam {
  int index {};
};

struct Optional {
  TypeId inner;
};

struct Function {
  std::vector<TypeId> params;
  TypeId ret;
};

struct Applied {
  TypeId base;
  std::vector<TypeId> args;
};

using SemanticType = std::variant<Named, TypeParam, Optional, Function, Applied>;

class TypeArena {
  std::vector<SemanticType> types_ {};

  public:
  template <typename T>
  TypeId add(T&& t) {
    types_.emplace_back(std::forward<T>(t));
    return TypeId {static_cast<uint32_t>(types_.size() - 1)};
  }

  [[nodiscard]] const SemanticType& at(TypeId id) const {
    return types_[id.value];
  }
};
