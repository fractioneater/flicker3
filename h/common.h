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
#define DEBUG_DOT_FILENAME "/home/fractioneater/stuff/git/flicker-3/tree.dot"

// OTHER FLAGS ---------------------------------------------------------------------------

// This should be disabled for use in a terminal that doesn't support color.
#define PRINT_COLORS 1

// COMPILER AND VM VALUES ----------------------------------------------------------------

// Pretty stuff
#define USE_SYSTEM_COLORS_ONLY 0
#if USE_SYSTEM_COLORS_ONLY
#  define PROMPT_COLOR "\033[38;5;13m"
#  define RESULT_COLOR "\033[38;5;10m"
#  define ERROR_COLOR "\033[38;5;9m"
#  define WARNING_COLOR "\033[38;5;11m"
#  define NOTE_COLOR "\033[38;5;14m"
#  define POINTER_COLOR "\033[38;5;10m"
#else
#  define PROMPT_COLOR "\033[38;2;187;134;255m"
#  define RESULT_COLOR "\033[38;2;119;235;53m"
#  define ERROR_COLOR "\033[38;2;232;98;91m"
#  define WARNING_COLOR "\033[38;2;235;195;53m"
#  define NOTE_COLOR "\033[38;2;74;190;218m"
#  define POINTER_COLOR "\033[38;2;187;134;255m"
#endif
#define DARK_GRAY_COLOR "\033[38;5;8m"
#define BOLD "\033[1m"
#define CLEAR_FORMAT "\033[0m"

// Restricting stuff
#define MAX_PARAMETERS 16
#define MAX_METHOD_NAME 64
#define MAX_CONSTANTS 0x7FFF

// Lexer stuff
#define MAX_COMMENT_NEST 16
#define MAX_INTERPOLATION_NEST 8
