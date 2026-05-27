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
  constexpr std::string_view prompt {"~ > "};
  std::string line {};

  #if PRINT_COLORS
  #  define PROMPT PROMPT_COLOR << prompt << CLEAR_FORMAT
  #else
  #  define PROMPT prompt
  #endif

  ml.load_repl();
  // Not the cleanest syntax, but this comma expression works to print the "~ >" prompt and then get input.
  while (std::cout << PROMPT, std::getline(std::cin >> std::ws, line)) {
    ml.send_repl_line(line);
  }

  // Clear the prompt characters from the last line with a quick ANSI escape.
  std::cout << "\033[2K\033[1G";
}

void run_file(ModuleLoader& ml, const char* path) {
  // Module name
  const std::filesystem::path p {path};
  const std::string module_name {p.stem().string()};
  // And here we go!
  ml.load_by_path(module_name, path);

  // if (result == INTERPRET_COMPILE_ERROR) throw std::system_error(65, std::generic_category()); // Exit code 65: data format error (compile error).
  // if (result == INTERPRET_RUNTIME_ERROR) throw std::system_error(70, std::generic_category()); // Exit code 70: internal software error (runtime error).
}

int main(int argc, const char* argv[]) {
  ModuleLoader ml {};

  if (argc == 1) {
    // One arg (just 'flicker').
    repl(ml);
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
