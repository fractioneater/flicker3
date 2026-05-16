/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "analyzer.h"

#include <iostream>

void Analyzer::run() {
  // Just for now, don't worry.
  std::cout << typeid(program_.front()).name() << '\n';
}
