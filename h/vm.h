#ifndef FLICKER_3_VM_H
#define FLICKER_3_VM_H

#include <fstream>

enum interpret_result {
  INTERPRET_OK, INTERPRET_COMPILE_ERROR, INTERPRET_RUNTIME_ERROR
};

interpret_result interpret(std::string* source, std::string_view module);
interpret_result interpret_and_print(std::string* source, std::string_view module);

#endif // FLICKER_3_VM_H
