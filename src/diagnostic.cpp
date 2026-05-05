/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "diagnostic.h"

#include <iomanip>
#include <iostream>

#include "common.h"
#include "lexer.h"

Diagnostic::Diagnostic(std::string message, const Token* token, Severity severity)
  : Diagnostic {token->start_offset, std::move(message), severity, nullptr} {}

Diagnostic::Diagnostic(std::string message, const Diagnostic& context, const Token* token, Severity severity)
  : Diagnostic {token->start_offset, std::move(message), severity, &context} {}

Diagnostic::Diagnostic(std::string message, size_t offset, Severity severity)
  : Diagnostic {offset, std::move(message), severity, nullptr} {}

Diagnostic::Diagnostic(std::string message, const Diagnostic& context, size_t offset, Severity severity)
  : Diagnostic {offset, std::move(message), severity, &context} {}

Diagnostic::Diagnostic(std::string message, Severity severity)
  : Diagnostic {std::nullopt, std::move(message), severity, nullptr} {}

Diagnostic::Diagnostic(std::string message, const Diagnostic& context, Severity severity)
  : Diagnostic {std::nullopt, std::move(message), severity, &context} {}

void Diagnostic::formatting() const {
  switch (this->severity_) {
    case ERROR:
      #if PRINT_COLORS
      std::cout << ERROR_COLOR << BOLD;
      #endif
      if (!has_position_)
        std::cout << "Error: ";
      break;
    case WARNING:
      #if PRINT_COLORS
      std::cout << WARNING_COLOR << BOLD;
      #endif
      if (!has_position_)
        std::cout << "Warning: ";
      break;
    case NOTE:
      #if PRINT_COLORS
      std::cout << NOTE_COLOR << BOLD;
      #endif
      if (!has_position_)
        std::cout << "Note: ";
      break;
    default: ;
  }
}

void Diagnostic::print(const Lexer* lexer, std::string_view module) const {
  // moduleName@39:14 Block comment is missing closing '-#'
  //    39 │ print 0xABCD #- unclosed!
  //                      ^
  formatting();

  const auto [line, col] = lexer->offset_to_line_col(offset_);
  const auto line_str    = lexer->offset_to_line_string(offset_);
  if (has_position_) {
    std::cout << module << "@" << line << ":" << col << CLEAR_FORMAT << ' ' << message_ << '\n';
    std::cout << std::setw(5) << line << " │ " << line_str << '\n';
    #if PRINT_COLORS
    std::cout << "        " << std::string(col - 1, ' ') << POINTER_COLOR << BOLD << '^' << CLEAR_FORMAT << '\n';
    #else
    std::cout << "        " << std::string(col - 1, ' ') << "^\n";
    #endif
  } else {
    // No line or column.
    std::cout << CLEAR_FORMAT << message_ << '\n';
  }

  if (context_) {
    std::cout << ".. ";
    context_->print(lexer, module);
  }
}
