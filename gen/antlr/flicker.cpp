
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
      "program", "newline", "codeItem", "type", "statement", "declaration", 
      "namespace", "variableDecl", "typeParam", "functionDecl", "funcReturnType", 
      "functionContents", "paramList", "param", "block", "blockBody", "accessSpecifier", 
      "classDecl", "classBody", "companionNamespace", "classItem", "initializer", 
      "initParamList", "initParam", "superInitParams", "method", "usingStatement", 
      "importList", "importItem", "loopLabel", "doStatement", "blockOrStatement", 
      "ifStmt", "whileStmt", "eachStmt", "forStmt", "breakStmt", "continueStmt", 
      "whenStmt", "returnStmt", "passStmt", "whenBody", "whenContents", 
      "whenCase", "elseCase", "expression", "comparisonOperator", "assignOperator", 
      "interpolationExpr", "constantExpr", "listOrMapLiteral", "listLiteral", 
      "listItems", "mapLiteral", "mapItems", "mapItem", "lambdaLiteral", 
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
      "DO", "EACH", "ELIF", "ELSE", "FALSE", "FOR", "FUN", "IF", "IN", "IS", 
      "NAMESPACE", "NIL", "NOT", "OF", "OR", "OVERRIDE", "PASS", "PRINT", 
      "PRINT_ERROR", "PRIVATE", "RETURN", "STATIC", "SUPER", "THIS", "TRUE", 
      "USING", "VAL", "VAR", "WHEN", "WHILE", "INDENT", "DEDENT", "LINE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,90,735,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
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
  	4,1,4,1,4,3,4,173,8,4,1,5,1,5,1,5,1,5,1,5,3,5,180,8,5,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,5,6,189,8,6,10,6,12,6,192,9,6,1,6,3,6,195,8,6,1,6,1,6,1,7,
  	1,7,1,7,1,7,3,7,203,8,7,1,7,1,7,3,7,207,8,7,1,8,1,8,1,8,1,9,1,9,1,9,3,
  	9,215,8,9,1,9,1,9,3,9,219,8,9,1,9,1,9,3,9,223,8,9,1,9,1,9,1,10,1,10,1,
  	10,1,11,1,11,1,11,3,11,233,8,11,1,12,1,12,1,12,5,12,238,8,12,10,12,12,
  	12,241,9,12,1,13,1,13,1,13,1,13,1,14,3,14,248,8,14,1,14,1,14,1,14,1,14,
  	1,14,1,15,1,15,1,15,5,15,258,8,15,10,15,12,15,261,9,15,1,15,3,15,264,
  	8,15,1,16,1,16,1,17,1,17,1,17,3,17,271,8,17,1,17,1,17,3,17,275,8,17,1,
  	17,1,17,1,17,1,17,1,17,1,18,1,18,1,18,3,18,285,8,18,1,18,1,18,1,18,5,
  	18,290,8,18,10,18,12,18,293,9,18,1,18,3,18,296,8,18,1,19,1,19,1,19,1,
  	19,1,19,1,19,5,19,304,8,19,10,19,12,19,307,9,19,1,19,3,19,310,8,19,1,
  	19,1,19,1,20,1,20,5,20,316,8,20,10,20,12,20,319,9,20,1,20,1,20,3,20,323,
  	8,20,3,20,325,8,20,1,21,1,21,1,21,3,21,330,8,21,1,21,1,21,3,21,334,8,
  	21,1,21,1,21,1,22,1,22,1,22,5,22,341,8,22,10,22,12,22,344,9,22,1,23,3,
  	23,347,8,23,1,23,1,23,1,23,1,23,1,24,1,24,1,24,1,24,5,24,357,8,24,10,
  	24,12,24,360,9,24,3,24,362,8,24,1,24,1,24,1,25,1,25,1,26,1,26,1,26,1,
  	26,1,26,1,26,3,26,374,8,26,3,26,376,8,26,1,26,1,26,1,26,1,26,3,26,382,
  	8,26,1,27,1,27,1,27,5,27,387,8,27,10,27,12,27,390,9,27,1,28,1,28,1,28,
  	1,28,3,28,396,8,28,1,29,1,29,1,29,1,30,1,30,1,30,1,31,1,31,3,31,406,8,
  	31,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,5,32,416,8,32,10,32,12,32,
  	419,9,32,1,32,1,32,1,32,1,32,3,32,425,8,32,1,33,1,33,3,33,429,8,33,1,
  	33,1,33,1,33,1,33,1,33,1,33,3,33,437,8,33,1,34,1,34,3,34,441,8,34,1,34,
  	1,34,1,34,1,34,3,34,447,8,34,1,34,1,34,1,34,1,34,1,35,1,35,3,35,455,8,
  	35,1,35,1,35,3,35,459,8,35,1,35,1,35,3,35,463,8,35,1,35,1,35,3,35,467,
  	8,35,1,35,1,35,1,36,1,36,3,36,473,8,36,1,37,1,37,3,37,477,8,37,1,38,1,
  	38,1,38,1,38,1,39,1,39,3,39,485,8,39,1,40,1,40,1,41,1,41,1,41,1,41,1,
  	41,1,42,1,42,1,42,4,42,497,8,42,11,42,12,42,498,1,42,1,42,3,42,503,8,
  	42,1,42,3,42,506,8,42,1,43,1,43,1,43,1,44,1,44,1,44,1,45,1,45,1,45,1,
  	45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,
  	45,1,45,3,45,533,8,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,
  	45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,
  	45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,3,45,566,8,45,1,45,1,45,1,45,1,
  	45,1,45,3,45,573,8,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,
  	45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,5,
  	45,598,8,45,10,45,12,45,601,9,45,3,45,603,8,45,1,45,1,45,1,45,1,45,1,
  	45,1,45,5,45,611,8,45,10,45,12,45,614,9,45,1,45,1,45,1,45,1,45,1,45,1,
  	45,5,45,622,8,45,10,45,12,45,625,9,45,1,46,1,46,1,47,1,47,1,48,1,48,3,
  	48,633,8,48,4,48,635,8,48,11,48,12,48,636,1,48,1,48,1,49,1,49,1,50,1,
  	50,3,50,645,8,50,1,51,1,51,3,51,649,8,51,1,51,1,51,1,52,1,52,1,52,5,52,
  	656,8,52,10,52,12,52,659,9,52,1,52,3,52,662,8,52,1,53,1,53,1,53,3,53,
  	667,8,53,1,53,1,53,1,54,1,54,1,54,5,54,674,8,54,10,54,12,54,677,9,54,
  	1,54,3,54,680,8,54,1,55,1,55,1,55,1,55,1,56,1,56,1,56,3,56,689,8,56,1,
  	57,1,57,3,57,693,8,57,1,58,1,58,3,58,697,8,58,1,58,1,58,1,59,1,59,1,59,
  	1,59,3,59,705,8,59,1,60,1,60,1,60,3,60,710,8,60,1,60,1,60,1,61,1,61,1,
  	61,3,61,717,8,61,1,61,1,61,1,61,5,61,722,8,61,10,61,12,61,725,9,61,1,
  	62,3,62,728,8,62,1,62,1,62,1,62,3,62,733,8,62,1,62,0,1,90,63,0,2,4,6,
  	8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,
  	56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,
  	102,104,106,108,110,112,114,116,118,120,122,124,0,16,2,0,63,63,71,71,
  	1,0,84,85,2,0,16,16,33,33,2,0,73,73,77,77,4,0,9,9,14,15,19,19,45,45,1,
  	0,75,76,1,0,22,23,3,0,10,10,35,35,37,37,2,0,14,14,18,18,2,0,28,28,31,
  	31,3,0,39,39,41,41,43,43,2,0,21,21,26,26,2,0,15,15,19,19,5,0,27,27,29,
  	30,32,32,46,46,48,48,9,0,12,13,17,17,20,20,36,36,38,38,40,40,42,42,44,
  	44,47,47,5,0,50,50,52,53,62,62,69,69,82,82,796,0,127,1,0,0,0,2,143,1,
  	0,0,0,4,149,1,0,0,0,6,151,1,0,0,0,8,172,1,0,0,0,10,179,1,0,0,0,12,181,
  	1,0,0,0,14,198,1,0,0,0,16,208,1,0,0,0,18,211,1,0,0,0,20,226,1,0,0,0,22,
  	232,1,0,0,0,24,234,1,0,0,0,26,242,1,0,0,0,28,247,1,0,0,0,30,259,1,0,0,
  	0,32,265,1,0,0,0,34,267,1,0,0,0,36,284,1,0,0,0,38,297,1,0,0,0,40,324,
  	1,0,0,0,42,326,1,0,0,0,44,337,1,0,0,0,46,346,1,0,0,0,48,352,1,0,0,0,50,
  	365,1,0,0,0,52,381,1,0,0,0,54,383,1,0,0,0,56,395,1,0,0,0,58,397,1,0,0,
  	0,60,400,1,0,0,0,62,405,1,0,0,0,64,407,1,0,0,0,66,426,1,0,0,0,68,438,
  	1,0,0,0,70,452,1,0,0,0,72,470,1,0,0,0,74,474,1,0,0,0,76,478,1,0,0,0,78,
  	482,1,0,0,0,80,486,1,0,0,0,82,488,1,0,0,0,84,496,1,0,0,0,86,507,1,0,0,
  	0,88,510,1,0,0,0,90,532,1,0,0,0,92,626,1,0,0,0,94,628,1,0,0,0,96,634,
  	1,0,0,0,98,640,1,0,0,0,100,644,1,0,0,0,102,646,1,0,0,0,104,652,1,0,0,
  	0,106,663,1,0,0,0,108,670,1,0,0,0,110,681,1,0,0,0,112,685,1,0,0,0,114,
  	692,1,0,0,0,116,694,1,0,0,0,118,700,1,0,0,0,120,706,1,0,0,0,122,716,1,
  	0,0,0,124,727,1,0,0,0,126,128,3,2,1,0,127,126,1,0,0,0,127,128,1,0,0,0,
  	128,134,1,0,0,0,129,130,3,4,2,0,130,131,3,2,1,0,131,133,1,0,0,0,132,129,
  	1,0,0,0,133,136,1,0,0,0,134,132,1,0,0,0,134,135,1,0,0,0,135,138,1,0,0,
  	0,136,134,1,0,0,0,137,139,3,4,2,0,138,137,1,0,0,0,138,139,1,0,0,0,139,
  	140,1,0,0,0,140,141,5,0,0,1,141,1,1,0,0,0,142,144,5,90,0,0,143,142,1,
  	0,0,0,144,145,1,0,0,0,145,143,1,0,0,0,145,146,1,0,0,0,146,3,1,0,0,0,147,
  	150,3,8,4,0,148,150,3,90,45,0,149,147,1,0,0,0,149,148,1,0,0,0,150,5,1,
  	0,0,0,151,153,5,49,0,0,152,154,5,24,0,0,153,152,1,0,0,0,153,154,1,0,0,
  	0,154,160,1,0,0,0,155,156,7,0,0,0,156,158,5,49,0,0,157,159,5,24,0,0,158,
  	157,1,0,0,0,158,159,1,0,0,0,159,161,1,0,0,0,160,155,1,0,0,0,160,161,1,
  	0,0,0,161,7,1,0,0,0,162,173,3,10,5,0,163,173,3,64,32,0,164,173,3,66,33,
  	0,165,173,3,68,34,0,166,173,3,70,35,0,167,173,3,72,36,0,168,173,3,74,
  	37,0,169,173,3,76,38,0,170,173,3,78,39,0,171,173,3,80,40,0,172,162,1,
  	0,0,0,172,163,1,0,0,0,172,164,1,0,0,0,172,165,1,0,0,0,172,166,1,0,0,0,
  	172,167,1,0,0,0,172,168,1,0,0,0,172,169,1,0,0,0,172,170,1,0,0,0,172,171,
  	1,0,0,0,173,9,1,0,0,0,174,180,3,14,7,0,175,180,3,18,9,0,176,180,3,34,
  	17,0,177,180,3,52,26,0,178,180,3,12,6,0,179,174,1,0,0,0,179,175,1,0,0,
  	0,179,176,1,0,0,0,179,177,1,0,0,0,179,178,1,0,0,0,180,11,1,0,0,0,181,
  	182,5,68,0,0,182,183,5,49,0,0,183,184,3,2,1,0,184,190,5,88,0,0,185,186,
  	3,10,5,0,186,187,3,2,1,0,187,189,1,0,0,0,188,185,1,0,0,0,189,192,1,0,
  	0,0,190,188,1,0,0,0,190,191,1,0,0,0,191,194,1,0,0,0,192,190,1,0,0,0,193,
  	195,3,10,5,0,194,193,1,0,0,0,194,195,1,0,0,0,195,196,1,0,0,0,196,197,
  	5,89,0,0,197,13,1,0,0,0,198,199,7,1,0,0,199,202,5,49,0,0,200,201,5,33,
  	0,0,201,203,3,6,3,0,202,200,1,0,0,0,202,203,1,0,0,0,203,206,1,0,0,0,204,
  	205,5,47,0,0,205,207,3,90,45,0,206,204,1,0,0,0,206,207,1,0,0,0,207,15,
  	1,0,0,0,208,209,7,0,0,0,209,210,5,49,0,0,210,17,1,0,0,0,211,212,5,64,
  	0,0,212,214,5,49,0,0,213,215,3,16,8,0,214,213,1,0,0,0,214,215,1,0,0,0,
  	215,216,1,0,0,0,216,218,5,1,0,0,217,219,3,24,12,0,218,217,1,0,0,0,218,
  	219,1,0,0,0,219,220,1,0,0,0,220,222,5,2,0,0,221,223,3,20,10,0,222,221,
  	1,0,0,0,222,223,1,0,0,0,223,224,1,0,0,0,224,225,3,22,11,0,225,19,1,0,
  	0,0,226,227,7,2,0,0,227,228,5,49,0,0,228,21,1,0,0,0,229,233,3,62,31,0,
  	230,231,5,47,0,0,231,233,3,90,45,0,232,229,1,0,0,0,232,230,1,0,0,0,233,
  	23,1,0,0,0,234,239,3,26,13,0,235,236,5,8,0,0,236,238,3,26,13,0,237,235,
  	1,0,0,0,238,241,1,0,0,0,239,237,1,0,0,0,239,240,1,0,0,0,240,25,1,0,0,
  	0,241,239,1,0,0,0,242,243,5,49,0,0,243,244,5,33,0,0,244,245,3,6,3,0,245,
  	27,1,0,0,0,246,248,5,58,0,0,247,246,1,0,0,0,247,248,1,0,0,0,248,249,1,
  	0,0,0,249,250,3,2,1,0,250,251,5,88,0,0,251,252,3,30,15,0,252,253,5,89,
  	0,0,253,29,1,0,0,0,254,255,3,4,2,0,255,256,3,2,1,0,256,258,1,0,0,0,257,
  	254,1,0,0,0,258,261,1,0,0,0,259,257,1,0,0,0,259,260,1,0,0,0,260,263,1,
  	0,0,0,261,259,1,0,0,0,262,264,3,4,2,0,263,262,1,0,0,0,263,264,1,0,0,0,
  	264,31,1,0,0,0,265,266,7,3,0,0,266,33,1,0,0,0,267,268,5,56,0,0,268,270,
  	5,49,0,0,269,271,3,16,8,0,270,269,1,0,0,0,270,271,1,0,0,0,271,274,1,0,
  	0,0,272,273,5,67,0,0,273,275,3,6,3,0,274,272,1,0,0,0,274,275,1,0,0,0,
  	275,276,1,0,0,0,276,277,3,2,1,0,277,278,5,88,0,0,278,279,3,36,18,0,279,
  	280,5,89,0,0,280,35,1,0,0,0,281,282,3,38,19,0,282,283,3,2,1,0,283,285,
  	1,0,0,0,284,281,1,0,0,0,284,285,1,0,0,0,285,291,1,0,0,0,286,287,3,40,
  	20,0,287,288,3,2,1,0,288,290,1,0,0,0,289,286,1,0,0,0,290,293,1,0,0,0,
  	291,289,1,0,0,0,291,292,1,0,0,0,292,295,1,0,0,0,293,291,1,0,0,0,294,296,
  	3,40,20,0,295,294,1,0,0,0,295,296,1,0,0,0,296,37,1,0,0,0,297,298,5,68,
  	0,0,298,299,3,2,1,0,299,305,5,88,0,0,300,301,3,40,20,0,301,302,3,2,1,
  	0,302,304,1,0,0,0,303,300,1,0,0,0,304,307,1,0,0,0,305,303,1,0,0,0,305,
  	306,1,0,0,0,306,309,1,0,0,0,307,305,1,0,0,0,308,310,3,40,20,0,309,308,
  	1,0,0,0,309,310,1,0,0,0,310,311,1,0,0,0,311,312,5,89,0,0,312,39,1,0,0,
  	0,313,325,3,42,21,0,314,316,3,32,16,0,315,314,1,0,0,0,316,319,1,0,0,0,
  	317,315,1,0,0,0,317,318,1,0,0,0,318,322,1,0,0,0,319,317,1,0,0,0,320,323,
  	3,14,7,0,321,323,3,50,25,0,322,320,1,0,0,0,322,321,1,0,0,0,323,325,1,
  	0,0,0,324,313,1,0,0,0,324,317,1,0,0,0,325,41,1,0,0,0,326,327,5,49,0,0,
  	327,329,5,1,0,0,328,330,3,44,22,0,329,328,1,0,0,0,329,330,1,0,0,0,330,
  	331,1,0,0,0,331,333,5,2,0,0,332,334,3,48,24,0,333,332,1,0,0,0,333,334,
  	1,0,0,0,334,335,1,0,0,0,335,336,3,62,31,0,336,43,1,0,0,0,337,342,3,46,
  	23,0,338,339,5,8,0,0,339,341,3,46,23,0,340,338,1,0,0,0,341,344,1,0,0,
  	0,342,340,1,0,0,0,342,343,1,0,0,0,343,45,1,0,0,0,344,342,1,0,0,0,345,
  	347,7,1,0,0,346,345,1,0,0,0,346,347,1,0,0,0,347,348,1,0,0,0,348,349,5,
  	49,0,0,349,350,5,33,0,0,350,351,3,6,3,0,351,47,1,0,0,0,352,361,5,5,0,
  	0,353,358,3,90,45,0,354,355,5,8,0,0,355,357,3,90,45,0,356,354,1,0,0,0,
  	357,360,1,0,0,0,358,356,1,0,0,0,358,359,1,0,0,0,359,362,1,0,0,0,360,358,
  	1,0,0,0,361,353,1,0,0,0,361,362,1,0,0,0,362,363,1,0,0,0,363,364,5,6,0,
  	0,364,49,1,0,0,0,365,366,3,18,9,0,366,51,1,0,0,0,367,368,5,83,0,0,368,
  	375,5,50,0,0,369,373,5,63,0,0,370,374,5,21,0,0,371,374,5,10,0,0,372,374,
  	3,54,27,0,373,370,1,0,0,0,373,371,1,0,0,0,373,372,1,0,0,0,374,376,1,0,
  	0,0,375,369,1,0,0,0,375,376,1,0,0,0,376,382,1,0,0,0,377,378,5,83,0,0,
  	378,379,5,49,0,0,379,380,5,47,0,0,380,382,3,6,3,0,381,367,1,0,0,0,381,
  	377,1,0,0,0,382,53,1,0,0,0,383,388,3,56,28,0,384,385,5,8,0,0,385,387,
  	3,56,28,0,386,384,1,0,0,0,387,390,1,0,0,0,388,386,1,0,0,0,388,389,1,0,
  	0,0,389,55,1,0,0,0,390,388,1,0,0,0,391,396,5,49,0,0,392,393,5,49,0,0,
  	393,394,5,16,0,0,394,396,5,49,0,0,395,391,1,0,0,0,395,392,1,0,0,0,396,
  	57,1,0,0,0,397,398,5,33,0,0,398,399,5,49,0,0,399,59,1,0,0,0,400,401,5,
  	58,0,0,401,402,3,4,2,0,402,61,1,0,0,0,403,406,3,28,14,0,404,406,3,60,
  	30,0,405,403,1,0,0,0,405,404,1,0,0,0,406,63,1,0,0,0,407,408,5,65,0,0,
  	408,409,3,90,45,0,409,417,3,62,31,0,410,411,3,2,1,0,411,412,5,60,0,0,
  	412,413,3,90,45,0,413,414,3,62,31,0,414,416,1,0,0,0,415,410,1,0,0,0,416,
  	419,1,0,0,0,417,415,1,0,0,0,417,418,1,0,0,0,418,424,1,0,0,0,419,417,1,
  	0,0,0,420,421,3,2,1,0,421,422,5,61,0,0,422,423,3,62,31,0,423,425,1,0,
  	0,0,424,420,1,0,0,0,424,425,1,0,0,0,425,65,1,0,0,0,426,428,5,87,0,0,427,
  	429,3,58,29,0,428,427,1,0,0,0,428,429,1,0,0,0,429,430,1,0,0,0,430,431,
  	3,90,45,0,431,436,3,62,31,0,432,433,3,2,1,0,433,434,5,61,0,0,434,435,
  	3,62,31,0,435,437,1,0,0,0,436,432,1,0,0,0,436,437,1,0,0,0,437,67,1,0,
  	0,0,438,440,5,59,0,0,439,441,3,58,29,0,440,439,1,0,0,0,440,441,1,0,0,
  	0,441,442,1,0,0,0,442,446,5,49,0,0,443,444,5,3,0,0,444,445,5,49,0,0,445,
  	447,5,4,0,0,446,443,1,0,0,0,446,447,1,0,0,0,447,448,1,0,0,0,448,449,5,
  	66,0,0,449,450,3,90,45,0,450,451,3,62,31,0,451,69,1,0,0,0,452,454,5,63,
  	0,0,453,455,3,58,29,0,454,453,1,0,0,0,454,455,1,0,0,0,455,458,1,0,0,0,
  	456,459,3,14,7,0,457,459,3,90,45,0,458,456,1,0,0,0,458,457,1,0,0,0,458,
  	459,1,0,0,0,459,460,1,0,0,0,460,462,5,7,0,0,461,463,3,90,45,0,462,461,
  	1,0,0,0,462,463,1,0,0,0,463,464,1,0,0,0,464,466,5,7,0,0,465,467,3,90,
  	45,0,466,465,1,0,0,0,466,467,1,0,0,0,467,468,1,0,0,0,468,469,3,62,31,
  	0,469,71,1,0,0,0,470,472,5,55,0,0,471,473,3,58,29,0,472,471,1,0,0,0,472,
  	473,1,0,0,0,473,73,1,0,0,0,474,476,5,57,0,0,475,477,3,58,29,0,476,475,
  	1,0,0,0,476,477,1,0,0,0,477,75,1,0,0,0,478,479,5,86,0,0,479,480,3,90,
  	45,0,480,481,3,82,41,0,481,77,1,0,0,0,482,484,5,78,0,0,483,485,3,90,45,
  	0,484,483,1,0,0,0,484,485,1,0,0,0,485,79,1,0,0,0,486,487,5,74,0,0,487,
  	81,1,0,0,0,488,489,3,2,1,0,489,490,5,88,0,0,490,491,3,84,42,0,491,492,
  	5,89,0,0,492,83,1,0,0,0,493,494,3,86,43,0,494,495,3,2,1,0,495,497,1,0,
  	0,0,496,493,1,0,0,0,497,498,1,0,0,0,498,496,1,0,0,0,498,499,1,0,0,0,499,
  	502,1,0,0,0,500,503,3,86,43,0,501,503,3,88,44,0,502,500,1,0,0,0,502,501,
  	1,0,0,0,502,503,1,0,0,0,503,505,1,0,0,0,504,506,3,2,1,0,505,504,1,0,0,
  	0,505,506,1,0,0,0,506,85,1,0,0,0,507,508,3,90,45,0,508,509,3,62,31,0,
  	509,87,1,0,0,0,510,511,5,61,0,0,511,512,3,62,31,0,512,89,1,0,0,0,513,
  	514,6,45,-1,0,514,515,5,49,0,0,515,516,5,34,0,0,516,533,5,49,0,0,517,
  	533,5,49,0,0,518,533,3,98,49,0,519,533,3,96,48,0,520,533,3,100,50,0,521,
  	533,3,112,56,0,522,523,5,1,0,0,523,524,3,90,45,0,524,525,5,2,0,0,525,
  	533,1,0,0,0,526,527,7,4,0,0,527,533,3,90,45,14,528,529,5,70,0,0,529,533,
  	3,90,45,3,530,531,7,5,0,0,531,533,3,90,45,1,532,513,1,0,0,0,532,517,1,
  	0,0,0,532,518,1,0,0,0,532,519,1,0,0,0,532,520,1,0,0,0,532,521,1,0,0,0,
  	532,522,1,0,0,0,532,526,1,0,0,0,532,528,1,0,0,0,532,530,1,0,0,0,533,623,
  	1,0,0,0,534,535,10,22,0,0,535,536,7,6,0,0,536,622,3,90,45,23,537,538,
  	10,16,0,0,538,539,5,25,0,0,539,622,3,90,45,17,540,541,10,15,0,0,541,542,
  	5,11,0,0,542,622,3,90,45,15,543,544,10,13,0,0,544,545,7,7,0,0,545,622,
  	3,90,45,14,546,547,10,12,0,0,547,548,7,8,0,0,548,622,3,90,45,13,549,550,
  	10,11,0,0,550,551,7,9,0,0,551,622,3,90,45,12,552,553,10,10,0,0,553,554,
  	7,10,0,0,554,622,3,90,45,11,555,556,10,9,0,0,556,557,5,65,0,0,557,558,
  	3,90,45,0,558,559,5,61,0,0,559,560,3,90,45,10,560,622,1,0,0,0,561,565,
  	10,8,0,0,562,566,5,67,0,0,563,564,5,67,0,0,564,566,5,70,0,0,565,562,1,
  	0,0,0,565,563,1,0,0,0,566,567,1,0,0,0,567,622,3,90,45,9,568,572,10,7,
  	0,0,569,573,5,66,0,0,570,571,5,70,0,0,571,573,5,66,0,0,572,569,1,0,0,
  	0,572,570,1,0,0,0,573,574,1,0,0,0,574,622,3,90,45,8,575,576,10,6,0,0,
  	576,577,3,92,46,0,577,578,3,90,45,7,578,622,1,0,0,0,579,580,10,5,0,0,
  	580,581,5,54,0,0,581,622,3,90,45,6,582,583,10,4,0,0,583,584,5,72,0,0,
  	584,622,3,90,45,5,585,586,10,2,0,0,586,587,3,94,47,0,587,588,3,90,45,
  	2,588,622,1,0,0,0,589,590,10,21,0,0,590,591,7,11,0,0,591,622,5,49,0,0,
  	592,593,10,20,0,0,593,602,5,1,0,0,594,599,3,90,45,0,595,596,5,8,0,0,596,
  	598,3,90,45,0,597,595,1,0,0,0,598,601,1,0,0,0,599,597,1,0,0,0,599,600,
  	1,0,0,0,600,603,1,0,0,0,601,599,1,0,0,0,602,594,1,0,0,0,602,603,1,0,0,
  	0,603,604,1,0,0,0,604,622,5,2,0,0,605,606,10,19,0,0,606,607,5,3,0,0,607,
  	612,3,90,45,0,608,609,5,8,0,0,609,611,3,90,45,0,610,608,1,0,0,0,611,614,
  	1,0,0,0,612,610,1,0,0,0,612,613,1,0,0,0,613,615,1,0,0,0,614,612,1,0,0,
  	0,615,616,5,4,0,0,616,622,1,0,0,0,617,618,10,18,0,0,618,622,3,120,60,
  	0,619,620,10,17,0,0,620,622,7,12,0,0,621,534,1,0,0,0,621,537,1,0,0,0,
  	621,540,1,0,0,0,621,543,1,0,0,0,621,546,1,0,0,0,621,549,1,0,0,0,621,552,
  	1,0,0,0,621,555,1,0,0,0,621,561,1,0,0,0,621,568,1,0,0,0,621,575,1,0,0,
  	0,621,579,1,0,0,0,621,582,1,0,0,0,621,585,1,0,0,0,621,589,1,0,0,0,621,
  	592,1,0,0,0,621,605,1,0,0,0,621,617,1,0,0,0,621,619,1,0,0,0,622,625,1,
  	0,0,0,623,621,1,0,0,0,623,624,1,0,0,0,624,91,1,0,0,0,625,623,1,0,0,0,
  	626,627,7,13,0,0,627,93,1,0,0,0,628,629,7,14,0,0,629,95,1,0,0,0,630,632,
  	5,51,0,0,631,633,3,90,45,0,632,631,1,0,0,0,632,633,1,0,0,0,633,635,1,
  	0,0,0,634,630,1,0,0,0,635,636,1,0,0,0,636,634,1,0,0,0,636,637,1,0,0,0,
  	637,638,1,0,0,0,638,639,5,50,0,0,639,97,1,0,0,0,640,641,7,15,0,0,641,
  	99,1,0,0,0,642,645,3,102,51,0,643,645,3,106,53,0,644,642,1,0,0,0,644,
  	643,1,0,0,0,645,101,1,0,0,0,646,648,5,3,0,0,647,649,3,104,52,0,648,647,
  	1,0,0,0,648,649,1,0,0,0,649,650,1,0,0,0,650,651,5,4,0,0,651,103,1,0,0,
  	0,652,657,3,90,45,0,653,654,5,8,0,0,654,656,3,90,45,0,655,653,1,0,0,0,
  	656,659,1,0,0,0,657,655,1,0,0,0,657,658,1,0,0,0,658,661,1,0,0,0,659,657,
  	1,0,0,0,660,662,5,8,0,0,661,660,1,0,0,0,661,662,1,0,0,0,662,105,1,0,0,
  	0,663,666,5,3,0,0,664,667,5,16,0,0,665,667,3,108,54,0,666,664,1,0,0,0,
  	666,665,1,0,0,0,667,668,1,0,0,0,668,669,5,4,0,0,669,107,1,0,0,0,670,675,
  	3,110,55,0,671,672,5,8,0,0,672,674,3,110,55,0,673,671,1,0,0,0,674,677,
  	1,0,0,0,675,673,1,0,0,0,675,676,1,0,0,0,676,679,1,0,0,0,677,675,1,0,0,
  	0,678,680,5,8,0,0,679,678,1,0,0,0,679,680,1,0,0,0,680,109,1,0,0,0,681,
  	682,3,90,45,0,682,683,5,16,0,0,683,684,3,90,45,0,684,111,1,0,0,0,685,
  	688,5,64,0,0,686,689,3,120,60,0,687,689,3,118,59,0,688,686,1,0,0,0,688,
  	687,1,0,0,0,689,113,1,0,0,0,690,693,3,24,12,0,691,693,3,116,58,0,692,
  	690,1,0,0,0,692,691,1,0,0,0,693,115,1,0,0,0,694,696,5,1,0,0,695,697,3,
  	24,12,0,696,695,1,0,0,0,696,697,1,0,0,0,697,698,1,0,0,0,698,699,5,2,0,
  	0,699,117,1,0,0,0,700,704,3,114,57,0,701,705,3,62,31,0,702,703,5,47,0,
  	0,703,705,3,90,45,0,704,701,1,0,0,0,704,702,1,0,0,0,705,119,1,0,0,0,706,
  	709,5,5,0,0,707,710,3,122,61,0,708,710,3,124,62,0,709,707,1,0,0,0,709,
  	708,1,0,0,0,710,711,1,0,0,0,711,712,5,6,0,0,712,121,1,0,0,0,713,714,3,
  	114,57,0,714,715,5,16,0,0,715,717,1,0,0,0,716,713,1,0,0,0,716,717,1,0,
  	0,0,717,723,1,0,0,0,718,719,3,4,2,0,719,720,5,7,0,0,720,722,1,0,0,0,721,
  	718,1,0,0,0,722,725,1,0,0,0,723,721,1,0,0,0,723,724,1,0,0,0,724,123,1,
  	0,0,0,725,723,1,0,0,0,726,728,3,114,57,0,727,726,1,0,0,0,727,728,1,0,
  	0,0,728,729,1,0,0,0,729,730,5,47,0,0,730,732,3,90,45,0,731,733,5,7,0,
  	0,732,731,1,0,0,0,732,733,1,0,0,0,733,125,1,0,0,0,86,127,134,138,145,
  	149,153,158,160,172,179,190,194,202,206,214,218,222,232,239,247,259,263,
  	270,274,284,291,295,305,309,317,322,324,329,333,342,346,358,361,373,375,
  	381,388,395,405,417,424,428,436,440,446,454,458,462,466,472,476,484,498,
  	502,505,532,565,572,599,602,612,621,623,632,636,644,648,657,661,666,675,
  	679,688,692,696,704,709,716,723,727,732
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
      ((1ULL << _la) & -3765537054062493174) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 16538739) != 0)) {
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

flicker::DeclarationContext* flicker::StatementContext::declaration() {
  return getRuleContext<flicker::DeclarationContext>(0);
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
    setState(172);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::CLASS:
      case flicker::FUN:
      case flicker::NAMESPACE:
      case flicker::USING:
      case flicker::VAL:
      case flicker::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(162);
        declaration();
        break;
      }

      case flicker::IF: {
        enterOuterAlt(_localctx, 2);
        setState(163);
        ifStmt();
        break;
      }

      case flicker::WHILE: {
        enterOuterAlt(_localctx, 3);
        setState(164);
        whileStmt();
        break;
      }

      case flicker::EACH: {
        enterOuterAlt(_localctx, 4);
        setState(165);
        eachStmt();
        break;
      }

      case flicker::FOR: {
        enterOuterAlt(_localctx, 5);
        setState(166);
        forStmt();
        break;
      }

      case flicker::BREAK: {
        enterOuterAlt(_localctx, 6);
        setState(167);
        breakStmt();
        break;
      }

      case flicker::CONTINUE: {
        enterOuterAlt(_localctx, 7);
        setState(168);
        continueStmt();
        break;
      }

      case flicker::WHEN: {
        enterOuterAlt(_localctx, 8);
        setState(169);
        whenStmt();
        break;
      }

      case flicker::RETURN: {
        enterOuterAlt(_localctx, 9);
        setState(170);
        returnStmt();
        break;
      }

      case flicker::PASS: {
        enterOuterAlt(_localctx, 10);
        setState(171);
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

//----------------- DeclarationContext ------------------------------------------------------------------

flicker::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

flicker::VariableDeclContext* flicker::DeclarationContext::variableDecl() {
  return getRuleContext<flicker::VariableDeclContext>(0);
}

flicker::FunctionDeclContext* flicker::DeclarationContext::functionDecl() {
  return getRuleContext<flicker::FunctionDeclContext>(0);
}

flicker::ClassDeclContext* flicker::DeclarationContext::classDecl() {
  return getRuleContext<flicker::ClassDeclContext>(0);
}

flicker::UsingStatementContext* flicker::DeclarationContext::usingStatement() {
  return getRuleContext<flicker::UsingStatementContext>(0);
}

flicker::NamespaceContext* flicker::DeclarationContext::namespace_() {
  return getRuleContext<flicker::NamespaceContext>(0);
}


size_t flicker::DeclarationContext::getRuleIndex() const {
  return flicker::RuleDeclaration;
}

void flicker::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void flicker::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


std::any flicker::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

flicker::DeclarationContext* flicker::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 10, flicker::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(179);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::VAL:
      case flicker::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(174);
        variableDecl();
        break;
      }

      case flicker::FUN: {
        enterOuterAlt(_localctx, 2);
        setState(175);
        functionDecl();
        break;
      }

      case flicker::CLASS: {
        enterOuterAlt(_localctx, 3);
        setState(176);
        classDecl();
        break;
      }

      case flicker::USING: {
        enterOuterAlt(_localctx, 4);
        setState(177);
        usingStatement();
        break;
      }

      case flicker::NAMESPACE: {
        enterOuterAlt(_localctx, 5);
        setState(178);
        namespace_();
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

//----------------- NamespaceContext ------------------------------------------------------------------

flicker::NamespaceContext::NamespaceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::NamespaceContext::NAMESPACE() {
  return getToken(flicker::NAMESPACE, 0);
}

tree::TerminalNode* flicker::NamespaceContext::IDENTIFIER() {
  return getToken(flicker::IDENTIFIER, 0);
}

std::vector<flicker::NewlineContext *> flicker::NamespaceContext::newline() {
  return getRuleContexts<flicker::NewlineContext>();
}

flicker::NewlineContext* flicker::NamespaceContext::newline(size_t i) {
  return getRuleContext<flicker::NewlineContext>(i);
}

tree::TerminalNode* flicker::NamespaceContext::INDENT() {
  return getToken(flicker::INDENT, 0);
}

tree::TerminalNode* flicker::NamespaceContext::DEDENT() {
  return getToken(flicker::DEDENT, 0);
}

std::vector<flicker::DeclarationContext *> flicker::NamespaceContext::declaration() {
  return getRuleContexts<flicker::DeclarationContext>();
}

flicker::DeclarationContext* flicker::NamespaceContext::declaration(size_t i) {
  return getRuleContext<flicker::DeclarationContext>(i);
}


size_t flicker::NamespaceContext::getRuleIndex() const {
  return flicker::RuleNamespace;
}

void flicker::NamespaceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamespace(this);
}

void flicker::NamespaceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamespace(this);
}


std::any flicker::NamespaceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitNamespace(this);
  else
    return visitor->visitChildren(this);
}

flicker::NamespaceContext* flicker::namespace_() {
  NamespaceContext *_localctx = _tracker.createInstance<NamespaceContext>(_ctx, getState());
  enterRule(_localctx, 12, flicker::RuleNamespace);
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
    setState(181);
    match(flicker::NAMESPACE);
    setState(182);
    match(flicker::IDENTIFIER);
    setState(183);
    newline();
    setState(184);
    match(flicker::INDENT);
    setState(190);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(185);
        declaration();
        setState(186);
        newline(); 
      }
      setState(192);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
    setState(194);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 56) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 56)) & 939528449) != 0)) {
      setState(193);
      declaration();
    }
    setState(196);
    match(flicker::DEDENT);
   
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
  enterRule(_localctx, 14, flicker::RuleVariableDecl);
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
    setState(198);
    _la = _input->LA(1);
    if (!(_la == flicker::VAL

    || _la == flicker::VAR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(199);
    match(flicker::IDENTIFIER);
    setState(202);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(200);
      match(flicker::COLON);
      setState(201);
      type();
      break;
    }

    default:
      break;
    }
    setState(206);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(204);
      match(flicker::EQ);
      setState(205);
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
  enterRule(_localctx, 16, flicker::RuleTypeParam);
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
    setState(208);
    _la = _input->LA(1);
    if (!(_la == flicker::FOR

    || _la == flicker::OF)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(209);
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
  enterRule(_localctx, 18, flicker::RuleFunctionDecl);
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
    setState(211);
    match(flicker::FUN);
    setState(212);
    match(flicker::IDENTIFIER);
    setState(214);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::FOR

    || _la == flicker::OF) {
      setState(213);
      typeParam();
    }
    setState(216);
    match(flicker::LEFT_PAREN);
    setState(218);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::IDENTIFIER) {
      setState(217);
      paramList();
    }
    setState(220);
    match(flicker::RIGHT_PAREN);
    setState(222);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::RIGHT_ARROW

    || _la == flicker::COLON) {
      setState(221);
      funcReturnType();
    }
    setState(224);
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
  enterRule(_localctx, 20, flicker::RuleFuncReturnType);
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
    setState(226);
    _la = _input->LA(1);
    if (!(_la == flicker::RIGHT_ARROW

    || _la == flicker::COLON)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(227);
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
  enterRule(_localctx, 22, flicker::RuleFunctionContents);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(232);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::DO:
      case flicker::LINE: {
        enterOuterAlt(_localctx, 1);
        setState(229);
        blockOrStatement();
        break;
      }

      case flicker::EQ: {
        enterOuterAlt(_localctx, 2);
        setState(230);
        match(flicker::EQ);
        setState(231);
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
  enterRule(_localctx, 24, flicker::RuleParamList);
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
    setState(234);
    param();
    setState(239);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == flicker::COMMA) {
      setState(235);
      match(flicker::COMMA);
      setState(236);
      param();
      setState(241);
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
  enterRule(_localctx, 26, flicker::RuleParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(242);
    match(flicker::IDENTIFIER);
    setState(243);
    match(flicker::COLON);
    setState(244);
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
  enterRule(_localctx, 28, flicker::RuleBlock);
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
    setState(247);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::DO) {
      setState(246);
      match(flicker::DO);
    }
    setState(249);
    newline();
    setState(250);
    match(flicker::INDENT);
    setState(251);
    blockBody();
    setState(252);
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
  enterRule(_localctx, 30, flicker::RuleBlockBody);
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
    setState(259);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(254);
        codeItem();
        setState(255);
        newline(); 
      }
      setState(261);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
    setState(263);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -3765537054062493174) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 16538739) != 0)) {
      setState(262);
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
  enterRule(_localctx, 32, flicker::RuleAccessSpecifier);
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
    setState(265);
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
  enterRule(_localctx, 34, flicker::RuleClassDecl);
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
    setState(267);
    match(flicker::CLASS);
    setState(268);
    match(flicker::IDENTIFIER);
    setState(270);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::FOR

    || _la == flicker::OF) {
      setState(269);
      typeParam();
    }
    setState(274);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::IS) {
      setState(272);
      match(flicker::IS);
      setState(273);
      type();
    }
    setState(276);
    newline();
    setState(277);
    match(flicker::INDENT);
    setState(278);
    classBody();
    setState(279);
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
  enterRule(_localctx, 36, flicker::RuleClassBody);
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
    setState(284);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::NAMESPACE) {
      setState(281);
      companionNamespace();
      setState(282);
      newline();
    }
    setState(291);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(286);
        classItem();
        setState(287);
        newline(); 
      }
      setState(293);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
    setState(295);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 49) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 49)) & 103364460545) != 0)) {
      setState(294);
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

tree::TerminalNode* flicker::CompanionNamespaceContext::NAMESPACE() {
  return getToken(flicker::NAMESPACE, 0);
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
  enterRule(_localctx, 38, flicker::RuleCompanionNamespace);
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
    setState(297);
    match(flicker::NAMESPACE);
    setState(298);
    newline();
    setState(299);
    match(flicker::INDENT);
    setState(305);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(300);
        classItem();
        setState(301);
        newline(); 
      }
      setState(307);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
    setState(309);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 49) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 49)) & 103364460545) != 0)) {
      setState(308);
      classItem();
    }
    setState(311);
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
  enterRule(_localctx, 40, flicker::RuleClassItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(324);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(313);
        initializer();
        break;
      }

      case flicker::FUN:
      case flicker::OVERRIDE:
      case flicker::PRIVATE:
      case flicker::VAL:
      case flicker::VAR: {
        enterOuterAlt(_localctx, 2);
        setState(317);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == flicker::OVERRIDE

        || _la == flicker::PRIVATE) {
          setState(314);
          accessSpecifier();
          setState(319);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(322);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case flicker::VAL:
          case flicker::VAR: {
            setState(320);
            variableDecl();
            break;
          }

          case flicker::FUN: {
            setState(321);
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
  enterRule(_localctx, 42, flicker::RuleInitializer);
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
    setState(326);
    match(flicker::IDENTIFIER);
    setState(327);
    match(flicker::LEFT_PAREN);
    setState(329);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 49) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 49)) & 103079215105) != 0)) {
      setState(328);
      initParamList();
    }
    setState(331);
    match(flicker::RIGHT_PAREN);
    setState(333);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::LEFT_BRACE) {
      setState(332);
      superInitParams();
    }
    setState(335);
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
  enterRule(_localctx, 44, flicker::RuleInitParamList);
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
    setState(337);
    initParam();
    setState(342);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == flicker::COMMA) {
      setState(338);
      match(flicker::COMMA);
      setState(339);
      initParam();
      setState(344);
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
  enterRule(_localctx, 46, flicker::RuleInitParam);
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
    setState(346);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::VAL

    || _la == flicker::VAR) {
      setState(345);
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
    setState(348);
    match(flicker::IDENTIFIER);
    setState(349);
    match(flicker::COLON);
    setState(350);
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
  enterRule(_localctx, 48, flicker::RuleSuperInitParams);
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
    setState(352);
    match(flicker::LEFT_BRACE);
    setState(361);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4629172651356111370) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 268385) != 0)) {
      setState(353);
      expression(0);
      setState(358);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == flicker::COMMA) {
        setState(354);
        match(flicker::COMMA);
        setState(355);
        expression(0);
        setState(360);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(363);
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
  enterRule(_localctx, 50, flicker::RuleMethod);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(365);
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
  enterRule(_localctx, 52, flicker::RuleUsingStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(381);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(367);
      match(flicker::USING);
      setState(368);
      match(flicker::STRING);
      setState(375);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
      case 1: {
        setState(369);
        match(flicker::FOR);
        setState(373);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case flicker::DOT: {
            setState(370);
            match(flicker::DOT);
            break;
          }

          case flicker::STAR: {
            setState(371);
            match(flicker::STAR);
            break;
          }

          case flicker::IDENTIFIER: {
            setState(372);
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
      setState(377);
      match(flicker::USING);
      setState(378);
      match(flicker::IDENTIFIER);
      setState(379);
      match(flicker::EQ);
      setState(380);
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
  enterRule(_localctx, 54, flicker::RuleImportList);

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
    setState(383);
    importItem();
    setState(388);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(384);
        match(flicker::COMMA);
        setState(385);
        importItem(); 
      }
      setState(390);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
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
  enterRule(_localctx, 56, flicker::RuleImportItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(395);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(391);
      match(flicker::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(392);
      match(flicker::IDENTIFIER);
      setState(393);
      match(flicker::RIGHT_ARROW);
      setState(394);
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
  enterRule(_localctx, 58, flicker::RuleLoopLabel);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(397);
    match(flicker::COLON);
    setState(398);
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
  enterRule(_localctx, 60, flicker::RuleDoStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(400);
    match(flicker::DO);
    setState(401);
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
  enterRule(_localctx, 62, flicker::RuleBlockOrStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(405);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(403);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(404);
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
  enterRule(_localctx, 64, flicker::RuleIfStmt);

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
    setState(407);
    match(flicker::IF);
    setState(408);
    expression(0);
    setState(409);
    blockOrStatement();
    setState(417);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(410);
        newline();
        setState(411);
        match(flicker::ELIF);
        setState(412);
        expression(0);
        setState(413);
        blockOrStatement(); 
      }
      setState(419);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    }
    setState(424);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      setState(420);
      newline();
      setState(421);
      match(flicker::ELSE);
      setState(422);
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
  enterRule(_localctx, 66, flicker::RuleWhileStmt);
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
    setState(426);
    match(flicker::WHILE);
    setState(428);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(427);
      loopLabel();
    }
    setState(430);
    expression(0);
    setState(431);
    blockOrStatement();
    setState(436);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      setState(432);
      newline();
      setState(433);
      match(flicker::ELSE);
      setState(434);
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
  enterRule(_localctx, 68, flicker::RuleEachStmt);
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
    setState(438);
    match(flicker::EACH);
    setState(440);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(439);
      loopLabel();
    }
    setState(442);
    match(flicker::IDENTIFIER);
    setState(446);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::LEFT_BRACKET) {
      setState(443);
      match(flicker::LEFT_BRACKET);
      setState(444);
      match(flicker::IDENTIFIER);
      setState(445);
      match(flicker::RIGHT_BRACKET);
    }
    setState(448);
    match(flicker::IN);
    setState(449);
    expression(0);
    setState(450);
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
  enterRule(_localctx, 70, flicker::RuleForStmt);
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
    setState(452);
    match(flicker::FOR);
    setState(454);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(453);
      loopLabel();
    }
    setState(458);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::VAL:
      case flicker::VAR: {
        setState(456);
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
      case flicker::PRINT:
      case flicker::PRINT_ERROR:
      case flicker::TRUE: {
        setState(457);
        expression(0);
        break;
      }

      case flicker::SEMICOLON: {
        break;
      }

    default:
      break;
    }
    setState(460);
    match(flicker::SEMICOLON);
    setState(462);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4629172651356111370) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 268385) != 0)) {
      setState(461);
      expression(0);
    }
    setState(464);
    match(flicker::SEMICOLON);
    setState(466);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4629172651356111370) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 268385) != 0)) {
      setState(465);
      expression(0);
    }
    setState(468);
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
  enterRule(_localctx, 72, flicker::RuleBreakStmt);

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
    match(flicker::BREAK);
    setState(472);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      setState(471);
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
  enterRule(_localctx, 74, flicker::RuleContinueStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(474);
    match(flicker::CONTINUE);
    setState(476);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
    case 1: {
      setState(475);
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
  enterRule(_localctx, 76, flicker::RuleWhenStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(478);
    match(flicker::WHEN);
    setState(479);
    expression(0);
    setState(480);
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
  enterRule(_localctx, 78, flicker::RuleReturnStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(482);
    match(flicker::RETURN);
    setState(484);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      setState(483);
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
    setState(486);
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
    setState(488);
    newline();
    setState(489);
    match(flicker::INDENT);
    setState(490);
    whenContents();
    setState(491);
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
    setState(496); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(493);
              whenCase();
              setState(494);
              newline();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(498); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(502);
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
      case flicker::PRINT:
      case flicker::PRINT_ERROR:
      case flicker::TRUE: {
        setState(500);
        whenCase();
        break;
      }

      case flicker::ELSE: {
        setState(501);
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
    setState(505);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::LINE) {
      setState(504);
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
    setState(507);
    expression(0);
    setState(508);
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
    setState(510);
    match(flicker::ELSE);
    setState(511);
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

tree::TerminalNode* flicker::FactorExprContext::PERCENT() {
  return getToken(flicker::PERCENT, 0);
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
//----------------- PrintExprContext ------------------------------------------------------------------

flicker::ExpressionContext* flicker::PrintExprContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}

tree::TerminalNode* flicker::PrintExprContext::PRINT() {
  return getToken(flicker::PRINT, 0);
}

tree::TerminalNode* flicker::PrintExprContext::PRINT_ERROR() {
  return getToken(flicker::PRINT_ERROR, 0);
}

flicker::PrintExprContext::PrintExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::PrintExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrintExpr(this);
}
void flicker::PrintExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrintExpr(this);
}

std::any flicker::PrintExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitPrintExpr(this);
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
//----------------- BitwiseExprContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::BitwiseExprContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::BitwiseExprContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::BitwiseExprContext::PIPE() {
  return getToken(flicker::PIPE, 0);
}

tree::TerminalNode* flicker::BitwiseExprContext::AMPERSAND() {
  return getToken(flicker::AMPERSAND, 0);
}

tree::TerminalNode* flicker::BitwiseExprContext::CARET() {
  return getToken(flicker::CARET, 0);
}

flicker::BitwiseExprContext::BitwiseExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::BitwiseExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitwiseExpr(this);
}
void flicker::BitwiseExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitwiseExpr(this);
}

std::any flicker::BitwiseExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitBitwiseExpr(this);
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
    setState(532);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ScopedIdentifierContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(514);
      match(flicker::IDENTIFIER);
      setState(515);
      match(flicker::COLON_COLON);
      setState(516);
      match(flicker::IDENTIFIER);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<IdentifierContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(517);
      match(flicker::IDENTIFIER);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ConstantContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(518);
      constantExpr();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<InterpolationContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(519);
      interpolationExpr();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ListOrMapContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(520);
      listOrMapLiteral();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<LambdaContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(521);
      lambdaLiteral();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(522);
      match(flicker::LEFT_PAREN);
      setState(523);
      expression(0);
      setState(524);
      match(flicker::RIGHT_PAREN);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<PrefixExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(526);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 35184372662784) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(527);
      expression(14);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<NotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(528);
      match(flicker::NOT);
      setState(529);
      expression(3);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<PrintExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(530);
      _la = _input->LA(1);
      if (!(_la == flicker::PRINT

      || _la == flicker::PRINT_ERROR)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(531);
      expression(1);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(623);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(621);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<RangeExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(534);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(535);
          _la = _input->LA(1);
          if (!(_la == flicker::DOT_DOT

          || _la == flicker::DOT_DOT_LT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(536);
          expression(23);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<NilCoalescingOpContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(537);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(538);
          match(flicker::QUEST_COLON);
          setState(539);
          expression(17);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<PowerExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(540);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(541);
          match(flicker::STAR_STAR);
          setState(542);
          expression(15);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<FactorExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(543);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(544);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 171798692864) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(545);
          expression(14);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<TermExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(546);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(547);
          _la = _input->LA(1);
          if (!(_la == flicker::MINUS

          || _la == flicker::PLUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(548);
          expression(13);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BitShiftExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(549);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(550);
          _la = _input->LA(1);
          if (!(_la == flicker::GT_GT

          || _la == flicker::LT_LT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(551);
          expression(12);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BitwiseExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(552);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(553);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 11544872091648) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(554);
          expression(11);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<IfExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(555);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(556);
          match(flicker::IF);
          setState(557);
          expression(0);
          setState(558);
          match(flicker::ELSE);
          setState(559);
          expression(10);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<IsExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(561);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(565);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx)) {
          case 1: {
            setState(562);
            match(flicker::IS);
            break;
          }

          case 2: {
            setState(563);
            match(flicker::IS);
            setState(564);
            match(flicker::NOT);
            break;
          }

          default:
            break;
          }
          setState(567);
          expression(9);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<InExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(568);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(572);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case flicker::IN: {
              setState(569);
              match(flicker::IN);
              break;
            }

            case flicker::NOT: {
              setState(570);
              match(flicker::NOT);
              setState(571);
              match(flicker::IN);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(574);
          expression(8);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<ComparisonContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(575);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(576);
          comparisonOperator();
          setState(577);
          expression(7);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(579);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(580);
          match(flicker::AND);
          setState(581);
          expression(6);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(582);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(583);
          match(flicker::OR);
          setState(584);
          expression(5);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<AssignmentContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(585);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(586);
          assignOperator();
          setState(587);
          expression(2);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<MemberContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(589);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(590);
          _la = _input->LA(1);
          if (!(_la == flicker::DOT

          || _la == flicker::QUEST_DOT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(591);
          match(flicker::IDENTIFIER);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<CallContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(592);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(593);
          match(flicker::LEFT_PAREN);
          setState(602);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 4629172651356111370) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 64)) & 268385) != 0)) {
            setState(594);
            expression(0);
            setState(599);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == flicker::COMMA) {
              setState(595);
              match(flicker::COMMA);
              setState(596);
              expression(0);
              setState(601);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(604);
          match(flicker::RIGHT_PAREN);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<ArrayAccessContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(605);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(606);
          match(flicker::LEFT_BRACKET);

          setState(607);
          expression(0);
          setState(612);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == flicker::COMMA) {
            setState(608);
            match(flicker::COMMA);
            setState(609);
            expression(0);
            setState(614);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(615);
          match(flicker::RIGHT_BRACKET);
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<LambdaCallContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(617);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(618);
          braceLambda();
          break;
        }

        case 19: {
          auto newContext = _tracker.createInstance<PostfixExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(619);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(620);
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
      setState(625);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
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
    setState(626);
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
    setState(628);
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
    setState(634); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(630);
      match(flicker::INTERPOLATION);
      setState(632);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx)) {
      case 1: {
        setState(631);
        expression(0);
        break;
      }

      default:
        break;
      }
      setState(636); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == flicker::INTERPOLATION);
    setState(638);
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
    setState(640);
    _la = _input->LA(1);
    if (!(((((_la - 50) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 50)) & 4295495693) != 0))) {
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
    setState(644);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(642);
      listLiteral();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(643);
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
    setState(646);
    match(flicker::LEFT_BRACKET);
    setState(648);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4629172651356111370) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 268385) != 0)) {
      setState(647);
      listItems();
    }
    setState(650);
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
    setState(652);
    expression(0);
    setState(657);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(653);
        match(flicker::COMMA);
        setState(654);
        expression(0); 
      }
      setState(659);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
    }
    setState(661);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COMMA) {
      setState(660);
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
    setState(663);
    match(flicker::LEFT_BRACKET);
    setState(666);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::RIGHT_ARROW: {
        setState(664);
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
      case flicker::PRINT:
      case flicker::PRINT_ERROR:
      case flicker::TRUE: {
        setState(665);
        mapItems();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(668);
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
    setState(670);
    mapItem();
    setState(675);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(671);
        match(flicker::COMMA);
        setState(672);
        mapItem(); 
      }
      setState(677);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
    }
    setState(679);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COMMA) {
      setState(678);
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
    setState(681);
    expression(0);
    setState(682);
    match(flicker::RIGHT_ARROW);
    setState(683);
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
    setState(685);
    match(flicker::FUN);
    setState(688);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::LEFT_BRACE: {
        setState(686);
        braceLambda();
        break;
      }

      case flicker::LEFT_PAREN:
      case flicker::IDENTIFIER: {
        setState(687);
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
    setState(692);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(690);
        paramList();
        break;
      }

      case flicker::LEFT_PAREN: {
        enterOuterAlt(_localctx, 2);
        setState(691);
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
    setState(694);
    match(flicker::LEFT_PAREN);
    setState(696);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::IDENTIFIER) {
      setState(695);
      paramList();
    }
    setState(698);
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
    setState(700);
    lambdaParams();
    setState(704);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::DO:
      case flicker::LINE: {
        setState(701);
        blockOrStatement();
        break;
      }

      case flicker::EQ: {
        setState(702);
        match(flicker::EQ);
        setState(703);
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
    setState(706);
    match(flicker::LEFT_BRACE);
    setState(709);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx)) {
    case 1: {
      setState(707);
      statementLambdaBody();
      break;
    }

    case 2: {
      setState(708);
      exprLambdaBody();
      break;
    }

    default:
      break;
    }
    setState(711);
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
    setState(716);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx)) {
    case 1: {
      setState(713);
      lambdaParams();
      setState(714);
      match(flicker::RIGHT_ARROW);
      break;
    }

    default:
      break;
    }
    setState(723);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -3765537054062493174) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 16538739) != 0)) {
      setState(718);
      codeItem();
      setState(719);
      match(flicker::SEMICOLON);
      setState(725);
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

tree::TerminalNode* flicker::ExprLambdaBodyContext::SEMICOLON() {
  return getToken(flicker::SEMICOLON, 0);
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
    setState(727);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::LEFT_PAREN

    || _la == flicker::IDENTIFIER) {
      setState(726);
      lambdaParams();
    }
    setState(729);
    match(flicker::EQ);
    setState(730);
    expression(0);
    setState(732);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::SEMICOLON) {
      setState(731);
      match(flicker::SEMICOLON);
    }
   
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
    case 0: return precpred(_ctx, 22);
    case 1: return precpred(_ctx, 16);
    case 2: return precpred(_ctx, 15);
    case 3: return precpred(_ctx, 13);
    case 4: return precpred(_ctx, 12);
    case 5: return precpred(_ctx, 11);
    case 6: return precpred(_ctx, 10);
    case 7: return precpred(_ctx, 9);
    case 8: return precpred(_ctx, 8);
    case 9: return precpred(_ctx, 7);
    case 10: return precpred(_ctx, 6);
    case 11: return precpred(_ctx, 5);
    case 12: return precpred(_ctx, 4);
    case 13: return precpred(_ctx, 2);
    case 14: return precpred(_ctx, 21);
    case 15: return precpred(_ctx, 20);
    case 16: return precpred(_ctx, 19);
    case 17: return precpred(_ctx, 18);
    case 18: return precpred(_ctx, 17);

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
