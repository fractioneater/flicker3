/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "vm.h"

#include <filesystem>
#include <fstream>
#include <iostream>

#include "module.h"

void repl(ModuleLoader& ml) {
  ml.run_repl();
}

void run_file(ModuleLoader& ml, const char* path) {
  // Module name
  const std::filesystem::path p {path};
  const std::string module_name {p.stem().string()};

  // And here we go!
  const auto [module, success] {ml.load_by_path(module_name, path)};
  if (!success)
    throw std::system_error(70, std::generic_category()); // Exit code 70: internal software error (something weird happened).

  if (module->second.status != MODULE_COMPILED)
    throw std::system_error(65, std::generic_category()); // Exit code 65: data format error (compile error, not my fault).

  if (!module->second.run())
    throw std::system_error(70, std::generic_category()); // Exit code 70: internal software error (runtime error, maybe my fault).
}

int main(int argc, const char* argv[]) {
  ModuleLoader ml {};

  if (argc == 1) {
    // One arg (just 'flicker').
    try {
      repl(ml);
    } catch (const std::system_error& err) {
      return err.code().value();
    }
  } else if (argc == 2) {
    // Two args, and we'll assume it's 'flicker <path>'.
    try {
      run_file(ml, argv[1]);
    } catch (const std::system_error& err) {
      return err.code().value();
    }
  } else {
    std::cout << "Usage: flicker [path]\n";
    return 64; // Exit code 64: command-line usage error.
  }

  return 0;
}
