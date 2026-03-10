#include "lexer.h"

#include <fstream>
#include <sstream>
#include <string>
#include <benchmark/benchmark.h>

static std::string read_file(const char* path) {
  std::ifstream f(path);
  std::ostringstream ss;
  ss << f.rdbuf();
  return ss.str();
}

// Benchmark that scans the whole source string.
static void bm_lex_all(benchmark::State& state) {
  // Pick whatever test file exercises the lexer the most.
  const std::string src {read_file("test/lexer/numbers.fl")};

  for (auto _ : state) {
    Lexer lexer {src};
    Token token;
    do {
      token = lexer.next_token();
    } while (token.type != TOKEN_EOF);
    benchmark::DoNotOptimize(token);
  }
}

BENCHMARK(bm_lex_all);
