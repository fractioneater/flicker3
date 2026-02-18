
// Generated from /home/fractioneater/stuff/git/flicker-3/src/antlr/flicker.g4 by ANTLR 4.13.2


#include "flickerListener.h"
#include "flickerVisitor.h"

#include "flicker.h"


using namespace antlrcpp;
using namespace antlr;

using namespace antlr4;

namespace {

struct FlickerStaticData final {
  FlickerStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  FlickerStaticData(const FlickerStaticData&) = delete;
  FlickerStaticData(FlickerStaticData&&) = delete;
  FlickerStaticData& operator=(const FlickerStaticData&) = delete;
  FlickerStaticData& operator=(FlickerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag flickerParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<FlickerStaticData> flickerParserStaticData = nullptr;

void flickerParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (flickerParserStaticData != nullptr) {
    return;
  }
#else
  assert(flickerParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<FlickerStaticData>(
    std::vector<std::string>{
      "program", "newline", "codeItem", "type", "statement", "variableDecl", 
      "typeParam", "functionDecl", "funcReturnType", "functionContents", 
      "paramList", "param", "block", "blockBody", "accessSpecifier", "classDecl", 
      "classBody", "companionNamespace", "classItem", "initializer", "initParamList", 
      "initParam", "superInitParams", "method", "usingStatement", "importList", 
      "importItem", "loopLabel", "doStatement", "blockOrStatement", "ifStmt", 
      "whileStmt", "eachStmt", "forStmt", "breakStmt", "continueStmt", "whenStmt", 
      "returnStmt", "printStmt", "consoleErrorStmt", "passStmt", "whenBody", 
      "whenContents", "whenCase", "elseCase", "expression", "comparisonOperator", 
      "assignOperator", "interpolationExpr", "constantExpr", "listOrMapLiteral", 
      "listLiteral", "listItems", "mapLiteral", "mapItems", "mapItem", "lambdaLiteral", 
      "lambdaParams", "parenthesizedOptionalParamList", "blockLambda", "braceLambda", 
      "statementLambdaBody", "exprLambdaBody"
    },
    std::vector<std::string>{
    },
    std::vector<std::string>{
      "", "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET", 
      "LEFT_BRACE", "RIGHT_BRACE", "SEMICOLON", "COMMA", "TILDE", "STAR", 
      "STAR_STAR", "STAR_EQ", "STAR_STAR_EQ", "MINUS", "MINUS_MINUS", "RIGHT_ARROW", 
      "MINUS_EQ", "PLUS", "PLUS_PLUS", "PLUS_EQ", "DOT", "DOT_DOT", "DOT_DOT_LT", 
      "QUEST", "QUEST_COLON", "QUEST_DOT", "GT", "GT_GT", "GT_EQ", "LT", 
      "LT_LT", "LT_EQ", "COLON", "COLON_COLON", "SLASH", "SLASH_EQ", "PERCENT", 
      "PERCENT_EQ", "PIPE", "PIPE_EQ", "CARET", "CARET_EQ", "AMPERSAND", 
      "AMPERSAND_EQ", "BANG", "BANG_EQ", "EQ", "EQ_EQ", "IDENTIFIER", "STRING", 
      "INTERPOLATION", "CHAR", "NUMBER", "AND", "BREAK", "CLASS", "CONTINUE", 
      "CN", "DO", "EACH", "ELIF", "ELSE", "FALSE", "FOR", "FUN", "IF", "IN", 
      "IS", "NIL", "NOT", "OF", "OR", "OVERRIDE", "PASS", "PRINT", "PRINT_ERROR", 
      "PRIVATE", "RETURN", "STATIC", "SUPER", "THIS", "TRUE", "USING", "VAL", 
      "VAR", "WHEN", "WHILE", "INDENT", "DEDENT", "LINE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,90,718,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,1,0,3,
  	0,128,8,0,1,0,1,0,1,0,5,0,133,8,0,10,0,12,0,136,9,0,1,0,3,0,139,8,0,1,
  	0,1,0,1,1,4,1,144,8,1,11,1,12,1,145,1,2,1,2,3,2,150,8,2,1,3,1,3,3,3,154,
  	8,3,1,3,1,3,1,3,3,3,159,8,3,3,3,161,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,178,8,4,1,5,1,5,1,5,1,5,3,5,184,8,5,
  	1,5,1,5,3,5,188,8,5,1,6,1,6,1,6,1,7,1,7,1,7,3,7,196,8,7,1,7,1,7,3,7,200,
  	8,7,1,7,1,7,3,7,204,8,7,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,9,3,9,214,8,9,1,
  	10,1,10,1,10,5,10,219,8,10,10,10,12,10,222,9,10,1,11,1,11,1,11,1,11,1,
  	12,3,12,229,8,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,5,13,239,8,13,
  	10,13,12,13,242,9,13,1,13,3,13,245,8,13,1,14,1,14,1,15,1,15,1,15,3,15,
  	252,8,15,1,15,1,15,3,15,256,8,15,1,15,1,15,1,15,1,15,1,15,1,16,1,16,1,
  	16,3,16,266,8,16,1,16,1,16,1,16,5,16,271,8,16,10,16,12,16,274,9,16,1,
  	16,3,16,277,8,16,1,17,1,17,1,17,1,17,1,17,1,17,5,17,285,8,17,10,17,12,
  	17,288,9,17,1,17,3,17,291,8,17,1,17,1,17,1,18,1,18,5,18,297,8,18,10,18,
  	12,18,300,9,18,1,18,1,18,3,18,304,8,18,3,18,306,8,18,1,19,1,19,1,19,3,
  	19,311,8,19,1,19,1,19,3,19,315,8,19,1,19,1,19,1,20,1,20,1,20,5,20,322,
  	8,20,10,20,12,20,325,9,20,1,21,3,21,328,8,21,1,21,1,21,1,21,1,21,1,22,
  	1,22,1,22,1,22,5,22,338,8,22,10,22,12,22,341,9,22,3,22,343,8,22,1,22,
  	1,22,1,23,1,23,1,24,1,24,1,24,1,24,1,24,1,24,3,24,355,8,24,3,24,357,8,
  	24,1,24,1,24,1,24,1,24,3,24,363,8,24,1,25,1,25,1,25,5,25,368,8,25,10,
  	25,12,25,371,9,25,1,26,1,26,1,26,1,26,3,26,377,8,26,1,27,1,27,1,27,1,
  	28,1,28,1,28,1,29,1,29,3,29,387,8,29,1,30,1,30,1,30,1,30,1,30,1,30,1,
  	30,1,30,5,30,397,8,30,10,30,12,30,400,9,30,1,30,1,30,1,30,1,30,3,30,406,
  	8,30,1,31,1,31,3,31,410,8,31,1,31,1,31,1,31,1,31,1,31,1,31,3,31,418,8,
  	31,1,32,1,32,3,32,422,8,32,1,32,1,32,1,32,1,32,3,32,428,8,32,1,32,1,32,
  	1,32,1,32,1,33,1,33,3,33,436,8,33,1,33,1,33,3,33,440,8,33,1,33,1,33,3,
  	33,444,8,33,1,33,1,33,3,33,448,8,33,1,33,1,33,1,34,1,34,3,34,454,8,34,
  	1,35,1,35,3,35,458,8,35,1,36,1,36,1,36,1,36,1,37,1,37,3,37,466,8,37,1,
  	38,1,38,1,38,1,39,1,39,1,39,1,40,1,40,1,41,1,41,1,41,1,41,1,41,1,42,1,
  	42,1,42,4,42,484,8,42,11,42,12,42,485,1,42,1,42,3,42,490,8,42,1,42,3,
  	42,493,8,42,1,43,1,43,1,43,1,44,1,44,1,44,1,45,1,45,1,45,1,45,1,45,1,
  	45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,3,45,518,8,
  	45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,
  	45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,
  	45,1,45,1,45,1,45,3,45,551,8,45,1,45,1,45,1,45,1,45,1,45,3,45,558,8,45,
  	1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,
  	1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,5,45,583,8,45,10,45,12,45,
  	586,9,45,3,45,588,8,45,1,45,1,45,1,45,1,45,1,45,1,45,5,45,596,8,45,10,
  	45,12,45,599,9,45,1,45,1,45,1,45,1,45,1,45,1,45,5,45,607,8,45,10,45,12,
  	45,610,9,45,1,46,1,46,1,47,1,47,1,48,1,48,3,48,618,8,48,4,48,620,8,48,
  	11,48,12,48,621,1,48,1,48,1,49,1,49,1,50,1,50,3,50,630,8,50,1,51,1,51,
  	3,51,634,8,51,1,51,1,51,1,52,1,52,1,52,5,52,641,8,52,10,52,12,52,644,
  	9,52,1,52,3,52,647,8,52,1,53,1,53,1,53,3,53,652,8,53,1,53,1,53,1,54,1,
  	54,1,54,5,54,659,8,54,10,54,12,54,662,9,54,1,54,3,54,665,8,54,1,55,1,
  	55,1,55,1,55,1,56,1,56,1,56,3,56,674,8,56,1,57,1,57,3,57,678,8,57,1,58,
  	1,58,3,58,682,8,58,1,58,1,58,1,59,1,59,1,59,1,59,3,59,690,8,59,1,60,1,
  	60,1,60,3,60,695,8,60,1,60,1,60,1,61,1,61,1,61,3,61,702,8,61,1,61,1,61,
  	1,61,5,61,707,8,61,10,61,12,61,710,9,61,1,62,3,62,713,8,62,1,62,1,62,
  	1,62,1,62,0,1,90,63,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,
  	36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,
  	82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,
  	122,124,0,15,2,0,64,64,71,71,1,0,84,85,2,0,16,16,33,33,2,0,73,73,77,77,
  	4,0,9,9,14,15,19,19,45,45,1,0,22,23,2,0,10,10,35,35,2,0,14,14,18,18,2,
  	0,28,28,31,31,3,0,39,39,41,41,43,43,2,0,21,21,26,26,2,0,15,15,19,19,5,
  	0,27,27,29,30,32,32,46,46,48,48,9,0,12,13,17,17,20,20,36,36,38,38,40,
  	40,42,42,44,44,47,47,5,0,50,50,52,53,63,63,69,69,82,82,776,0,127,1,0,
  	0,0,2,143,1,0,0,0,4,149,1,0,0,0,6,151,1,0,0,0,8,177,1,0,0,0,10,179,1,
  	0,0,0,12,189,1,0,0,0,14,192,1,0,0,0,16,207,1,0,0,0,18,213,1,0,0,0,20,
  	215,1,0,0,0,22,223,1,0,0,0,24,228,1,0,0,0,26,240,1,0,0,0,28,246,1,0,0,
  	0,30,248,1,0,0,0,32,265,1,0,0,0,34,278,1,0,0,0,36,305,1,0,0,0,38,307,
  	1,0,0,0,40,318,1,0,0,0,42,327,1,0,0,0,44,333,1,0,0,0,46,346,1,0,0,0,48,
  	362,1,0,0,0,50,364,1,0,0,0,52,376,1,0,0,0,54,378,1,0,0,0,56,381,1,0,0,
  	0,58,386,1,0,0,0,60,388,1,0,0,0,62,407,1,0,0,0,64,419,1,0,0,0,66,433,
  	1,0,0,0,68,451,1,0,0,0,70,455,1,0,0,0,72,459,1,0,0,0,74,463,1,0,0,0,76,
  	467,1,0,0,0,78,470,1,0,0,0,80,473,1,0,0,0,82,475,1,0,0,0,84,483,1,0,0,
  	0,86,494,1,0,0,0,88,497,1,0,0,0,90,517,1,0,0,0,92,611,1,0,0,0,94,613,
  	1,0,0,0,96,619,1,0,0,0,98,625,1,0,0,0,100,629,1,0,0,0,102,631,1,0,0,0,
  	104,637,1,0,0,0,106,648,1,0,0,0,108,655,1,0,0,0,110,666,1,0,0,0,112,670,
  	1,0,0,0,114,677,1,0,0,0,116,679,1,0,0,0,118,685,1,0,0,0,120,691,1,0,0,
  	0,122,701,1,0,0,0,124,712,1,0,0,0,126,128,3,2,1,0,127,126,1,0,0,0,127,
  	128,1,0,0,0,128,134,1,0,0,0,129,130,3,4,2,0,130,131,3,2,1,0,131,133,1,
  	0,0,0,132,129,1,0,0,0,133,136,1,0,0,0,134,132,1,0,0,0,134,135,1,0,0,0,
  	135,138,1,0,0,0,136,134,1,0,0,0,137,139,3,4,2,0,138,137,1,0,0,0,138,139,
  	1,0,0,0,139,140,1,0,0,0,140,141,5,0,0,1,141,1,1,0,0,0,142,144,5,90,0,
  	0,143,142,1,0,0,0,144,145,1,0,0,0,145,143,1,0,0,0,145,146,1,0,0,0,146,
  	3,1,0,0,0,147,150,3,8,4,0,148,150,3,90,45,0,149,147,1,0,0,0,149,148,1,
  	0,0,0,150,5,1,0,0,0,151,153,5,49,0,0,152,154,5,24,0,0,153,152,1,0,0,0,
  	153,154,1,0,0,0,154,160,1,0,0,0,155,156,7,0,0,0,156,158,5,49,0,0,157,
  	159,5,24,0,0,158,157,1,0,0,0,158,159,1,0,0,0,159,161,1,0,0,0,160,155,
  	1,0,0,0,160,161,1,0,0,0,161,7,1,0,0,0,162,178,3,10,5,0,163,178,3,14,7,
  	0,164,178,3,30,15,0,165,178,3,48,24,0,166,178,3,60,30,0,167,178,3,62,
  	31,0,168,178,3,64,32,0,169,178,3,66,33,0,170,178,3,68,34,0,171,178,3,
  	70,35,0,172,178,3,72,36,0,173,178,3,74,37,0,174,178,3,76,38,0,175,178,
  	3,78,39,0,176,178,3,80,40,0,177,162,1,0,0,0,177,163,1,0,0,0,177,164,1,
  	0,0,0,177,165,1,0,0,0,177,166,1,0,0,0,177,167,1,0,0,0,177,168,1,0,0,0,
  	177,169,1,0,0,0,177,170,1,0,0,0,177,171,1,0,0,0,177,172,1,0,0,0,177,173,
  	1,0,0,0,177,174,1,0,0,0,177,175,1,0,0,0,177,176,1,0,0,0,178,9,1,0,0,0,
  	179,180,7,1,0,0,180,183,5,49,0,0,181,182,5,33,0,0,182,184,3,6,3,0,183,
  	181,1,0,0,0,183,184,1,0,0,0,184,187,1,0,0,0,185,186,5,47,0,0,186,188,
  	3,90,45,0,187,185,1,0,0,0,187,188,1,0,0,0,188,11,1,0,0,0,189,190,7,0,
  	0,0,190,191,5,49,0,0,191,13,1,0,0,0,192,193,5,65,0,0,193,195,5,49,0,0,
  	194,196,3,12,6,0,195,194,1,0,0,0,195,196,1,0,0,0,196,197,1,0,0,0,197,
  	199,5,1,0,0,198,200,3,20,10,0,199,198,1,0,0,0,199,200,1,0,0,0,200,201,
  	1,0,0,0,201,203,5,2,0,0,202,204,3,16,8,0,203,202,1,0,0,0,203,204,1,0,
  	0,0,204,205,1,0,0,0,205,206,3,18,9,0,206,15,1,0,0,0,207,208,7,2,0,0,208,
  	209,5,49,0,0,209,17,1,0,0,0,210,214,3,58,29,0,211,212,5,47,0,0,212,214,
  	3,90,45,0,213,210,1,0,0,0,213,211,1,0,0,0,214,19,1,0,0,0,215,220,3,22,
  	11,0,216,217,5,8,0,0,217,219,3,22,11,0,218,216,1,0,0,0,219,222,1,0,0,
  	0,220,218,1,0,0,0,220,221,1,0,0,0,221,21,1,0,0,0,222,220,1,0,0,0,223,
  	224,5,49,0,0,224,225,5,33,0,0,225,226,3,6,3,0,226,23,1,0,0,0,227,229,
  	5,59,0,0,228,227,1,0,0,0,228,229,1,0,0,0,229,230,1,0,0,0,230,231,3,2,
  	1,0,231,232,5,88,0,0,232,233,3,26,13,0,233,234,5,89,0,0,234,25,1,0,0,
  	0,235,236,3,4,2,0,236,237,3,2,1,0,237,239,1,0,0,0,238,235,1,0,0,0,239,
  	242,1,0,0,0,240,238,1,0,0,0,240,241,1,0,0,0,241,244,1,0,0,0,242,240,1,
  	0,0,0,243,245,3,4,2,0,244,243,1,0,0,0,244,245,1,0,0,0,245,27,1,0,0,0,
  	246,247,7,3,0,0,247,29,1,0,0,0,248,249,5,56,0,0,249,251,5,49,0,0,250,
  	252,3,12,6,0,251,250,1,0,0,0,251,252,1,0,0,0,252,255,1,0,0,0,253,254,
  	5,68,0,0,254,256,3,6,3,0,255,253,1,0,0,0,255,256,1,0,0,0,256,257,1,0,
  	0,0,257,258,3,2,1,0,258,259,5,88,0,0,259,260,3,32,16,0,260,261,5,89,0,
  	0,261,31,1,0,0,0,262,263,3,34,17,0,263,264,3,2,1,0,264,266,1,0,0,0,265,
  	262,1,0,0,0,265,266,1,0,0,0,266,272,1,0,0,0,267,268,3,36,18,0,268,269,
  	3,2,1,0,269,271,1,0,0,0,270,267,1,0,0,0,271,274,1,0,0,0,272,270,1,0,0,
  	0,272,273,1,0,0,0,273,276,1,0,0,0,274,272,1,0,0,0,275,277,3,36,18,0,276,
  	275,1,0,0,0,276,277,1,0,0,0,277,33,1,0,0,0,278,279,5,58,0,0,279,280,3,
  	2,1,0,280,286,5,88,0,0,281,282,3,36,18,0,282,283,3,2,1,0,283,285,1,0,
  	0,0,284,281,1,0,0,0,285,288,1,0,0,0,286,284,1,0,0,0,286,287,1,0,0,0,287,
  	290,1,0,0,0,288,286,1,0,0,0,289,291,3,36,18,0,290,289,1,0,0,0,290,291,
  	1,0,0,0,291,292,1,0,0,0,292,293,5,89,0,0,293,35,1,0,0,0,294,306,3,38,
  	19,0,295,297,3,28,14,0,296,295,1,0,0,0,297,300,1,0,0,0,298,296,1,0,0,
  	0,298,299,1,0,0,0,299,303,1,0,0,0,300,298,1,0,0,0,301,304,3,10,5,0,302,
  	304,3,46,23,0,303,301,1,0,0,0,303,302,1,0,0,0,304,306,1,0,0,0,305,294,
  	1,0,0,0,305,298,1,0,0,0,306,37,1,0,0,0,307,308,5,49,0,0,308,310,5,1,0,
  	0,309,311,3,40,20,0,310,309,1,0,0,0,310,311,1,0,0,0,311,312,1,0,0,0,312,
  	314,5,2,0,0,313,315,3,44,22,0,314,313,1,0,0,0,314,315,1,0,0,0,315,316,
  	1,0,0,0,316,317,3,58,29,0,317,39,1,0,0,0,318,323,3,42,21,0,319,320,5,
  	8,0,0,320,322,3,42,21,0,321,319,1,0,0,0,322,325,1,0,0,0,323,321,1,0,0,
  	0,323,324,1,0,0,0,324,41,1,0,0,0,325,323,1,0,0,0,326,328,7,1,0,0,327,
  	326,1,0,0,0,327,328,1,0,0,0,328,329,1,0,0,0,329,330,5,49,0,0,330,331,
  	5,33,0,0,331,332,3,6,3,0,332,43,1,0,0,0,333,342,5,5,0,0,334,339,3,90,
  	45,0,335,336,5,8,0,0,336,338,3,90,45,0,337,335,1,0,0,0,338,341,1,0,0,
  	0,339,337,1,0,0,0,339,340,1,0,0,0,340,343,1,0,0,0,341,339,1,0,0,0,342,
  	334,1,0,0,0,342,343,1,0,0,0,343,344,1,0,0,0,344,345,5,6,0,0,345,45,1,
  	0,0,0,346,347,3,14,7,0,347,47,1,0,0,0,348,349,5,83,0,0,349,356,5,50,0,
  	0,350,354,5,64,0,0,351,355,5,21,0,0,352,355,5,10,0,0,353,355,3,50,25,
  	0,354,351,1,0,0,0,354,352,1,0,0,0,354,353,1,0,0,0,355,357,1,0,0,0,356,
  	350,1,0,0,0,356,357,1,0,0,0,357,363,1,0,0,0,358,359,5,83,0,0,359,360,
  	5,49,0,0,360,361,5,47,0,0,361,363,3,6,3,0,362,348,1,0,0,0,362,358,1,0,
  	0,0,363,49,1,0,0,0,364,369,3,52,26,0,365,366,5,8,0,0,366,368,3,52,26,
  	0,367,365,1,0,0,0,368,371,1,0,0,0,369,367,1,0,0,0,369,370,1,0,0,0,370,
  	51,1,0,0,0,371,369,1,0,0,0,372,377,5,49,0,0,373,374,5,49,0,0,374,375,
  	5,16,0,0,375,377,5,49,0,0,376,372,1,0,0,0,376,373,1,0,0,0,377,53,1,0,
  	0,0,378,379,5,33,0,0,379,380,5,49,0,0,380,55,1,0,0,0,381,382,5,59,0,0,
  	382,383,3,4,2,0,383,57,1,0,0,0,384,387,3,24,12,0,385,387,3,56,28,0,386,
  	384,1,0,0,0,386,385,1,0,0,0,387,59,1,0,0,0,388,389,5,66,0,0,389,390,3,
  	90,45,0,390,398,3,58,29,0,391,392,3,2,1,0,392,393,5,61,0,0,393,394,3,
  	90,45,0,394,395,3,58,29,0,395,397,1,0,0,0,396,391,1,0,0,0,397,400,1,0,
  	0,0,398,396,1,0,0,0,398,399,1,0,0,0,399,405,1,0,0,0,400,398,1,0,0,0,401,
  	402,3,2,1,0,402,403,5,62,0,0,403,404,3,58,29,0,404,406,1,0,0,0,405,401,
  	1,0,0,0,405,406,1,0,0,0,406,61,1,0,0,0,407,409,5,87,0,0,408,410,3,54,
  	27,0,409,408,1,0,0,0,409,410,1,0,0,0,410,411,1,0,0,0,411,412,3,90,45,
  	0,412,417,3,58,29,0,413,414,3,2,1,0,414,415,5,62,0,0,415,416,3,58,29,
  	0,416,418,1,0,0,0,417,413,1,0,0,0,417,418,1,0,0,0,418,63,1,0,0,0,419,
  	421,5,60,0,0,420,422,3,54,27,0,421,420,1,0,0,0,421,422,1,0,0,0,422,423,
  	1,0,0,0,423,427,5,49,0,0,424,425,5,3,0,0,425,426,5,49,0,0,426,428,5,4,
  	0,0,427,424,1,0,0,0,427,428,1,0,0,0,428,429,1,0,0,0,429,430,5,67,0,0,
  	430,431,3,90,45,0,431,432,3,58,29,0,432,65,1,0,0,0,433,435,5,64,0,0,434,
  	436,3,54,27,0,435,434,1,0,0,0,435,436,1,0,0,0,436,439,1,0,0,0,437,440,
  	3,10,5,0,438,440,3,90,45,0,439,437,1,0,0,0,439,438,1,0,0,0,439,440,1,
  	0,0,0,440,441,1,0,0,0,441,443,5,7,0,0,442,444,3,90,45,0,443,442,1,0,0,
  	0,443,444,1,0,0,0,444,445,1,0,0,0,445,447,5,7,0,0,446,448,3,90,45,0,447,
  	446,1,0,0,0,447,448,1,0,0,0,448,449,1,0,0,0,449,450,3,58,29,0,450,67,
  	1,0,0,0,451,453,5,55,0,0,452,454,3,54,27,0,453,452,1,0,0,0,453,454,1,
  	0,0,0,454,69,1,0,0,0,455,457,5,57,0,0,456,458,3,54,27,0,457,456,1,0,0,
  	0,457,458,1,0,0,0,458,71,1,0,0,0,459,460,5,86,0,0,460,461,3,90,45,0,461,
  	462,3,82,41,0,462,73,1,0,0,0,463,465,5,78,0,0,464,466,3,90,45,0,465,464,
  	1,0,0,0,465,466,1,0,0,0,466,75,1,0,0,0,467,468,5,75,0,0,468,469,3,90,
  	45,0,469,77,1,0,0,0,470,471,5,76,0,0,471,472,3,90,45,0,472,79,1,0,0,0,
  	473,474,5,74,0,0,474,81,1,0,0,0,475,476,3,2,1,0,476,477,5,88,0,0,477,
  	478,3,84,42,0,478,479,5,89,0,0,479,83,1,0,0,0,480,481,3,86,43,0,481,482,
  	3,2,1,0,482,484,1,0,0,0,483,480,1,0,0,0,484,485,1,0,0,0,485,483,1,0,0,
  	0,485,486,1,0,0,0,486,489,1,0,0,0,487,490,3,86,43,0,488,490,3,88,44,0,
  	489,487,1,0,0,0,489,488,1,0,0,0,489,490,1,0,0,0,490,492,1,0,0,0,491,493,
  	3,2,1,0,492,491,1,0,0,0,492,493,1,0,0,0,493,85,1,0,0,0,494,495,3,90,45,
  	0,495,496,3,58,29,0,496,87,1,0,0,0,497,498,5,62,0,0,498,499,3,58,29,0,
  	499,89,1,0,0,0,500,501,6,45,-1,0,501,502,5,49,0,0,502,503,5,34,0,0,503,
  	518,5,49,0,0,504,518,5,49,0,0,505,518,3,98,49,0,506,518,3,96,48,0,507,
  	518,3,100,50,0,508,518,3,112,56,0,509,510,5,1,0,0,510,511,3,90,45,0,511,
  	512,5,2,0,0,512,518,1,0,0,0,513,514,7,4,0,0,514,518,3,90,45,13,515,516,
  	5,70,0,0,516,518,3,90,45,2,517,500,1,0,0,0,517,504,1,0,0,0,517,505,1,
  	0,0,0,517,506,1,0,0,0,517,507,1,0,0,0,517,508,1,0,0,0,517,509,1,0,0,0,
  	517,513,1,0,0,0,517,515,1,0,0,0,518,608,1,0,0,0,519,520,10,21,0,0,520,
  	521,7,5,0,0,521,607,3,90,45,22,522,523,10,15,0,0,523,524,5,25,0,0,524,
  	607,3,90,45,16,525,526,10,14,0,0,526,527,5,11,0,0,527,607,3,90,45,14,
  	528,529,10,12,0,0,529,530,7,6,0,0,530,607,3,90,45,13,531,532,10,11,0,
  	0,532,533,7,7,0,0,533,607,3,90,45,12,534,535,10,10,0,0,535,536,7,8,0,
  	0,536,607,3,90,45,11,537,538,10,9,0,0,538,539,7,9,0,0,539,607,3,90,45,
  	10,540,541,10,8,0,0,541,542,5,66,0,0,542,543,3,90,45,0,543,544,5,62,0,
  	0,544,545,3,90,45,9,545,607,1,0,0,0,546,550,10,7,0,0,547,551,5,68,0,0,
  	548,549,5,68,0,0,549,551,5,70,0,0,550,547,1,0,0,0,550,548,1,0,0,0,551,
  	552,1,0,0,0,552,607,3,90,45,8,553,557,10,6,0,0,554,558,5,67,0,0,555,556,
  	5,70,0,0,556,558,5,67,0,0,557,554,1,0,0,0,557,555,1,0,0,0,558,559,1,0,
  	0,0,559,607,3,90,45,7,560,561,10,5,0,0,561,562,3,92,46,0,562,563,3,90,
  	45,6,563,607,1,0,0,0,564,565,10,4,0,0,565,566,5,54,0,0,566,607,3,90,45,
  	5,567,568,10,3,0,0,568,569,5,72,0,0,569,607,3,90,45,4,570,571,10,1,0,
  	0,571,572,3,94,47,0,572,573,3,90,45,1,573,607,1,0,0,0,574,575,10,20,0,
  	0,575,576,7,10,0,0,576,607,5,49,0,0,577,578,10,19,0,0,578,587,5,1,0,0,
  	579,584,3,90,45,0,580,581,5,8,0,0,581,583,3,90,45,0,582,580,1,0,0,0,583,
  	586,1,0,0,0,584,582,1,0,0,0,584,585,1,0,0,0,585,588,1,0,0,0,586,584,1,
  	0,0,0,587,579,1,0,0,0,587,588,1,0,0,0,588,589,1,0,0,0,589,607,5,2,0,0,
  	590,591,10,18,0,0,591,592,5,3,0,0,592,597,3,90,45,0,593,594,5,8,0,0,594,
  	596,3,90,45,0,595,593,1,0,0,0,596,599,1,0,0,0,597,595,1,0,0,0,597,598,
  	1,0,0,0,598,600,1,0,0,0,599,597,1,0,0,0,600,601,5,4,0,0,601,607,1,0,0,
  	0,602,603,10,17,0,0,603,607,3,120,60,0,604,605,10,16,0,0,605,607,7,11,
  	0,0,606,519,1,0,0,0,606,522,1,0,0,0,606,525,1,0,0,0,606,528,1,0,0,0,606,
  	531,1,0,0,0,606,534,1,0,0,0,606,537,1,0,0,0,606,540,1,0,0,0,606,546,1,
  	0,0,0,606,553,1,0,0,0,606,560,1,0,0,0,606,564,1,0,0,0,606,567,1,0,0,0,
  	606,570,1,0,0,0,606,574,1,0,0,0,606,577,1,0,0,0,606,590,1,0,0,0,606,602,
  	1,0,0,0,606,604,1,0,0,0,607,610,1,0,0,0,608,606,1,0,0,0,608,609,1,0,0,
  	0,609,91,1,0,0,0,610,608,1,0,0,0,611,612,7,12,0,0,612,93,1,0,0,0,613,
  	614,7,13,0,0,614,95,1,0,0,0,615,617,5,51,0,0,616,618,3,90,45,0,617,616,
  	1,0,0,0,617,618,1,0,0,0,618,620,1,0,0,0,619,615,1,0,0,0,620,621,1,0,0,
  	0,621,619,1,0,0,0,621,622,1,0,0,0,622,623,1,0,0,0,623,624,5,50,0,0,624,
  	97,1,0,0,0,625,626,7,14,0,0,626,99,1,0,0,0,627,630,3,102,51,0,628,630,
  	3,106,53,0,629,627,1,0,0,0,629,628,1,0,0,0,630,101,1,0,0,0,631,633,5,
  	3,0,0,632,634,3,104,52,0,633,632,1,0,0,0,633,634,1,0,0,0,634,635,1,0,
  	0,0,635,636,5,4,0,0,636,103,1,0,0,0,637,642,3,90,45,0,638,639,5,8,0,0,
  	639,641,3,90,45,0,640,638,1,0,0,0,641,644,1,0,0,0,642,640,1,0,0,0,642,
  	643,1,0,0,0,643,646,1,0,0,0,644,642,1,0,0,0,645,647,5,8,0,0,646,645,1,
  	0,0,0,646,647,1,0,0,0,647,105,1,0,0,0,648,651,5,3,0,0,649,652,5,16,0,
  	0,650,652,3,108,54,0,651,649,1,0,0,0,651,650,1,0,0,0,652,653,1,0,0,0,
  	653,654,5,4,0,0,654,107,1,0,0,0,655,660,3,110,55,0,656,657,5,8,0,0,657,
  	659,3,110,55,0,658,656,1,0,0,0,659,662,1,0,0,0,660,658,1,0,0,0,660,661,
  	1,0,0,0,661,664,1,0,0,0,662,660,1,0,0,0,663,665,5,8,0,0,664,663,1,0,0,
  	0,664,665,1,0,0,0,665,109,1,0,0,0,666,667,3,90,45,0,667,668,5,16,0,0,
  	668,669,3,90,45,0,669,111,1,0,0,0,670,673,5,65,0,0,671,674,3,120,60,0,
  	672,674,3,118,59,0,673,671,1,0,0,0,673,672,1,0,0,0,674,113,1,0,0,0,675,
  	678,3,20,10,0,676,678,3,116,58,0,677,675,1,0,0,0,677,676,1,0,0,0,678,
  	115,1,0,0,0,679,681,5,1,0,0,680,682,3,20,10,0,681,680,1,0,0,0,681,682,
  	1,0,0,0,682,683,1,0,0,0,683,684,5,2,0,0,684,117,1,0,0,0,685,689,3,114,
  	57,0,686,690,3,58,29,0,687,688,5,47,0,0,688,690,3,90,45,0,689,686,1,0,
  	0,0,689,687,1,0,0,0,690,119,1,0,0,0,691,694,5,5,0,0,692,695,3,122,61,
  	0,693,695,3,124,62,0,694,692,1,0,0,0,694,693,1,0,0,0,695,696,1,0,0,0,
  	696,697,5,6,0,0,697,121,1,0,0,0,698,699,3,114,57,0,699,700,5,16,0,0,700,
  	702,1,0,0,0,701,698,1,0,0,0,701,702,1,0,0,0,702,708,1,0,0,0,703,704,3,
  	4,2,0,704,705,5,7,0,0,705,707,1,0,0,0,706,703,1,0,0,0,707,710,1,0,0,0,
  	708,706,1,0,0,0,708,709,1,0,0,0,709,123,1,0,0,0,710,708,1,0,0,0,711,713,
  	3,114,57,0,712,711,1,0,0,0,712,713,1,0,0,0,713,714,1,0,0,0,714,715,5,
  	47,0,0,715,716,3,90,45,0,716,125,1,0,0,0,82,127,134,138,145,149,153,158,
  	160,177,183,187,195,199,203,213,220,228,240,244,251,255,265,272,276,286,
  	290,298,303,305,310,314,323,327,339,342,354,356,362,369,376,386,398,405,
  	409,417,421,427,435,439,443,447,453,457,465,485,489,492,517,550,557,584,
  	587,597,606,608,617,621,629,633,642,646,651,660,664,673,677,681,689,694,
  	701,708,712
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  flickerParserStaticData = std::move(staticData);
}

}

flicker::flicker(TokenStream *input) : flicker(input, antlr4::atn::ParserATNSimulatorOptions()) {}

flicker::flicker(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  flicker::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *flickerParserStaticData->atn, flickerParserStaticData->decisionToDFA, flickerParserStaticData->sharedContextCache, options);
}

flicker::~flicker() {
  delete _interpreter;
}

const atn::ATN& flicker::getATN() const {
  return *flickerParserStaticData->atn;
}

std::string flicker::getGrammarFileName() const {
  return "flicker.g4";
}

const std::vector<std::string>& flicker::getRuleNames() const {
  return flickerParserStaticData->ruleNames;
}

const dfa::Vocabulary& flicker::getVocabulary() const {
  return flickerParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView flicker::getSerializedATN() const {
  return flickerParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

flicker::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::ProgramContext::EOF() {
  return getToken(flicker::EOF, 0);
}

std::vector<flicker::NewlineContext *> flicker::ProgramContext::newline() {
  return getRuleContexts<flicker::NewlineContext>();
}

flicker::NewlineContext* flicker::ProgramContext::newline(size_t i) {
  return getRuleContext<flicker::NewlineContext>(i);
}

std::vector<flicker::CodeItemContext *> flicker::ProgramContext::codeItem() {
  return getRuleContexts<flicker::CodeItemContext>();
}

flicker::CodeItemContext* flicker::ProgramContext::codeItem(size_t i) {
  return getRuleContext<flicker::CodeItemContext>(i);
}


size_t flicker::ProgramContext::getRuleIndex() const {
  return flicker::RuleProgram;
}

void flicker::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void flicker::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any flicker::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

flicker::ProgramContext* flicker::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, flicker::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(127);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::LINE) {
      setState(126);
      newline();
    }
    setState(134);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(129);
        codeItem();
        setState(130);
        newline(); 
      }
      setState(136);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(138);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -7800762320186457590) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 16538727) != 0)) {
      setState(137);
      codeItem();
    }
    setState(140);
    match(flicker::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewlineContext ------------------------------------------------------------------

flicker::NewlineContext::NewlineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> flicker::NewlineContext::LINE() {
  return getTokens(flicker::LINE);
}

tree::TerminalNode* flicker::NewlineContext::LINE(size_t i) {
  return getToken(flicker::LINE, i);
}


size_t flicker::NewlineContext::getRuleIndex() const {
  return flicker::RuleNewline;
}

void flicker::NewlineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNewline(this);
}

void flicker::NewlineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNewline(this);
}


std::any flicker::NewlineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitNewline(this);
  else
    return visitor->visitChildren(this);
}

flicker::NewlineContext* flicker::newline() {
  NewlineContext *_localctx = _tracker.createInstance<NewlineContext>(_ctx, getState());
  enterRule(_localctx, 2, flicker::RuleNewline);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(143); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(142);
              match(flicker::LINE);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(145); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CodeItemContext ------------------------------------------------------------------

flicker::CodeItemContext::CodeItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

flicker::StatementContext* flicker::CodeItemContext::statement() {
  return getRuleContext<flicker::StatementContext>(0);
}

flicker::ExpressionContext* flicker::CodeItemContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}


size_t flicker::CodeItemContext::getRuleIndex() const {
  return flicker::RuleCodeItem;
}

void flicker::CodeItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCodeItem(this);
}

void flicker::CodeItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCodeItem(this);
}


std::any flicker::CodeItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitCodeItem(this);
  else
    return visitor->visitChildren(this);
}

flicker::CodeItemContext* flicker::codeItem() {
  CodeItemContext *_localctx = _tracker.createInstance<CodeItemContext>(_ctx, getState());
  enterRule(_localctx, 4, flicker::RuleCodeItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(149);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(147);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(148);
      expression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

flicker::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> flicker::TypeContext::IDENTIFIER() {
  return getTokens(flicker::IDENTIFIER);
}

tree::TerminalNode* flicker::TypeContext::IDENTIFIER(size_t i) {
  return getToken(flicker::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> flicker::TypeContext::QUEST() {
  return getTokens(flicker::QUEST);
}

tree::TerminalNode* flicker::TypeContext::QUEST(size_t i) {
  return getToken(flicker::QUEST, i);
}

tree::TerminalNode* flicker::TypeContext::OF() {
  return getToken(flicker::OF, 0);
}

tree::TerminalNode* flicker::TypeContext::FOR() {
  return getToken(flicker::FOR, 0);
}


size_t flicker::TypeContext::getRuleIndex() const {
  return flicker::RuleType;
}

void flicker::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void flicker::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


std::any flicker::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

flicker::TypeContext* flicker::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 6, flicker::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    match(flicker::IDENTIFIER);
    setState(153);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(152);
      match(flicker::QUEST);
      break;
    }

    default:
      break;
    }
    setState(160);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(155);
      _la = _input->LA(1);
      if (!(_la == flicker::FOR

      || _la == flicker::OF)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(156);
      match(flicker::IDENTIFIER);
      setState(158);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
      case 1: {
        setState(157);
        match(flicker::QUEST);
        break;
      }

      default:
        break;
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

flicker::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

flicker::VariableDeclContext* flicker::StatementContext::variableDecl() {
  return getRuleContext<flicker::VariableDeclContext>(0);
}

flicker::FunctionDeclContext* flicker::StatementContext::functionDecl() {
  return getRuleContext<flicker::FunctionDeclContext>(0);
}

flicker::ClassDeclContext* flicker::StatementContext::classDecl() {
  return getRuleContext<flicker::ClassDeclContext>(0);
}

flicker::UsingStatementContext* flicker::StatementContext::usingStatement() {
  return getRuleContext<flicker::UsingStatementContext>(0);
}

flicker::IfStmtContext* flicker::StatementContext::ifStmt() {
  return getRuleContext<flicker::IfStmtContext>(0);
}

flicker::WhileStmtContext* flicker::StatementContext::whileStmt() {
  return getRuleContext<flicker::WhileStmtContext>(0);
}

flicker::EachStmtContext* flicker::StatementContext::eachStmt() {
  return getRuleContext<flicker::EachStmtContext>(0);
}

flicker::ForStmtContext* flicker::StatementContext::forStmt() {
  return getRuleContext<flicker::ForStmtContext>(0);
}

flicker::BreakStmtContext* flicker::StatementContext::breakStmt() {
  return getRuleContext<flicker::BreakStmtContext>(0);
}

flicker::ContinueStmtContext* flicker::StatementContext::continueStmt() {
  return getRuleContext<flicker::ContinueStmtContext>(0);
}

flicker::WhenStmtContext* flicker::StatementContext::whenStmt() {
  return getRuleContext<flicker::WhenStmtContext>(0);
}

flicker::ReturnStmtContext* flicker::StatementContext::returnStmt() {
  return getRuleContext<flicker::ReturnStmtContext>(0);
}

flicker::PrintStmtContext* flicker::StatementContext::printStmt() {
  return getRuleContext<flicker::PrintStmtContext>(0);
}

flicker::ConsoleErrorStmtContext* flicker::StatementContext::consoleErrorStmt() {
  return getRuleContext<flicker::ConsoleErrorStmtContext>(0);
}

flicker::PassStmtContext* flicker::StatementContext::passStmt() {
  return getRuleContext<flicker::PassStmtContext>(0);
}


size_t flicker::StatementContext::getRuleIndex() const {
  return flicker::RuleStatement;
}

void flicker::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void flicker::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any flicker::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

flicker::StatementContext* flicker::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 8, flicker::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(177);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::VAL:
      case flicker::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(162);
        variableDecl();
        break;
      }

      case flicker::FUN: {
        enterOuterAlt(_localctx, 2);
        setState(163);
        functionDecl();
        break;
      }

      case flicker::CLASS: {
        enterOuterAlt(_localctx, 3);
        setState(164);
        classDecl();
        break;
      }

      case flicker::USING: {
        enterOuterAlt(_localctx, 4);
        setState(165);
        usingStatement();
        break;
      }

      case flicker::IF: {
        enterOuterAlt(_localctx, 5);
        setState(166);
        ifStmt();
        break;
      }

      case flicker::WHILE: {
        enterOuterAlt(_localctx, 6);
        setState(167);
        whileStmt();
        break;
      }

      case flicker::EACH: {
        enterOuterAlt(_localctx, 7);
        setState(168);
        eachStmt();
        break;
      }

      case flicker::FOR: {
        enterOuterAlt(_localctx, 8);
        setState(169);
        forStmt();
        break;
      }

      case flicker::BREAK: {
        enterOuterAlt(_localctx, 9);
        setState(170);
        breakStmt();
        break;
      }

      case flicker::CONTINUE: {
        enterOuterAlt(_localctx, 10);
        setState(171);
        continueStmt();
        break;
      }

      case flicker::WHEN: {
        enterOuterAlt(_localctx, 11);
        setState(172);
        whenStmt();
        break;
      }

      case flicker::RETURN: {
        enterOuterAlt(_localctx, 12);
        setState(173);
        returnStmt();
        break;
      }

      case flicker::PRINT: {
        enterOuterAlt(_localctx, 13);
        setState(174);
        printStmt();
        break;
      }

      case flicker::PRINT_ERROR: {
        enterOuterAlt(_localctx, 14);
        setState(175);
        consoleErrorStmt();
        break;
      }

      case flicker::PASS: {
        enterOuterAlt(_localctx, 15);
        setState(176);
        passStmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclContext ------------------------------------------------------------------

flicker::VariableDeclContext::VariableDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::VariableDeclContext::IDENTIFIER() {
  return getToken(flicker::IDENTIFIER, 0);
}

tree::TerminalNode* flicker::VariableDeclContext::VAR() {
  return getToken(flicker::VAR, 0);
}

tree::TerminalNode* flicker::VariableDeclContext::VAL() {
  return getToken(flicker::VAL, 0);
}

tree::TerminalNode* flicker::VariableDeclContext::COLON() {
  return getToken(flicker::COLON, 0);
}

flicker::TypeContext* flicker::VariableDeclContext::type() {
  return getRuleContext<flicker::TypeContext>(0);
}

tree::TerminalNode* flicker::VariableDeclContext::EQ() {
  return getToken(flicker::EQ, 0);
}

flicker::ExpressionContext* flicker::VariableDeclContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}


size_t flicker::VariableDeclContext::getRuleIndex() const {
  return flicker::RuleVariableDecl;
}

void flicker::VariableDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDecl(this);
}

void flicker::VariableDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDecl(this);
}


std::any flicker::VariableDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitVariableDecl(this);
  else
    return visitor->visitChildren(this);
}

flicker::VariableDeclContext* flicker::variableDecl() {
  VariableDeclContext *_localctx = _tracker.createInstance<VariableDeclContext>(_ctx, getState());
  enterRule(_localctx, 10, flicker::RuleVariableDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(179);
    _la = _input->LA(1);
    if (!(_la == flicker::VAL

    || _la == flicker::VAR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(180);
    match(flicker::IDENTIFIER);
    setState(183);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(181);
      match(flicker::COLON);
      setState(182);
      type();
      break;
    }

    default:
      break;
    }
    setState(187);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(185);
      match(flicker::EQ);
      setState(186);
      expression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeParamContext ------------------------------------------------------------------

flicker::TypeParamContext::TypeParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::TypeParamContext::IDENTIFIER() {
  return getToken(flicker::IDENTIFIER, 0);
}

tree::TerminalNode* flicker::TypeParamContext::OF() {
  return getToken(flicker::OF, 0);
}

tree::TerminalNode* flicker::TypeParamContext::FOR() {
  return getToken(flicker::FOR, 0);
}


size_t flicker::TypeParamContext::getRuleIndex() const {
  return flicker::RuleTypeParam;
}

void flicker::TypeParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeParam(this);
}

void flicker::TypeParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeParam(this);
}


std::any flicker::TypeParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitTypeParam(this);
  else
    return visitor->visitChildren(this);
}

flicker::TypeParamContext* flicker::typeParam() {
  TypeParamContext *_localctx = _tracker.createInstance<TypeParamContext>(_ctx, getState());
  enterRule(_localctx, 12, flicker::RuleTypeParam);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    _la = _input->LA(1);
    if (!(_la == flicker::FOR

    || _la == flicker::OF)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(190);
    match(flicker::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclContext ------------------------------------------------------------------

flicker::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::FunctionDeclContext::FUN() {
  return getToken(flicker::FUN, 0);
}

tree::TerminalNode* flicker::FunctionDeclContext::IDENTIFIER() {
  return getToken(flicker::IDENTIFIER, 0);
}

tree::TerminalNode* flicker::FunctionDeclContext::LEFT_PAREN() {
  return getToken(flicker::LEFT_PAREN, 0);
}

tree::TerminalNode* flicker::FunctionDeclContext::RIGHT_PAREN() {
  return getToken(flicker::RIGHT_PAREN, 0);
}

flicker::FunctionContentsContext* flicker::FunctionDeclContext::functionContents() {
  return getRuleContext<flicker::FunctionContentsContext>(0);
}

flicker::TypeParamContext* flicker::FunctionDeclContext::typeParam() {
  return getRuleContext<flicker::TypeParamContext>(0);
}

flicker::ParamListContext* flicker::FunctionDeclContext::paramList() {
  return getRuleContext<flicker::ParamListContext>(0);
}

flicker::FuncReturnTypeContext* flicker::FunctionDeclContext::funcReturnType() {
  return getRuleContext<flicker::FuncReturnTypeContext>(0);
}


size_t flicker::FunctionDeclContext::getRuleIndex() const {
  return flicker::RuleFunctionDecl;
}

void flicker::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void flicker::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}


std::any flicker::FunctionDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitFunctionDecl(this);
  else
    return visitor->visitChildren(this);
}

flicker::FunctionDeclContext* flicker::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 14, flicker::RuleFunctionDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    match(flicker::FUN);
    setState(193);
    match(flicker::IDENTIFIER);
    setState(195);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::FOR

    || _la == flicker::OF) {
      setState(194);
      typeParam();
    }
    setState(197);
    match(flicker::LEFT_PAREN);
    setState(199);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::IDENTIFIER) {
      setState(198);
      paramList();
    }
    setState(201);
    match(flicker::RIGHT_PAREN);
    setState(203);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::RIGHT_ARROW

    || _la == flicker::COLON) {
      setState(202);
      funcReturnType();
    }
    setState(205);
    functionContents();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncReturnTypeContext ------------------------------------------------------------------

flicker::FuncReturnTypeContext::FuncReturnTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::FuncReturnTypeContext::IDENTIFIER() {
  return getToken(flicker::IDENTIFIER, 0);
}

tree::TerminalNode* flicker::FuncReturnTypeContext::COLON() {
  return getToken(flicker::COLON, 0);
}

tree::TerminalNode* flicker::FuncReturnTypeContext::RIGHT_ARROW() {
  return getToken(flicker::RIGHT_ARROW, 0);
}


size_t flicker::FuncReturnTypeContext::getRuleIndex() const {
  return flicker::RuleFuncReturnType;
}

void flicker::FuncReturnTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncReturnType(this);
}

void flicker::FuncReturnTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncReturnType(this);
}


std::any flicker::FuncReturnTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitFuncReturnType(this);
  else
    return visitor->visitChildren(this);
}

flicker::FuncReturnTypeContext* flicker::funcReturnType() {
  FuncReturnTypeContext *_localctx = _tracker.createInstance<FuncReturnTypeContext>(_ctx, getState());
  enterRule(_localctx, 16, flicker::RuleFuncReturnType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(207);
    _la = _input->LA(1);
    if (!(_la == flicker::RIGHT_ARROW

    || _la == flicker::COLON)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(208);
    match(flicker::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContentsContext ------------------------------------------------------------------

flicker::FunctionContentsContext::FunctionContentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

flicker::BlockOrStatementContext* flicker::FunctionContentsContext::blockOrStatement() {
  return getRuleContext<flicker::BlockOrStatementContext>(0);
}

tree::TerminalNode* flicker::FunctionContentsContext::EQ() {
  return getToken(flicker::EQ, 0);
}

flicker::ExpressionContext* flicker::FunctionContentsContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}


size_t flicker::FunctionContentsContext::getRuleIndex() const {
  return flicker::RuleFunctionContents;
}

void flicker::FunctionContentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionContents(this);
}

void flicker::FunctionContentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionContents(this);
}


std::any flicker::FunctionContentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitFunctionContents(this);
  else
    return visitor->visitChildren(this);
}

flicker::FunctionContentsContext* flicker::functionContents() {
  FunctionContentsContext *_localctx = _tracker.createInstance<FunctionContentsContext>(_ctx, getState());
  enterRule(_localctx, 18, flicker::RuleFunctionContents);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(213);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::DO:
      case flicker::LINE: {
        enterOuterAlt(_localctx, 1);
        setState(210);
        blockOrStatement();
        break;
      }

      case flicker::EQ: {
        enterOuterAlt(_localctx, 2);
        setState(211);
        match(flicker::EQ);
        setState(212);
        expression(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamListContext ------------------------------------------------------------------

flicker::ParamListContext::ParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<flicker::ParamContext *> flicker::ParamListContext::param() {
  return getRuleContexts<flicker::ParamContext>();
}

flicker::ParamContext* flicker::ParamListContext::param(size_t i) {
  return getRuleContext<flicker::ParamContext>(i);
}

std::vector<tree::TerminalNode *> flicker::ParamListContext::COMMA() {
  return getTokens(flicker::COMMA);
}

tree::TerminalNode* flicker::ParamListContext::COMMA(size_t i) {
  return getToken(flicker::COMMA, i);
}


size_t flicker::ParamListContext::getRuleIndex() const {
  return flicker::RuleParamList;
}

void flicker::ParamListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamList(this);
}

void flicker::ParamListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamList(this);
}


std::any flicker::ParamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitParamList(this);
  else
    return visitor->visitChildren(this);
}

flicker::ParamListContext* flicker::paramList() {
  ParamListContext *_localctx = _tracker.createInstance<ParamListContext>(_ctx, getState());
  enterRule(_localctx, 20, flicker::RuleParamList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    param();
    setState(220);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == flicker::COMMA) {
      setState(216);
      match(flicker::COMMA);
      setState(217);
      param();
      setState(222);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

flicker::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::ParamContext::IDENTIFIER() {
  return getToken(flicker::IDENTIFIER, 0);
}

tree::TerminalNode* flicker::ParamContext::COLON() {
  return getToken(flicker::COLON, 0);
}

flicker::TypeContext* flicker::ParamContext::type() {
  return getRuleContext<flicker::TypeContext>(0);
}


size_t flicker::ParamContext::getRuleIndex() const {
  return flicker::RuleParam;
}

void flicker::ParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam(this);
}

void flicker::ParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam(this);
}


std::any flicker::ParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitParam(this);
  else
    return visitor->visitChildren(this);
}

flicker::ParamContext* flicker::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 22, flicker::RuleParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(223);
    match(flicker::IDENTIFIER);
    setState(224);
    match(flicker::COLON);
    setState(225);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

flicker::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

flicker::NewlineContext* flicker::BlockContext::newline() {
  return getRuleContext<flicker::NewlineContext>(0);
}

tree::TerminalNode* flicker::BlockContext::INDENT() {
  return getToken(flicker::INDENT, 0);
}

flicker::BlockBodyContext* flicker::BlockContext::blockBody() {
  return getRuleContext<flicker::BlockBodyContext>(0);
}

tree::TerminalNode* flicker::BlockContext::DEDENT() {
  return getToken(flicker::DEDENT, 0);
}

tree::TerminalNode* flicker::BlockContext::DO() {
  return getToken(flicker::DO, 0);
}


size_t flicker::BlockContext::getRuleIndex() const {
  return flicker::RuleBlock;
}

void flicker::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void flicker::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any flicker::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

flicker::BlockContext* flicker::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 24, flicker::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(228);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::DO) {
      setState(227);
      match(flicker::DO);
    }
    setState(230);
    newline();
    setState(231);
    match(flicker::INDENT);
    setState(232);
    blockBody();
    setState(233);
    match(flicker::DEDENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockBodyContext ------------------------------------------------------------------

flicker::BlockBodyContext::BlockBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<flicker::CodeItemContext *> flicker::BlockBodyContext::codeItem() {
  return getRuleContexts<flicker::CodeItemContext>();
}

flicker::CodeItemContext* flicker::BlockBodyContext::codeItem(size_t i) {
  return getRuleContext<flicker::CodeItemContext>(i);
}

std::vector<flicker::NewlineContext *> flicker::BlockBodyContext::newline() {
  return getRuleContexts<flicker::NewlineContext>();
}

flicker::NewlineContext* flicker::BlockBodyContext::newline(size_t i) {
  return getRuleContext<flicker::NewlineContext>(i);
}


size_t flicker::BlockBodyContext::getRuleIndex() const {
  return flicker::RuleBlockBody;
}

void flicker::BlockBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockBody(this);
}

void flicker::BlockBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockBody(this);
}


std::any flicker::BlockBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitBlockBody(this);
  else
    return visitor->visitChildren(this);
}

flicker::BlockBodyContext* flicker::blockBody() {
  BlockBodyContext *_localctx = _tracker.createInstance<BlockBodyContext>(_ctx, getState());
  enterRule(_localctx, 26, flicker::RuleBlockBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(240);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(235);
        codeItem();
        setState(236);
        newline(); 
      }
      setState(242);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
    setState(244);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -7800762320186457590) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 16538727) != 0)) {
      setState(243);
      codeItem();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AccessSpecifierContext ------------------------------------------------------------------

flicker::AccessSpecifierContext::AccessSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::AccessSpecifierContext::PRIVATE() {
  return getToken(flicker::PRIVATE, 0);
}

tree::TerminalNode* flicker::AccessSpecifierContext::OVERRIDE() {
  return getToken(flicker::OVERRIDE, 0);
}


size_t flicker::AccessSpecifierContext::getRuleIndex() const {
  return flicker::RuleAccessSpecifier;
}

void flicker::AccessSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAccessSpecifier(this);
}

void flicker::AccessSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAccessSpecifier(this);
}


std::any flicker::AccessSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitAccessSpecifier(this);
  else
    return visitor->visitChildren(this);
}

flicker::AccessSpecifierContext* flicker::accessSpecifier() {
  AccessSpecifierContext *_localctx = _tracker.createInstance<AccessSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 28, flicker::RuleAccessSpecifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
    _la = _input->LA(1);
    if (!(_la == flicker::OVERRIDE

    || _la == flicker::PRIVATE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDeclContext ------------------------------------------------------------------

flicker::ClassDeclContext::ClassDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::ClassDeclContext::CLASS() {
  return getToken(flicker::CLASS, 0);
}

tree::TerminalNode* flicker::ClassDeclContext::IDENTIFIER() {
  return getToken(flicker::IDENTIFIER, 0);
}

flicker::NewlineContext* flicker::ClassDeclContext::newline() {
  return getRuleContext<flicker::NewlineContext>(0);
}

tree::TerminalNode* flicker::ClassDeclContext::INDENT() {
  return getToken(flicker::INDENT, 0);
}

flicker::ClassBodyContext* flicker::ClassDeclContext::classBody() {
  return getRuleContext<flicker::ClassBodyContext>(0);
}

tree::TerminalNode* flicker::ClassDeclContext::DEDENT() {
  return getToken(flicker::DEDENT, 0);
}

flicker::TypeParamContext* flicker::ClassDeclContext::typeParam() {
  return getRuleContext<flicker::TypeParamContext>(0);
}

tree::TerminalNode* flicker::ClassDeclContext::IS() {
  return getToken(flicker::IS, 0);
}

flicker::TypeContext* flicker::ClassDeclContext::type() {
  return getRuleContext<flicker::TypeContext>(0);
}


size_t flicker::ClassDeclContext::getRuleIndex() const {
  return flicker::RuleClassDecl;
}

void flicker::ClassDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassDecl(this);
}

void flicker::ClassDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassDecl(this);
}


std::any flicker::ClassDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitClassDecl(this);
  else
    return visitor->visitChildren(this);
}

flicker::ClassDeclContext* flicker::classDecl() {
  ClassDeclContext *_localctx = _tracker.createInstance<ClassDeclContext>(_ctx, getState());
  enterRule(_localctx, 30, flicker::RuleClassDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    match(flicker::CLASS);
    setState(249);
    match(flicker::IDENTIFIER);
    setState(251);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::FOR

    || _la == flicker::OF) {
      setState(250);
      typeParam();
    }
    setState(255);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::IS) {
      setState(253);
      match(flicker::IS);
      setState(254);
      type();
    }
    setState(257);
    newline();
    setState(258);
    match(flicker::INDENT);
    setState(259);
    classBody();
    setState(260);
    match(flicker::DEDENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassBodyContext ------------------------------------------------------------------

flicker::ClassBodyContext::ClassBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

flicker::CompanionNamespaceContext* flicker::ClassBodyContext::companionNamespace() {
  return getRuleContext<flicker::CompanionNamespaceContext>(0);
}

std::vector<flicker::NewlineContext *> flicker::ClassBodyContext::newline() {
  return getRuleContexts<flicker::NewlineContext>();
}

flicker::NewlineContext* flicker::ClassBodyContext::newline(size_t i) {
  return getRuleContext<flicker::NewlineContext>(i);
}

std::vector<flicker::ClassItemContext *> flicker::ClassBodyContext::classItem() {
  return getRuleContexts<flicker::ClassItemContext>();
}

flicker::ClassItemContext* flicker::ClassBodyContext::classItem(size_t i) {
  return getRuleContext<flicker::ClassItemContext>(i);
}


size_t flicker::ClassBodyContext::getRuleIndex() const {
  return flicker::RuleClassBody;
}

void flicker::ClassBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassBody(this);
}

void flicker::ClassBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassBody(this);
}


std::any flicker::ClassBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitClassBody(this);
  else
    return visitor->visitChildren(this);
}

flicker::ClassBodyContext* flicker::classBody() {
  ClassBodyContext *_localctx = _tracker.createInstance<ClassBodyContext>(_ctx, getState());
  enterRule(_localctx, 32, flicker::RuleClassBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(265);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::CN) {
      setState(262);
      companionNamespace();
      setState(263);
      newline();
    }
    setState(272);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(267);
        classItem();
        setState(268);
        newline(); 
      }
      setState(274);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
    setState(276);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 49) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 49)) & 103364493313) != 0)) {
      setState(275);
      classItem();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompanionNamespaceContext ------------------------------------------------------------------

flicker::CompanionNamespaceContext::CompanionNamespaceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::CompanionNamespaceContext::CN() {
  return getToken(flicker::CN, 0);
}

std::vector<flicker::NewlineContext *> flicker::CompanionNamespaceContext::newline() {
  return getRuleContexts<flicker::NewlineContext>();
}

flicker::NewlineContext* flicker::CompanionNamespaceContext::newline(size_t i) {
  return getRuleContext<flicker::NewlineContext>(i);
}

tree::TerminalNode* flicker::CompanionNamespaceContext::INDENT() {
  return getToken(flicker::INDENT, 0);
}

tree::TerminalNode* flicker::CompanionNamespaceContext::DEDENT() {
  return getToken(flicker::DEDENT, 0);
}

std::vector<flicker::ClassItemContext *> flicker::CompanionNamespaceContext::classItem() {
  return getRuleContexts<flicker::ClassItemContext>();
}

flicker::ClassItemContext* flicker::CompanionNamespaceContext::classItem(size_t i) {
  return getRuleContext<flicker::ClassItemContext>(i);
}


size_t flicker::CompanionNamespaceContext::getRuleIndex() const {
  return flicker::RuleCompanionNamespace;
}

void flicker::CompanionNamespaceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompanionNamespace(this);
}

void flicker::CompanionNamespaceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompanionNamespace(this);
}


std::any flicker::CompanionNamespaceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitCompanionNamespace(this);
  else
    return visitor->visitChildren(this);
}

flicker::CompanionNamespaceContext* flicker::companionNamespace() {
  CompanionNamespaceContext *_localctx = _tracker.createInstance<CompanionNamespaceContext>(_ctx, getState());
  enterRule(_localctx, 34, flicker::RuleCompanionNamespace);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(278);
    match(flicker::CN);
    setState(279);
    newline();
    setState(280);
    match(flicker::INDENT);
    setState(286);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(281);
        classItem();
        setState(282);
        newline(); 
      }
      setState(288);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
    setState(290);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 49) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 49)) & 103364493313) != 0)) {
      setState(289);
      classItem();
    }
    setState(292);
    match(flicker::DEDENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassItemContext ------------------------------------------------------------------

flicker::ClassItemContext::ClassItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

flicker::InitializerContext* flicker::ClassItemContext::initializer() {
  return getRuleContext<flicker::InitializerContext>(0);
}

flicker::VariableDeclContext* flicker::ClassItemContext::variableDecl() {
  return getRuleContext<flicker::VariableDeclContext>(0);
}

flicker::MethodContext* flicker::ClassItemContext::method() {
  return getRuleContext<flicker::MethodContext>(0);
}

std::vector<flicker::AccessSpecifierContext *> flicker::ClassItemContext::accessSpecifier() {
  return getRuleContexts<flicker::AccessSpecifierContext>();
}

flicker::AccessSpecifierContext* flicker::ClassItemContext::accessSpecifier(size_t i) {
  return getRuleContext<flicker::AccessSpecifierContext>(i);
}


size_t flicker::ClassItemContext::getRuleIndex() const {
  return flicker::RuleClassItem;
}

void flicker::ClassItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassItem(this);
}

void flicker::ClassItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassItem(this);
}


std::any flicker::ClassItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitClassItem(this);
  else
    return visitor->visitChildren(this);
}

flicker::ClassItemContext* flicker::classItem() {
  ClassItemContext *_localctx = _tracker.createInstance<ClassItemContext>(_ctx, getState());
  enterRule(_localctx, 36, flicker::RuleClassItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(305);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(294);
        initializer();
        break;
      }

      case flicker::FUN:
      case flicker::OVERRIDE:
      case flicker::PRIVATE:
      case flicker::VAL:
      case flicker::VAR: {
        enterOuterAlt(_localctx, 2);
        setState(298);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == flicker::OVERRIDE

        || _la == flicker::PRIVATE) {
          setState(295);
          accessSpecifier();
          setState(300);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(303);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case flicker::VAL:
          case flicker::VAR: {
            setState(301);
            variableDecl();
            break;
          }

          case flicker::FUN: {
            setState(302);
            method();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitializerContext ------------------------------------------------------------------

flicker::InitializerContext::InitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::InitializerContext::IDENTIFIER() {
  return getToken(flicker::IDENTIFIER, 0);
}

tree::TerminalNode* flicker::InitializerContext::LEFT_PAREN() {
  return getToken(flicker::LEFT_PAREN, 0);
}

tree::TerminalNode* flicker::InitializerContext::RIGHT_PAREN() {
  return getToken(flicker::RIGHT_PAREN, 0);
}

flicker::BlockOrStatementContext* flicker::InitializerContext::blockOrStatement() {
  return getRuleContext<flicker::BlockOrStatementContext>(0);
}

flicker::InitParamListContext* flicker::InitializerContext::initParamList() {
  return getRuleContext<flicker::InitParamListContext>(0);
}

flicker::SuperInitParamsContext* flicker::InitializerContext::superInitParams() {
  return getRuleContext<flicker::SuperInitParamsContext>(0);
}


size_t flicker::InitializerContext::getRuleIndex() const {
  return flicker::RuleInitializer;
}

void flicker::InitializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitializer(this);
}

void flicker::InitializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitializer(this);
}


std::any flicker::InitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitInitializer(this);
  else
    return visitor->visitChildren(this);
}

flicker::InitializerContext* flicker::initializer() {
  InitializerContext *_localctx = _tracker.createInstance<InitializerContext>(_ctx, getState());
  enterRule(_localctx, 38, flicker::RuleInitializer);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(307);
    match(flicker::IDENTIFIER);
    setState(308);
    match(flicker::LEFT_PAREN);
    setState(310);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 49) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 49)) & 103079215105) != 0)) {
      setState(309);
      initParamList();
    }
    setState(312);
    match(flicker::RIGHT_PAREN);
    setState(314);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::LEFT_BRACE) {
      setState(313);
      superInitParams();
    }
    setState(316);
    blockOrStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitParamListContext ------------------------------------------------------------------

flicker::InitParamListContext::InitParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<flicker::InitParamContext *> flicker::InitParamListContext::initParam() {
  return getRuleContexts<flicker::InitParamContext>();
}

flicker::InitParamContext* flicker::InitParamListContext::initParam(size_t i) {
  return getRuleContext<flicker::InitParamContext>(i);
}

std::vector<tree::TerminalNode *> flicker::InitParamListContext::COMMA() {
  return getTokens(flicker::COMMA);
}

tree::TerminalNode* flicker::InitParamListContext::COMMA(size_t i) {
  return getToken(flicker::COMMA, i);
}


size_t flicker::InitParamListContext::getRuleIndex() const {
  return flicker::RuleInitParamList;
}

void flicker::InitParamListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitParamList(this);
}

void flicker::InitParamListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitParamList(this);
}


std::any flicker::InitParamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitInitParamList(this);
  else
    return visitor->visitChildren(this);
}

flicker::InitParamListContext* flicker::initParamList() {
  InitParamListContext *_localctx = _tracker.createInstance<InitParamListContext>(_ctx, getState());
  enterRule(_localctx, 40, flicker::RuleInitParamList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(318);
    initParam();
    setState(323);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == flicker::COMMA) {
      setState(319);
      match(flicker::COMMA);
      setState(320);
      initParam();
      setState(325);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitParamContext ------------------------------------------------------------------

flicker::InitParamContext::InitParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::InitParamContext::IDENTIFIER() {
  return getToken(flicker::IDENTIFIER, 0);
}

tree::TerminalNode* flicker::InitParamContext::COLON() {
  return getToken(flicker::COLON, 0);
}

flicker::TypeContext* flicker::InitParamContext::type() {
  return getRuleContext<flicker::TypeContext>(0);
}

tree::TerminalNode* flicker::InitParamContext::VAR() {
  return getToken(flicker::VAR, 0);
}

tree::TerminalNode* flicker::InitParamContext::VAL() {
  return getToken(flicker::VAL, 0);
}


size_t flicker::InitParamContext::getRuleIndex() const {
  return flicker::RuleInitParam;
}

void flicker::InitParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitParam(this);
}

void flicker::InitParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitParam(this);
}


std::any flicker::InitParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitInitParam(this);
  else
    return visitor->visitChildren(this);
}

flicker::InitParamContext* flicker::initParam() {
  InitParamContext *_localctx = _tracker.createInstance<InitParamContext>(_ctx, getState());
  enterRule(_localctx, 42, flicker::RuleInitParam);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(327);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::VAL

    || _la == flicker::VAR) {
      setState(326);
      _la = _input->LA(1);
      if (!(_la == flicker::VAL

      || _la == flicker::VAR)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(329);
    match(flicker::IDENTIFIER);
    setState(330);
    match(flicker::COLON);
    setState(331);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SuperInitParamsContext ------------------------------------------------------------------

flicker::SuperInitParamsContext::SuperInitParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::SuperInitParamsContext::LEFT_BRACE() {
  return getToken(flicker::LEFT_BRACE, 0);
}

tree::TerminalNode* flicker::SuperInitParamsContext::RIGHT_BRACE() {
  return getToken(flicker::RIGHT_BRACE, 0);
}

std::vector<flicker::ExpressionContext *> flicker::SuperInitParamsContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::SuperInitParamsContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> flicker::SuperInitParamsContext::COMMA() {
  return getTokens(flicker::COMMA);
}

tree::TerminalNode* flicker::SuperInitParamsContext::COMMA(size_t i) {
  return getToken(flicker::COMMA, i);
}


size_t flicker::SuperInitParamsContext::getRuleIndex() const {
  return flicker::RuleSuperInitParams;
}

void flicker::SuperInitParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSuperInitParams(this);
}

void flicker::SuperInitParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSuperInitParams(this);
}


std::any flicker::SuperInitParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitSuperInitParams(this);
  else
    return visitor->visitChildren(this);
}

flicker::SuperInitParamsContext* flicker::superInitParams() {
  SuperInitParamsContext *_localctx = _tracker.createInstance<SuperInitParamsContext>(_ctx, getState());
  enterRule(_localctx, 44, flicker::RuleSuperInitParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(333);
    match(flicker::LEFT_BRACE);
    setState(342);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -9205885403926052342) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & 131121) != 0)) {
      setState(334);
      expression(0);
      setState(339);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == flicker::COMMA) {
        setState(335);
        match(flicker::COMMA);
        setState(336);
        expression(0);
        setState(341);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(344);
    match(flicker::RIGHT_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodContext ------------------------------------------------------------------

flicker::MethodContext::MethodContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

flicker::FunctionDeclContext* flicker::MethodContext::functionDecl() {
  return getRuleContext<flicker::FunctionDeclContext>(0);
}


size_t flicker::MethodContext::getRuleIndex() const {
  return flicker::RuleMethod;
}

void flicker::MethodContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethod(this);
}

void flicker::MethodContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethod(this);
}


std::any flicker::MethodContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitMethod(this);
  else
    return visitor->visitChildren(this);
}

flicker::MethodContext* flicker::method() {
  MethodContext *_localctx = _tracker.createInstance<MethodContext>(_ctx, getState());
  enterRule(_localctx, 46, flicker::RuleMethod);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(346);
    functionDecl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UsingStatementContext ------------------------------------------------------------------

flicker::UsingStatementContext::UsingStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::UsingStatementContext::USING() {
  return getToken(flicker::USING, 0);
}

tree::TerminalNode* flicker::UsingStatementContext::STRING() {
  return getToken(flicker::STRING, 0);
}

tree::TerminalNode* flicker::UsingStatementContext::FOR() {
  return getToken(flicker::FOR, 0);
}

tree::TerminalNode* flicker::UsingStatementContext::DOT() {
  return getToken(flicker::DOT, 0);
}

tree::TerminalNode* flicker::UsingStatementContext::STAR() {
  return getToken(flicker::STAR, 0);
}

flicker::ImportListContext* flicker::UsingStatementContext::importList() {
  return getRuleContext<flicker::ImportListContext>(0);
}

tree::TerminalNode* flicker::UsingStatementContext::IDENTIFIER() {
  return getToken(flicker::IDENTIFIER, 0);
}

tree::TerminalNode* flicker::UsingStatementContext::EQ() {
  return getToken(flicker::EQ, 0);
}

flicker::TypeContext* flicker::UsingStatementContext::type() {
  return getRuleContext<flicker::TypeContext>(0);
}


size_t flicker::UsingStatementContext::getRuleIndex() const {
  return flicker::RuleUsingStatement;
}

void flicker::UsingStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUsingStatement(this);
}

void flicker::UsingStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUsingStatement(this);
}


std::any flicker::UsingStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitUsingStatement(this);
  else
    return visitor->visitChildren(this);
}

flicker::UsingStatementContext* flicker::usingStatement() {
  UsingStatementContext *_localctx = _tracker.createInstance<UsingStatementContext>(_ctx, getState());
  enterRule(_localctx, 48, flicker::RuleUsingStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(362);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(348);
      match(flicker::USING);
      setState(349);
      match(flicker::STRING);
      setState(356);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
      case 1: {
        setState(350);
        match(flicker::FOR);
        setState(354);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case flicker::DOT: {
            setState(351);
            match(flicker::DOT);
            break;
          }

          case flicker::STAR: {
            setState(352);
            match(flicker::STAR);
            break;
          }

          case flicker::IDENTIFIER: {
            setState(353);
            importList();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(358);
      match(flicker::USING);
      setState(359);
      match(flicker::IDENTIFIER);
      setState(360);
      match(flicker::EQ);
      setState(361);
      type();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportListContext ------------------------------------------------------------------

flicker::ImportListContext::ImportListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<flicker::ImportItemContext *> flicker::ImportListContext::importItem() {
  return getRuleContexts<flicker::ImportItemContext>();
}

flicker::ImportItemContext* flicker::ImportListContext::importItem(size_t i) {
  return getRuleContext<flicker::ImportItemContext>(i);
}

std::vector<tree::TerminalNode *> flicker::ImportListContext::COMMA() {
  return getTokens(flicker::COMMA);
}

tree::TerminalNode* flicker::ImportListContext::COMMA(size_t i) {
  return getToken(flicker::COMMA, i);
}


size_t flicker::ImportListContext::getRuleIndex() const {
  return flicker::RuleImportList;
}

void flicker::ImportListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportList(this);
}

void flicker::ImportListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportList(this);
}


std::any flicker::ImportListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitImportList(this);
  else
    return visitor->visitChildren(this);
}

flicker::ImportListContext* flicker::importList() {
  ImportListContext *_localctx = _tracker.createInstance<ImportListContext>(_ctx, getState());
  enterRule(_localctx, 50, flicker::RuleImportList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(364);
    importItem();
    setState(369);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(365);
        match(flicker::COMMA);
        setState(366);
        importItem(); 
      }
      setState(371);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportItemContext ------------------------------------------------------------------

flicker::ImportItemContext::ImportItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> flicker::ImportItemContext::IDENTIFIER() {
  return getTokens(flicker::IDENTIFIER);
}

tree::TerminalNode* flicker::ImportItemContext::IDENTIFIER(size_t i) {
  return getToken(flicker::IDENTIFIER, i);
}

tree::TerminalNode* flicker::ImportItemContext::RIGHT_ARROW() {
  return getToken(flicker::RIGHT_ARROW, 0);
}


size_t flicker::ImportItemContext::getRuleIndex() const {
  return flicker::RuleImportItem;
}

void flicker::ImportItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportItem(this);
}

void flicker::ImportItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportItem(this);
}


std::any flicker::ImportItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitImportItem(this);
  else
    return visitor->visitChildren(this);
}

flicker::ImportItemContext* flicker::importItem() {
  ImportItemContext *_localctx = _tracker.createInstance<ImportItemContext>(_ctx, getState());
  enterRule(_localctx, 52, flicker::RuleImportItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(376);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(372);
      match(flicker::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(373);
      match(flicker::IDENTIFIER);
      setState(374);
      match(flicker::RIGHT_ARROW);
      setState(375);
      match(flicker::IDENTIFIER);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopLabelContext ------------------------------------------------------------------

flicker::LoopLabelContext::LoopLabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::LoopLabelContext::COLON() {
  return getToken(flicker::COLON, 0);
}

tree::TerminalNode* flicker::LoopLabelContext::IDENTIFIER() {
  return getToken(flicker::IDENTIFIER, 0);
}


size_t flicker::LoopLabelContext::getRuleIndex() const {
  return flicker::RuleLoopLabel;
}

void flicker::LoopLabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoopLabel(this);
}

void flicker::LoopLabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoopLabel(this);
}


std::any flicker::LoopLabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitLoopLabel(this);
  else
    return visitor->visitChildren(this);
}

flicker::LoopLabelContext* flicker::loopLabel() {
  LoopLabelContext *_localctx = _tracker.createInstance<LoopLabelContext>(_ctx, getState());
  enterRule(_localctx, 54, flicker::RuleLoopLabel);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(378);
    match(flicker::COLON);
    setState(379);
    match(flicker::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DoStatementContext ------------------------------------------------------------------

flicker::DoStatementContext::DoStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::DoStatementContext::DO() {
  return getToken(flicker::DO, 0);
}

flicker::CodeItemContext* flicker::DoStatementContext::codeItem() {
  return getRuleContext<flicker::CodeItemContext>(0);
}


size_t flicker::DoStatementContext::getRuleIndex() const {
  return flicker::RuleDoStatement;
}

void flicker::DoStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDoStatement(this);
}

void flicker::DoStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDoStatement(this);
}


std::any flicker::DoStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitDoStatement(this);
  else
    return visitor->visitChildren(this);
}

flicker::DoStatementContext* flicker::doStatement() {
  DoStatementContext *_localctx = _tracker.createInstance<DoStatementContext>(_ctx, getState());
  enterRule(_localctx, 56, flicker::RuleDoStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(381);
    match(flicker::DO);
    setState(382);
    codeItem();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockOrStatementContext ------------------------------------------------------------------

flicker::BlockOrStatementContext::BlockOrStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

flicker::BlockContext* flicker::BlockOrStatementContext::block() {
  return getRuleContext<flicker::BlockContext>(0);
}

flicker::DoStatementContext* flicker::BlockOrStatementContext::doStatement() {
  return getRuleContext<flicker::DoStatementContext>(0);
}


size_t flicker::BlockOrStatementContext::getRuleIndex() const {
  return flicker::RuleBlockOrStatement;
}

void flicker::BlockOrStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockOrStatement(this);
}

void flicker::BlockOrStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockOrStatement(this);
}


std::any flicker::BlockOrStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitBlockOrStatement(this);
  else
    return visitor->visitChildren(this);
}

flicker::BlockOrStatementContext* flicker::blockOrStatement() {
  BlockOrStatementContext *_localctx = _tracker.createInstance<BlockOrStatementContext>(_ctx, getState());
  enterRule(_localctx, 58, flicker::RuleBlockOrStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(386);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(384);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(385);
      doStatement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

flicker::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::IfStmtContext::IF() {
  return getToken(flicker::IF, 0);
}

std::vector<flicker::ExpressionContext *> flicker::IfStmtContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::IfStmtContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

std::vector<flicker::BlockOrStatementContext *> flicker::IfStmtContext::blockOrStatement() {
  return getRuleContexts<flicker::BlockOrStatementContext>();
}

flicker::BlockOrStatementContext* flicker::IfStmtContext::blockOrStatement(size_t i) {
  return getRuleContext<flicker::BlockOrStatementContext>(i);
}

std::vector<flicker::NewlineContext *> flicker::IfStmtContext::newline() {
  return getRuleContexts<flicker::NewlineContext>();
}

flicker::NewlineContext* flicker::IfStmtContext::newline(size_t i) {
  return getRuleContext<flicker::NewlineContext>(i);
}

std::vector<tree::TerminalNode *> flicker::IfStmtContext::ELIF() {
  return getTokens(flicker::ELIF);
}

tree::TerminalNode* flicker::IfStmtContext::ELIF(size_t i) {
  return getToken(flicker::ELIF, i);
}

tree::TerminalNode* flicker::IfStmtContext::ELSE() {
  return getToken(flicker::ELSE, 0);
}


size_t flicker::IfStmtContext::getRuleIndex() const {
  return flicker::RuleIfStmt;
}

void flicker::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}

void flicker::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}


std::any flicker::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

flicker::IfStmtContext* flicker::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 60, flicker::RuleIfStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(388);
    match(flicker::IF);
    setState(389);
    expression(0);
    setState(390);
    blockOrStatement();
    setState(398);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(391);
        newline();
        setState(392);
        match(flicker::ELIF);
        setState(393);
        expression(0);
        setState(394);
        blockOrStatement(); 
      }
      setState(400);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    }
    setState(405);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      setState(401);
      newline();
      setState(402);
      match(flicker::ELSE);
      setState(403);
      blockOrStatement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStmtContext ------------------------------------------------------------------

flicker::WhileStmtContext::WhileStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::WhileStmtContext::WHILE() {
  return getToken(flicker::WHILE, 0);
}

flicker::ExpressionContext* flicker::WhileStmtContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}

std::vector<flicker::BlockOrStatementContext *> flicker::WhileStmtContext::blockOrStatement() {
  return getRuleContexts<flicker::BlockOrStatementContext>();
}

flicker::BlockOrStatementContext* flicker::WhileStmtContext::blockOrStatement(size_t i) {
  return getRuleContext<flicker::BlockOrStatementContext>(i);
}

flicker::LoopLabelContext* flicker::WhileStmtContext::loopLabel() {
  return getRuleContext<flicker::LoopLabelContext>(0);
}

flicker::NewlineContext* flicker::WhileStmtContext::newline() {
  return getRuleContext<flicker::NewlineContext>(0);
}

tree::TerminalNode* flicker::WhileStmtContext::ELSE() {
  return getToken(flicker::ELSE, 0);
}


size_t flicker::WhileStmtContext::getRuleIndex() const {
  return flicker::RuleWhileStmt;
}

void flicker::WhileStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStmt(this);
}

void flicker::WhileStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStmt(this);
}


std::any flicker::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}

flicker::WhileStmtContext* flicker::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 62, flicker::RuleWhileStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(407);
    match(flicker::WHILE);
    setState(409);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(408);
      loopLabel();
    }
    setState(411);
    expression(0);
    setState(412);
    blockOrStatement();
    setState(417);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      setState(413);
      newline();
      setState(414);
      match(flicker::ELSE);
      setState(415);
      blockOrStatement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EachStmtContext ------------------------------------------------------------------

flicker::EachStmtContext::EachStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::EachStmtContext::EACH() {
  return getToken(flicker::EACH, 0);
}

std::vector<tree::TerminalNode *> flicker::EachStmtContext::IDENTIFIER() {
  return getTokens(flicker::IDENTIFIER);
}

tree::TerminalNode* flicker::EachStmtContext::IDENTIFIER(size_t i) {
  return getToken(flicker::IDENTIFIER, i);
}

tree::TerminalNode* flicker::EachStmtContext::IN() {
  return getToken(flicker::IN, 0);
}

flicker::ExpressionContext* flicker::EachStmtContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}

flicker::BlockOrStatementContext* flicker::EachStmtContext::blockOrStatement() {
  return getRuleContext<flicker::BlockOrStatementContext>(0);
}

flicker::LoopLabelContext* flicker::EachStmtContext::loopLabel() {
  return getRuleContext<flicker::LoopLabelContext>(0);
}

tree::TerminalNode* flicker::EachStmtContext::LEFT_BRACKET() {
  return getToken(flicker::LEFT_BRACKET, 0);
}

tree::TerminalNode* flicker::EachStmtContext::RIGHT_BRACKET() {
  return getToken(flicker::RIGHT_BRACKET, 0);
}


size_t flicker::EachStmtContext::getRuleIndex() const {
  return flicker::RuleEachStmt;
}

void flicker::EachStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEachStmt(this);
}

void flicker::EachStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEachStmt(this);
}


std::any flicker::EachStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitEachStmt(this);
  else
    return visitor->visitChildren(this);
}

flicker::EachStmtContext* flicker::eachStmt() {
  EachStmtContext *_localctx = _tracker.createInstance<EachStmtContext>(_ctx, getState());
  enterRule(_localctx, 64, flicker::RuleEachStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(419);
    match(flicker::EACH);
    setState(421);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(420);
      loopLabel();
    }
    setState(423);
    match(flicker::IDENTIFIER);
    setState(427);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::LEFT_BRACKET) {
      setState(424);
      match(flicker::LEFT_BRACKET);
      setState(425);
      match(flicker::IDENTIFIER);
      setState(426);
      match(flicker::RIGHT_BRACKET);
    }
    setState(429);
    match(flicker::IN);
    setState(430);
    expression(0);
    setState(431);
    blockOrStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStmtContext ------------------------------------------------------------------

flicker::ForStmtContext::ForStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::ForStmtContext::FOR() {
  return getToken(flicker::FOR, 0);
}

std::vector<tree::TerminalNode *> flicker::ForStmtContext::SEMICOLON() {
  return getTokens(flicker::SEMICOLON);
}

tree::TerminalNode* flicker::ForStmtContext::SEMICOLON(size_t i) {
  return getToken(flicker::SEMICOLON, i);
}

flicker::BlockOrStatementContext* flicker::ForStmtContext::blockOrStatement() {
  return getRuleContext<flicker::BlockOrStatementContext>(0);
}

flicker::LoopLabelContext* flicker::ForStmtContext::loopLabel() {
  return getRuleContext<flicker::LoopLabelContext>(0);
}

flicker::VariableDeclContext* flicker::ForStmtContext::variableDecl() {
  return getRuleContext<flicker::VariableDeclContext>(0);
}

std::vector<flicker::ExpressionContext *> flicker::ForStmtContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::ForStmtContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}


size_t flicker::ForStmtContext::getRuleIndex() const {
  return flicker::RuleForStmt;
}

void flicker::ForStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStmt(this);
}

void flicker::ForStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStmt(this);
}


std::any flicker::ForStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitForStmt(this);
  else
    return visitor->visitChildren(this);
}

flicker::ForStmtContext* flicker::forStmt() {
  ForStmtContext *_localctx = _tracker.createInstance<ForStmtContext>(_ctx, getState());
  enterRule(_localctx, 66, flicker::RuleForStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(433);
    match(flicker::FOR);
    setState(435);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(434);
      loopLabel();
    }
    setState(439);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::VAL:
      case flicker::VAR: {
        setState(437);
        variableDecl();
        break;
      }

      case flicker::LEFT_PAREN:
      case flicker::LEFT_BRACKET:
      case flicker::TILDE:
      case flicker::MINUS:
      case flicker::MINUS_MINUS:
      case flicker::PLUS_PLUS:
      case flicker::BANG:
      case flicker::IDENTIFIER:
      case flicker::STRING:
      case flicker::INTERPOLATION:
      case flicker::CHAR:
      case flicker::NUMBER:
      case flicker::FALSE:
      case flicker::FUN:
      case flicker::NIL:
      case flicker::NOT:
      case flicker::TRUE: {
        setState(438);
        expression(0);
        break;
      }

      case flicker::SEMICOLON: {
        break;
      }

    default:
      break;
    }
    setState(441);
    match(flicker::SEMICOLON);
    setState(443);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -9205885403926052342) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & 131121) != 0)) {
      setState(442);
      expression(0);
    }
    setState(445);
    match(flicker::SEMICOLON);
    setState(447);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -9205885403926052342) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & 131121) != 0)) {
      setState(446);
      expression(0);
    }
    setState(449);
    blockOrStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStmtContext ------------------------------------------------------------------

flicker::BreakStmtContext::BreakStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::BreakStmtContext::BREAK() {
  return getToken(flicker::BREAK, 0);
}

flicker::LoopLabelContext* flicker::BreakStmtContext::loopLabel() {
  return getRuleContext<flicker::LoopLabelContext>(0);
}


size_t flicker::BreakStmtContext::getRuleIndex() const {
  return flicker::RuleBreakStmt;
}

void flicker::BreakStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStmt(this);
}

void flicker::BreakStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStmt(this);
}


std::any flicker::BreakStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitBreakStmt(this);
  else
    return visitor->visitChildren(this);
}

flicker::BreakStmtContext* flicker::breakStmt() {
  BreakStmtContext *_localctx = _tracker.createInstance<BreakStmtContext>(_ctx, getState());
  enterRule(_localctx, 68, flicker::RuleBreakStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(451);
    match(flicker::BREAK);
    setState(453);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      setState(452);
      loopLabel();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContinueStmtContext ------------------------------------------------------------------

flicker::ContinueStmtContext::ContinueStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::ContinueStmtContext::CONTINUE() {
  return getToken(flicker::CONTINUE, 0);
}

flicker::LoopLabelContext* flicker::ContinueStmtContext::loopLabel() {
  return getRuleContext<flicker::LoopLabelContext>(0);
}


size_t flicker::ContinueStmtContext::getRuleIndex() const {
  return flicker::RuleContinueStmt;
}

void flicker::ContinueStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContinueStmt(this);
}

void flicker::ContinueStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContinueStmt(this);
}


std::any flicker::ContinueStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitContinueStmt(this);
  else
    return visitor->visitChildren(this);
}

flicker::ContinueStmtContext* flicker::continueStmt() {
  ContinueStmtContext *_localctx = _tracker.createInstance<ContinueStmtContext>(_ctx, getState());
  enterRule(_localctx, 70, flicker::RuleContinueStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(455);
    match(flicker::CONTINUE);
    setState(457);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
    case 1: {
      setState(456);
      loopLabel();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhenStmtContext ------------------------------------------------------------------

flicker::WhenStmtContext::WhenStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::WhenStmtContext::WHEN() {
  return getToken(flicker::WHEN, 0);
}

flicker::ExpressionContext* flicker::WhenStmtContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}

flicker::WhenBodyContext* flicker::WhenStmtContext::whenBody() {
  return getRuleContext<flicker::WhenBodyContext>(0);
}


size_t flicker::WhenStmtContext::getRuleIndex() const {
  return flicker::RuleWhenStmt;
}

void flicker::WhenStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhenStmt(this);
}

void flicker::WhenStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhenStmt(this);
}


std::any flicker::WhenStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitWhenStmt(this);
  else
    return visitor->visitChildren(this);
}

flicker::WhenStmtContext* flicker::whenStmt() {
  WhenStmtContext *_localctx = _tracker.createInstance<WhenStmtContext>(_ctx, getState());
  enterRule(_localctx, 72, flicker::RuleWhenStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(459);
    match(flicker::WHEN);
    setState(460);
    expression(0);
    setState(461);
    whenBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

flicker::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::ReturnStmtContext::RETURN() {
  return getToken(flicker::RETURN, 0);
}

flicker::ExpressionContext* flicker::ReturnStmtContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}


size_t flicker::ReturnStmtContext::getRuleIndex() const {
  return flicker::RuleReturnStmt;
}

void flicker::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}

void flicker::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}


std::any flicker::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}

flicker::ReturnStmtContext* flicker::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 74, flicker::RuleReturnStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(463);
    match(flicker::RETURN);
    setState(465);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      setState(464);
      expression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintStmtContext ------------------------------------------------------------------

flicker::PrintStmtContext::PrintStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::PrintStmtContext::PRINT() {
  return getToken(flicker::PRINT, 0);
}

flicker::ExpressionContext* flicker::PrintStmtContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}


size_t flicker::PrintStmtContext::getRuleIndex() const {
  return flicker::RulePrintStmt;
}

void flicker::PrintStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrintStmt(this);
}

void flicker::PrintStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrintStmt(this);
}


std::any flicker::PrintStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitPrintStmt(this);
  else
    return visitor->visitChildren(this);
}

flicker::PrintStmtContext* flicker::printStmt() {
  PrintStmtContext *_localctx = _tracker.createInstance<PrintStmtContext>(_ctx, getState());
  enterRule(_localctx, 76, flicker::RulePrintStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(467);
    match(flicker::PRINT);
    setState(468);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConsoleErrorStmtContext ------------------------------------------------------------------

flicker::ConsoleErrorStmtContext::ConsoleErrorStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::ConsoleErrorStmtContext::PRINT_ERROR() {
  return getToken(flicker::PRINT_ERROR, 0);
}

flicker::ExpressionContext* flicker::ConsoleErrorStmtContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}


size_t flicker::ConsoleErrorStmtContext::getRuleIndex() const {
  return flicker::RuleConsoleErrorStmt;
}

void flicker::ConsoleErrorStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConsoleErrorStmt(this);
}

void flicker::ConsoleErrorStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConsoleErrorStmt(this);
}


std::any flicker::ConsoleErrorStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitConsoleErrorStmt(this);
  else
    return visitor->visitChildren(this);
}

flicker::ConsoleErrorStmtContext* flicker::consoleErrorStmt() {
  ConsoleErrorStmtContext *_localctx = _tracker.createInstance<ConsoleErrorStmtContext>(_ctx, getState());
  enterRule(_localctx, 78, flicker::RuleConsoleErrorStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(470);
    match(flicker::PRINT_ERROR);
    setState(471);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PassStmtContext ------------------------------------------------------------------

flicker::PassStmtContext::PassStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::PassStmtContext::PASS() {
  return getToken(flicker::PASS, 0);
}


size_t flicker::PassStmtContext::getRuleIndex() const {
  return flicker::RulePassStmt;
}

void flicker::PassStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPassStmt(this);
}

void flicker::PassStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPassStmt(this);
}


std::any flicker::PassStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitPassStmt(this);
  else
    return visitor->visitChildren(this);
}

flicker::PassStmtContext* flicker::passStmt() {
  PassStmtContext *_localctx = _tracker.createInstance<PassStmtContext>(_ctx, getState());
  enterRule(_localctx, 80, flicker::RulePassStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(473);
    match(flicker::PASS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhenBodyContext ------------------------------------------------------------------

flicker::WhenBodyContext::WhenBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

flicker::NewlineContext* flicker::WhenBodyContext::newline() {
  return getRuleContext<flicker::NewlineContext>(0);
}

tree::TerminalNode* flicker::WhenBodyContext::INDENT() {
  return getToken(flicker::INDENT, 0);
}

flicker::WhenContentsContext* flicker::WhenBodyContext::whenContents() {
  return getRuleContext<flicker::WhenContentsContext>(0);
}

tree::TerminalNode* flicker::WhenBodyContext::DEDENT() {
  return getToken(flicker::DEDENT, 0);
}


size_t flicker::WhenBodyContext::getRuleIndex() const {
  return flicker::RuleWhenBody;
}

void flicker::WhenBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhenBody(this);
}

void flicker::WhenBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhenBody(this);
}


std::any flicker::WhenBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitWhenBody(this);
  else
    return visitor->visitChildren(this);
}

flicker::WhenBodyContext* flicker::whenBody() {
  WhenBodyContext *_localctx = _tracker.createInstance<WhenBodyContext>(_ctx, getState());
  enterRule(_localctx, 82, flicker::RuleWhenBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(475);
    newline();
    setState(476);
    match(flicker::INDENT);
    setState(477);
    whenContents();
    setState(478);
    match(flicker::DEDENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhenContentsContext ------------------------------------------------------------------

flicker::WhenContentsContext::WhenContentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<flicker::WhenCaseContext *> flicker::WhenContentsContext::whenCase() {
  return getRuleContexts<flicker::WhenCaseContext>();
}

flicker::WhenCaseContext* flicker::WhenContentsContext::whenCase(size_t i) {
  return getRuleContext<flicker::WhenCaseContext>(i);
}

std::vector<flicker::NewlineContext *> flicker::WhenContentsContext::newline() {
  return getRuleContexts<flicker::NewlineContext>();
}

flicker::NewlineContext* flicker::WhenContentsContext::newline(size_t i) {
  return getRuleContext<flicker::NewlineContext>(i);
}

flicker::ElseCaseContext* flicker::WhenContentsContext::elseCase() {
  return getRuleContext<flicker::ElseCaseContext>(0);
}


size_t flicker::WhenContentsContext::getRuleIndex() const {
  return flicker::RuleWhenContents;
}

void flicker::WhenContentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhenContents(this);
}

void flicker::WhenContentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhenContents(this);
}


std::any flicker::WhenContentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitWhenContents(this);
  else
    return visitor->visitChildren(this);
}

flicker::WhenContentsContext* flicker::whenContents() {
  WhenContentsContext *_localctx = _tracker.createInstance<WhenContentsContext>(_ctx, getState());
  enterRule(_localctx, 84, flicker::RuleWhenContents);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(483); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(480);
              whenCase();
              setState(481);
              newline();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(485); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(489);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::LEFT_PAREN:
      case flicker::LEFT_BRACKET:
      case flicker::TILDE:
      case flicker::MINUS:
      case flicker::MINUS_MINUS:
      case flicker::PLUS_PLUS:
      case flicker::BANG:
      case flicker::IDENTIFIER:
      case flicker::STRING:
      case flicker::INTERPOLATION:
      case flicker::CHAR:
      case flicker::NUMBER:
      case flicker::FALSE:
      case flicker::FUN:
      case flicker::NIL:
      case flicker::NOT:
      case flicker::TRUE: {
        setState(487);
        whenCase();
        break;
      }

      case flicker::ELSE: {
        setState(488);
        elseCase();
        break;
      }

      case flicker::DEDENT:
      case flicker::LINE: {
        break;
      }

    default:
      break;
    }
    setState(492);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::LINE) {
      setState(491);
      newline();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhenCaseContext ------------------------------------------------------------------

flicker::WhenCaseContext::WhenCaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

flicker::ExpressionContext* flicker::WhenCaseContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}

flicker::BlockOrStatementContext* flicker::WhenCaseContext::blockOrStatement() {
  return getRuleContext<flicker::BlockOrStatementContext>(0);
}


size_t flicker::WhenCaseContext::getRuleIndex() const {
  return flicker::RuleWhenCase;
}

void flicker::WhenCaseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhenCase(this);
}

void flicker::WhenCaseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhenCase(this);
}


std::any flicker::WhenCaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitWhenCase(this);
  else
    return visitor->visitChildren(this);
}

flicker::WhenCaseContext* flicker::whenCase() {
  WhenCaseContext *_localctx = _tracker.createInstance<WhenCaseContext>(_ctx, getState());
  enterRule(_localctx, 86, flicker::RuleWhenCase);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(494);
    expression(0);
    setState(495);
    blockOrStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseCaseContext ------------------------------------------------------------------

flicker::ElseCaseContext::ElseCaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::ElseCaseContext::ELSE() {
  return getToken(flicker::ELSE, 0);
}

flicker::BlockOrStatementContext* flicker::ElseCaseContext::blockOrStatement() {
  return getRuleContext<flicker::BlockOrStatementContext>(0);
}


size_t flicker::ElseCaseContext::getRuleIndex() const {
  return flicker::RuleElseCase;
}

void flicker::ElseCaseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseCase(this);
}

void flicker::ElseCaseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseCase(this);
}


std::any flicker::ElseCaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitElseCase(this);
  else
    return visitor->visitChildren(this);
}

flicker::ElseCaseContext* flicker::elseCase() {
  ElseCaseContext *_localctx = _tracker.createInstance<ElseCaseContext>(_ctx, getState());
  enterRule(_localctx, 88, flicker::RuleElseCase);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(497);
    match(flicker::ELSE);
    setState(498);
    blockOrStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

flicker::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t flicker::ExpressionContext::getRuleIndex() const {
  return flicker::RuleExpression;
}

void flicker::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ConstantContext ------------------------------------------------------------------

flicker::ConstantExprContext* flicker::ConstantContext::constantExpr() {
  return getRuleContext<flicker::ConstantExprContext>(0);
}

flicker::ConstantContext::ConstantContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant(this);
}
void flicker::ConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant(this);
}

std::any flicker::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PowerExprContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::PowerExprContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::PowerExprContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::PowerExprContext::STAR_STAR() {
  return getToken(flicker::STAR_STAR, 0);
}

flicker::PowerExprContext::PowerExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::PowerExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPowerExpr(this);
}
void flicker::PowerExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPowerExpr(this);
}

std::any flicker::PowerExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitPowerExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TermExprContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::TermExprContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::TermExprContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::TermExprContext::PLUS() {
  return getToken(flicker::PLUS, 0);
}

tree::TerminalNode* flicker::TermExprContext::MINUS() {
  return getToken(flicker::MINUS, 0);
}

flicker::TermExprContext::TermExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::TermExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTermExpr(this);
}
void flicker::TermExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTermExpr(this);
}

std::any flicker::TermExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitTermExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitShiftExprContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::BitShiftExprContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::BitShiftExprContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::BitShiftExprContext::LT_LT() {
  return getToken(flicker::LT_LT, 0);
}

tree::TerminalNode* flicker::BitShiftExprContext::GT_GT() {
  return getToken(flicker::GT_GT, 0);
}

flicker::BitShiftExprContext::BitShiftExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::BitShiftExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitShiftExpr(this);
}
void flicker::BitShiftExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitShiftExpr(this);
}

std::any flicker::BitShiftExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitBitShiftExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactorExprContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::FactorExprContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::FactorExprContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::FactorExprContext::SLASH() {
  return getToken(flicker::SLASH, 0);
}

tree::TerminalNode* flicker::FactorExprContext::STAR() {
  return getToken(flicker::STAR, 0);
}

flicker::FactorExprContext::FactorExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::FactorExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactorExpr(this);
}
void flicker::FactorExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactorExpr(this);
}

std::any flicker::FactorExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitFactorExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LambdaCallContext ------------------------------------------------------------------

flicker::ExpressionContext* flicker::LambdaCallContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}

flicker::BraceLambdaContext* flicker::LambdaCallContext::braceLambda() {
  return getRuleContext<flicker::BraceLambdaContext>(0);
}

flicker::LambdaCallContext::LambdaCallContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::LambdaCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLambdaCall(this);
}
void flicker::LambdaCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLambdaCall(this);
}

std::any flicker::LambdaCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitLambdaCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenExprContext ------------------------------------------------------------------

tree::TerminalNode* flicker::ParenExprContext::LEFT_PAREN() {
  return getToken(flicker::LEFT_PAREN, 0);
}

flicker::ExpressionContext* flicker::ParenExprContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}

tree::TerminalNode* flicker::ParenExprContext::RIGHT_PAREN() {
  return getToken(flicker::RIGHT_PAREN, 0);
}

flicker::ParenExprContext::ParenExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ParenExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenExpr(this);
}
void flicker::ParenExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenExpr(this);
}

std::any flicker::ParenExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitParenExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LambdaContext ------------------------------------------------------------------

flicker::LambdaLiteralContext* flicker::LambdaContext::lambdaLiteral() {
  return getRuleContext<flicker::LambdaLiteralContext>(0);
}

flicker::LambdaContext::LambdaContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::LambdaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLambda(this);
}
void flicker::LambdaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLambda(this);
}

std::any flicker::LambdaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitLambda(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwisExprContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::BitwisExprContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::BitwisExprContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::BitwisExprContext::PIPE() {
  return getToken(flicker::PIPE, 0);
}

tree::TerminalNode* flicker::BitwisExprContext::AMPERSAND() {
  return getToken(flicker::AMPERSAND, 0);
}

tree::TerminalNode* flicker::BitwisExprContext::CARET() {
  return getToken(flicker::CARET, 0);
}

flicker::BitwisExprContext::BitwisExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::BitwisExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitwisExpr(this);
}
void flicker::BitwisExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitwisExpr(this);
}

std::any flicker::BitwisExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitBitwisExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NilCoalescingOpContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::NilCoalescingOpContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::NilCoalescingOpContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::NilCoalescingOpContext::QUEST_COLON() {
  return getToken(flicker::QUEST_COLON, 0);
}

flicker::NilCoalescingOpContext::NilCoalescingOpContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::NilCoalescingOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNilCoalescingOp(this);
}
void flicker::NilCoalescingOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNilCoalescingOp(this);
}

std::any flicker::NilCoalescingOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitNilCoalescingOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberContext ------------------------------------------------------------------

flicker::ExpressionContext* flicker::MemberContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}

tree::TerminalNode* flicker::MemberContext::IDENTIFIER() {
  return getToken(flicker::IDENTIFIER, 0);
}

tree::TerminalNode* flicker::MemberContext::DOT() {
  return getToken(flicker::DOT, 0);
}

tree::TerminalNode* flicker::MemberContext::QUEST_DOT() {
  return getToken(flicker::QUEST_DOT, 0);
}

flicker::MemberContext::MemberContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::MemberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMember(this);
}
void flicker::MemberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMember(this);
}

std::any flicker::MemberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitMember(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfExprContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::IfExprContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::IfExprContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::IfExprContext::IF() {
  return getToken(flicker::IF, 0);
}

tree::TerminalNode* flicker::IfExprContext::ELSE() {
  return getToken(flicker::ELSE, 0);
}

flicker::IfExprContext::IfExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::IfExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfExpr(this);
}
void flicker::IfExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfExpr(this);
}

std::any flicker::IfExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitIfExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayAccessContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::ArrayAccessContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::ArrayAccessContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::ArrayAccessContext::LEFT_BRACKET() {
  return getToken(flicker::LEFT_BRACKET, 0);
}

tree::TerminalNode* flicker::ArrayAccessContext::RIGHT_BRACKET() {
  return getToken(flicker::RIGHT_BRACKET, 0);
}

std::vector<tree::TerminalNode *> flicker::ArrayAccessContext::COMMA() {
  return getTokens(flicker::COMMA);
}

tree::TerminalNode* flicker::ArrayAccessContext::COMMA(size_t i) {
  return getToken(flicker::COMMA, i);
}

flicker::ArrayAccessContext::ArrayAccessContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ArrayAccessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayAccess(this);
}
void flicker::ArrayAccessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayAccess(this);
}

std::any flicker::ArrayAccessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitArrayAccess(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PostfixExprContext ------------------------------------------------------------------

flicker::ExpressionContext* flicker::PostfixExprContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}

tree::TerminalNode* flicker::PostfixExprContext::PLUS_PLUS() {
  return getToken(flicker::PLUS_PLUS, 0);
}

tree::TerminalNode* flicker::PostfixExprContext::MINUS_MINUS() {
  return getToken(flicker::MINUS_MINUS, 0);
}

flicker::PostfixExprContext::PostfixExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::PostfixExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostfixExpr(this);
}
void flicker::PostfixExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostfixExpr(this);
}

std::any flicker::PostfixExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitPostfixExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ListOrMapContext ------------------------------------------------------------------

flicker::ListOrMapLiteralContext* flicker::ListOrMapContext::listOrMapLiteral() {
  return getRuleContext<flicker::ListOrMapLiteralContext>(0);
}

flicker::ListOrMapContext::ListOrMapContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ListOrMapContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListOrMap(this);
}
void flicker::ListOrMapContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListOrMap(this);
}

std::any flicker::ListOrMapContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitListOrMap(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IsExprContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::IsExprContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::IsExprContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::IsExprContext::IS() {
  return getToken(flicker::IS, 0);
}

tree::TerminalNode* flicker::IsExprContext::NOT() {
  return getToken(flicker::NOT, 0);
}

flicker::IsExprContext::IsExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::IsExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIsExpr(this);
}
void flicker::IsExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIsExpr(this);
}

std::any flicker::IsExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitIsExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentifierContext ------------------------------------------------------------------

tree::TerminalNode* flicker::IdentifierContext::IDENTIFIER() {
  return getToken(flicker::IDENTIFIER, 0);
}

flicker::IdentifierContext::IdentifierContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::IdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier(this);
}
void flicker::IdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier(this);
}

std::any flicker::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ComparisonContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::ComparisonContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::ComparisonContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

flicker::ComparisonOperatorContext* flicker::ComparisonContext::comparisonOperator() {
  return getRuleContext<flicker::ComparisonOperatorContext>(0);
}

flicker::ComparisonContext::ComparisonContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ComparisonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparison(this);
}
void flicker::ComparisonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparison(this);
}

std::any flicker::ComparisonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitComparison(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InExprContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::InExprContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::InExprContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::InExprContext::IN() {
  return getToken(flicker::IN, 0);
}

tree::TerminalNode* flicker::InExprContext::NOT() {
  return getToken(flicker::NOT, 0);
}

flicker::InExprContext::InExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::InExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInExpr(this);
}
void flicker::InExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInExpr(this);
}

std::any flicker::InExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitInExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::AssignmentContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::AssignmentContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

flicker::AssignOperatorContext* flicker::AssignmentContext::assignOperator() {
  return getRuleContext<flicker::AssignOperatorContext>(0);
}

flicker::AssignmentContext::AssignmentContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}
void flicker::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}

std::any flicker::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrExprContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::OrExprContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::OrExprContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::OrExprContext::OR() {
  return getToken(flicker::OR, 0);
}

flicker::OrExprContext::OrExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::OrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrExpr(this);
}
void flicker::OrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrExpr(this);
}

std::any flicker::OrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitOrExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CallContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::CallContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::CallContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::CallContext::LEFT_PAREN() {
  return getToken(flicker::LEFT_PAREN, 0);
}

tree::TerminalNode* flicker::CallContext::RIGHT_PAREN() {
  return getToken(flicker::RIGHT_PAREN, 0);
}

std::vector<tree::TerminalNode *> flicker::CallContext::COMMA() {
  return getTokens(flicker::COMMA);
}

tree::TerminalNode* flicker::CallContext::COMMA(size_t i) {
  return getToken(flicker::COMMA, i);
}

flicker::CallContext::CallContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::CallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall(this);
}
void flicker::CallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall(this);
}

std::any flicker::CallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrefixExprContext ------------------------------------------------------------------

flicker::ExpressionContext* flicker::PrefixExprContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}

tree::TerminalNode* flicker::PrefixExprContext::MINUS() {
  return getToken(flicker::MINUS, 0);
}

tree::TerminalNode* flicker::PrefixExprContext::BANG() {
  return getToken(flicker::BANG, 0);
}

tree::TerminalNode* flicker::PrefixExprContext::TILDE() {
  return getToken(flicker::TILDE, 0);
}

tree::TerminalNode* flicker::PrefixExprContext::PLUS_PLUS() {
  return getToken(flicker::PLUS_PLUS, 0);
}

tree::TerminalNode* flicker::PrefixExprContext::MINUS_MINUS() {
  return getToken(flicker::MINUS_MINUS, 0);
}

flicker::PrefixExprContext::PrefixExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::PrefixExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrefixExpr(this);
}
void flicker::PrefixExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrefixExpr(this);
}

std::any flicker::PrefixExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitPrefixExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InterpolationContext ------------------------------------------------------------------

flicker::InterpolationExprContext* flicker::InterpolationContext::interpolationExpr() {
  return getRuleContext<flicker::InterpolationExprContext>(0);
}

flicker::InterpolationContext::InterpolationContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::InterpolationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterpolation(this);
}
void flicker::InterpolationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterpolation(this);
}

std::any flicker::InterpolationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitInterpolation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotExprContext ------------------------------------------------------------------

tree::TerminalNode* flicker::NotExprContext::NOT() {
  return getToken(flicker::NOT, 0);
}

flicker::ExpressionContext* flicker::NotExprContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}

flicker::NotExprContext::NotExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::NotExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNotExpr(this);
}
void flicker::NotExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNotExpr(this);
}

std::any flicker::NotExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitNotExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ScopedIdentifierContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> flicker::ScopedIdentifierContext::IDENTIFIER() {
  return getTokens(flicker::IDENTIFIER);
}

tree::TerminalNode* flicker::ScopedIdentifierContext::IDENTIFIER(size_t i) {
  return getToken(flicker::IDENTIFIER, i);
}

tree::TerminalNode* flicker::ScopedIdentifierContext::COLON_COLON() {
  return getToken(flicker::COLON_COLON, 0);
}

flicker::ScopedIdentifierContext::ScopedIdentifierContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ScopedIdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScopedIdentifier(this);
}
void flicker::ScopedIdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScopedIdentifier(this);
}

std::any flicker::ScopedIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitScopedIdentifier(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RangeExprContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::RangeExprContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::RangeExprContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::RangeExprContext::DOT_DOT() {
  return getToken(flicker::DOT_DOT, 0);
}

tree::TerminalNode* flicker::RangeExprContext::DOT_DOT_LT() {
  return getToken(flicker::DOT_DOT_LT, 0);
}

flicker::RangeExprContext::RangeExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::RangeExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRangeExpr(this);
}
void flicker::RangeExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRangeExpr(this);
}

std::any flicker::RangeExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitRangeExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AndExprContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::AndExprContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::AndExprContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::AndExprContext::AND() {
  return getToken(flicker::AND, 0);
}

flicker::AndExprContext::AndExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::AndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndExpr(this);
}
void flicker::AndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndExpr(this);
}

std::any flicker::AndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitAndExpr(this);
  else
    return visitor->visitChildren(this);
}

flicker::ExpressionContext* flicker::expression() {
   return expression(0);
}

flicker::ExpressionContext* flicker::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  flicker::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  flicker::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 90;
  enterRecursionRule(_localctx, 90, flicker::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(517);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ScopedIdentifierContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(501);
      match(flicker::IDENTIFIER);
      setState(502);
      match(flicker::COLON_COLON);
      setState(503);
      match(flicker::IDENTIFIER);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<IdentifierContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(504);
      match(flicker::IDENTIFIER);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ConstantContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(505);
      constantExpr();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<InterpolationContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(506);
      interpolationExpr();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ListOrMapContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(507);
      listOrMapLiteral();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<LambdaContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(508);
      lambdaLiteral();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(509);
      match(flicker::LEFT_PAREN);
      setState(510);
      expression(0);
      setState(511);
      match(flicker::RIGHT_PAREN);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<PrefixExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(513);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 35184372662784) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(514);
      expression(13);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<NotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(515);
      match(flicker::NOT);
      setState(516);
      expression(2);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(608);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(606);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<RangeExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(519);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(520);
          _la = _input->LA(1);
          if (!(_la == flicker::DOT_DOT

          || _la == flicker::DOT_DOT_LT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(521);
          expression(22);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<NilCoalescingOpContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(522);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(523);
          match(flicker::QUEST_COLON);
          setState(524);
          expression(16);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<PowerExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(525);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(526);
          match(flicker::STAR_STAR);
          setState(527);
          expression(14);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<FactorExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(528);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(529);
          _la = _input->LA(1);
          if (!(_la == flicker::STAR

          || _la == flicker::SLASH)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(530);
          expression(13);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<TermExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(531);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(532);
          _la = _input->LA(1);
          if (!(_la == flicker::MINUS

          || _la == flicker::PLUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(533);
          expression(12);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BitShiftExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(534);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(535);
          _la = _input->LA(1);
          if (!(_la == flicker::GT_GT

          || _la == flicker::LT_LT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(536);
          expression(11);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BitwisExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(537);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(538);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 11544872091648) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(539);
          expression(10);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<IfExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(540);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(541);
          match(flicker::IF);
          setState(542);
          expression(0);
          setState(543);
          match(flicker::ELSE);
          setState(544);
          expression(9);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<IsExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(546);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(550);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
          case 1: {
            setState(547);
            match(flicker::IS);
            break;
          }

          case 2: {
            setState(548);
            match(flicker::IS);
            setState(549);
            match(flicker::NOT);
            break;
          }

          default:
            break;
          }
          setState(552);
          expression(8);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<InExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(553);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(557);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case flicker::IN: {
              setState(554);
              match(flicker::IN);
              break;
            }

            case flicker::NOT: {
              setState(555);
              match(flicker::NOT);
              setState(556);
              match(flicker::IN);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(559);
          expression(7);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<ComparisonContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(560);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(561);
          comparisonOperator();
          setState(562);
          expression(6);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(564);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(565);
          match(flicker::AND);
          setState(566);
          expression(5);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(567);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(568);
          match(flicker::OR);
          setState(569);
          expression(4);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<AssignmentContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(570);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(571);
          assignOperator();
          setState(572);
          expression(1);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<MemberContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(574);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(575);
          _la = _input->LA(1);
          if (!(_la == flicker::DOT

          || _la == flicker::QUEST_DOT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(576);
          match(flicker::IDENTIFIER);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<CallContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(577);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(578);
          match(flicker::LEFT_PAREN);
          setState(587);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & -9205885403926052342) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 65)) & 131121) != 0)) {
            setState(579);
            expression(0);
            setState(584);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == flicker::COMMA) {
              setState(580);
              match(flicker::COMMA);
              setState(581);
              expression(0);
              setState(586);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(589);
          match(flicker::RIGHT_PAREN);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<ArrayAccessContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(590);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(591);
          match(flicker::LEFT_BRACKET);

          setState(592);
          expression(0);
          setState(597);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == flicker::COMMA) {
            setState(593);
            match(flicker::COMMA);
            setState(594);
            expression(0);
            setState(599);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(600);
          match(flicker::RIGHT_BRACKET);
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<LambdaCallContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(602);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(603);
          braceLambda();
          break;
        }

        case 19: {
          auto newContext = _tracker.createInstance<PostfixExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(604);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(605);
          _la = _input->LA(1);
          if (!(_la == flicker::MINUS_MINUS

          || _la == flicker::PLUS_PLUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        default:
          break;
        } 
      }
      setState(610);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ComparisonOperatorContext ------------------------------------------------------------------

flicker::ComparisonOperatorContext::ComparisonOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::ComparisonOperatorContext::EQ_EQ() {
  return getToken(flicker::EQ_EQ, 0);
}

tree::TerminalNode* flicker::ComparisonOperatorContext::BANG_EQ() {
  return getToken(flicker::BANG_EQ, 0);
}

tree::TerminalNode* flicker::ComparisonOperatorContext::GT() {
  return getToken(flicker::GT, 0);
}

tree::TerminalNode* flicker::ComparisonOperatorContext::GT_EQ() {
  return getToken(flicker::GT_EQ, 0);
}

tree::TerminalNode* flicker::ComparisonOperatorContext::LT() {
  return getToken(flicker::LT, 0);
}

tree::TerminalNode* flicker::ComparisonOperatorContext::LT_EQ() {
  return getToken(flicker::LT_EQ, 0);
}


size_t flicker::ComparisonOperatorContext::getRuleIndex() const {
  return flicker::RuleComparisonOperator;
}

void flicker::ComparisonOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparisonOperator(this);
}

void flicker::ComparisonOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparisonOperator(this);
}


std::any flicker::ComparisonOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitComparisonOperator(this);
  else
    return visitor->visitChildren(this);
}

flicker::ComparisonOperatorContext* flicker::comparisonOperator() {
  ComparisonOperatorContext *_localctx = _tracker.createInstance<ComparisonOperatorContext>(_ctx, getState());
  enterRule(_localctx, 92, flicker::RuleComparisonOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(611);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 351849760686080) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignOperatorContext ------------------------------------------------------------------

flicker::AssignOperatorContext::AssignOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::AssignOperatorContext::EQ() {
  return getToken(flicker::EQ, 0);
}

tree::TerminalNode* flicker::AssignOperatorContext::MINUS_EQ() {
  return getToken(flicker::MINUS_EQ, 0);
}

tree::TerminalNode* flicker::AssignOperatorContext::PLUS_EQ() {
  return getToken(flicker::PLUS_EQ, 0);
}

tree::TerminalNode* flicker::AssignOperatorContext::STAR_EQ() {
  return getToken(flicker::STAR_EQ, 0);
}

tree::TerminalNode* flicker::AssignOperatorContext::SLASH_EQ() {
  return getToken(flicker::SLASH_EQ, 0);
}

tree::TerminalNode* flicker::AssignOperatorContext::STAR_STAR_EQ() {
  return getToken(flicker::STAR_STAR_EQ, 0);
}

tree::TerminalNode* flicker::AssignOperatorContext::PIPE_EQ() {
  return getToken(flicker::PIPE_EQ, 0);
}

tree::TerminalNode* flicker::AssignOperatorContext::AMPERSAND_EQ() {
  return getToken(flicker::AMPERSAND_EQ, 0);
}

tree::TerminalNode* flicker::AssignOperatorContext::CARET_EQ() {
  return getToken(flicker::CARET_EQ, 0);
}

tree::TerminalNode* flicker::AssignOperatorContext::PERCENT_EQ() {
  return getToken(flicker::PERCENT_EQ, 0);
}


size_t flicker::AssignOperatorContext::getRuleIndex() const {
  return flicker::RuleAssignOperator;
}

void flicker::AssignOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignOperator(this);
}

void flicker::AssignOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignOperator(this);
}


std::any flicker::AssignOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitAssignOperator(this);
  else
    return visitor->visitChildren(this);
}

flicker::AssignOperatorContext* flicker::assignOperator() {
  AssignOperatorContext *_localctx = _tracker.createInstance<AssignOperatorContext>(_ctx, getState());
  enterRule(_localctx, 94, flicker::RuleAssignOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(613);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 164170831114240) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterpolationExprContext ------------------------------------------------------------------

flicker::InterpolationExprContext::InterpolationExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::InterpolationExprContext::STRING() {
  return getToken(flicker::STRING, 0);
}

std::vector<tree::TerminalNode *> flicker::InterpolationExprContext::INTERPOLATION() {
  return getTokens(flicker::INTERPOLATION);
}

tree::TerminalNode* flicker::InterpolationExprContext::INTERPOLATION(size_t i) {
  return getToken(flicker::INTERPOLATION, i);
}

std::vector<flicker::ExpressionContext *> flicker::InterpolationExprContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::InterpolationExprContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}


size_t flicker::InterpolationExprContext::getRuleIndex() const {
  return flicker::RuleInterpolationExpr;
}

void flicker::InterpolationExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterpolationExpr(this);
}

void flicker::InterpolationExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterpolationExpr(this);
}


std::any flicker::InterpolationExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitInterpolationExpr(this);
  else
    return visitor->visitChildren(this);
}

flicker::InterpolationExprContext* flicker::interpolationExpr() {
  InterpolationExprContext *_localctx = _tracker.createInstance<InterpolationExprContext>(_ctx, getState());
  enterRule(_localctx, 96, flicker::RuleInterpolationExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(619); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(615);
      match(flicker::INTERPOLATION);
      setState(617);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
      case 1: {
        setState(616);
        expression(0);
        break;
      }

      default:
        break;
      }
      setState(621); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == flicker::INTERPOLATION);
    setState(623);
    match(flicker::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantExprContext ------------------------------------------------------------------

flicker::ConstantExprContext::ConstantExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::ConstantExprContext::NUMBER() {
  return getToken(flicker::NUMBER, 0);
}

tree::TerminalNode* flicker::ConstantExprContext::TRUE() {
  return getToken(flicker::TRUE, 0);
}

tree::TerminalNode* flicker::ConstantExprContext::FALSE() {
  return getToken(flicker::FALSE, 0);
}

tree::TerminalNode* flicker::ConstantExprContext::NIL() {
  return getToken(flicker::NIL, 0);
}

tree::TerminalNode* flicker::ConstantExprContext::STRING() {
  return getToken(flicker::STRING, 0);
}

tree::TerminalNode* flicker::ConstantExprContext::CHAR() {
  return getToken(flicker::CHAR, 0);
}


size_t flicker::ConstantExprContext::getRuleIndex() const {
  return flicker::RuleConstantExpr;
}

void flicker::ConstantExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstantExpr(this);
}

void flicker::ConstantExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstantExpr(this);
}


std::any flicker::ConstantExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitConstantExpr(this);
  else
    return visitor->visitChildren(this);
}

flicker::ConstantExprContext* flicker::constantExpr() {
  ConstantExprContext *_localctx = _tracker.createInstance<ConstantExprContext>(_ctx, getState());
  enterRule(_localctx, 98, flicker::RuleConstantExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(625);
    _la = _input->LA(1);
    if (!(((((_la - 50) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 50)) & 4295499789) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListOrMapLiteralContext ------------------------------------------------------------------

flicker::ListOrMapLiteralContext::ListOrMapLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

flicker::ListLiteralContext* flicker::ListOrMapLiteralContext::listLiteral() {
  return getRuleContext<flicker::ListLiteralContext>(0);
}

flicker::MapLiteralContext* flicker::ListOrMapLiteralContext::mapLiteral() {
  return getRuleContext<flicker::MapLiteralContext>(0);
}


size_t flicker::ListOrMapLiteralContext::getRuleIndex() const {
  return flicker::RuleListOrMapLiteral;
}

void flicker::ListOrMapLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListOrMapLiteral(this);
}

void flicker::ListOrMapLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListOrMapLiteral(this);
}


std::any flicker::ListOrMapLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitListOrMapLiteral(this);
  else
    return visitor->visitChildren(this);
}

flicker::ListOrMapLiteralContext* flicker::listOrMapLiteral() {
  ListOrMapLiteralContext *_localctx = _tracker.createInstance<ListOrMapLiteralContext>(_ctx, getState());
  enterRule(_localctx, 100, flicker::RuleListOrMapLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(629);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(627);
      listLiteral();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(628);
      mapLiteral();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListLiteralContext ------------------------------------------------------------------

flicker::ListLiteralContext::ListLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::ListLiteralContext::LEFT_BRACKET() {
  return getToken(flicker::LEFT_BRACKET, 0);
}

tree::TerminalNode* flicker::ListLiteralContext::RIGHT_BRACKET() {
  return getToken(flicker::RIGHT_BRACKET, 0);
}

flicker::ListItemsContext* flicker::ListLiteralContext::listItems() {
  return getRuleContext<flicker::ListItemsContext>(0);
}


size_t flicker::ListLiteralContext::getRuleIndex() const {
  return flicker::RuleListLiteral;
}

void flicker::ListLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListLiteral(this);
}

void flicker::ListLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListLiteral(this);
}


std::any flicker::ListLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitListLiteral(this);
  else
    return visitor->visitChildren(this);
}

flicker::ListLiteralContext* flicker::listLiteral() {
  ListLiteralContext *_localctx = _tracker.createInstance<ListLiteralContext>(_ctx, getState());
  enterRule(_localctx, 102, flicker::RuleListLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(631);
    match(flicker::LEFT_BRACKET);
    setState(633);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -9205885403926052342) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & 131121) != 0)) {
      setState(632);
      listItems();
    }
    setState(635);
    match(flicker::RIGHT_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListItemsContext ------------------------------------------------------------------

flicker::ListItemsContext::ListItemsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<flicker::ExpressionContext *> flicker::ListItemsContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::ListItemsContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> flicker::ListItemsContext::COMMA() {
  return getTokens(flicker::COMMA);
}

tree::TerminalNode* flicker::ListItemsContext::COMMA(size_t i) {
  return getToken(flicker::COMMA, i);
}


size_t flicker::ListItemsContext::getRuleIndex() const {
  return flicker::RuleListItems;
}

void flicker::ListItemsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListItems(this);
}

void flicker::ListItemsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListItems(this);
}


std::any flicker::ListItemsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitListItems(this);
  else
    return visitor->visitChildren(this);
}

flicker::ListItemsContext* flicker::listItems() {
  ListItemsContext *_localctx = _tracker.createInstance<ListItemsContext>(_ctx, getState());
  enterRule(_localctx, 104, flicker::RuleListItems);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(637);
    expression(0);
    setState(642);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(638);
        match(flicker::COMMA);
        setState(639);
        expression(0); 
      }
      setState(644);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
    }
    setState(646);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COMMA) {
      setState(645);
      match(flicker::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MapLiteralContext ------------------------------------------------------------------

flicker::MapLiteralContext::MapLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::MapLiteralContext::LEFT_BRACKET() {
  return getToken(flicker::LEFT_BRACKET, 0);
}

tree::TerminalNode* flicker::MapLiteralContext::RIGHT_BRACKET() {
  return getToken(flicker::RIGHT_BRACKET, 0);
}

tree::TerminalNode* flicker::MapLiteralContext::RIGHT_ARROW() {
  return getToken(flicker::RIGHT_ARROW, 0);
}

flicker::MapItemsContext* flicker::MapLiteralContext::mapItems() {
  return getRuleContext<flicker::MapItemsContext>(0);
}


size_t flicker::MapLiteralContext::getRuleIndex() const {
  return flicker::RuleMapLiteral;
}

void flicker::MapLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMapLiteral(this);
}

void flicker::MapLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMapLiteral(this);
}


std::any flicker::MapLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitMapLiteral(this);
  else
    return visitor->visitChildren(this);
}

flicker::MapLiteralContext* flicker::mapLiteral() {
  MapLiteralContext *_localctx = _tracker.createInstance<MapLiteralContext>(_ctx, getState());
  enterRule(_localctx, 106, flicker::RuleMapLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(648);
    match(flicker::LEFT_BRACKET);
    setState(651);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::RIGHT_ARROW: {
        setState(649);
        match(flicker::RIGHT_ARROW);
        break;
      }

      case flicker::LEFT_PAREN:
      case flicker::LEFT_BRACKET:
      case flicker::TILDE:
      case flicker::MINUS:
      case flicker::MINUS_MINUS:
      case flicker::PLUS_PLUS:
      case flicker::BANG:
      case flicker::IDENTIFIER:
      case flicker::STRING:
      case flicker::INTERPOLATION:
      case flicker::CHAR:
      case flicker::NUMBER:
      case flicker::FALSE:
      case flicker::FUN:
      case flicker::NIL:
      case flicker::NOT:
      case flicker::TRUE: {
        setState(650);
        mapItems();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(653);
    match(flicker::RIGHT_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MapItemsContext ------------------------------------------------------------------

flicker::MapItemsContext::MapItemsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<flicker::MapItemContext *> flicker::MapItemsContext::mapItem() {
  return getRuleContexts<flicker::MapItemContext>();
}

flicker::MapItemContext* flicker::MapItemsContext::mapItem(size_t i) {
  return getRuleContext<flicker::MapItemContext>(i);
}

std::vector<tree::TerminalNode *> flicker::MapItemsContext::COMMA() {
  return getTokens(flicker::COMMA);
}

tree::TerminalNode* flicker::MapItemsContext::COMMA(size_t i) {
  return getToken(flicker::COMMA, i);
}


size_t flicker::MapItemsContext::getRuleIndex() const {
  return flicker::RuleMapItems;
}

void flicker::MapItemsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMapItems(this);
}

void flicker::MapItemsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMapItems(this);
}


std::any flicker::MapItemsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitMapItems(this);
  else
    return visitor->visitChildren(this);
}

flicker::MapItemsContext* flicker::mapItems() {
  MapItemsContext *_localctx = _tracker.createInstance<MapItemsContext>(_ctx, getState());
  enterRule(_localctx, 108, flicker::RuleMapItems);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(655);
    mapItem();
    setState(660);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(656);
        match(flicker::COMMA);
        setState(657);
        mapItem(); 
      }
      setState(662);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
    }
    setState(664);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COMMA) {
      setState(663);
      match(flicker::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MapItemContext ------------------------------------------------------------------

flicker::MapItemContext::MapItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<flicker::ExpressionContext *> flicker::MapItemContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::MapItemContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::MapItemContext::RIGHT_ARROW() {
  return getToken(flicker::RIGHT_ARROW, 0);
}


size_t flicker::MapItemContext::getRuleIndex() const {
  return flicker::RuleMapItem;
}

void flicker::MapItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMapItem(this);
}

void flicker::MapItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMapItem(this);
}


std::any flicker::MapItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitMapItem(this);
  else
    return visitor->visitChildren(this);
}

flicker::MapItemContext* flicker::mapItem() {
  MapItemContext *_localctx = _tracker.createInstance<MapItemContext>(_ctx, getState());
  enterRule(_localctx, 110, flicker::RuleMapItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(666);
    expression(0);
    setState(667);
    match(flicker::RIGHT_ARROW);
    setState(668);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LambdaLiteralContext ------------------------------------------------------------------

flicker::LambdaLiteralContext::LambdaLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::LambdaLiteralContext::FUN() {
  return getToken(flicker::FUN, 0);
}

flicker::BraceLambdaContext* flicker::LambdaLiteralContext::braceLambda() {
  return getRuleContext<flicker::BraceLambdaContext>(0);
}

flicker::BlockLambdaContext* flicker::LambdaLiteralContext::blockLambda() {
  return getRuleContext<flicker::BlockLambdaContext>(0);
}


size_t flicker::LambdaLiteralContext::getRuleIndex() const {
  return flicker::RuleLambdaLiteral;
}

void flicker::LambdaLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLambdaLiteral(this);
}

void flicker::LambdaLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLambdaLiteral(this);
}


std::any flicker::LambdaLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitLambdaLiteral(this);
  else
    return visitor->visitChildren(this);
}

flicker::LambdaLiteralContext* flicker::lambdaLiteral() {
  LambdaLiteralContext *_localctx = _tracker.createInstance<LambdaLiteralContext>(_ctx, getState());
  enterRule(_localctx, 112, flicker::RuleLambdaLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(670);
    match(flicker::FUN);
    setState(673);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::LEFT_BRACE: {
        setState(671);
        braceLambda();
        break;
      }

      case flicker::LEFT_PAREN:
      case flicker::IDENTIFIER: {
        setState(672);
        blockLambda();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LambdaParamsContext ------------------------------------------------------------------

flicker::LambdaParamsContext::LambdaParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

flicker::ParamListContext* flicker::LambdaParamsContext::paramList() {
  return getRuleContext<flicker::ParamListContext>(0);
}

flicker::ParenthesizedOptionalParamListContext* flicker::LambdaParamsContext::parenthesizedOptionalParamList() {
  return getRuleContext<flicker::ParenthesizedOptionalParamListContext>(0);
}


size_t flicker::LambdaParamsContext::getRuleIndex() const {
  return flicker::RuleLambdaParams;
}

void flicker::LambdaParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLambdaParams(this);
}

void flicker::LambdaParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLambdaParams(this);
}


std::any flicker::LambdaParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitLambdaParams(this);
  else
    return visitor->visitChildren(this);
}

flicker::LambdaParamsContext* flicker::lambdaParams() {
  LambdaParamsContext *_localctx = _tracker.createInstance<LambdaParamsContext>(_ctx, getState());
  enterRule(_localctx, 114, flicker::RuleLambdaParams);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(677);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(675);
        paramList();
        break;
      }

      case flicker::LEFT_PAREN: {
        enterOuterAlt(_localctx, 2);
        setState(676);
        parenthesizedOptionalParamList();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParenthesizedOptionalParamListContext ------------------------------------------------------------------

flicker::ParenthesizedOptionalParamListContext::ParenthesizedOptionalParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::ParenthesizedOptionalParamListContext::LEFT_PAREN() {
  return getToken(flicker::LEFT_PAREN, 0);
}

tree::TerminalNode* flicker::ParenthesizedOptionalParamListContext::RIGHT_PAREN() {
  return getToken(flicker::RIGHT_PAREN, 0);
}

flicker::ParamListContext* flicker::ParenthesizedOptionalParamListContext::paramList() {
  return getRuleContext<flicker::ParamListContext>(0);
}


size_t flicker::ParenthesizedOptionalParamListContext::getRuleIndex() const {
  return flicker::RuleParenthesizedOptionalParamList;
}

void flicker::ParenthesizedOptionalParamListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenthesizedOptionalParamList(this);
}

void flicker::ParenthesizedOptionalParamListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenthesizedOptionalParamList(this);
}


std::any flicker::ParenthesizedOptionalParamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitParenthesizedOptionalParamList(this);
  else
    return visitor->visitChildren(this);
}

flicker::ParenthesizedOptionalParamListContext* flicker::parenthesizedOptionalParamList() {
  ParenthesizedOptionalParamListContext *_localctx = _tracker.createInstance<ParenthesizedOptionalParamListContext>(_ctx, getState());
  enterRule(_localctx, 116, flicker::RuleParenthesizedOptionalParamList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(679);
    match(flicker::LEFT_PAREN);
    setState(681);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::IDENTIFIER) {
      setState(680);
      paramList();
    }
    setState(683);
    match(flicker::RIGHT_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockLambdaContext ------------------------------------------------------------------

flicker::BlockLambdaContext::BlockLambdaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

flicker::LambdaParamsContext* flicker::BlockLambdaContext::lambdaParams() {
  return getRuleContext<flicker::LambdaParamsContext>(0);
}

flicker::BlockOrStatementContext* flicker::BlockLambdaContext::blockOrStatement() {
  return getRuleContext<flicker::BlockOrStatementContext>(0);
}

tree::TerminalNode* flicker::BlockLambdaContext::EQ() {
  return getToken(flicker::EQ, 0);
}

flicker::ExpressionContext* flicker::BlockLambdaContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}


size_t flicker::BlockLambdaContext::getRuleIndex() const {
  return flicker::RuleBlockLambda;
}

void flicker::BlockLambdaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockLambda(this);
}

void flicker::BlockLambdaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockLambda(this);
}


std::any flicker::BlockLambdaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitBlockLambda(this);
  else
    return visitor->visitChildren(this);
}

flicker::BlockLambdaContext* flicker::blockLambda() {
  BlockLambdaContext *_localctx = _tracker.createInstance<BlockLambdaContext>(_ctx, getState());
  enterRule(_localctx, 118, flicker::RuleBlockLambda);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(685);
    lambdaParams();
    setState(689);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::DO:
      case flicker::LINE: {
        setState(686);
        blockOrStatement();
        break;
      }

      case flicker::EQ: {
        setState(687);
        match(flicker::EQ);
        setState(688);
        expression(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BraceLambdaContext ------------------------------------------------------------------

flicker::BraceLambdaContext::BraceLambdaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::BraceLambdaContext::LEFT_BRACE() {
  return getToken(flicker::LEFT_BRACE, 0);
}

tree::TerminalNode* flicker::BraceLambdaContext::RIGHT_BRACE() {
  return getToken(flicker::RIGHT_BRACE, 0);
}

flicker::StatementLambdaBodyContext* flicker::BraceLambdaContext::statementLambdaBody() {
  return getRuleContext<flicker::StatementLambdaBodyContext>(0);
}

flicker::ExprLambdaBodyContext* flicker::BraceLambdaContext::exprLambdaBody() {
  return getRuleContext<flicker::ExprLambdaBodyContext>(0);
}


size_t flicker::BraceLambdaContext::getRuleIndex() const {
  return flicker::RuleBraceLambda;
}

void flicker::BraceLambdaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBraceLambda(this);
}

void flicker::BraceLambdaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBraceLambda(this);
}


std::any flicker::BraceLambdaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitBraceLambda(this);
  else
    return visitor->visitChildren(this);
}

flicker::BraceLambdaContext* flicker::braceLambda() {
  BraceLambdaContext *_localctx = _tracker.createInstance<BraceLambdaContext>(_ctx, getState());
  enterRule(_localctx, 120, flicker::RuleBraceLambda);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(691);
    match(flicker::LEFT_BRACE);
    setState(694);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx)) {
    case 1: {
      setState(692);
      statementLambdaBody();
      break;
    }

    case 2: {
      setState(693);
      exprLambdaBody();
      break;
    }

    default:
      break;
    }
    setState(696);
    match(flicker::RIGHT_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementLambdaBodyContext ------------------------------------------------------------------

flicker::StatementLambdaBodyContext::StatementLambdaBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

flicker::LambdaParamsContext* flicker::StatementLambdaBodyContext::lambdaParams() {
  return getRuleContext<flicker::LambdaParamsContext>(0);
}

tree::TerminalNode* flicker::StatementLambdaBodyContext::RIGHT_ARROW() {
  return getToken(flicker::RIGHT_ARROW, 0);
}

std::vector<flicker::CodeItemContext *> flicker::StatementLambdaBodyContext::codeItem() {
  return getRuleContexts<flicker::CodeItemContext>();
}

flicker::CodeItemContext* flicker::StatementLambdaBodyContext::codeItem(size_t i) {
  return getRuleContext<flicker::CodeItemContext>(i);
}

std::vector<tree::TerminalNode *> flicker::StatementLambdaBodyContext::SEMICOLON() {
  return getTokens(flicker::SEMICOLON);
}

tree::TerminalNode* flicker::StatementLambdaBodyContext::SEMICOLON(size_t i) {
  return getToken(flicker::SEMICOLON, i);
}


size_t flicker::StatementLambdaBodyContext::getRuleIndex() const {
  return flicker::RuleStatementLambdaBody;
}

void flicker::StatementLambdaBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementLambdaBody(this);
}

void flicker::StatementLambdaBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementLambdaBody(this);
}


std::any flicker::StatementLambdaBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitStatementLambdaBody(this);
  else
    return visitor->visitChildren(this);
}

flicker::StatementLambdaBodyContext* flicker::statementLambdaBody() {
  StatementLambdaBodyContext *_localctx = _tracker.createInstance<StatementLambdaBodyContext>(_ctx, getState());
  enterRule(_localctx, 122, flicker::RuleStatementLambdaBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(701);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx)) {
    case 1: {
      setState(698);
      lambdaParams();
      setState(699);
      match(flicker::RIGHT_ARROW);
      break;
    }

    default:
      break;
    }
    setState(708);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -7800762320186457590) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 16538727) != 0)) {
      setState(703);
      codeItem();
      setState(704);
      match(flicker::SEMICOLON);
      setState(710);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprLambdaBodyContext ------------------------------------------------------------------

flicker::ExprLambdaBodyContext::ExprLambdaBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::ExprLambdaBodyContext::EQ() {
  return getToken(flicker::EQ, 0);
}

flicker::ExpressionContext* flicker::ExprLambdaBodyContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}

flicker::LambdaParamsContext* flicker::ExprLambdaBodyContext::lambdaParams() {
  return getRuleContext<flicker::LambdaParamsContext>(0);
}


size_t flicker::ExprLambdaBodyContext::getRuleIndex() const {
  return flicker::RuleExprLambdaBody;
}

void flicker::ExprLambdaBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprLambdaBody(this);
}

void flicker::ExprLambdaBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprLambdaBody(this);
}


std::any flicker::ExprLambdaBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprLambdaBody(this);
  else
    return visitor->visitChildren(this);
}

flicker::ExprLambdaBodyContext* flicker::exprLambdaBody() {
  ExprLambdaBodyContext *_localctx = _tracker.createInstance<ExprLambdaBodyContext>(_ctx, getState());
  enterRule(_localctx, 124, flicker::RuleExprLambdaBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(712);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::LEFT_PAREN

    || _la == flicker::IDENTIFIER) {
      setState(711);
      lambdaParams();
    }
    setState(714);
    match(flicker::EQ);
    setState(715);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool flicker::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 45: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool flicker::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 21);
    case 1: return precpred(_ctx, 15);
    case 2: return precpred(_ctx, 14);
    case 3: return precpred(_ctx, 12);
    case 4: return precpred(_ctx, 11);
    case 5: return precpred(_ctx, 10);
    case 6: return precpred(_ctx, 9);
    case 7: return precpred(_ctx, 8);
    case 8: return precpred(_ctx, 7);
    case 9: return precpred(_ctx, 6);
    case 10: return precpred(_ctx, 5);
    case 11: return precpred(_ctx, 4);
    case 12: return precpred(_ctx, 3);
    case 13: return precpred(_ctx, 1);
    case 14: return precpred(_ctx, 20);
    case 15: return precpred(_ctx, 19);
    case 16: return precpred(_ctx, 18);
    case 17: return precpred(_ctx, 17);
    case 18: return precpred(_ctx, 16);

  default:
    break;
  }
  return true;
}

void flicker::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  flickerParserInitialize();
#else
  ::antlr4::internal::call_once(flickerParserOnceFlag, flickerParserInitialize);
#endif
}
