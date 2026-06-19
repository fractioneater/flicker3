/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

export module param;

import lexer;
import type;

export struct Param {
  enum Modifier {
    NONE, VAL, VAR
  };

  Token* identifier {};
  SyntacticTypePtr type {};
  Modifier mod {NONE};
};
