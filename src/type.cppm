/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

module;
#include "common.h"

export module type;

import lexer;

import std;

// There are two types of types: the parser's types, and the analyzer's types. Look for a comment above each category for an explanation of the structure.

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

export enum class TypeKind {
  NAMED,
  APPLIED,
  OPTIONAL,
  FUNCTION,
  NAMESPACED,
};

class SyntacticType {
  public:
  virtual ~SyntacticType() = default;
  [[nodiscard]] virtual TypeKind kind() const = 0;
};

export using SyntacticTypePtr = std::shared_ptr<SyntacticType>;

export struct NamedType final : SyntacticType {
  std::string name {};
  const Token* identifier {};

  explicit NamedType(std::string name, const Token* token) : name {std::move(name)}, identifier {token} {}
  [[nodiscard]] TypeKind kind() const override { return TypeKind::NAMED; }
};

export struct AppliedType final : SyntacticType {
  SyntacticTypePtr constructor {};
  std::vector<SyntacticTypePtr> args {};

  AppliedType(const SyntacticTypePtr& constructor, std::vector<SyntacticTypePtr> args) : constructor {std::move(constructor)}, args {std::move(args)} {}
  [[nodiscard]] TypeKind kind() const override { return TypeKind::APPLIED; }
};

export struct OptionalType final : SyntacticType {
  SyntacticTypePtr inner {};

  explicit OptionalType(const SyntacticTypePtr& inner) : inner {std::move(inner)} {}
  [[nodiscard]] TypeKind kind() const override { return TypeKind::OPTIONAL; }
};

export struct FunctionType final : SyntacticType {
  std::vector<SyntacticTypePtr> params {};
  SyntacticTypePtr return_type {};

  FunctionType(std::vector<SyntacticTypePtr> params, const SyntacticTypePtr& return_type) : params {std::move(params)}, return_type {std::move(return_type)} {}
  [[nodiscard]] TypeKind kind() const override { return TypeKind::FUNCTION; }
};

export struct NamespacedType final : SyntacticType {
  std::vector<std::string> namespace_path {};
  std::string name {};
  const Token* where {};

  NamespacedType(std::vector<std::string> namespace_path, std::string name, const Token* token)
    : namespace_path {std::move(namespace_path)}, name {std::move(name)}, where {token} {}

  [[nodiscard]] TypeKind kind() const override { return TypeKind::NAMESPACED; }
};

/**
 * SEMANTIC (ANALYZER) TYPES --------------------------------------------------
 *
 * After parsing, the analyzer converts syntactic types into semantic ones to determine the validity of names, members, and such. This system uses interning
 * to possibly increase performance—each type seen in code is assigned a TypeId (std::uint32_t wrapper), so equality is just integer comparison.
 *
 * Unlike the shared_ptr weirdness of SyntacticType, SemanticType is a variant of Named, TypeParam, Optional, Function, and Applied. Most of these classes are
 * exactly the same as their syntactic counterparts, but instead of storing a SyntacticTypePtr, they store a TypeId.
 *
 * All types are stored in the type arena, which maintains a vector for storage and an unordered_set for interning. Types are accessed via
 * TypeId (by index in the vector) rather than pointers/references since the vector can reallocate when resized. Interning is done by storing TypeId indices
 * in the set, whose transparent hash/equality functors dereference back into the storage vector. Finally, each type lives in exactly one place (the vector)
 * and is never copied for interning.
 */

export struct TypeId {
  std::uint32_t value {};

  static constexpr std::uint32_t INVALID {std::numeric_limits<std::uint32_t>::max()};

  constexpr TypeId() : value {INVALID} {}
  constexpr explicit TypeId(std::uint32_t value) : value {value} {}

  constexpr bool operator==(const TypeId& other) const { return value == other.value; }
  constexpr bool operator!=(const TypeId& other) const { return value != other.value; }
  constexpr explicit operator bool() const { return value != INVALID; }
};

using TypeDefId = std::uint32_t;

export struct Named {
  std::string name {}; // For hashing and error messages.
  int arity {0};       // In case this is a template type.
  bool operator==(const Named& other) const = default;
};

export struct TypeParam {
  int index {};
  std::string host_name {}; // Just for hashing.
  bool operator==(const TypeParam& other) const = default;
};

export struct Optional {
  TypeId inner;
  bool operator==(const Optional& other) const = default;
};

export struct Function {
  std::vector<TypeId> params {};
  TypeId return_type;
  bool operator==(const Function& other) const = default;
};

export struct OverloadSet {
  std::string name {};              // For hashing.
  std::vector<TypeId> overloads {}; // Should only hold Function TypeIds. DO NOT MUTATE! It would throw off interning.

  [[nodiscard]] bool has(const TypeId signature) const {
    return std::ranges::any_of(overloads, [&](const TypeId& id) { return id == signature; });
  }

  void add(const TypeId signature) {
    // We're just going to hope very optimistically (and nervously) that a Function is passed.
    overloads.emplace_back(signature);
  }

  bool operator==(const OverloadSet& other) const = default;
};

export struct Applied {
  TypeId base;
  std::vector<TypeId> args {};
  bool operator==(const Applied& other) const = default;
};

export using SemanticType = std::variant<Named, TypeParam, Optional, Function, OverloadSet, Applied>;

// Hashing functions for SemanticType
template <>
struct std::hash<TypeId> {
  std::size_t operator()(const TypeId& id) const noexcept {
    return std::hash<std::uint32_t> {}(id.value);
  }
};

namespace TypeHash {
  inline void hash_combine(std::size_t& seed, std::size_t h) noexcept {
    seed ^= h + 0x9e3779b97f4a7c15ULL + (seed << 6) + (seed >> 2);
  }

  template <class T>
  void hash_combine(std::size_t& seed, const T& v) noexcept {
    hash_combine(seed, std::hash<T> {}(v));
  }

  template <class T>
  std::size_t hash_vec(const std::vector<T>& v) noexcept {
    std::size_t seed {0};
    hash_combine(seed, v.size());
    for (auto& x : v) hash_combine(seed, x);
    return seed;
  }

  inline std::size_t hash_named(const Named& t) noexcept {
    std::size_t seed {0};
    hash_combine(seed, 1u);
    hash_combine(seed, t.name);
    hash_combine(seed, t.arity);
    return seed;
  }

  inline std::size_t hash_typeparam(const TypeParam& t) noexcept {
    std::size_t seed {0};
    hash_combine(seed, 2u);
    hash_combine(seed, t.index);
    hash_combine(seed, t.host_name);
    return seed;
  }

  inline std::size_t hash_optional(const Optional& t) noexcept {
    std::size_t seed {0};
    hash_combine(seed, 3u);
    hash_combine(seed, t.inner);
    return seed;
  }

  inline std::size_t hash_function(const Function& t) noexcept {
    std::size_t seed {0};
    hash_combine(seed, 4u);
    hash_combine(seed, hash_vec(t.params));
    hash_combine(seed, t.return_type);
    return seed;
  }

  inline std::size_t hash_overload_set(const OverloadSet& t) noexcept {
    std::size_t seed {0};
    hash_combine(seed, 5u);
    hash_combine(seed, t.name);
    hash_combine(seed, hash_vec(t.overloads));
    return seed;
  }

  inline std::size_t hash_applied(const Applied& t) noexcept {
    std::size_t seed {0};
    hash_combine(seed, 6u);
    hash_combine(seed, t.base);
    hash_combine(seed, hash_vec(t.args));
    return seed;
  }
}

inline std::size_t hash_semantic_type(const SemanticType& t) noexcept {
  return std::visit(
    []<typename T>(T&& k) -> std::size_t {
      using A = std::decay_t<T>;
      if constexpr (std::is_same_v<A, Named>) return TypeHash::hash_named(k);
      else if constexpr (std::is_same_v<A, TypeParam>) return TypeHash::hash_typeparam(k);
      else if constexpr (std::is_same_v<A, Optional>) return TypeHash::hash_optional(k);
      else if constexpr (std::is_same_v<A, Function>) return TypeHash::hash_function(k);
      else if constexpr (std::is_same_v<A, OverloadSet>) return TypeHash::hash_overload_set(k);
      else if constexpr (std::is_same_v<A, Applied>) return TypeHash::hash_applied(k);
      else static_assert(false, "SemanticType visitor isn't exhaustive!");
      return 0;
    },
    t
  );
}

// Hash and equality functors for interning by TypeId index. They dereference into the arena's type vector, so the type lives in one place and never needs
// to be copied for interning. TypeIds (indices) are stored instead of pointers or refs, because a vector resize won't invalidate them.
struct ArenaTypeHash {
  // ReSharper disable once CppInconsistentNaming; is_transparent has to be written this way.
  using is_transparent = void;
  const std::vector<SemanticType>* types {};

  std::size_t operator()(const TypeId id) const noexcept { return hash_semantic_type((*types)[id.value]); }
  std::size_t operator()(const SemanticType& t) const noexcept { return hash_semantic_type(t); }
};

struct ArenaTypeEq {
  // ReSharper disable once CppInconsistentNaming; is_transparent has to be written this way.
  using is_transparent = void;
  const std::vector<SemanticType>* types {};

  bool operator()(const TypeId a, const TypeId b) const { return (*types)[a.value] == (*types)[b.value]; }
  bool operator()(const TypeId a, const SemanticType& b) const { return (*types)[a.value] == b; }
  bool operator()(const SemanticType& a, const TypeId b) const { return a == (*types)[b.value]; }
};

/**
 * An lvalue. Stores a bool is_mutable and a TypeId declared_type.
 * Its type may be INVALID if an error occurs in the user's code (or Flicker's code, but... you know what I mean).
 */
export struct ObjectSymbol {
  bool is_mutable {false};
  TypeId declared_type {};
};

export struct SymbolTable;

export class Searchable {
  public:
  virtual ~Searchable() = default;

  [[nodiscard]] virtual std::optional<TypeId> find_type(const std::string& name) const = 0;
  [[nodiscard]] virtual std::optional<ObjectSymbol> find_object(const std::string& name) const = 0;
  [[nodiscard]] virtual std::optional<std::shared_ptr<SymbolTable>> find_namespace(const std::string& name) const = 0;
};

export struct SymbolTable : Searchable {
  std::unordered_map<std::string, ObjectSymbol> objects {};
  std::unordered_map<std::string, TypeId> types {};
  std::unordered_map<std::string, std::shared_ptr<SymbolTable>> namespaces {};

  [[nodiscard]] std::optional<ObjectSymbol> find_object(const std::string& name) const override {
    const auto it {objects.find(name)};
    if (it != objects.end()) return it->second;
    return std::nullopt;
  }

  [[nodiscard]] std::optional<TypeId> find_type(const std::string& name) const override {
    const auto it {types.find(name)};
    if (it != types.end()) return it->second;
    return std::nullopt;
  }

  [[nodiscard]] std::optional<std::shared_ptr<SymbolTable>> find_namespace(const std::string& name) const override {
    const auto it {namespaces.find(name)};
    if (it != namespaces.end()) return it->second;
    return std::nullopt;
  }
};

export using Namespace = std::shared_ptr<SymbolTable>;

struct TypeDefinition {
  SymbolTable symbols {};
  std::vector<TypeId> supertypes {};
};

/**
 * The location where the compiler's (semantic) types are stored. Consists of a vector of type objects, accessible with at(),
 * and an unordered_set for interning, so type equality can be determined cheaply by ID.
 *
 * Because the data type for storage is a vector, references and pointers are not stable (all will be invalidated on resize),
 * so access is done with a TypeId (AKA std::uint32_t).
 */
export class TypeArena {
  std::vector<SemanticType> types_ {};
  std::unordered_set<TypeId, ArenaTypeHash, ArenaTypeEq> interned_;

  std::vector<TypeDefinition> definitions_ {};

  [[nodiscard]] const SemanticType& at_(TypeId id) const {
    return types_[id.value];
  }

  public:
  TypeArena() : interned_(TYPE_ARENA_RESERVE_SIZE, ArenaTypeHash {&types_}, ArenaTypeEq {&types_}) {
    types_.reserve(TYPE_ARENA_RESERVE_SIZE);
    definitions_.reserve(TYPE_ARENA_RESERVE_SIZE);
  }

  TypeId new_named(std::string&& name, int arity) {
    return add(Named {std::move(name), arity});
  }

  TypeId add(SemanticType&& t) {
    // Check by value with transparent lookup—no copy needed!
    if (const auto existing {interned_.find(t)}; existing != interned_.end()) return *existing;

    // Not interned, so put it in the vector and intern the index.
    types_.emplace_back(std::move(t));
    const TypeId id {static_cast<std::uint32_t>(types_.size() - 1)};
    interned_.insert(id);

    // And finally, create its definition.
    definitions_.emplace_back();
    return id;
  }

  [[nodiscard]] const SemanticType& at(TypeId id) const {
    if (!id) throw std::runtime_error("Invalid type ID in at()");
    return at_(id);
  }

  // May return TypeId::INVALID, which needs to be handled.
  [[nodiscard]] TypeId method_return_type(TypeId id, const std::string& method_name, const std::vector<TypeId>& params) const {
    if (!id) return {};
    const auto symbols {definitions_[id.value].symbols};
    const auto it {symbols.find_object(method_name)};
    if (!it) return {};
    const SemanticType& symbol {at(it->declared_type)};

    // Check if it's an overload set.
    if (!std::holds_alternative<OverloadSet>(symbol)) return {};

    for (const TypeId overload : std::get<OverloadSet>(symbol).overloads) {
      const auto& [overload_params, return_type] {std::get<Function>(at(overload))};
      if (overload_params == params) return return_type;
    }
    return {};
  }

  // Invalid return means an error has already been handled, std::nullopt means it has yet to be.
  [[nodiscard]] std::optional<TypeId> member_type(TypeId id, const std::string& member_name) const {
    if (!id) return std::nullopt;
    const SymbolTable& symbols {definitions_[id.value].symbols};
    const auto it {symbols.find_object(member_name)};
    if (!it) return std::nullopt;
    return it->declared_type;
  }

  /**
   * Gives a class member a new type, not altering its mutability. For method overloading.
   * @param id Class holding the member to edit
   * @param member_name Name of the member being edited
   * @param new_type New type to assign to the member
   */
  void edit_member_type(TypeId id, const std::string& member_name, TypeId new_type) {
    if (!id) return;
    SymbolTable& symbols {definitions_[id.value].symbols};
    auto it {symbols.objects.find(member_name)};
    if (it == symbols.objects.end()) return;
    it->second.declared_type = new_type;
  }

  /**
   * Defines supertypes for a type definition.
   * Why do we call it inheritance in programming? You're only supposed to inherit things when the ancestor dies in real life. I don't get it.
   * As the usage of the word "define" suggests, this should only be called once per type, because it overwrites the supertype vector.
   * @param id TypeId to add supertypes to
   * @param supertypes Supertypes to add to the definition
   */
  void define_supertypes(TypeId id, std::vector<TypeId>&& supertypes) {
    if (id) definitions_[id.value].supertypes = std::move(supertypes);
  }

  [[nodiscard]] bool is_supertype(TypeId test, TypeId possible_supertype) const {
    if (!test || !possible_supertype) return false;
    if (test == possible_supertype) return true;
    for (const TypeId super : definitions_[test.value].supertypes)
      // A little recursion never hurt anyone. I'm dreading how slow this may end up being, though. Well, no. Multiple inheritance won't be too common.
      if (is_supertype(super, possible_supertype)) return true;

    return false;
  }

  void add_members(TypeId id, std::unordered_map<std::string, ObjectSymbol>&& objects, std::unordered_map<std::string, TypeId>&& types) {
    if (!id) throw std::runtime_error("Can't add members to a type without a definition");
    auto& symbols {definitions_[id.value].symbols};
    symbols.objects.insert(std::begin(objects), std::end(objects));
    symbols.types.insert(std::begin(types), std::end(types));
  }

  [[nodiscard]] std::string to_string(TypeId id) const {
    if (!id) return "<invalid type>";
    return std::visit(
      [*this]<typename T>(const T& t) -> std::string {
        using A = std::decay_t<T>;
        if constexpr (std::is_same_v<A, Named>) return t.name;
        else if constexpr (std::is_same_v<A, TypeParam>) return t.host_name + "@" + std::to_string(t.index);
        else if constexpr (std::is_same_v<A, Optional>) return std::string {to_string(t.inner) + "?"};
        else if constexpr (std::is_same_v<A, Function>) {
          std::string result {"("};
          for (std::size_t i {0}; i < t.params.size(); ++i) {
            if (i > 0) result += ", ";
            result += to_string(t.params[i]);
          }
          result += ") -> " + to_string(t.return_type);
          return result;
        } else if constexpr (std::is_same_v<A, OverloadSet>) {
          std::string result {"<fn " + t.name + ", overloading [ "};
          for (std::size_t i {0}; i < t.overloads.size(); ++i) {
            if (i > 0) result += "; ";
            result += to_string(t.overloads[i]);
          }
          return result + " ]>";
        } else if constexpr (std::is_same_v<A, Applied>) {
          std::string result {to_string(t.base) + " of"};
          for (std::size_t i {0}; i < t.args.size(); ++i) {
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
