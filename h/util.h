/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include "antlr4-runtime.h"
#include "lexer.h"

/**
 * Prints an error, warning, or note, and all of its child contexts.
 * @param lexer The source file's lexer, to turn the offset into  line:column
 * @param err The error, warning, or note to print
 * @param module A module string
 * @param type 0 for error, 1 for warning, anything else (but use 2) for note
 */
void print_error(const Lexer& lexer, const LexerError& err, std::string_view module, int type);

namespace flicker {
 /**
  * Exports an ANTLR parse tree to GraphViz DOT format.
  * @param tree The parse tree to export
  * @param parser The parser that generated the tree (used for rule names)
  * @return A string containing the DOT representation of the tree
  */
 std::string to_dot(antlr4::tree::ParseTree* tree, antlr4::Parser* parser);
}
