/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "module.h"

#include <array>
#include <filesystem>
#include <fstream>
#include <iostream>

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

const ModuleExports& ModuleLoader::exports(const std::string& path) {
  const auto module {load_by_path(path).first};
  if (module == loaded_.end()) throw std::runtime_error("Module not found");
  return module->second.exports;
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

static constexpr std::array STAGE_NAMES {"Lexer", "Parser", "Analyzer", "Bytecode Generator", "Virtual Machine"};

template <typename T>
bool print_errors(const T& component, const Lexer& lexer, std::string_view module_name, CompileStage stage) {
  for (const auto& err : component.get_diagnostics())
    err.print(&lexer, module_name);

  if (component.encountered_halt()) {
    const auto error_stage {static_cast<int>(stage)};
    std::cout << "Compiling halted at " << STAGE_NAMES[error_stage] << '\n';

    #if PRINT_COLORS
    std::cout << "\033[4m"; // 4m: underline.
    for (int i {0}; i < STAGE_NAMES.size(); ++i) {
      if (i > 0) std::cout << (i <= error_stage ? RESULT_COLOR : DARK_GRAY_COLOR) << " -> ";

      std::cout << (i < error_stage ? RESULT_COLOR : (i == error_stage ? ERROR_COLOR : DARK_GRAY_COLOR));
      std::cout << STAGE_NAMES[i];
    }
    std::cout << CLEAR_FORMAT << '\n';
    #endif
    return true;
  }
  return false;
}

// Module base --------------------------------------------------

bool Module::compile(std::string_view module_name, std::string src, int debug_level) {
  status = MODULE_COMPILE_ERROR;

  // Initialize lexer and parser, which runs the lexer.
  lexer  = std::make_unique<Lexer>(std::move(src));
  parser = std::make_unique<Parser>(*lexer);

  // LEXER ERRORS, because lexing has already happened.
  if (print_errors(*lexer, *lexer, module_name, CompileStage::LEXER)) return false;

  #if DEBUG_PRINT_TOKENS
  if (DEBUG_PRINT_TOKENS >= debug_level)
    debug_print_tokens(parser->get_tokens(), *lexer);
  #endif

  // PARSING
  const auto program {parser->parse()};

  if (print_errors(*parser, *lexer, module_name, CompileStage::PARSER)) return false;

  #if DEBUG_PRINT_DOT == 1
  if (DEBUG_PRINT_DOT >= debug_level) {
    parser->output_dot();
    if (debug_level == 2) {
      std::cout << "Waiting for you to read the parse tree DOT file... ";
      std::string _ {};
      std::getline(std::cin >> std::ws, _);
    }
  }
  #endif

  // ANALYSIS
  program->accept(analyzer);

  if (print_errors(analyzer, *lexer, module_name, CompileStage::ANALYZER)) return false;

  status = MODULE_COMPILED;
  return true;
}

// Standard modules --------------------------------------------------

/**
 * Load a module by a filepath.
 * @param path File path to load.
 * @return Same as try_emplace—a pair, the first of which is an iterator to the possibly loaded module, and the second of which is a bool of whether the
 *         module was loaded.
 */
std::pair<std::unordered_map<std::string, StandardModule>::iterator, bool> ModuleLoader::load_by_path(const std::string& path) {
  // Module name
  const std::filesystem::path p {path};
  const std::string name {p.stem().string()};

  if (core_ == nullptr) load_core();
  // If the module is already loaded, try_emplace shouldn't overwrite it.
  // The first param is the map key, the next few are for StandardModule constructor.
  const auto result {loaded_.try_emplace(name, *this, core_->analyzer, name, read_entire_file(path))};

  return result;
}

StandardModule::StandardModule(AnalyzerHost& host, Analyzer& parent, const std::string& name, std::string src) : Module {host, parent} {
  compile(name, std::move(src));
  const auto& [o, t, o_i, t_i] {analyzer.global_scope()};
  for (const auto& [object_name, symbol] : o)
    exports.objects.try_emplace(object_name, symbol);
  for (const auto& [type_name, id] : t)
    exports.types.try_emplace(type_name, id);
}

bool StandardModule::run() {
  if (status != MODULE_COMPILED) return false;
  return true;
}

// Core module --------------------------------------------------

void ModuleLoader::load_core() {
  if (core_ != nullptr) return;
  core_ = std::make_unique<CoreModule>(*this);
  // TODO: initialize natives.
}

CoreModule::CoreModule(AnalyzerHost& host) : Module {host} {
  compile(CORE_NAME, std::string {Core::SRC}, 2);
  if (status != MODULE_COMPILED) {
    std::cerr << "This is a core library compilation error---it's not your fault. Submit an issue on Codeberg or communicate this to me however possible.\n";
    // Exit code 70: internal software error (core library error, my fault).
    throw std::system_error(70, std::generic_category());
  }

  // Initialized all at once to ensure everything is present.
  types = {
    analyzer.find_type("Any"),
    analyzer.find_type("Bool"),
    analyzer.find_type("Char"),
    analyzer.find_type("List"),
    analyzer.find_type("Map"),
    analyzer.find_type("Nothing"),
    analyzer.find_type("Number"),
    analyzer.find_type("String"),
    analyzer.find_type("Unit")
  };
}

bool CoreModule::run() {
  if (status != MODULE_COMPILED) return false;
  return true;
}

// REPL module --------------------------------------------------

void ModuleLoader::run_repl() {
  if (core_ == nullptr) load_core();
  if (repl_ == nullptr) {
    repl_ = std::make_unique<ReplModule>(*this, core_->analyzer);
  }

  constexpr std::string_view prompt {"~ > "};
  std::string line {};

  #if PRINT_COLORS
  #  define PROMPT PROMPT_COLOR << prompt << CLEAR_FORMAT
  #else
  #  define PROMPT prompt
  #endif

  // Not the cleanest syntax, but this comma expression works to print the "~ >" prompt and then get input.
  while (std::cout << PROMPT, std::getline(std::cin >> std::ws, line)) {
    send_repl_line(line);
  }

  // Clear the prompt characters from the last line with a quick ANSI escape.
  std::cout << "\033[2K\033[1G";
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

  const bool success {compile(REPL_NAME, line)};
  if (!success) return false;

  return run();
}

bool ReplModule::run() {
  return true;
}
