/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

module;
#include "common.h"
#include "linenoise-wrapper.h"

export module module_;

import analyzer;
import analyzer_host;
import core;
import lexer;
import parser;
import type;

import std;

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

static constexpr std::array STAGE_NAMES {"Lexer", "Parser", "Analyzer", "Bytecode Generator", "Virtual Machine"};

template <typename T>
bool print_errors(const T& component, const Lexer& lexer, std::string_view module_name, CompileStage stage) {
  std::function<std::pair<std::size_t, std::size_t>(std::size_t)> line_col {[&lexer](std::size_t it) { return lexer.offset_to_line_col(it); }};
  std::function<std::string_view(std::size_t)> string {[&lexer](std::size_t it) { return lexer.offset_to_line_string(it); }};
  for (const auto& err : component.get_diagnostics())
    err.print(line_col, string, module_name);

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

export enum ModuleStatus { MODULE_CREATED, MODULE_COMPILED, MODULE_COMPILE_ERROR, MODULE_RUNTIME_ERROR };

struct Module {
  ModuleStatus status {MODULE_CREATED};

  std::unique_ptr<Lexer> lexer {};
  std::unique_ptr<Parser> parser {};
  Analyzer analyzer; // Why isn't it a unique_ptr? Because there can only be one, and it's safe to initialize immediately.

  virtual bool run() = 0;

  explicit Module(AnalyzerHost& host) : analyzer {host} {}
  explicit Module(AnalyzerHost& host, Analyzer& parent) : analyzer {host, parent} {}

  virtual ~Module() = default;

  protected:
  bool compile(std::string_view module_name, std::string src, int debug_level = 1) {
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
};

struct StandardModule : Module {
  std::string name {};
  std::string src {}; // Do not attempt to use. The value is moved out as soon as it is placed in here.

  SymbolTable exports {};

  bool run() override {
    if (status != MODULE_COMPILED) return false;
    return true;
  }

  StandardModule(AnalyzerHost& host, Analyzer& parent, const std::string& name_tmp, std::string src) : Module {host, parent}, name {name_tmp},
    src {std::move(src)} {}

  void compile() {
    Module::compile(name, std::move(src));
    if (status != MODULE_COMPILED) return;
    const auto& [o, t, n] {analyzer.global_scope().locals};
    for (const auto& [object_name, symbol] : o)
      exports.objects.try_emplace(object_name, symbol);
    for (const auto& [type_name, id] : t)
      exports.types.try_emplace(type_name, id);
    for (const auto& [namespace_name, ns] : n)
      exports.namespaces.try_emplace(namespace_name, ns);
  }
};

/**
 * CoreModule, which is almost exactly the same as StandardModule, but its name is always "core," and it has small behavioral differences:
 * - There's only one of it.
 * - Debug outputs (PRINT_TOKENS, OUTPUT_DOT, PRINT_CODE, TRACE_EXECUTION) will only happen when the flag in common.h is set to 2.
 * - OUTPUT_DOT waits until the user presses Enter in case they want to read the DOT tree before it's overwritten by another module's output.
 * - It remembers its types for other modules to use.
 */
struct CoreModule : Module {
  static constexpr std::string_view CORE_NAME {"core"};

  CoreTypes types {};

  bool run() override {
    if (status != MODULE_COMPILED) return false;
    return true;
  }

  void compile() {
    Module::compile(CORE_NAME, std::string {Core::SRC}, 2);
    if (status != MODULE_COMPILED) {
      std::cerr << "This is a core library compilation error---it's not your fault. Submit an issue on Codeberg or communicate this to me however possible." <<
        std::endl;
      // Exit code 70: internal software error (core library error, my fault).
      throw std::system_error(70, std::generic_category());
    }
  }

  explicit CoreModule(AnalyzerHost& host) : Module {host} {}
};

/**
 * The idea of this is weird, but a ReplModule could potentially be loaded into a StandardModule to make an integrated debugger. Maybe.
 */
struct ReplModule : Module {
  static constexpr std::string_view REPL_NAME {"input"};

  bool run_line(const std::string& line) {
    analyzer.clear_diagnostics();

    const bool success {compile(REPL_NAME, line)};
    if (!success) return false;

    return run();
  }

  explicit ReplModule(AnalyzerHost& host, Analyzer& parent) : Module {host, parent} {}

  private:
  bool run() override { return true; }
};

export class ModuleLoader : public AnalyzerHost {
  std::unique_ptr<CoreModule> core_ {nullptr};
  std::unique_ptr<ReplModule> repl_ {nullptr};
  std::unordered_map<std::string, StandardModule> loaded_ {};

  TypeArena types_ {};

  TypeId define_core_class(const std::string& name, int arity, std::vector<TypeId>&& supertypes) {
    // Add to type arena.
    const TypeId id {types_.new_named(std::string {name}, arity)};
    types_.define_supertypes(id, std::move(supertypes));
    // Add to symbol table.
    core_->analyzer.define_core_class(name, id);
    return id;
  }

  void load_core() {
    if (core_ != nullptr) return;
    core_ = std::make_unique<CoreModule>(*this);

    // Initialize types
    const TypeId any_t {define_core_class("Any", 0, {})};

    core_->compile();

    const TypeId bool_t {*core_->analyzer.find_type("Bool")};
    const TypeId char_t {*core_->analyzer.find_type("Char")};
    const TypeId list_t {*core_->analyzer.find_type("List")};
    const TypeId map_t {*core_->analyzer.find_type("Map")};
    const TypeId nothing_t {*core_->analyzer.find_type("Nothing")};
    const TypeId number_t {*core_->analyzer.find_type("Number")};
    const TypeId sequence_t {*core_->analyzer.find_type("Sequence")};
    const TypeId string_t {*core_->analyzer.find_type("String")};
    const TypeId unit_t {*core_->analyzer.find_type("Unit")};

    core_->types = CoreTypes {any_t, bool_t, char_t, list_t, map_t, nothing_t, number_t, sequence_t, string_t, unit_t};
  }

  public:
  // AnalyzerHost interface methods
  [[nodiscard]] const std::optional<ModuleExports> exports(const std::string& path) override {
    const auto iter {load_by_path(path).first};
    if (iter == loaded_.end() || iter->second.status != MODULE_COMPILED) return std::nullopt;
    return ModuleExports {iter->second.name, iter->second.exports};
  }

  [[nodiscard]] const CoreTypes& core_types() const override { return core_->types; }
  TypeArena& type_arena() override { return types_; }

  /**
   * Load a module by a filepath.
   * @param path File path to load.
   * @return Same as try_emplace—a pair, the first of which is an iterator to the possibly loaded module, and the second of which is a bool of whether the
   *         module was loaded.
   */
  std::pair<std::unordered_map<std::string, StandardModule>::iterator, bool> load_by_path(const std::string& path) {
    // Module name
    const std::filesystem::path p {path};
    const std::string name {p.stem().string()};

    if (core_ == nullptr) load_core();
    // If the module is already loaded, try_emplace shouldn't overwrite it.
    // The first param is the map key, the next few are for StandardModule constructor.
    const auto result {loaded_.try_emplace(name, *this, core_->analyzer, name, read_entire_file(path))};

    if (result.second) result.first->second.compile();

    return result;
  }

  /**
   * Get REPL input until ctrl+D.
   */
  void run_repl() {
    if (core_ == nullptr) load_core();
    if (repl_ == nullptr) {
      repl_ = std::make_unique<ReplModule>(*this, core_->analyzer);
    }

    [[maybe_unused]] constexpr auto prompt {"~ > "};
    [[maybe_unused]] constexpr auto color_prompt {PROMPT_COLOR "~ > " CLEAR_FORMAT};
    [[maybe_unused]] constexpr auto continuation_prompt {"  . "};
    [[maybe_unused]] constexpr auto color_continuation_prompt {PROMPT_COLOR "  . " CLEAR_FORMAT};

    #if PRINT_COLORS
    #  define PROMPT color_prompt
    #  define CONT_PROMPT color_continuation_prompt
    #else
    #  define PROMPT prompt
    #  define CONT_PROMPT continuation_prompt
    #endif

    enable_multiline();
    set_continuation_prompt(CONT_PROMPT);

    // The history file is placed in the same directory as the executable, so multiple Flicker builds can have different history files and nothing
    // gets polluted excessively by adding the file to the CWD. The get_executable_path() function is not pretty, though.
    const std::filesystem::path exec_path {get_executable_path()};
    const std::filesystem::path history_path {exec_path.parent_path() / ".flicker-history"};
    load_history(history_path.c_str());

    std::string line {};
    while (read_line(PROMPT, line)) {
      send_repl_line(line);
      add_history(line);
    }

    save_history(history_path.c_str());

    // Clear the prompt characters from the last line with a quick ANSI escape.
    // std::cout << "\033[2K\033[1G";
  }

  void send_repl_line(const std::string& line) const {
    if (repl_->run_line(line)) {
      #if PRINT_COLORS
      std::cout << RESULT_COLOR << "= > " << CLEAR_FORMAT << '\n';
      #else
      std::cout << "= > \n";
      #endif
    }
  }
};
