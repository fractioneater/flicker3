#ifndef FLICKER_3_VM_H
#define FLICKER_3_VM_H

#include <fstream>

enum interpret_result {
  INTERPRET_OK, INTERPRET_COMPILE_ERROR, INTERPRET_RUNTIME_ERROR
};

interpret_result interpret(std::ifstream* source, std::string module);

#endif // FLICKER_3_VM_H
