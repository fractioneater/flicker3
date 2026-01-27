#include "vm.h"

#include <fstream>
#include <iostream>

void repl() {
  constexpr std::string_view prompt {"~ > "};
  std::string line {};
  // Not the cleanest syntax, but this comma expression works to print the "~ >" prompt and then get input.
  while (std::cout << prompt, std::getline(std::cin >> std::ws, line)) {
    interpret_and_print(&line, "input");
  }

  // Clear the prompt characters from the last line by printing \b as many times as necessary.
  std::cout << std::string(std::ssize(prompt), '\b');
}

void run_file(const char* path) {
  std::ifstream in {path};

  if (!in) {
    std::cerr << "Could not open file '" << path << "'\n";
    throw std::system_error(74, std::iostream_category()); // Exit code 74: generic i/o failure.
  }

  // TODO: What about memory errors? How will they be reported?

  // std::string str_input {};
  // while (std::getline(in, str_input)) {
  //   // Normally this would be added to some sort of longer source buffer to be run.
  //   std::cout << str_input << '\n';
  // }

  std::string source {};
  InterpretResult result = interpret(&source, "module");

  // This will be done automatically when it goes out of scope, but it's good practice anyway.
  in.close();

  if (result == INTERPRET_COMPILE_ERROR) throw std::system_error(65, std::generic_category()); // Exit code 65: data format error (compile error).
  if (result == INTERPRET_RUNTIME_ERROR) throw std::system_error(70, std::generic_category()); // Exit code 70: internal software error (runtime error).
}

int main(int argc, const char* argv[]) {
  if (argc == 1) {
    repl();
  } else if (argc == 2) {
    try {
      run_file(argv[1]);
    } catch (std::system_error& err) {
      return err.code().value();
    }
  } else {
    std::cout << "Usage: flicker [path]\n";
    return 64; // Exit code 64: command-line usage error.
  }

  return 0;
}
