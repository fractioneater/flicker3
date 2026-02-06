#pragma once

#include <string>
#include "antlr4-runtime.h"

namespace flicker {
  /**
   * Exports an ANTLR4 parse tree to GraphViz DOT format.
   * @param tree The parse tree to export.
   * @param parser The parser that generated the tree (used for rule names).
   * @return A string containing the DOT representation of the tree.
   */
  std::string to_dot(antlr4::tree::ParseTree* tree, antlr4::Parser* parser);
}
