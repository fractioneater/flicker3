/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

// DEBUG FLAGS ---------------------------------------------------------------------------

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

// Print the parse tree in DOT format for GraphViz.
#define DEBUG_PRINT_DOT 1
#define DEBUG_DOT_FILENAME "./tree.dot"

// OTHER FLAGS ---------------------------------------------------------------------------

// This should be disabled for use in a terminal that doesn't support color.
#define PRINT_ERROR_COLORS 1

// COMPILER AND VM VALUES ----------------------------------------------------------------

// Pretty stuff
#define COLOR_ERROR 211
#define COLOR_WARNING 221
#define COLOR_NOTE 74

// Restricting stuff
#define MAX_PARAMETERS 16
#define MAX_METHOD_NAME 64
#define MAX_CONSTANTS 0x7FFF

// Lexer stuff
#define MAX_COMMENT_NEST 16
#define MAX_INTERPOLATION_NEST 8
