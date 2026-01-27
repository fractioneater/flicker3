#pragma once

// DEBUG FLAGS

// For the three following flags: 0 to disable, 1 to print user code, 2 to print everything (includes core module)
// Don't compile; just print the tokens straight from the lexer.
#define DEBUG_PRINT_TOKENS 0
// Print bytecode instructions immediately after compiling.
#define DEBUG_PRINT_CODE 0
// Print bytecode instructions as they run.
#define DEBUG_TRACE_EXECUTION 0

// Run the GC whenever the VM or compiler messes with memory.
#define DEBUG_STRESS_GC 0
// Log memory management and garbage collector runs.
#define DEBUG_LOG_GC 0

// COMPILER AND VM VALUES

#define MAX_PARAMETERS 16
#define MAX_METHOD_NAME 64
#define MAX_CONSTANTS 0x7fff
