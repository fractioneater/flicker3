/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <utility>

struct Token;
class Lexer;

class Diagnostic {
  public:
  enum Severity {
    ERROR, WARNING, NOTE
  };

  private:
  std::string message_ {};
  std::unique_ptr<Diagnostic> context_ {};
  bool has_position_ {true};
  size_t offset_ {};
  Severity severity_ {ERROR};

  void formatting() const;

  static std::unique_ptr<Diagnostic> clone_context(const Diagnostic* ctx) {
    return ctx ? std::make_unique<Diagnostic>(*ctx) : nullptr;
  }

  Diagnostic(std::optional<size_t> pos, std::string message, Severity severity, const Diagnostic* ctx) :
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

  // This should be plenty.
  Diagnostic(std::string message, const Token* token, Severity severity);
  Diagnostic(std::string message, const Diagnostic& context, const Token* token, Severity severity);
  Diagnostic(std::string message, size_t offset, Severity severity);
  Diagnostic(std::string message, const Diagnostic& context, size_t offset, Severity severity);
  Diagnostic(std::string message, Severity severity);
  Diagnostic(std::string message, const Diagnostic& context, Severity severity);

  void add_context(Diagnostic&& c) {
    this->context_ = std::make_unique<Diagnostic>(std::move(c));
  }

  [[nodiscard]] bool is_halting() const {
    return this->severity_ == ERROR;
  }

  void print(const Lexer* lexer, std::string_view module) const;
};
