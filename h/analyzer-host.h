/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include "type.h"

struct CoreTypes {
  TypeId bool_t {};
  TypeId char_t {};
  TypeId list_t {};
  TypeId map_t {};
  TypeId nil_t {};
  TypeId number_t {};
  TypeId string_t {};
};

// The interface containing everything a ModuleLoader needs to expose to an Analyzer. This involves:
// - Module loading (imports)
// - Core type access
// - Maybe more later...
class AnalyzerHost {
  public:
  virtual ~AnalyzerHost() = default;

  /**
   * Make sure a module exists (attempt to load it if it doesn't).
   * @param current_module The module being compiled; the one with the 'using' statement. Storing this should help later with errors.
   * @param new_path Path of the module to load.
   * @return Whether the module is loaded after an attempt.
   */
  virtual bool ensure_loaded(std::string_view current_module, std::string& new_path) = 0;

  [[nodiscard]] virtual const CoreTypes& core_types() const = 0;
};
