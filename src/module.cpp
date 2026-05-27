/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "module.h"

#include <array>
#include <filesystem>
#include <fstream>

#include "lexer.h"
#include "parser.h"

// Random things --------------------------------------------------

std::string read_entire_file(const std::string& path) {
  std::ifstream in {path, std::ios::binary};

  if (!in) {
    std::cerr << "Could not open file '" << path << "'\n";
    throw std::system_error(74, std::iostream_category()); // Exit code 74: generic i/o failure.
  }

  in.seekg(0, std::ios::end);
  const std::streampos end_pos {in.tellg()};

  if (end_pos >= 0) {
    std::string contents {};
    const auto size {static_cast<std::streamsize>(end_pos)};
    if (size == static_cast<std::streamsize>(-1)) {
      std::cerr << "File '" << path << "' is too large\n";
      throw std::system_error(74, std::iostream_category());
    }
    contents.resize(size);

    in.seekg(0, std::ios::beg);
    in.read(contents.data(), size);
    if (!in) {
      std::cerr << "Could not read file '" << path << "'\n";
      throw std::system_error(74, std::iostream_category());
    }

    in.close();
    return contents;
  }

  // Fallback in case seek and tell aren't supported.
  in.clear();
  in.seekg(0, std::ios::beg);
  return std::string {std::istreambuf_iterator(in), std::istreambuf_iterator<char>()};
}

void debug_print_tokens(const std::vector<Token>& tokens, const Lexer& lexer) {
  for (const auto& token : tokens) {
    if (token.type == TOKEN_EOF) {
      std::cout << "EOF: col " << lexer.offset_to_line_col(token.start_offset).second << "\n";
      continue;
    }

    const auto [line, col] {lexer.offset_to_line_col(token.start_offset)};
    if (token.type == TOKEN_INDENT) {
      std::cout << "Indent\n";
    } else if (token.type == TOKEN_DEDENT) {
      std::cout << "Dedent\n";
    } else if (token.type == TOKEN_LINE) {
      std::cout << "Newline\n";
    } else { // Other:
      std::cout << "Token '" << token.src_string << "': type " << token.type << ", " << line << ":" << col << ", length " << token.length << "\n";
    }
  }
}

// Error printing --------------------------------------------------

enum class CompileStage { LEXER = 0, PARSER, ANALYZER, BYTECODE_GEN, VM };

static constexpr std::array stage_names {"Lexer", "Parser", "Analyzer", "Bytecode Generator", "Virtual Machine"};

template <typename T>
bool print_errors(const T& component, const Lexer& lexer, std::string_view module_name, CompileStage stage) {
  for (const auto& err : component.get_diagnostics())
    err.print(&lexer, module_name);

  if (component.encountered_halt()) {
    const auto error_stage {static_cast<int>(stage)};
    std::cout << "Compiling halted at " << stage_names[error_stage] << '\n';

    #if PRINT_COLORS
    std::cout << "\033[4m"; // 4m: underline.
    for (int i {0}; i < stage_names.size(); ++i) {
      if (i > 0) std::cout << (i <= error_stage ? RESULT_COLOR : DARK_GRAY_COLOR) << " -> ";

      std::cout << (i < error_stage ? RESULT_COLOR : (i == error_stage ? ERROR_COLOR : DARK_GRAY_COLOR));
      std::cout << stage_names[i];
    }
    std::cout << CLEAR_FORMAT << '\n';
    #endif
    return true;
  }
  return false;
}

// Standard modules --------------------------------------------------

void ModuleLoader::load_by_path(const std::string& name, const std::string& path) {
  if (core_ == nullptr) load_core();
  StandardModule main {name, read_entire_file(path)};
}

StandardModule::StandardModule(const std::string& name, std::string src) : name {name}, lexer {std::move(src)}, parser {lexer} {
  if (print_errors(lexer, lexer, name, CompileStage::LEXER)) return;

  #if DEBUG_PRINT_TOKENS
  debug_print_tokens(parser.get_tokens(), lexer);
  #endif

  const auto program {parser.parse()};

  if (print_errors(parser, lexer, name, CompileStage::PARSER)) return;

  #if DEBUG_PRINT_DOT
  parser.output_dot();
  #endif

  program->accept(analyzer);

  if (print_errors(analyzer, lexer, name, CompileStage::ANALYZER)) return;
}

// Core module --------------------------------------------------

void ModuleLoader::load_core() {
  if (core_ != nullptr) return;
  core_ = std::make_unique<CoreModule>();
  // TODO: initialize natives.
}

CoreModule::CoreModule() : lexer {std::string {Core::src}}, parser {lexer} {
  if (print_errors(lexer, lexer, core_name, CompileStage::LEXER)) return;

  #if DEBUG_PRINT_TOKENS == 2
  debug_print_tokens(parser.get_tokens(), lexer);
  #endif

  const auto program {parser.parse()};

  if (print_errors(parser, lexer, core_name, CompileStage::PARSER)) return;

  #if DEBUG_PRINT_DOT == 2
  parser.output_dot();
  std::cout << "Waiting for you to read the core library DOT tree... ";
  std::string _ {};
  std::getline(std::cin >> std::ws, _);
  #endif

  program->accept(analyzer);

  if (print_errors(analyzer, lexer, core_name, CompileStage::ANALYZER)) return;
}

// REPL module --------------------------------------------------

void ModuleLoader::load_repl() {
  if (core_ == nullptr) load_core();
  repl_ = std::make_unique<ReplModule>();
}

void ModuleLoader::send_repl_line(const std::string& line) const {
  if (repl_->run_line(line)) {
    #if PRINT_COLORS
    std::cout << RESULT_COLOR << "= > " << CLEAR_FORMAT << '\n';
    #else
    std::cout << "= > \n";
    #endif
  }
}

bool ReplModule::run_line(const std::string& line) {
  analyzer.clear_diagnostics();

  // Unlike other modules, the REPL creates a temporary lexer and parser for every line. Its analyzer stays, though.
  Lexer lexer {line};
  Parser parser {lexer};

  if (print_errors(lexer, lexer, repl_name, CompileStage::LEXER)) return false;

  #if DEBUG_PRINT_TOKENS
  debug_print_tokens(parser.get_tokens(), lexer);
  #endif

  const auto program {parser.parse()};

  if (print_errors(parser, lexer, repl_name, CompileStage::PARSER)) return false;

  #if DEBUG_PRINT_DOT
  parser.output_dot();
  #endif

  program->accept(analyzer);

  if (print_errors(analyzer, lexer, repl_name, CompileStage::ANALYZER)) return false;

  return true;
}
