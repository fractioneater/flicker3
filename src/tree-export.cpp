#include "tree-export.h"
#include <sstream>
#include <vector>
#include <iomanip>

namespace flicker {
  static std::string escape(const std::string& s) {
    std::ostringstream oss;
    for (const auto c : s) {
      switch (c) {
        case '"': oss << "\\\"";
          break;
        case '\\': oss << "\\\\";
          break;
        case '\n': oss << "\\n";
          break;
        case '\r': oss << "\\r";
          break;
        case '\t': oss << "\\t";
          break;
        default: oss << c;
          break;
      }
    }
    return oss.str();
  }

  static void walk(antlr4::tree::ParseTree* node, antlr4::Parser* parser, std::ostringstream& out, int& id_counter, int parent_id) {
    const int my_id = id_counter++;
    std::string label;

    if (const auto* ctx = dynamic_cast<antlr4::ParserRuleContext*>(node)) {
      label = parser->getRuleNames()[ctx->getRuleIndex()];
      out << "  n" << my_id << " [label=\"" << escape(label) << "\", shape=box, color=blue, fontcolor=blue];\n";
    } else if (const auto* terminal = dynamic_cast<antlr4::tree::TerminalNode*>(node)) {
      const auto* token = terminal->getSymbol();
      label       = token->getText();
      if (token->getType() == antlr4::Token::EOF) {
        label = "EOF";
      }
      out << "  n" << my_id << " [label=\"" << escape(label) << "\", shape=ellipse, color=green, fontcolor=darkgreen];\n";
    } else {
      label = "Unknown";
      out << "  n" << my_id << " [label=\"" << escape(label) << "\"];\n";
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
    out << "  node [fontname=\"Courier New\"];\n";
    int id_counter = 0;
    walk(tree, parser, out, id_counter, -1);
    out << "}\n";
    return out.str();
  }
}
