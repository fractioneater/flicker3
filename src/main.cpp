/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "vm.h"

#include <fstream>
#include <iostream>

std::string read_entire_file(const char* path) {
  std::ifstream in {path, std::ios::binary};

  if (!in) {
    std::cerr << "Could not open file '" << path << "'\n";
    throw std::system_error(74, std::iostream_category()); // Exit code 74: generic i/o failure.
  }

  in.seekg(0, std::ios::end);
  const std::streampos end_pos = in.tellg();

  if (end_pos >= 0) {
    std::string contents {};
    const auto size = static_cast<std::streamsize>(end_pos);
    if (size == static_cast<std::streamsize>(-1)) {
      std::cerr << "File '" << path << "' is too large\n";
      throw std::system_error(74, std::iostream_category());
    }
    contents.resize(size);

    in.seekg(0, std::ios::beg);
    in.read(contents.data(), size);
    if (!in) {
      std::cerr << "Could not read file '" << path << "'\n";
      throw std::system_error(74, std::iostream_category());
    }

    in.close();
    return contents;
  }

  // Fallback in case seek and tell aren't supported.
  in.clear();
  in.seekg(0, std::ios::beg);
  return std::string {std::istreambuf_iterator(in), std::istreambuf_iterator<char>()};
}

void repl() {
  constexpr std::string_view prompt {"~ > "};
  std::string line {};
  // Not the cleanest syntax, but this comma expression works to print the "~ >" prompt and then get input.
  while (std::cout << prompt, std::getline(std::cin >> std::ws, line)) {
    interpret_and_print(line, "input");
  }

  // Clear the prompt characters from the last line by printing \b as many times as necessary.
  std::cout << std::string(std::ssize(prompt), '\b');
}

void run_file(const char* path) {
  const std::string source {read_entire_file(path)};
  const InterpretResult result {interpret(source, path)};

  if (result == INTERPRET_COMPILE_ERROR) throw std::system_error(65, std::generic_category()); // Exit code 65: data format error (compile error).
  if (result == INTERPRET_RUNTIME_ERROR) throw std::system_error(70, std::generic_category()); // Exit code 70: internal software error (runtime error).
}

int main(int argc, const char* argv[]) {
  if (argc == 1) {
    repl();
  } else if (argc == 2) {
    try {
      run_file(argv[1]);
    } catch (const std::system_error& err) {
      return err.code().value();
    }
  } else {
    std::cout << "Usage: flicker [path]\n";
    return 64; // Exit code 64: command-line usage error.
  }

  return 0;
}
