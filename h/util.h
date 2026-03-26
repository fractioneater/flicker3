/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include "lexer.h"
#include "parser.h"

/**
 * Prints an error, warning, or note, and all of its child contexts.
 * @param line Line number (1-based)
 * @param col Column number (1-based)
 * @param module Name of the module being compiled
 * @param line_str Line in the source code where the error occurs
 * @param message Error message
 * @param type 0 for error, 1 for warning, 2 for note
 */
void print_error(size_t line, size_t col, std::string_view module, std::string_view line_str, const char* message, int type);

/**
 * Wrapper around print_error(line, col, module, line_str, message, type).
 */
void print_error(const Lexer& lexer, const LexerError& err, std::string_view module, int type);

/**
 * Wrapper around print_error(line, col, module, line_str, message, type).
 */
void print_error(const Lexer& lexer, const ParserError& err, std::string_view module, int type);

/**
 * Exports a  parse tree to GraphViz DOT format.
 * @param tree Parse tree to export
 * @return A string containing the DOT representation of the tree
 */
std::string to_dot(const std::vector<StmtNode>& tree);
