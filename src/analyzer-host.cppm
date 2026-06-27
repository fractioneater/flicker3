/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

export module analyzer_host;

import type;

import std;

export struct ModuleExports {
  std::string name {};
  SymbolTable& symbols;
};

export struct CoreTypes {
  // Keep this list in alphabetical order.
  TypeId any_t {};
  TypeId bool_t {};
  TypeId char_t {};
  TypeId list_t {};
  TypeId map_t {};
  TypeId nothing_t {};
  TypeId number_t {};
  TypeId sequence_t {};
  TypeId string_t {};
  TypeId unit_t {};

  CoreTypes() = default;

  // This should be alphabetical too. Add an underscore suffix for conflicting C++ types.
  CoreTypes(TypeId any, TypeId bool_, TypeId char_, TypeId list, TypeId map, TypeId nothing, TypeId number, TypeId sequence, TypeId string, TypeId unit) :
    any_t {any}, bool_t {bool_}, char_t {char_}, list_t {list}, map_t {map}, nothing_t {nothing}, number_t {number}, sequence_t {sequence}, string_t {string},
    unit_t {unit} {}
};

// The interface containing everything a ModuleLoader needs to expose to an Analyzer. This involves:
// - Module loading (imports)
// - Core type access
// - TypeArena access
// - And maybe more...
export class AnalyzerHost {
  public:
  virtual ~AnalyzerHost() = default;

  /**
   * Make sure a module exists (attempt to load it if it doesn't) and get its exports.
   * @param path Path of the module to load.
   * @return The module's top-level variables by name (exports) and name.
   */
  [[nodiscard]] virtual const std::optional<ModuleExports> exports(const std::string& path) = 0;

  [[nodiscard]] virtual const CoreTypes& core_types() const = 0;

  virtual TypeArena& type_arena() = 0;
};
