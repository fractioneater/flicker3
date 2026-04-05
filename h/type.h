/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

class Type {
  struct TypeElement {
    Token* name {};
    bool optional {};
  };

  TypeElement base_ {};
  std::vector<TypeElement> type_params_ {};

public:
  explicit Type(Token* name, bool optional) : base_ {name, optional} {}
  // A type that is left to be inferred.
  Type() : base_ {nullptr, true} {}

  [[nodiscard]] Token* name() const { return base_.name; }
  [[nodiscard]] bool is_optional() const { return base_.optional; }
  [[nodiscard]] const std::vector<TypeElement>& type_params() const { return type_params_; }

  void add_type_param(Token* token, bool optional) {
    type_params_.emplace_back(token, optional);
  }
};
