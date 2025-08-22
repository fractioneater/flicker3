#include "vm.h"

#include "common.h"

#include <iostream>
#include <fstream>

interpret_result interpret(std::ifstream* source, std::string module) {
# if DEBUG_PRINT_TOKENS
  std::cout << "I'm supposed to print your tokens.\n";
# endif
# if DEBUG_PRINT_CODE
  std::cout << "I'm supposed to print your code after compiling.\n";
# endif
# if DEBUG_TRACE_EXECUTION
  std::cout << "I'm supposed to trace execution.\n";
# endif

  return INTERPRET_OK;
}
