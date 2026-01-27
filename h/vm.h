#pragma once

#include <fstream>

enum InterpretResult {
  INTERPRET_OK, INTERPRET_COMPILE_ERROR, INTERPRET_RUNTIME_ERROR
};

InterpretResult interpret(std::string* source, std::string_view module);
InterpretResult interpret_and_print(std::string* source, std::string_view module);
