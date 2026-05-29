/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

#include "analyzer.h"
#include "core.fl.h"
#include "lexer.h"
#include "parser.h"

enum ModuleStatus { MODULE_COMPILED, MODULE_COMPILE_ERROR, MODULE_RUNTIME_ERROR };

struct Module {
  ModuleStatus status {};

  std::unique_ptr<Lexer> lexer {};
  std::unique_ptr<Parser> parser {};
  Analyzer analyzer {}; // Why isn't it a unique_ptr? Because there can only be one, and it's safe to initialize immediately.

  virtual bool run() = 0;

  virtual ~Module() = default;

  protected:
  bool compile(std::string_view module_name, std::string src, int debug_level = 1);
};

struct StandardModule : Module {
  std::string name {};

  bool run() override;

  StandardModule(const std::string& name, std::string src);
};

/**
 * CoreModule, which is almost exactly the same as StandardModule, but its name is always "core," and it has small behavioral differences:
 * - There's only one of it.
 * - Debug outputs (PRINT_TOKENS, OUTPUT_DOT, PRINT_CODE, TRACE_EXECUTION) will only happen when the flag in common.h is set to 2.
 * - OUTPUT_DOT waits until the user presses Enter in case they want to read the DOT tree before it's overwritten by another module's output.
 */
struct CoreModule : Module {
  static constexpr std::string_view core_name {"core"};

  bool run() override;

  CoreModule();
};

/**
 * The idea of this is weird, but a ReplModule could potentially be loaded into a StandardModule to make an integrated debugger. Maybe.
 */
struct ReplModule : Module {
  static constexpr std::string_view repl_name {"input"};

  bool run_line(const std::string& line);

  private:
  bool run() override;
};

class ModuleLoader {
  std::unique_ptr<CoreModule> core_ {nullptr};
  std::unique_ptr<ReplModule> repl_ {nullptr};
  std::unordered_map<std::string, StandardModule> loaded_ {};

  void load_core();

  public:
  std::pair<std::unordered_map<std::string, StandardModule>::iterator, bool> load_by_path(const std::string& name, const std::string& path);

  /**
   * Get REPL input until ctrl+D.
   */
  void run_repl();
  void send_repl_line(const std::string& line) const;
};
