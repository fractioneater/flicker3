/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <algorithm>
#include <limits>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <variant>
#include <vector>

// There are two types of types: the parser's types, and the analyzer's types. Look for a comment above each category for an explanation of the structure.

#define TYPE_ARENA_RESERVE_SIZE 32

/**
 * SYNTACTIC (PARSER) TYPES --------------------------------------------------
 *
 * Don't assume that just because the parser doesn't do any type-checking, it doesn't have a complex type interface. It still has to handle the syntax,
 * and Flicker has a somewhat complex type syntax.
 *
 * This structure is taken care of by shared pointers because the parser and its ownership are a little messy. The base SyntacticType class is abstract and
 * includes basically no methods, instead acting mostly just as a parent for the actual type classes. Each class stores its "kind" (it's easier to say
 * type-kind than type-type) as an enumeration.
 *
 * The TypeKind enum stores these options:                                     EXAMPLE:
 *   Named: A simple type or type alias.                                       String
 *   Applied: Generic instantiation of a named constructor—like a container.  List of String
 *   Optional: Wrapper to add the possibility of nil value.                    String?
 *   Function: Callable type.                                                  (String, String) -> String
 */

enum class TypeKind {
  NAMED,
  APPLIED,
  OPTIONAL,
  FUNCTION,
};

class SyntacticType {
  public:
  virtual ~SyntacticType() = default;
  [[nodiscard]] virtual TypeKind kind() const = 0;
};

using SyntacticTypePtr = std::shared_ptr<SyntacticType>;

struct Token;

struct NamedType final : SyntacticType {
  std::string name {};
  const Token* identifier {};

  explicit NamedType(std::string name, const Token* token) : name {std::move(name)}, identifier {token} {}
  [[nodiscard]] TypeKind kind() const override { return TypeKind::NAMED; }
};

struct AppliedType final : SyntacticType {
  SyntacticTypePtr constructor {};
  std::vector<SyntacticTypePtr> args {};

  AppliedType(SyntacticTypePtr constructor, std::vector<SyntacticTypePtr> args) : constructor {std::move(constructor)}, args {std::move(args)} {}
  [[nodiscard]] TypeKind kind() const override { return TypeKind::APPLIED; }
};

struct OptionalType final : SyntacticType {
  SyntacticTypePtr inner {};

  explicit OptionalType(SyntacticTypePtr inner) : inner {std::move(inner)} {}
  [[nodiscard]] TypeKind kind() const override { return TypeKind::OPTIONAL; }
};

struct FunctionType final : SyntacticType {
  std::vector<SyntacticTypePtr> params {};
  SyntacticTypePtr result {};

  FunctionType(std::vector<SyntacticTypePtr> params, SyntacticTypePtr result) : params {std::move(params)}, result {std::move(result)} {}
  [[nodiscard]] TypeKind kind() const override { return TypeKind::FUNCTION; }
};

/**
 * SEMANTIC (ANALYZER) TYPES --------------------------------------------------
 *
 * After parsing, the analyzer converts syntactic types into semantic ones to determine the validity of names, members, and such. This system uses interning
 * to possibly increase performance—each type seen in code is assigned a TypeId (uint32_t wrapper), so equality is just integer comparison.
 *
 * Unlike the shared_ptr weirdness of SyntacticType, SemanticType is a variant of Named, TypeParam, Optional, Function, and Applied. Most of these classes are
 * exactly the same as their syntactic counterparts, but instead of storing a SyntacticTypePtr, they store a TypeId.
 *
 * All types are stored in the type arena, which maintains a vector for storage and an unordered_map for interning. Types are accessed via
 * TypeId (by index in the vector) rather than pointers/references since the vector can reallocate when resized. Interning is done with a quick hash through
 * TypeKey, which is an owning wrapper around SemanticType. Yes, this does mean the types exist in two places, but the only "real" storage location is the
 * vector.
 */

struct TypeId {
  uint32_t value {};

  static constexpr uint32_t INVALID {std::numeric_limits<uint32_t>::max()};

  constexpr TypeId() : value {INVALID} {}
  constexpr explicit TypeId(uint32_t value) : value {value} {}

  constexpr bool operator==(const TypeId& other) const { return value == other.value; }
  constexpr bool operator!=(const TypeId& other) const { return value != other.value; }
  constexpr explicit operator bool() const { return value != INVALID; }
};

using TypeDefId = uint32_t;

struct Named {
  std::string name {}; // For hashing and error messages.
  std::optional<TypeDefId> definition {};
  int arity {0}; // In case this is a template type.
  bool operator==(const Named& other) const = default;
};

struct TypeParam {
  int index {};
  std::string host_name {}; // Just for hashing.
  bool operator==(const TypeParam& other) const = default;
};

struct Optional {
  TypeId inner;
  bool operator==(const Optional& other) const = default;
};

struct Function {
  std::vector<TypeId> params;
  TypeId return_type;
  bool operator==(const Function& other) const = default;
};

struct OverloadSet {
  std::string name {};              // For hashing.
  std::vector<TypeId> overloads {}; // Should only hold Function TypeIds.

  [[nodiscard]] bool has(const TypeId signature) const {
    return std::ranges::any_of(overloads, [&](const TypeId& id) { return id == signature; });
  }

  void add(const TypeId signature) {
    // We're just going to hope very optimistically (and nervously) that a Function is passed.
    overloads.emplace_back(signature);
  }

  bool operator==(const OverloadSet& other) const = default;
};

struct Applied {
  TypeId base;
  std::vector<TypeId> args;
  bool operator==(const Applied& other) const = default;
};

using SemanticType = std::variant<Named, TypeParam, Optional, Function, OverloadSet, Applied>;

struct TypeKey {
  SemanticType type {};

  bool operator==(const TypeKey& other) const {
    return type == other.type;
  }

  explicit TypeKey(SemanticType t) : type {std::move(t)} {}
};

// Hashing functions for SemanticType
template <>
struct std::hash<TypeId> {
  size_t operator()(const TypeId& id) const noexcept {
    return std::hash<uint32_t> {}(id.value);
  }
};

namespace TypeHash {
  inline void hash_combine(size_t& seed, size_t h) noexcept {
    seed ^= h + 0x9e3779b97f4a7c15ULL + (seed << 6) + (seed >> 2);
  }

  template <class T>
  void hash_combine(size_t& seed, const T& v) noexcept {
    hash_combine(seed, std::hash<T> {}(v));
  }

  template <class T>
  size_t hash_vec(const std::vector<T>& v) noexcept {
    size_t seed {0};
    hash_combine(seed, v.size());
    for (auto& x : v) hash_combine(seed, x);
    return seed;
  }

  inline size_t hash_named(const Named& t) noexcept {
    size_t seed {0};
    hash_combine(seed, 1u);
    hash_combine(seed, t.name);
    hash_combine(seed, t.definition.value_or(std::numeric_limits<uint32_t>::max()));
    hash_combine(seed, t.arity);
    return seed;
  }

  inline size_t hash_typeparam(const TypeParam& t) noexcept {
    size_t seed {0};
    hash_combine(seed, 2u);
    hash_combine(seed, t.index);
    hash_combine(seed, t.host_name);
    return seed;
  }

  inline size_t hash_optional(const Optional& t) noexcept {
    size_t seed {0};
    hash_combine(seed, 3u);
    hash_combine(seed, t.inner);
    return seed;
  }

  inline size_t hash_function(const Function& t) noexcept {
    size_t seed {0};
    hash_combine(seed, 4u);
    hash_combine(seed, hash_vec(t.params));
    hash_combine(seed, t.return_type);
    return seed;
  }

  inline size_t hash_overload_set(const OverloadSet& t) noexcept {
    size_t seed {0};
    hash_combine(seed, 5u);
    hash_combine(seed, t.name);
    hash_combine(seed, hash_vec(t.overloads));
    return seed;
  }

  inline size_t hash_applied(const Applied& t) noexcept {
    size_t seed {0};
    hash_combine(seed, 5u);
    hash_combine(seed, t.base);
    hash_combine(seed, hash_vec(t.args));
    return seed;
  }
}

template <>
struct std::hash<TypeKey> {
  size_t operator()(const TypeKey& key) const noexcept {
    return std::visit(
      []<typename T>(T&& k) -> size_t {
        using A = std::decay_t<T>;
        if constexpr (std::is_same_v<A, Named>) return TypeHash::hash_named(k);
        else if constexpr (std::is_same_v<A, TypeParam>) return TypeHash::hash_typeparam(k);
        else if constexpr (std::is_same_v<A, Optional>) return TypeHash::hash_optional(k);
        else if constexpr (std::is_same_v<A, Function>) return TypeHash::hash_function(k);
        else if constexpr (std::is_same_v<A, OverloadSet>) return TypeHash::hash_overload_set(k);
        else if constexpr (std::is_same_v<A, Applied>) return TypeHash::hash_applied(k);
        else static_assert(false, "TypeKey visitor isn't exhaustive!");
        return 0;
      },
      key.type
    );
  }
};
class TypeArena;

class TypeDefinition {
  std::unordered_map<std::string, TypeId> namespace_symbols_ {}; // TODO NEXT. Also add the normal symbols.
  std::unordered_map<std::string, TypeId> symbols_ {};

  public:
  TypeId method_return_type(const TypeArena& arena, const std::string& name, const std::vector<TypeId>& params) const;
};

/**
 * The location where the compiler's (semantic) types are stored. Consists of a vector of type objects, accessible with at(),
 * and an unordered_map for interning, so type equality can be determined cheaply by ID.
 *
 * Because the data type for storage is a vector, references and pointers are not stable (all will be invalidated on resize),
 * so access is done with a TypeId (AKA uint32_t).
 */
class TypeArena {
  std::vector<SemanticType> types_ {};
  std::unordered_map<TypeKey, TypeId> interned_ {};

  std::vector<TypeDefinition> definitions_ {};

  [[nodiscard]] const SemanticType& at_(TypeId id) const {
    return types_[id.value];
  }

  public:
  TypeArena() {
    types_.reserve(TYPE_ARENA_RESERVE_SIZE + 1);
    interned_.reserve(TYPE_ARENA_RESERVE_SIZE + 1);
  }

  TypeId new_named(std::string&& name, int arity) {
    definitions_.emplace_back();
    const TypeDefId definition {static_cast<uint32_t>(definitions_.size() - 1)};

    return add(Named {std::move(name), definition, arity});
  }

  TypeId add(SemanticType&& t) {
    // This makes a copy. I've tried to find a way that allows single ownership (using std::list is one), but I'm not sure if it's worth the fight.
    const SemanticType new_t {t};
    const TypeKey key {new_t};
    const auto existing {interned_.find(key)};
    if (existing != interned_.end()) return existing->second;

    types_.emplace_back(std::forward<SemanticType>(t));
    TypeId id {static_cast<uint32_t>(types_.size() - 1)};
    interned_.emplace(key, id);
    return id;
  }

  [[nodiscard]] const SemanticType& at(TypeId id) const {
    if (!id) throw std::runtime_error("Invalid type ID");
    return at_(id);
  }

  [[nodiscard]] TypeId method_return_type(TypeId id, const std::string& method_name, const std::vector<TypeId>& params) const {
    const SemanticType& t {at(id)};
    return std::visit(
      [*this, &method_name, &params]<typename T>(T&& k) -> TypeId {
        using A = std::decay_t<T>;
        if constexpr (std::is_same_v<A, Named>) {
          if (!k.definition) throw std::runtime_error("Type '" + k.name + "' doesn't have a definition");
          return definitions_[k.definition.value()].method_return_type(*this, method_name, params);
        } else if constexpr (std::is_same_v<A, Applied>) {
          return method_return_type(k.base, method_name, params);
        } else return {};
      },
      t
    );
  }

  std::string to_string(TypeId id) const {
    if (!id) throw std::runtime_error("Invalid type ID");
    return std::visit(
      [*this]<typename T>(const T& t) -> std::string {
        using A = std::decay_t<T>;
        if constexpr (std::is_same_v<A, Named>) return t.name;
        else if constexpr (std::is_same_v<A, TypeParam>) return t.host_name;
        else if constexpr (std::is_same_v<A, Optional>) return std::string {to_string(t.inner) + "?"};
        else if constexpr (std::is_same_v<A, Function>) {
          std::string result {"("};
          for (size_t i {0}; i < t.params.size(); ++i) {
            if (i > 0) result += ", ";
            result += to_string(t.params[i]);
          }
          result += ") -> " + to_string(t.return_type);
          return result;
        } else if constexpr (std::is_same_v<A, OverloadSet>) {
          std::string result {"<fn " + t.name + ", overloading [ "};
          for (size_t i {0}; i < t.overloads.size(); ++i) {
            if (i > 0) result += "; ";
            result += to_string(t.overloads[i]);
          }
          return result + " ]>";
        } else if constexpr (std::is_same_v<A, Applied>) {
          std::string result {to_string(t.base) + " of"};
          for (size_t i {0}; i < t.args.size(); ++i) {
            result += " ";
            result += to_string(t.args[i]);
          }
          return result;
        } else static_assert(false, "as_string visitor isn't exhaustive!");
        return "";
      }, at_(id)
    );
  }

  [[nodiscard]] bool empty() const {
    return types_.empty();
  }
};

inline TypeId TypeDefinition::method_return_type(const TypeArena& arena, const std::string& name, const std::vector<TypeId>& params) const {
  const auto it {symbols_.find(name)};
  if (it == symbols_.end()) return {};
  const SemanticType& symbol {arena.at(it->second)};

  // Check if it's an overload set.
  if (!std::holds_alternative<OverloadSet>(symbol)) return {};

  for (const TypeId overload : std::get<OverloadSet>(symbol).overloads) {
    const auto& [overload_params, return_type] {std::get<Function>(arena.at(overload))};
    if (overload_params == params) return return_type;
  }
  return {};
}
