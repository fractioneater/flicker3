/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <vector>

#include "ast.h"

class Analyzer {
  // AST from the parser.
  const std::vector<StmtNode>& program_ {};
  // Errors/warnings/notes
  std::vector<Diagnostic> diagnostics_ {};

  public:
  explicit Analyzer(const std::vector<StmtNode>& program) : program_ {program} {}

  /**
   * Checks the parsed AST to make sure all names and types are correct.
   */
  void run();

  [[nodiscard]] bool encountered_halt() const {
    return std::ranges::any_of(diagnostics_, [](const Diagnostic& d) { return d.is_halting(); });
  }
};
