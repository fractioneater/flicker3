/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "util.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "common.h"

void formatting(int type) {
  #if PRINT_ERROR_COLORS
  if (type == 0) { // Error.
    std::cout << "\033[38;5;" << ERROR_COLOR << "m\033[1m";
  } else if (type == 1) { // Warning.
    std::cout << "\033[38;5;" << WARNING_COLOR << "m\033[1m";
  } else { // Note.
    std::cout << "\033[38;5;" << NOTE_COLOR << "m\033[1m  note: ";
  }
  #else
  if (type == 0) { // Error.
    std::cout << "ERROR ";
  } else if (type == 1) { // Warning.
    std::cout << "WARNING ";
  } else { // Note.
    std::cout << "NOTE ";
  }
  #endif
}

void print_error(size_t line, size_t col, const std::string_view module, const std::string_view line_str, const char* message, int type) {
  // moduleName@39:14 Block comment is missing closing '-#'
  //    39 │ print 0xABCD #- unclosed!
  //                      ^
  formatting(type);
  std::cout << module << "@" << line << ":" << col << "\033[0m " << message << '\n';
  std::cout << std::setw(5) << line << " │ " << line_str << '\n';
  std::cout << "        " << std::string(col - 1, ' ') << "\033[38;5;" << POINTER_COLOR << "m\033[1m^\033[0m\n";
}

void print_error(const Lexer& lexer, const LexerError& err, const std::string_view module, int type) {
  const auto [line, col] {lexer.offset_to_line_col(err.offset)};
  print_error(line, col, module, lexer.offset_to_line_string(err.offset), err.what(), type);
  if (err.context) print_error(lexer, *err.context, module, 2);
}

void print_error(const Lexer& lexer, const ParserError& err, const std::string_view module, int type) {
  const auto [line, col] {lexer.offset_to_line_col(err.token->start_offset)};
  print_error(line, col, module, lexer.offset_to_line_string(err.token->start_offset), err.what(), type);
  if (err.context) print_error(lexer, *err.context, module, 2);
}

namespace flicker {
  static std::pair<std::string, bool> escape(const std::string& s) {
    std::ostringstream oss;
    bool whitespace = true;
    for (const auto c : s) {
      switch (c) {
        case '"': oss << "\\\"";
          break;
        case '\\': oss << "\\\\";
          break;
        case '\n': oss << "\\\\n";
          break;
        case '\r': oss << "\\\\r";
          break;
        case '\t': oss << "\\\\t";
          break;
        case ' ': break;
        default: oss << c;
          whitespace = false;
          break;
      }
    }
    return {oss.str(), whitespace};
  }

  // This code is not the greatest (well, I'm assuming this because I didn't write it). It was not intended to be permanent, but I now realize that a
  // parse tree visualization is actually rather helpful, so I might keep it. When ANTLR goes away, it'll get polished.
  static void walk(antlr4::tree::ParseTree* node, antlr4::Parser* parser, std::ostringstream& out, int& id_counter, int parent_id) {
    const int my_id = id_counter++;
    std::string label;

    while (node->children.size() == 1) {
      node = node->children[0];
    }

    if (const auto* ctx = dynamic_cast<antlr4::ParserRuleContext*>(node)) {
      label = parser->getRuleNames()[ctx->getRuleIndex()];
      out << "  n" << my_id << " [label=\"" << escape(label).first << "\", shape=box, color=cornflowerblue, fontcolor=blue];\n";
    } else if (const auto* terminal = dynamic_cast<antlr4::tree::TerminalNode*>(node)) {
      const auto* token = terminal->getSymbol();
      label             = token->getText();
      if (token->getType() == antlr4::Token::EOF) {
        label = "EOF";
      }
      const auto [txt,whitespace] {escape(label)};
      out << "  n" << my_id << " [label=\"" << txt << "\", shape=ellipse, ";
      if (!whitespace) out << "color=red, fontcolor=maroon];\n";
      else out << "color=black, fontcolor=black];\n";
    } else {
      label = "Unknown";
      out << "  n" << my_id << " [label=\"" << escape(label).first << "\"];\n";
    }

    if (parent_id != -1) {
      out << "  n" << parent_id << " -> n" << my_id << ";\n";
    }

    for (const auto& i : node->children) {
      walk(i, parser, out, id_counter, my_id);
    }
  }

  std::string to_dot(antlr4::tree::ParseTree* tree, antlr4::Parser* parser) {
    std::ostringstream out;
    out << "digraph ParseTree {\n";
    out << "  rankdir=TB;\n";
    out << "  node [fontname=\"Iosevka Term SS09\"];\n";
    int id_counter = 0;
    walk(tree, parser, out, id_counter, -1);
    out << "}\n";
    return out.str();
  }
}
