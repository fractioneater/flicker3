/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

module;
#include "common.h"

export module diagnostic;

import std;

export class Diagnostic {
  public:
  enum Severity {
    ERROR, WARNING, NOTE
  };

  private:
  std::string message_ {};
  std::unique_ptr<Diagnostic> context_ {};
  bool has_position_ {true};
  std::size_t offset_ {};
  Severity severity_ {ERROR};

  void formatting() const {
    switch (severity_) {
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

  static std::unique_ptr<Diagnostic> clone_context(const Diagnostic* ctx) {
    return ctx ? std::make_unique<Diagnostic>(*ctx) : nullptr;
  }

  Diagnostic(std::optional<std::size_t> pos, std::string message, Severity severity, const Diagnostic* ctx) :
    message_ {std::move(message)},
    context_ {clone_context(ctx)},
    has_position_ {pos.has_value()},
    offset_ {pos.value_or(0)},
    severity_ {severity} {}

  public:
  // If you ever need to prove to someone that C++ has quirks, show them these two constructors (and optionally some with move semantics as well).
  Diagnostic(const Diagnostic& other) :
    message_ {other.message_},
    context_ {other.context_ ? std::make_unique<Diagnostic>(*other.context_) : nullptr},
    has_position_ {other.has_position_},
    offset_ {other.offset_},
    severity_ {other.severity_} {}

  Diagnostic& operator=(const Diagnostic& other) {
    if (this == &other) return *this;
    message_      = other.message_;
    context_      = other.context_ ? std::make_unique<Diagnostic>(*other.context_) : nullptr;
    has_position_ = other.has_position_;
    offset_       = other.offset_;
    severity_     = other.severity_;
    return *this;
  }

  // This should be plenty. It's sad tokens had to leave.
  Diagnostic(std::string message, std::size_t offset, Severity severity = ERROR, const Diagnostic* context = nullptr)
    : Diagnostic {offset, std::move(message), severity, context} {}

  explicit Diagnostic(std::string message, Severity severity = ERROR, const Diagnostic* context = nullptr)
    : Diagnostic {std::nullopt, std::move(message), severity, context} {}

  void add_context(Diagnostic&& c) { context_ = std::make_unique<Diagnostic>(std::move(c)); }
  void add_context(const Diagnostic* c) { context_ = std::make_unique<Diagnostic>(*c); }

  [[nodiscard]] bool is_halting() const {
    return severity_ == ERROR;
  }

  void print(
    std::function<std::pair<std::size_t, std::size_t>(std::size_t)>& offset_to_line_col, std::function<std::string_view(std::size_t)>& line_string, std::string_view module_name
  ) const {
    // moduleName@39:14 Block comment is missing closing '-#'
    //    39 │ print 0xABCD #- unclosed!
    //                      ^
    formatting();

    if (has_position_) {
      const auto [line_, col_] {offset_to_line_col(offset_)};
      std::cout << module_name << "@" << line_ << ":" << col_ << CLEAR_FORMAT << ' ' << message_ << '\n';
      std::cout << std::setw(5) << line_ << " │ " << line_string(offset_) << '\n';
      #if PRINT_COLORS
      std::cout << "        " << std::string(col_ - 1, ' ') << POINTER_COLOR << BOLD << '^' << CLEAR_FORMAT << '\n';
      #else
      std::cout << "        " << std::string(col - 1, ' ') << "^\n";
      #endif
    } else {
      // No line or column.
      std::cout << CLEAR_FORMAT << message_ << '\n';
    }

    if (context_) {
      std::cout << ".. ";
      context_->print(offset_to_line_col, line_string, module_name);
    }
  }
};
