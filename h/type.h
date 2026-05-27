/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <limits>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <variant>
#include <vector>

// There are two types of types: the parser's types, and the analyzer's types. Look for a comment above each category for an explanation of the structure.

#define CORE_CLASS_COUNT 4

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

struct NamedType final : SyntacticType {
  std::string name {};

  explicit NamedType(std::string name) : name {std::move(name)} {}
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

  static constexpr uint32_t invalid {std::numeric_limits<uint32_t>::max()};

  constexpr TypeId() : value {invalid} {}
  constexpr explicit TypeId(uint32_t value) : value {value} {}

  constexpr bool operator==(const TypeId& other) const { return value == other.value; }
  constexpr bool operator!=(const TypeId& other) const { return value != other.value; }
  constexpr explicit operator bool() const { return value != invalid; }
};

struct Named {
  std::string name {}; // Just for hashing, really.
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

struct Applied {
  TypeId base;
  std::vector<TypeId> args;
  bool operator==(const Applied& other) const = default;
};

using SemanticType = std::variant<Named, TypeParam, Optional, Function, Applied>;

struct TypeKey {
  SemanticType type {};

  bool operator==(const TypeKey& other) const {
    return type == other.type;
  }

  explicit TypeKey(const SemanticType& t) : type {t} {}
};

// Hashing functions for SemanticType
template <>
struct std::hash<TypeId> {
  size_t operator()(const TypeId& id) const noexcept {
    return std::hash<uint32_t> {}(id.value);
  }
};

namespace Type_hash {
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
  size_t operator()(const TypeKey& key) const {
    return std::visit(
      []<typename T>(T&& k) -> size_t {
        using A = std::decay_t<T>;
        if constexpr (std::is_same_v<A, Named>) return Type_hash::hash_named(k);
        else if constexpr (std::is_same_v<A, TypeParam>) return Type_hash::hash_typeparam(k);
        else if constexpr (std::is_same_v<A, Optional>) return Type_hash::hash_optional(k);
        else if constexpr (std::is_same_v<A, Function>) return Type_hash::hash_function(k);
        else if constexpr (std::is_same_v<A, Applied>) return Type_hash::hash_applied(k);
        else static_assert(false, "TypeKey visitor isn't exhaustive!");
      },
      key.type
    );
  }
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

  public:
  TypeArena() {
    types_.reserve(CORE_CLASS_COUNT + 1);
    interned_.reserve(CORE_CLASS_COUNT + 1);
  }

  TypeId add(SemanticType&& t) {
    // This makes a copy. I've tried to find a way that allows single ownership (using std::list is one), but I'm not sure if it's worth the fight.
    const TypeKey key {t};
    const auto existing {interned_.find(key)};
    if (existing != interned_.end()) return existing->second;

    types_.emplace_back(std::forward<SemanticType>(t));
    TypeId id {static_cast<uint32_t>(types_.size() - 1)};
    interned_.emplace(key, id);
    return id;
  }

  [[nodiscard]] const SemanticType& at(TypeId id) const {
    return types_[id.value];
  }
};
