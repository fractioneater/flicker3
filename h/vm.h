/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <fstream>

enum InterpretResult {
  INTERPRET_OK, INTERPRET_COMPILE_ERROR, INTERPRET_RUNTIME_ERROR
};

InterpretResult interpret(const std::string& source, std::string_view module);
InterpretResult interpret_and_print(const std::string& source, std::string_view module);
