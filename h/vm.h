#pragma once

#include <fstream>

enum InterpretResult {
  INTERPRET_OK, INTERPRET_COMPILE_ERROR, INTERPRET_RUNTIME_ERROR
};

InterpretResult interpret(const std::string& source, std::string_view module);
InterpretResult interpret_and_print(const std::string& source, std::string_view module);
