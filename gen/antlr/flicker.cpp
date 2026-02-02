
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
      "program", "newline", "statementEnd", "topLevel", "type", "statement", 
      "variableDecl", "functionDecl", "funcReturnType", "functionContents", 
      "paramList", "param", "block", "blockBody", "classDecl", "classBody", 
      "usingStatement", "importList", "importItem", "loopLabel", "doStatement", 
      "blockOrStatement", "ifStmt", "whileStmt", "eachStmt", "forStmt", 
      "breakStmt", "continueStmt", "whenStmt", "returnStmt", "printStmt", 
      "consoleErrorStmt", "passStmt", "whenBody", "whenContents", "whenCase", 
      "elseCase", "expression", "comparisonOperator", "interpolationExpr", 
      "constantExpr", "listOrMapLiteral", "listLiteral", "listItems", "mapLiteral", 
      "mapItems", "mapItem", "lambdaLiteral", "lambdaParams", "parenthesizedOptionalParamList", 
      "lambdaBody", "braceBody", "terminator"
    },
    std::vector<std::string>{
    },
    std::vector<std::string>{
      "", "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET", 
      "LEFT_BRACE", "RIGHT_BRACE", "SEMICOLON", "COMMA", "PLUS", "SLASH", 
      "PERCENT", "PIPE", "CARET", "AMPERSAND", "TILDE", "DOT", "DOT_DOT", 
      "DOT_DOT_LT", "COLON", "COLON_COLON", "STAR", "STAR_STAR", "MINUS", 
      "RIGHT_ARROW", "BANG", "BANG_EQ", "EQ", "EQ_EQ", "GT", "GT_EQ", "LT", 
      "LT_EQ", "IDENTIFIER", "STRING", "INTERPOLATION", "CHAR", "NUMBER", 
      "AND", "ATTRIBUTE", "BREAK", "CLASS", "CONTINUE", "DO", "EACH", "ELIF", 
      "ELSE", "FALSE", "FOR", "FUN", "IF", "IN", "IS", "NIL", "NOT", "OF", 
      "OR", "PASS", "PRINT", "PRINT_ERROR", "RETURN", "SHL", "SHR", "STATIC", 
      "SUPER", "THIS", "TRUE", "USING", "VAL", "VAR", "WHEN", "WHILE", "INDENT", 
      "DEDENT", "LINE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,74,561,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,1,0,5,0,108,8,0,10,0,12,0,111,9,0,1,
  	0,1,0,1,0,5,0,116,8,0,10,0,12,0,119,9,0,1,0,1,0,1,1,4,1,124,8,1,11,1,
  	12,1,125,1,2,1,2,3,2,130,8,2,1,2,3,2,133,8,2,1,3,1,3,3,3,137,8,3,1,4,
  	1,4,1,4,3,4,142,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,3,5,159,8,5,1,6,1,6,1,6,1,6,3,6,165,8,6,1,6,1,6,3,6,169,8,6,
  	1,7,1,7,1,7,1,7,3,7,175,8,7,1,7,1,7,3,7,179,8,7,1,7,1,7,1,8,1,8,1,8,1,
  	9,1,9,1,9,3,9,189,8,9,1,10,1,10,1,10,5,10,194,8,10,10,10,12,10,197,9,
  	10,1,11,1,11,1,11,1,11,1,12,3,12,204,8,12,1,12,1,12,1,12,1,12,1,12,1,
  	13,1,13,1,13,5,13,214,8,13,10,13,12,13,217,9,13,1,14,1,14,1,14,1,14,3,
  	14,223,8,14,1,14,1,14,1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,16,3,16,235,
  	8,16,3,16,237,8,16,1,16,1,16,1,16,1,16,3,16,243,8,16,1,17,1,17,1,17,5,
  	17,248,8,17,10,17,12,17,251,9,17,1,18,1,18,1,18,1,18,3,18,257,8,18,1,
  	19,1,19,1,19,1,20,1,20,1,20,1,21,1,21,3,21,267,8,21,1,22,1,22,1,22,1,
  	22,1,22,1,22,1,22,5,22,276,8,22,10,22,12,22,279,9,22,1,22,1,22,3,22,283,
  	8,22,1,23,1,23,3,23,287,8,23,1,23,1,23,1,23,1,24,1,24,3,24,294,8,24,1,
  	24,1,24,1,24,1,24,3,24,300,8,24,1,24,1,24,1,24,1,24,1,25,1,25,3,25,308,
  	8,25,1,25,1,25,3,25,312,8,25,1,25,1,25,3,25,316,8,25,1,25,1,25,3,25,320,
  	8,25,1,25,1,25,1,26,1,26,3,26,326,8,26,1,27,1,27,3,27,330,8,27,1,28,1,
  	28,1,28,1,28,1,29,1,29,3,29,338,8,29,1,30,1,30,1,30,1,31,1,31,1,31,1,
  	32,1,32,1,33,1,33,1,33,1,33,1,33,1,34,1,34,1,34,4,34,356,8,34,11,34,12,
  	34,357,1,34,1,34,1,34,3,34,363,8,34,1,35,1,35,1,35,1,36,1,36,1,36,1,37,
  	1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,3,37,383,8,37,
  	1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,
  	1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,
  	1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,
  	1,37,1,37,1,37,1,37,1,37,1,37,5,37,433,8,37,10,37,12,37,436,9,37,3,37,
  	438,8,37,1,37,1,37,1,37,1,37,1,37,1,37,5,37,446,8,37,10,37,12,37,449,
  	9,37,1,37,1,37,5,37,453,8,37,10,37,12,37,456,9,37,1,38,1,38,1,39,1,39,
  	3,39,462,8,39,1,39,1,39,1,40,1,40,1,41,1,41,3,41,470,8,41,1,42,1,42,3,
  	42,474,8,42,1,42,1,42,1,43,1,43,1,43,5,43,481,8,43,10,43,12,43,484,9,
  	43,1,43,3,43,487,8,43,1,44,1,44,1,44,3,44,492,8,44,1,44,1,44,1,45,1,45,
  	1,45,5,45,499,8,45,10,45,12,45,502,9,45,1,45,3,45,505,8,45,1,46,1,46,
  	1,46,1,46,1,47,1,47,1,47,1,47,1,47,1,47,3,47,517,8,47,1,48,1,48,1,48,
  	3,48,522,8,48,1,49,1,49,3,49,526,8,49,1,49,1,49,1,50,1,50,3,50,532,8,
  	50,1,51,1,51,1,51,4,51,537,8,51,11,51,12,51,538,5,51,541,8,51,10,51,12,
  	51,544,9,51,1,51,3,51,547,8,51,1,51,5,51,550,8,51,10,51,12,51,553,9,51,
  	1,51,1,51,1,52,1,52,3,52,559,8,52,1,52,0,1,74,53,0,2,4,6,8,10,12,14,16,
  	18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,
  	64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,0,11,
  	2,0,48,48,55,55,1,0,68,69,2,0,19,19,24,24,3,0,15,15,23,23,25,25,2,0,10,
  	10,21,21,2,0,9,9,23,23,1,0,61,62,1,0,12,14,1,0,17,18,2,0,26,26,28,32,
  	5,0,34,34,37,37,47,47,53,53,66,66,601,0,109,1,0,0,0,2,123,1,0,0,0,4,132,
  	1,0,0,0,6,136,1,0,0,0,8,138,1,0,0,0,10,158,1,0,0,0,12,160,1,0,0,0,14,
  	170,1,0,0,0,16,182,1,0,0,0,18,188,1,0,0,0,20,190,1,0,0,0,22,198,1,0,0,
  	0,24,203,1,0,0,0,26,215,1,0,0,0,28,218,1,0,0,0,30,226,1,0,0,0,32,242,
  	1,0,0,0,34,244,1,0,0,0,36,256,1,0,0,0,38,258,1,0,0,0,40,261,1,0,0,0,42,
  	266,1,0,0,0,44,268,1,0,0,0,46,284,1,0,0,0,48,291,1,0,0,0,50,305,1,0,0,
  	0,52,323,1,0,0,0,54,327,1,0,0,0,56,331,1,0,0,0,58,335,1,0,0,0,60,339,
  	1,0,0,0,62,342,1,0,0,0,64,345,1,0,0,0,66,347,1,0,0,0,68,355,1,0,0,0,70,
  	364,1,0,0,0,72,367,1,0,0,0,74,382,1,0,0,0,76,457,1,0,0,0,78,459,1,0,0,
  	0,80,465,1,0,0,0,82,469,1,0,0,0,84,471,1,0,0,0,86,477,1,0,0,0,88,488,
  	1,0,0,0,90,495,1,0,0,0,92,506,1,0,0,0,94,510,1,0,0,0,96,521,1,0,0,0,98,
  	523,1,0,0,0,100,531,1,0,0,0,102,533,1,0,0,0,104,558,1,0,0,0,106,108,3,
  	2,1,0,107,106,1,0,0,0,108,111,1,0,0,0,109,107,1,0,0,0,109,110,1,0,0,0,
  	110,117,1,0,0,0,111,109,1,0,0,0,112,113,3,6,3,0,113,114,3,4,2,0,114,116,
  	1,0,0,0,115,112,1,0,0,0,116,119,1,0,0,0,117,115,1,0,0,0,117,118,1,0,0,
  	0,118,120,1,0,0,0,119,117,1,0,0,0,120,121,5,0,0,1,121,1,1,0,0,0,122,124,
  	5,74,0,0,123,122,1,0,0,0,124,125,1,0,0,0,125,123,1,0,0,0,125,126,1,0,
  	0,0,126,3,1,0,0,0,127,129,3,2,1,0,128,130,5,0,0,1,129,128,1,0,0,0,129,
  	130,1,0,0,0,130,133,1,0,0,0,131,133,5,0,0,1,132,127,1,0,0,0,132,131,1,
  	0,0,0,133,5,1,0,0,0,134,137,3,10,5,0,135,137,3,74,37,0,136,134,1,0,0,
  	0,136,135,1,0,0,0,137,7,1,0,0,0,138,141,5,33,0,0,139,140,7,0,0,0,140,
  	142,5,33,0,0,141,139,1,0,0,0,141,142,1,0,0,0,142,9,1,0,0,0,143,159,3,
  	12,6,0,144,159,3,14,7,0,145,159,3,28,14,0,146,159,3,32,16,0,147,159,3,
  	44,22,0,148,159,3,46,23,0,149,159,3,48,24,0,150,159,3,50,25,0,151,159,
  	3,52,26,0,152,159,3,54,27,0,153,159,3,56,28,0,154,159,3,58,29,0,155,159,
  	3,60,30,0,156,159,3,62,31,0,157,159,3,64,32,0,158,143,1,0,0,0,158,144,
  	1,0,0,0,158,145,1,0,0,0,158,146,1,0,0,0,158,147,1,0,0,0,158,148,1,0,0,
  	0,158,149,1,0,0,0,158,150,1,0,0,0,158,151,1,0,0,0,158,152,1,0,0,0,158,
  	153,1,0,0,0,158,154,1,0,0,0,158,155,1,0,0,0,158,156,1,0,0,0,158,157,1,
  	0,0,0,159,11,1,0,0,0,160,161,7,1,0,0,161,164,5,33,0,0,162,163,5,19,0,
  	0,163,165,3,8,4,0,164,162,1,0,0,0,164,165,1,0,0,0,165,168,1,0,0,0,166,
  	167,5,27,0,0,167,169,3,74,37,0,168,166,1,0,0,0,168,169,1,0,0,0,169,13,
  	1,0,0,0,170,171,5,49,0,0,171,172,5,33,0,0,172,174,5,1,0,0,173,175,3,20,
  	10,0,174,173,1,0,0,0,174,175,1,0,0,0,175,176,1,0,0,0,176,178,5,2,0,0,
  	177,179,3,16,8,0,178,177,1,0,0,0,178,179,1,0,0,0,179,180,1,0,0,0,180,
  	181,3,18,9,0,181,15,1,0,0,0,182,183,7,2,0,0,183,184,5,33,0,0,184,17,1,
  	0,0,0,185,189,3,42,21,0,186,187,5,27,0,0,187,189,3,74,37,0,188,185,1,
  	0,0,0,188,186,1,0,0,0,189,19,1,0,0,0,190,195,3,22,11,0,191,192,5,8,0,
  	0,192,194,3,22,11,0,193,191,1,0,0,0,194,197,1,0,0,0,195,193,1,0,0,0,195,
  	196,1,0,0,0,196,21,1,0,0,0,197,195,1,0,0,0,198,199,5,33,0,0,199,200,5,
  	19,0,0,200,201,3,8,4,0,201,23,1,0,0,0,202,204,5,43,0,0,203,202,1,0,0,
  	0,203,204,1,0,0,0,204,205,1,0,0,0,205,206,3,2,1,0,206,207,5,72,0,0,207,
  	208,3,26,13,0,208,209,5,73,0,0,209,25,1,0,0,0,210,211,3,6,3,0,211,212,
  	3,4,2,0,212,214,1,0,0,0,213,210,1,0,0,0,214,217,1,0,0,0,215,213,1,0,0,
  	0,215,216,1,0,0,0,216,27,1,0,0,0,217,215,1,0,0,0,218,219,5,41,0,0,219,
  	222,5,33,0,0,220,221,5,31,0,0,221,223,5,33,0,0,222,220,1,0,0,0,222,223,
  	1,0,0,0,223,224,1,0,0,0,224,225,3,30,15,0,225,29,1,0,0,0,226,227,5,37,
  	0,0,227,31,1,0,0,0,228,229,5,67,0,0,229,236,5,34,0,0,230,234,5,48,0,0,
  	231,235,5,16,0,0,232,235,5,21,0,0,233,235,3,34,17,0,234,231,1,0,0,0,234,
  	232,1,0,0,0,234,233,1,0,0,0,235,237,1,0,0,0,236,230,1,0,0,0,236,237,1,
  	0,0,0,237,243,1,0,0,0,238,239,5,67,0,0,239,240,5,33,0,0,240,241,5,27,
  	0,0,241,243,3,8,4,0,242,228,1,0,0,0,242,238,1,0,0,0,243,33,1,0,0,0,244,
  	249,3,36,18,0,245,246,5,8,0,0,246,248,3,36,18,0,247,245,1,0,0,0,248,251,
  	1,0,0,0,249,247,1,0,0,0,249,250,1,0,0,0,250,35,1,0,0,0,251,249,1,0,0,
  	0,252,257,5,33,0,0,253,254,5,33,0,0,254,255,5,24,0,0,255,257,5,33,0,0,
  	256,252,1,0,0,0,256,253,1,0,0,0,257,37,1,0,0,0,258,259,5,19,0,0,259,260,
  	5,33,0,0,260,39,1,0,0,0,261,262,5,43,0,0,262,263,3,6,3,0,263,41,1,0,0,
  	0,264,267,3,24,12,0,265,267,3,40,20,0,266,264,1,0,0,0,266,265,1,0,0,0,
  	267,43,1,0,0,0,268,269,5,50,0,0,269,270,3,74,37,0,270,277,3,42,21,0,271,
  	272,5,45,0,0,272,273,3,74,37,0,273,274,3,42,21,0,274,276,1,0,0,0,275,
  	271,1,0,0,0,276,279,1,0,0,0,277,275,1,0,0,0,277,278,1,0,0,0,278,282,1,
  	0,0,0,279,277,1,0,0,0,280,281,5,46,0,0,281,283,3,42,21,0,282,280,1,0,
  	0,0,282,283,1,0,0,0,283,45,1,0,0,0,284,286,5,71,0,0,285,287,3,38,19,0,
  	286,285,1,0,0,0,286,287,1,0,0,0,287,288,1,0,0,0,288,289,3,74,37,0,289,
  	290,3,42,21,0,290,47,1,0,0,0,291,293,5,44,0,0,292,294,3,38,19,0,293,292,
  	1,0,0,0,293,294,1,0,0,0,294,295,1,0,0,0,295,299,5,33,0,0,296,297,5,3,
  	0,0,297,298,5,33,0,0,298,300,5,4,0,0,299,296,1,0,0,0,299,300,1,0,0,0,
  	300,301,1,0,0,0,301,302,5,51,0,0,302,303,3,74,37,0,303,304,3,42,21,0,
  	304,49,1,0,0,0,305,307,5,48,0,0,306,308,3,38,19,0,307,306,1,0,0,0,307,
  	308,1,0,0,0,308,311,1,0,0,0,309,312,3,12,6,0,310,312,3,74,37,0,311,309,
  	1,0,0,0,311,310,1,0,0,0,311,312,1,0,0,0,312,313,1,0,0,0,313,315,5,7,0,
  	0,314,316,3,74,37,0,315,314,1,0,0,0,315,316,1,0,0,0,316,317,1,0,0,0,317,
  	319,5,7,0,0,318,320,3,74,37,0,319,318,1,0,0,0,319,320,1,0,0,0,320,321,
  	1,0,0,0,321,322,3,42,21,0,322,51,1,0,0,0,323,325,5,40,0,0,324,326,3,38,
  	19,0,325,324,1,0,0,0,325,326,1,0,0,0,326,53,1,0,0,0,327,329,5,42,0,0,
  	328,330,3,38,19,0,329,328,1,0,0,0,329,330,1,0,0,0,330,55,1,0,0,0,331,
  	332,5,70,0,0,332,333,3,74,37,0,333,334,3,66,33,0,334,57,1,0,0,0,335,337,
  	5,60,0,0,336,338,3,74,37,0,337,336,1,0,0,0,337,338,1,0,0,0,338,59,1,0,
  	0,0,339,340,5,58,0,0,340,341,3,74,37,0,341,61,1,0,0,0,342,343,5,59,0,
  	0,343,344,3,74,37,0,344,63,1,0,0,0,345,346,5,57,0,0,346,65,1,0,0,0,347,
  	348,3,2,1,0,348,349,5,72,0,0,349,350,3,68,34,0,350,351,5,73,0,0,351,67,
  	1,0,0,0,352,353,3,70,35,0,353,354,3,4,2,0,354,356,1,0,0,0,355,352,1,0,
  	0,0,356,357,1,0,0,0,357,355,1,0,0,0,357,358,1,0,0,0,358,362,1,0,0,0,359,
  	360,3,72,36,0,360,361,3,4,2,0,361,363,1,0,0,0,362,359,1,0,0,0,362,363,
  	1,0,0,0,363,69,1,0,0,0,364,365,3,74,37,0,365,366,3,42,21,0,366,71,1,0,
  	0,0,367,368,5,46,0,0,368,369,3,42,21,0,369,73,1,0,0,0,370,371,6,37,-1,
  	0,371,383,5,33,0,0,372,383,3,80,40,0,373,383,3,78,39,0,374,383,3,82,41,
  	0,375,383,3,94,47,0,376,377,5,1,0,0,377,378,3,74,37,0,378,379,5,2,0,0,
  	379,383,1,0,0,0,380,381,7,3,0,0,381,383,3,74,37,12,382,370,1,0,0,0,382,
  	372,1,0,0,0,382,373,1,0,0,0,382,374,1,0,0,0,382,375,1,0,0,0,382,376,1,
  	0,0,0,382,380,1,0,0,0,383,454,1,0,0,0,384,385,10,11,0,0,385,386,5,22,
  	0,0,386,453,3,74,37,11,387,388,10,10,0,0,388,389,7,4,0,0,389,453,3,74,
  	37,11,390,391,10,9,0,0,391,392,7,5,0,0,392,453,3,74,37,10,393,394,10,
  	8,0,0,394,395,7,6,0,0,395,453,3,74,37,9,396,397,10,7,0,0,397,398,7,7,
  	0,0,398,453,3,74,37,8,399,400,10,6,0,0,400,401,3,76,38,0,401,402,3,74,
  	37,7,402,453,1,0,0,0,403,404,10,5,0,0,404,405,7,8,0,0,405,453,3,74,37,
  	6,406,407,10,4,0,0,407,408,5,38,0,0,408,453,3,74,37,5,409,410,10,3,0,
  	0,410,411,5,56,0,0,411,453,3,74,37,4,412,413,10,2,0,0,413,414,5,50,0,
  	0,414,415,3,74,37,0,415,416,5,46,0,0,416,417,3,74,37,3,417,453,1,0,0,
  	0,418,419,10,1,0,0,419,420,5,27,0,0,420,453,3,74,37,1,421,422,10,16,0,
  	0,422,423,5,16,0,0,423,453,5,33,0,0,424,425,10,15,0,0,425,426,5,20,0,
  	0,426,453,5,33,0,0,427,428,10,14,0,0,428,437,5,1,0,0,429,434,3,74,37,
  	0,430,431,5,8,0,0,431,433,3,74,37,0,432,430,1,0,0,0,433,436,1,0,0,0,434,
  	432,1,0,0,0,434,435,1,0,0,0,435,438,1,0,0,0,436,434,1,0,0,0,437,429,1,
  	0,0,0,437,438,1,0,0,0,438,439,1,0,0,0,439,453,5,2,0,0,440,441,10,13,0,
  	0,441,442,5,3,0,0,442,447,3,74,37,0,443,444,5,8,0,0,444,446,3,74,37,0,
  	445,443,1,0,0,0,446,449,1,0,0,0,447,445,1,0,0,0,447,448,1,0,0,0,448,450,
  	1,0,0,0,449,447,1,0,0,0,450,451,5,4,0,0,451,453,1,0,0,0,452,384,1,0,0,
  	0,452,387,1,0,0,0,452,390,1,0,0,0,452,393,1,0,0,0,452,396,1,0,0,0,452,
  	399,1,0,0,0,452,403,1,0,0,0,452,406,1,0,0,0,452,409,1,0,0,0,452,412,1,
  	0,0,0,452,418,1,0,0,0,452,421,1,0,0,0,452,424,1,0,0,0,452,427,1,0,0,0,
  	452,440,1,0,0,0,453,456,1,0,0,0,454,452,1,0,0,0,454,455,1,0,0,0,455,75,
  	1,0,0,0,456,454,1,0,0,0,457,458,7,9,0,0,458,77,1,0,0,0,459,461,5,35,0,
  	0,460,462,3,74,37,0,461,460,1,0,0,0,461,462,1,0,0,0,462,463,1,0,0,0,463,
  	464,5,34,0,0,464,79,1,0,0,0,465,466,7,10,0,0,466,81,1,0,0,0,467,470,3,
  	84,42,0,468,470,3,88,44,0,469,467,1,0,0,0,469,468,1,0,0,0,470,83,1,0,
  	0,0,471,473,5,3,0,0,472,474,3,86,43,0,473,472,1,0,0,0,473,474,1,0,0,0,
  	474,475,1,0,0,0,475,476,5,4,0,0,476,85,1,0,0,0,477,482,3,74,37,0,478,
  	479,5,8,0,0,479,481,3,74,37,0,480,478,1,0,0,0,481,484,1,0,0,0,482,480,
  	1,0,0,0,482,483,1,0,0,0,483,486,1,0,0,0,484,482,1,0,0,0,485,487,5,8,0,
  	0,486,485,1,0,0,0,486,487,1,0,0,0,487,87,1,0,0,0,488,491,5,3,0,0,489,
  	492,5,24,0,0,490,492,3,90,45,0,491,489,1,0,0,0,491,490,1,0,0,0,492,493,
  	1,0,0,0,493,494,5,4,0,0,494,89,1,0,0,0,495,500,3,92,46,0,496,497,5,8,
  	0,0,497,499,3,92,46,0,498,496,1,0,0,0,499,502,1,0,0,0,500,498,1,0,0,0,
  	500,501,1,0,0,0,501,504,1,0,0,0,502,500,1,0,0,0,503,505,5,8,0,0,504,503,
  	1,0,0,0,504,505,1,0,0,0,505,91,1,0,0,0,506,507,3,74,37,0,507,508,5,24,
  	0,0,508,509,3,74,37,0,509,93,1,0,0,0,510,511,5,49,0,0,511,516,3,96,48,
  	0,512,513,5,24,0,0,513,517,3,100,50,0,514,515,5,27,0,0,515,517,3,74,37,
  	0,516,512,1,0,0,0,516,514,1,0,0,0,517,95,1,0,0,0,518,522,3,20,10,0,519,
  	522,3,98,49,0,520,522,1,0,0,0,521,518,1,0,0,0,521,519,1,0,0,0,521,520,
  	1,0,0,0,522,97,1,0,0,0,523,525,5,1,0,0,524,526,3,20,10,0,525,524,1,0,
  	0,0,525,526,1,0,0,0,526,527,1,0,0,0,527,528,5,2,0,0,528,99,1,0,0,0,529,
  	532,3,102,51,0,530,532,3,24,12,0,531,529,1,0,0,0,531,530,1,0,0,0,532,
  	101,1,0,0,0,533,542,5,5,0,0,534,536,3,10,5,0,535,537,3,104,52,0,536,535,
  	1,0,0,0,537,538,1,0,0,0,538,536,1,0,0,0,538,539,1,0,0,0,539,541,1,0,0,
  	0,540,534,1,0,0,0,541,544,1,0,0,0,542,540,1,0,0,0,542,543,1,0,0,0,543,
  	546,1,0,0,0,544,542,1,0,0,0,545,547,3,10,5,0,546,545,1,0,0,0,546,547,
  	1,0,0,0,547,551,1,0,0,0,548,550,3,104,52,0,549,548,1,0,0,0,550,553,1,
  	0,0,0,551,549,1,0,0,0,551,552,1,0,0,0,552,554,1,0,0,0,553,551,1,0,0,0,
  	554,555,5,6,0,0,555,103,1,0,0,0,556,559,5,7,0,0,557,559,3,2,1,0,558,556,
  	1,0,0,0,558,557,1,0,0,0,559,105,1,0,0,0,60,109,117,125,129,132,136,141,
  	158,164,168,174,178,188,195,203,215,222,234,236,242,249,256,266,277,282,
  	286,293,299,307,311,315,319,325,329,337,357,362,382,434,437,447,452,454,
  	461,469,473,482,486,491,500,504,516,521,525,531,538,542,546,551,558
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

std::vector<flicker::TopLevelContext *> flicker::ProgramContext::topLevel() {
  return getRuleContexts<flicker::TopLevelContext>();
}

flicker::TopLevelContext* flicker::ProgramContext::topLevel(size_t i) {
  return getRuleContext<flicker::TopLevelContext>(i);
}

std::vector<flicker::StatementEndContext *> flicker::ProgramContext::statementEnd() {
  return getRuleContexts<flicker::StatementEndContext>();
}

flicker::StatementEndContext* flicker::ProgramContext::statementEnd(size_t i) {
  return getRuleContext<flicker::StatementEndContext>(i);
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
    enterOuterAlt(_localctx, 1);
    setState(109);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == flicker::LINE) {
      setState(106);
      newline();
      setState(111);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(117);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2172871569095819274) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & 63) != 0)) {
      setState(112);
      topLevel();
      setState(113);
      statementEnd();
      setState(119);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(120);
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
    setState(123); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(122);
              match(flicker::LINE);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(125); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementEndContext ------------------------------------------------------------------

flicker::StatementEndContext::StatementEndContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

flicker::NewlineContext* flicker::StatementEndContext::newline() {
  return getRuleContext<flicker::NewlineContext>(0);
}

tree::TerminalNode* flicker::StatementEndContext::EOF() {
  return getToken(flicker::EOF, 0);
}


size_t flicker::StatementEndContext::getRuleIndex() const {
  return flicker::RuleStatementEnd;
}

void flicker::StatementEndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementEnd(this);
}

void flicker::StatementEndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementEnd(this);
}


std::any flicker::StatementEndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitStatementEnd(this);
  else
    return visitor->visitChildren(this);
}

flicker::StatementEndContext* flicker::statementEnd() {
  StatementEndContext *_localctx = _tracker.createInstance<StatementEndContext>(_ctx, getState());
  enterRule(_localctx, 4, flicker::RuleStatementEnd);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(132);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::LINE: {
        enterOuterAlt(_localctx, 1);
        setState(127);
        newline();
        setState(129);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          setState(128);
          match(flicker::EOF);
          break;
        }

        default:
          break;
        }
        break;
      }

      case flicker::EOF: {
        enterOuterAlt(_localctx, 2);
        setState(131);
        match(flicker::EOF);
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

//----------------- TopLevelContext ------------------------------------------------------------------

flicker::TopLevelContext::TopLevelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

flicker::StatementContext* flicker::TopLevelContext::statement() {
  return getRuleContext<flicker::StatementContext>(0);
}

flicker::ExpressionContext* flicker::TopLevelContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}


size_t flicker::TopLevelContext::getRuleIndex() const {
  return flicker::RuleTopLevel;
}

void flicker::TopLevelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTopLevel(this);
}

void flicker::TopLevelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTopLevel(this);
}


std::any flicker::TopLevelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitTopLevel(this);
  else
    return visitor->visitChildren(this);
}

flicker::TopLevelContext* flicker::topLevel() {
  TopLevelContext *_localctx = _tracker.createInstance<TopLevelContext>(_ctx, getState());
  enterRule(_localctx, 6, flicker::RuleTopLevel);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(136);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(134);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(135);
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
  enterRule(_localctx, 8, flicker::RuleType);
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
    setState(138);
    match(flicker::IDENTIFIER);
    setState(141);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::FOR

    || _la == flicker::OF) {
      setState(139);
      _la = _input->LA(1);
      if (!(_la == flicker::FOR

      || _la == flicker::OF)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(140);
      match(flicker::IDENTIFIER);
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
  enterRule(_localctx, 10, flicker::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(158);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::VAL:
      case flicker::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(143);
        variableDecl();
        break;
      }

      case flicker::FUN: {
        enterOuterAlt(_localctx, 2);
        setState(144);
        functionDecl();
        break;
      }

      case flicker::CLASS: {
        enterOuterAlt(_localctx, 3);
        setState(145);
        classDecl();
        break;
      }

      case flicker::USING: {
        enterOuterAlt(_localctx, 4);
        setState(146);
        usingStatement();
        break;
      }

      case flicker::IF: {
        enterOuterAlt(_localctx, 5);
        setState(147);
        ifStmt();
        break;
      }

      case flicker::WHILE: {
        enterOuterAlt(_localctx, 6);
        setState(148);
        whileStmt();
        break;
      }

      case flicker::EACH: {
        enterOuterAlt(_localctx, 7);
        setState(149);
        eachStmt();
        break;
      }

      case flicker::FOR: {
        enterOuterAlt(_localctx, 8);
        setState(150);
        forStmt();
        break;
      }

      case flicker::BREAK: {
        enterOuterAlt(_localctx, 9);
        setState(151);
        breakStmt();
        break;
      }

      case flicker::CONTINUE: {
        enterOuterAlt(_localctx, 10);
        setState(152);
        continueStmt();
        break;
      }

      case flicker::WHEN: {
        enterOuterAlt(_localctx, 11);
        setState(153);
        whenStmt();
        break;
      }

      case flicker::RETURN: {
        enterOuterAlt(_localctx, 12);
        setState(154);
        returnStmt();
        break;
      }

      case flicker::PRINT: {
        enterOuterAlt(_localctx, 13);
        setState(155);
        printStmt();
        break;
      }

      case flicker::PRINT_ERROR: {
        enterOuterAlt(_localctx, 14);
        setState(156);
        consoleErrorStmt();
        break;
      }

      case flicker::PASS: {
        enterOuterAlt(_localctx, 15);
        setState(157);
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
  enterRule(_localctx, 12, flicker::RuleVariableDecl);
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
    setState(160);
    _la = _input->LA(1);
    if (!(_la == flicker::VAL

    || _la == flicker::VAR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(161);
    match(flicker::IDENTIFIER);
    setState(164);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(162);
      match(flicker::COLON);
      setState(163);
      type();
    }
    setState(168);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::EQ) {
      setState(166);
      match(flicker::EQ);
      setState(167);
      expression(0);
    }
   
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
    setState(170);
    match(flicker::FUN);
    setState(171);
    match(flicker::IDENTIFIER);
    setState(172);
    match(flicker::LEFT_PAREN);
    setState(174);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::IDENTIFIER) {
      setState(173);
      paramList();
    }
    setState(176);
    match(flicker::RIGHT_PAREN);
    setState(178);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON

    || _la == flicker::RIGHT_ARROW) {
      setState(177);
      funcReturnType();
    }
    setState(180);
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
    setState(182);
    _la = _input->LA(1);
    if (!(_la == flicker::COLON

    || _la == flicker::RIGHT_ARROW)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(183);
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
    setState(188);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::DO:
      case flicker::LINE: {
        enterOuterAlt(_localctx, 1);
        setState(185);
        blockOrStatement();
        break;
      }

      case flicker::EQ: {
        enterOuterAlt(_localctx, 2);
        setState(186);
        match(flicker::EQ);
        setState(187);
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
    setState(190);
    param();
    setState(195);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == flicker::COMMA) {
      setState(191);
      match(flicker::COMMA);
      setState(192);
      param();
      setState(197);
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
    setState(198);
    match(flicker::IDENTIFIER);
    setState(199);
    match(flicker::COLON);
    setState(200);
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
    setState(203);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::DO) {
      setState(202);
      match(flicker::DO);
    }
    setState(205);
    newline();
    setState(206);
    match(flicker::INDENT);
    setState(207);
    blockBody();
    setState(208);
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

std::vector<flicker::TopLevelContext *> flicker::BlockBodyContext::topLevel() {
  return getRuleContexts<flicker::TopLevelContext>();
}

flicker::TopLevelContext* flicker::BlockBodyContext::topLevel(size_t i) {
  return getRuleContext<flicker::TopLevelContext>(i);
}

std::vector<flicker::StatementEndContext *> flicker::BlockBodyContext::statementEnd() {
  return getRuleContexts<flicker::StatementEndContext>();
}

flicker::StatementEndContext* flicker::BlockBodyContext::statementEnd(size_t i) {
  return getRuleContext<flicker::StatementEndContext>(i);
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
    enterOuterAlt(_localctx, 1);
    setState(215);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2172871569095819274) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & 63) != 0)) {
      setState(210);
      topLevel();
      setState(211);
      statementEnd();
      setState(217);
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

//----------------- ClassDeclContext ------------------------------------------------------------------

flicker::ClassDeclContext::ClassDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::ClassDeclContext::CLASS() {
  return getToken(flicker::CLASS, 0);
}

std::vector<tree::TerminalNode *> flicker::ClassDeclContext::IDENTIFIER() {
  return getTokens(flicker::IDENTIFIER);
}

tree::TerminalNode* flicker::ClassDeclContext::IDENTIFIER(size_t i) {
  return getToken(flicker::IDENTIFIER, i);
}

flicker::ClassBodyContext* flicker::ClassDeclContext::classBody() {
  return getRuleContext<flicker::ClassBodyContext>(0);
}

tree::TerminalNode* flicker::ClassDeclContext::LT() {
  return getToken(flicker::LT, 0);
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
  enterRule(_localctx, 28, flicker::RuleClassDecl);
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
    setState(218);
    match(flicker::CLASS);
    setState(219);
    match(flicker::IDENTIFIER);
    setState(222);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::LT) {
      setState(220);
      match(flicker::LT);
      setState(221);
      match(flicker::IDENTIFIER);
    }
    setState(224);
    classBody();
   
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

tree::TerminalNode* flicker::ClassBodyContext::NUMBER() {
  return getToken(flicker::NUMBER, 0);
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
  enterRule(_localctx, 30, flicker::RuleClassBody);

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
    match(flicker::NUMBER);
   
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
  enterRule(_localctx, 32, flicker::RuleUsingStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(242);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(228);
      match(flicker::USING);
      setState(229);
      match(flicker::STRING);
      setState(236);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == flicker::FOR) {
        setState(230);
        match(flicker::FOR);
        setState(234);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case flicker::DOT: {
            setState(231);
            match(flicker::DOT);
            break;
          }

          case flicker::STAR: {
            setState(232);
            match(flicker::STAR);
            break;
          }

          case flicker::IDENTIFIER: {
            setState(233);
            importList();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(238);
      match(flicker::USING);
      setState(239);
      match(flicker::IDENTIFIER);
      setState(240);
      match(flicker::EQ);
      setState(241);
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
  enterRule(_localctx, 34, flicker::RuleImportList);
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
    setState(244);
    importItem();
    setState(249);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == flicker::COMMA) {
      setState(245);
      match(flicker::COMMA);
      setState(246);
      importItem();
      setState(251);
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
  enterRule(_localctx, 36, flicker::RuleImportItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(256);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(252);
      match(flicker::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(253);
      match(flicker::IDENTIFIER);
      setState(254);
      match(flicker::RIGHT_ARROW);
      setState(255);
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
  enterRule(_localctx, 38, flicker::RuleLoopLabel);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(258);
    match(flicker::COLON);
    setState(259);
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

flicker::TopLevelContext* flicker::DoStatementContext::topLevel() {
  return getRuleContext<flicker::TopLevelContext>(0);
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
  enterRule(_localctx, 40, flicker::RuleDoStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(261);
    match(flicker::DO);
    setState(262);
    topLevel();
   
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
  enterRule(_localctx, 42, flicker::RuleBlockOrStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(266);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(264);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(265);
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
  enterRule(_localctx, 44, flicker::RuleIfStmt);

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
    setState(268);
    match(flicker::IF);
    setState(269);
    expression(0);
    setState(270);
    blockOrStatement();
    setState(277);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(271);
        match(flicker::ELIF);
        setState(272);
        expression(0);
        setState(273);
        blockOrStatement(); 
      }
      setState(279);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
    setState(282);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(280);
      match(flicker::ELSE);
      setState(281);
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

flicker::BlockOrStatementContext* flicker::WhileStmtContext::blockOrStatement() {
  return getRuleContext<flicker::BlockOrStatementContext>(0);
}

flicker::LoopLabelContext* flicker::WhileStmtContext::loopLabel() {
  return getRuleContext<flicker::LoopLabelContext>(0);
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
  enterRule(_localctx, 46, flicker::RuleWhileStmt);
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
    setState(284);
    match(flicker::WHILE);
    setState(286);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(285);
      loopLabel();
    }
    setState(288);
    expression(0);
    setState(289);
    blockOrStatement();
   
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
  enterRule(_localctx, 48, flicker::RuleEachStmt);
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
    setState(291);
    match(flicker::EACH);
    setState(293);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(292);
      loopLabel();
    }
    setState(295);
    match(flicker::IDENTIFIER);
    setState(299);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::LEFT_BRACKET) {
      setState(296);
      match(flicker::LEFT_BRACKET);
      setState(297);
      match(flicker::IDENTIFIER);
      setState(298);
      match(flicker::RIGHT_BRACKET);
    }
    setState(301);
    match(flicker::IN);
    setState(302);
    expression(0);
    setState(303);
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
  enterRule(_localctx, 50, flicker::RuleForStmt);
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
    setState(305);
    match(flicker::FOR);
    setState(307);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(306);
      loopLabel();
    }
    setState(311);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::VAL:
      case flicker::VAR: {
        setState(309);
        variableDecl();
        break;
      }

      case flicker::LEFT_PAREN:
      case flicker::LEFT_BRACKET:
      case flicker::TILDE:
      case flicker::MINUS:
      case flicker::BANG:
      case flicker::IDENTIFIER:
      case flicker::STRING:
      case flicker::INTERPOLATION:
      case flicker::NUMBER:
      case flicker::FALSE:
      case flicker::FUN:
      case flicker::NIL:
      case flicker::TRUE: {
        setState(310);
        expression(0);
        break;
      }

      case flicker::SEMICOLON: {
        break;
      }

    default:
      break;
    }
    setState(313);
    match(flicker::SEMICOLON);
    setState(315);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 9711084306989066) != 0) || _la == flicker::TRUE) {
      setState(314);
      expression(0);
    }
    setState(317);
    match(flicker::SEMICOLON);
    setState(319);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 9711084306989066) != 0) || _la == flicker::TRUE) {
      setState(318);
      expression(0);
    }
    setState(321);
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
  enterRule(_localctx, 52, flicker::RuleBreakStmt);
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
    setState(323);
    match(flicker::BREAK);
    setState(325);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(324);
      loopLabel();
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
  enterRule(_localctx, 54, flicker::RuleContinueStmt);
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
    match(flicker::CONTINUE);
    setState(329);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(328);
      loopLabel();
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
  enterRule(_localctx, 56, flicker::RuleWhenStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(331);
    match(flicker::WHEN);
    setState(332);
    expression(0);
    setState(333);
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
  enterRule(_localctx, 58, flicker::RuleReturnStmt);
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
    setState(335);
    match(flicker::RETURN);
    setState(337);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 9711084306989066) != 0) || _la == flicker::TRUE) {
      setState(336);
      expression(0);
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
  enterRule(_localctx, 60, flicker::RulePrintStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(339);
    match(flicker::PRINT);
    setState(340);
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
  enterRule(_localctx, 62, flicker::RuleConsoleErrorStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(342);
    match(flicker::PRINT_ERROR);
    setState(343);
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
  enterRule(_localctx, 64, flicker::RulePassStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(345);
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
  enterRule(_localctx, 66, flicker::RuleWhenBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(347);
    newline();
    setState(348);
    match(flicker::INDENT);
    setState(349);
    whenContents();
    setState(350);
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

std::vector<flicker::StatementEndContext *> flicker::WhenContentsContext::statementEnd() {
  return getRuleContexts<flicker::StatementEndContext>();
}

flicker::StatementEndContext* flicker::WhenContentsContext::statementEnd(size_t i) {
  return getRuleContext<flicker::StatementEndContext>(i);
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
  enterRule(_localctx, 68, flicker::RuleWhenContents);
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
    setState(355); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(352);
      whenCase();
      setState(353);
      statementEnd();
      setState(357); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 9711084306989066) != 0) || _la == flicker::TRUE);
    setState(362);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::ELSE) {
      setState(359);
      elseCase();
      setState(360);
      statementEnd();
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
  enterRule(_localctx, 70, flicker::RuleWhenCase);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(364);
    expression(0);
    setState(365);
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
  enterRule(_localctx, 72, flicker::RuleElseCase);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    match(flicker::ELSE);
    setState(368);
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

//----------------- ExprMulDivModContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::ExprMulDivModContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::ExprMulDivModContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::ExprMulDivModContext::SLASH() {
  return getToken(flicker::SLASH, 0);
}

tree::TerminalNode* flicker::ExprMulDivModContext::STAR() {
  return getToken(flicker::STAR, 0);
}

flicker::ExprMulDivModContext::ExprMulDivModContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprMulDivModContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprMulDivMod(this);
}
void flicker::ExprMulDivModContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprMulDivMod(this);
}

std::any flicker::ExprMulDivModContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprMulDivMod(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprAddSubContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::ExprAddSubContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::ExprAddSubContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::ExprAddSubContext::PLUS() {
  return getToken(flicker::PLUS, 0);
}

tree::TerminalNode* flicker::ExprAddSubContext::MINUS() {
  return getToken(flicker::MINUS, 0);
}

flicker::ExprAddSubContext::ExprAddSubContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprAddSubContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprAddSub(this);
}
void flicker::ExprAddSubContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprAddSub(this);
}

std::any flicker::ExprAddSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprAddSub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprIdentifierContext ------------------------------------------------------------------

tree::TerminalNode* flicker::ExprIdentifierContext::IDENTIFIER() {
  return getToken(flicker::IDENTIFIER, 0);
}

flicker::ExprIdentifierContext::ExprIdentifierContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprIdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprIdentifier(this);
}
void flicker::ExprIdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprIdentifier(this);
}

std::any flicker::ExprIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprIdentifier(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprRangeContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::ExprRangeContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::ExprRangeContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::ExprRangeContext::DOT_DOT() {
  return getToken(flicker::DOT_DOT, 0);
}

tree::TerminalNode* flicker::ExprRangeContext::DOT_DOT_LT() {
  return getToken(flicker::DOT_DOT_LT, 0);
}

flicker::ExprRangeContext::ExprRangeContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprRangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprRange(this);
}
void flicker::ExprRangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprRange(this);
}

std::any flicker::ExprRangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprRange(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprAssignContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::ExprAssignContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::ExprAssignContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::ExprAssignContext::EQ() {
  return getToken(flicker::EQ, 0);
}

flicker::ExprAssignContext::ExprAssignContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprAssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprAssign(this);
}
void flicker::ExprAssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprAssign(this);
}

std::any flicker::ExprAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprLambdaContext ------------------------------------------------------------------

flicker::LambdaLiteralContext* flicker::ExprLambdaContext::lambdaLiteral() {
  return getRuleContext<flicker::LambdaLiteralContext>(0);
}

flicker::ExprLambdaContext::ExprLambdaContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprLambdaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprLambda(this);
}
void flicker::ExprLambdaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprLambda(this);
}

std::any flicker::ExprLambdaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprLambda(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprCompareContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::ExprCompareContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::ExprCompareContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

flicker::ComparisonOperatorContext* flicker::ExprCompareContext::comparisonOperator() {
  return getRuleContext<flicker::ComparisonOperatorContext>(0);
}

flicker::ExprCompareContext::ExprCompareContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprCompareContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprCompare(this);
}
void flicker::ExprCompareContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprCompare(this);
}

std::any flicker::ExprCompareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprCompare(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprMemberContext ------------------------------------------------------------------

flicker::ExpressionContext* flicker::ExprMemberContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}

tree::TerminalNode* flicker::ExprMemberContext::DOT() {
  return getToken(flicker::DOT, 0);
}

tree::TerminalNode* flicker::ExprMemberContext::IDENTIFIER() {
  return getToken(flicker::IDENTIFIER, 0);
}

flicker::ExprMemberContext::ExprMemberContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprMemberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprMember(this);
}
void flicker::ExprMemberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprMember(this);
}

std::any flicker::ExprMemberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprMember(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprParenContext ------------------------------------------------------------------

tree::TerminalNode* flicker::ExprParenContext::LEFT_PAREN() {
  return getToken(flicker::LEFT_PAREN, 0);
}

flicker::ExpressionContext* flicker::ExprParenContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}

tree::TerminalNode* flicker::ExprParenContext::RIGHT_PAREN() {
  return getToken(flicker::RIGHT_PAREN, 0);
}

flicker::ExprParenContext::ExprParenContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprParenContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprParen(this);
}
void flicker::ExprParenContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprParen(this);
}

std::any flicker::ExprParenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprParen(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprOrContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::ExprOrContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::ExprOrContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::ExprOrContext::OR() {
  return getToken(flicker::OR, 0);
}

flicker::ExprOrContext::ExprOrContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprOrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprOr(this);
}
void flicker::ExprOrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprOr(this);
}

std::any flicker::ExprOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprOr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprInterpolationContext ------------------------------------------------------------------

flicker::InterpolationExprContext* flicker::ExprInterpolationContext::interpolationExpr() {
  return getRuleContext<flicker::InterpolationExprContext>(0);
}

flicker::ExprInterpolationContext::ExprInterpolationContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprInterpolationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprInterpolation(this);
}
void flicker::ExprInterpolationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprInterpolation(this);
}

std::any flicker::ExprInterpolationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprInterpolation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprCallContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::ExprCallContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::ExprCallContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::ExprCallContext::LEFT_PAREN() {
  return getToken(flicker::LEFT_PAREN, 0);
}

tree::TerminalNode* flicker::ExprCallContext::RIGHT_PAREN() {
  return getToken(flicker::RIGHT_PAREN, 0);
}

std::vector<tree::TerminalNode *> flicker::ExprCallContext::COMMA() {
  return getTokens(flicker::COMMA);
}

tree::TerminalNode* flicker::ExprCallContext::COMMA(size_t i) {
  return getToken(flicker::COMMA, i);
}

flicker::ExprCallContext::ExprCallContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprCall(this);
}
void flicker::ExprCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprCall(this);
}

std::any flicker::ExprCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprListOrMapContext ------------------------------------------------------------------

flicker::ListOrMapLiteralContext* flicker::ExprListOrMapContext::listOrMapLiteral() {
  return getRuleContext<flicker::ListOrMapLiteralContext>(0);
}

flicker::ExprListOrMapContext::ExprListOrMapContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprListOrMapContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprListOrMap(this);
}
void flicker::ExprListOrMapContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprListOrMap(this);
}

std::any flicker::ExprListOrMapContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprListOrMap(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprPrefixContext ------------------------------------------------------------------

flicker::ExpressionContext* flicker::ExprPrefixContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}

tree::TerminalNode* flicker::ExprPrefixContext::MINUS() {
  return getToken(flicker::MINUS, 0);
}

tree::TerminalNode* flicker::ExprPrefixContext::BANG() {
  return getToken(flicker::BANG, 0);
}

tree::TerminalNode* flicker::ExprPrefixContext::TILDE() {
  return getToken(flicker::TILDE, 0);
}

flicker::ExprPrefixContext::ExprPrefixContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprPrefixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprPrefix(this);
}
void flicker::ExprPrefixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprPrefix(this);
}

std::any flicker::ExprPrefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprPrefix(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprBitwiseBContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::ExprBitwiseBContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::ExprBitwiseBContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::ExprBitwiseBContext::PIPE() {
  return getToken(flicker::PIPE, 0);
}

tree::TerminalNode* flicker::ExprBitwiseBContext::AMPERSAND() {
  return getToken(flicker::AMPERSAND, 0);
}

tree::TerminalNode* flicker::ExprBitwiseBContext::CARET() {
  return getToken(flicker::CARET, 0);
}

flicker::ExprBitwiseBContext::ExprBitwiseBContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprBitwiseBContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprBitwiseB(this);
}
void flicker::ExprBitwiseBContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprBitwiseB(this);
}

std::any flicker::ExprBitwiseBContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprBitwiseB(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprAndContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::ExprAndContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::ExprAndContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::ExprAndContext::AND() {
  return getToken(flicker::AND, 0);
}

flicker::ExprAndContext::ExprAndContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprAndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprAnd(this);
}
void flicker::ExprAndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprAnd(this);
}

std::any flicker::ExprAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprAnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprPowerContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::ExprPowerContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::ExprPowerContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::ExprPowerContext::STAR_STAR() {
  return getToken(flicker::STAR_STAR, 0);
}

flicker::ExprPowerContext::ExprPowerContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprPowerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprPower(this);
}
void flicker::ExprPowerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprPower(this);
}

std::any flicker::ExprPowerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprPower(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprIndexContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::ExprIndexContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::ExprIndexContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::ExprIndexContext::LEFT_BRACKET() {
  return getToken(flicker::LEFT_BRACKET, 0);
}

tree::TerminalNode* flicker::ExprIndexContext::RIGHT_BRACKET() {
  return getToken(flicker::RIGHT_BRACKET, 0);
}

std::vector<tree::TerminalNode *> flicker::ExprIndexContext::COMMA() {
  return getTokens(flicker::COMMA);
}

tree::TerminalNode* flicker::ExprIndexContext::COMMA(size_t i) {
  return getToken(flicker::COMMA, i);
}

flicker::ExprIndexContext::ExprIndexContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprIndexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprIndex(this);
}
void flicker::ExprIndexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprIndex(this);
}

std::any flicker::ExprIndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprIndex(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprIfContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::ExprIfContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::ExprIfContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::ExprIfContext::IF() {
  return getToken(flicker::IF, 0);
}

tree::TerminalNode* flicker::ExprIfContext::ELSE() {
  return getToken(flicker::ELSE, 0);
}

flicker::ExprIfContext::ExprIfContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprIfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprIf(this);
}
void flicker::ExprIfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprIf(this);
}

std::any flicker::ExprIfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprIf(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprShiftContext ------------------------------------------------------------------

std::vector<flicker::ExpressionContext *> flicker::ExprShiftContext::expression() {
  return getRuleContexts<flicker::ExpressionContext>();
}

flicker::ExpressionContext* flicker::ExprShiftContext::expression(size_t i) {
  return getRuleContext<flicker::ExpressionContext>(i);
}

tree::TerminalNode* flicker::ExprShiftContext::SHL() {
  return getToken(flicker::SHL, 0);
}

tree::TerminalNode* flicker::ExprShiftContext::SHR() {
  return getToken(flicker::SHR, 0);
}

flicker::ExprShiftContext::ExprShiftContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprShiftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprShift(this);
}
void flicker::ExprShiftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprShift(this);
}

std::any flicker::ExprShiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprShift(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprConstantContext ------------------------------------------------------------------

flicker::ConstantExprContext* flicker::ExprConstantContext::constantExpr() {
  return getRuleContext<flicker::ConstantExprContext>(0);
}

flicker::ExprConstantContext::ExprConstantContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprConstant(this);
}
void flicker::ExprConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprConstant(this);
}

std::any flicker::ExprConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprConstant(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprStaticMemberContext ------------------------------------------------------------------

flicker::ExpressionContext* flicker::ExprStaticMemberContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}

tree::TerminalNode* flicker::ExprStaticMemberContext::COLON_COLON() {
  return getToken(flicker::COLON_COLON, 0);
}

tree::TerminalNode* flicker::ExprStaticMemberContext::IDENTIFIER() {
  return getToken(flicker::IDENTIFIER, 0);
}

flicker::ExprStaticMemberContext::ExprStaticMemberContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::ExprStaticMemberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprStaticMember(this);
}
void flicker::ExprStaticMemberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprStaticMember(this);
}

std::any flicker::ExprStaticMemberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitExprStaticMember(this);
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
  size_t startState = 74;
  enterRecursionRule(_localctx, 74, flicker::RuleExpression, precedence);

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
    setState(382);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::IDENTIFIER: {
        _localctx = _tracker.createInstance<ExprIdentifierContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(371);
        match(flicker::IDENTIFIER);
        break;
      }

      case flicker::STRING:
      case flicker::NUMBER:
      case flicker::FALSE:
      case flicker::NIL:
      case flicker::TRUE: {
        _localctx = _tracker.createInstance<ExprConstantContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(372);
        constantExpr();
        break;
      }

      case flicker::INTERPOLATION: {
        _localctx = _tracker.createInstance<ExprInterpolationContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(373);
        interpolationExpr();
        break;
      }

      case flicker::LEFT_BRACKET: {
        _localctx = _tracker.createInstance<ExprListOrMapContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(374);
        listOrMapLiteral();
        break;
      }

      case flicker::FUN: {
        _localctx = _tracker.createInstance<ExprLambdaContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(375);
        lambdaLiteral();
        break;
      }

      case flicker::LEFT_PAREN: {
        _localctx = _tracker.createInstance<ExprParenContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(376);
        match(flicker::LEFT_PAREN);
        setState(377);
        expression(0);
        setState(378);
        match(flicker::RIGHT_PAREN);
        break;
      }

      case flicker::TILDE:
      case flicker::MINUS:
      case flicker::BANG: {
        _localctx = _tracker.createInstance<ExprPrefixContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(380);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 41975808) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(381);
        expression(12);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(454);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(452);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprPowerContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(384);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(385);
          match(flicker::STAR_STAR);
          setState(386);
          expression(11);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprMulDivModContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(387);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(388);
          _la = _input->LA(1);
          if (!(_la == flicker::SLASH

          || _la == flicker::STAR)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(389);
          expression(11);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprAddSubContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(390);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(391);
          _la = _input->LA(1);
          if (!(_la == flicker::PLUS

          || _la == flicker::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(392);
          expression(10);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ExprShiftContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(393);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(394);
          _la = _input->LA(1);
          if (!(_la == flicker::SHL

          || _la == flicker::SHR)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(395);
          expression(9);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<ExprBitwiseBContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(396);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(397);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 28672) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(398);
          expression(8);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<ExprCompareContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(399);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(400);
          comparisonOperator();
          setState(401);
          expression(7);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<ExprRangeContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(403);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(404);
          _la = _input->LA(1);
          if (!(_la == flicker::DOT_DOT

          || _la == flicker::DOT_DOT_LT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(405);
          expression(6);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<ExprAndContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(406);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(407);
          match(flicker::AND);
          setState(408);
          expression(5);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<ExprOrContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(409);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(410);
          match(flicker::OR);
          setState(411);
          expression(4);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<ExprIfContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(412);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(413);
          match(flicker::IF);
          setState(414);
          expression(0);
          setState(415);
          match(flicker::ELSE);
          setState(416);
          expression(3);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<ExprAssignContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(418);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(419);
          match(flicker::EQ);
          setState(420);
          expression(1);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<ExprMemberContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(421);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(422);
          match(flicker::DOT);
          setState(423);
          match(flicker::IDENTIFIER);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<ExprStaticMemberContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(424);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(425);
          match(flicker::COLON_COLON);
          setState(426);
          match(flicker::IDENTIFIER);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<ExprCallContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(427);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(428);
          match(flicker::LEFT_PAREN);
          setState(437);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 9711084306989066) != 0) || _la == flicker::TRUE) {
            setState(429);
            expression(0);
            setState(434);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == flicker::COMMA) {
              setState(430);
              match(flicker::COMMA);
              setState(431);
              expression(0);
              setState(436);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(439);
          match(flicker::RIGHT_PAREN);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<ExprIndexContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(440);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(441);
          match(flicker::LEFT_BRACKET);

          setState(442);
          expression(0);
          setState(447);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == flicker::COMMA) {
            setState(443);
            match(flicker::COMMA);
            setState(444);
            expression(0);
            setState(449);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(450);
          match(flicker::RIGHT_BRACKET);
          break;
        }

        default:
          break;
        } 
      }
      setState(456);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
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
  enterRule(_localctx, 76, flicker::RuleComparisonOperator);
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
    setState(457);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8388608000) != 0))) {
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

tree::TerminalNode* flicker::InterpolationExprContext::INTERPOLATION() {
  return getToken(flicker::INTERPOLATION, 0);
}

tree::TerminalNode* flicker::InterpolationExprContext::STRING() {
  return getToken(flicker::STRING, 0);
}

flicker::ExpressionContext* flicker::InterpolationExprContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
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
  enterRule(_localctx, 78, flicker::RuleInterpolationExpr);

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
    match(flicker::INTERPOLATION);
    setState(461);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      setState(460);
      expression(0);
      break;
    }

    default:
      break;
    }
    setState(463);
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
  enterRule(_localctx, 80, flicker::RuleConstantExpr);
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
    setState(465);
    _la = _input->LA(1);
    if (!(((((_la - 34) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 34)) & 4295499785) != 0))) {
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
  enterRule(_localctx, 82, flicker::RuleListOrMapLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(469);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(467);
      listLiteral();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(468);
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
  enterRule(_localctx, 84, flicker::RuleListLiteral);
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
    setState(471);
    match(flicker::LEFT_BRACKET);
    setState(473);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 9711084306989066) != 0) || _la == flicker::TRUE) {
      setState(472);
      listItems();
    }
    setState(475);
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
  enterRule(_localctx, 86, flicker::RuleListItems);
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
    setState(477);
    expression(0);
    setState(482);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(478);
        match(flicker::COMMA);
        setState(479);
        expression(0); 
      }
      setState(484);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    }
    setState(486);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COMMA) {
      setState(485);
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
  enterRule(_localctx, 88, flicker::RuleMapLiteral);

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
    match(flicker::LEFT_BRACKET);
    setState(491);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::RIGHT_ARROW: {
        setState(489);
        match(flicker::RIGHT_ARROW);
        break;
      }

      case flicker::LEFT_PAREN:
      case flicker::LEFT_BRACKET:
      case flicker::TILDE:
      case flicker::MINUS:
      case flicker::BANG:
      case flicker::IDENTIFIER:
      case flicker::STRING:
      case flicker::INTERPOLATION:
      case flicker::NUMBER:
      case flicker::FALSE:
      case flicker::FUN:
      case flicker::NIL:
      case flicker::TRUE: {
        setState(490);
        mapItems();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(493);
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
  enterRule(_localctx, 90, flicker::RuleMapItems);
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
    setState(495);
    mapItem();
    setState(500);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(496);
        match(flicker::COMMA);
        setState(497);
        mapItem(); 
      }
      setState(502);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
    }
    setState(504);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COMMA) {
      setState(503);
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
  enterRule(_localctx, 92, flicker::RuleMapItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(506);
    expression(0);
    setState(507);
    match(flicker::RIGHT_ARROW);
    setState(508);
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

flicker::LambdaParamsContext* flicker::LambdaLiteralContext::lambdaParams() {
  return getRuleContext<flicker::LambdaParamsContext>(0);
}

tree::TerminalNode* flicker::LambdaLiteralContext::RIGHT_ARROW() {
  return getToken(flicker::RIGHT_ARROW, 0);
}

flicker::LambdaBodyContext* flicker::LambdaLiteralContext::lambdaBody() {
  return getRuleContext<flicker::LambdaBodyContext>(0);
}

tree::TerminalNode* flicker::LambdaLiteralContext::EQ() {
  return getToken(flicker::EQ, 0);
}

flicker::ExpressionContext* flicker::LambdaLiteralContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
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
  enterRule(_localctx, 94, flicker::RuleLambdaLiteral);

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
    match(flicker::FUN);
    setState(511);
    lambdaParams();
    setState(516);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::RIGHT_ARROW: {
        setState(512);
        match(flicker::RIGHT_ARROW);
        setState(513);
        lambdaBody();
        break;
      }

      case flicker::EQ: {
        setState(514);
        match(flicker::EQ);
        setState(515);
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
  enterRule(_localctx, 96, flicker::RuleLambdaParams);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(521);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(518);
        paramList();
        break;
      }

      case flicker::LEFT_PAREN: {
        enterOuterAlt(_localctx, 2);
        setState(519);
        parenthesizedOptionalParamList();
        break;
      }

      case flicker::RIGHT_ARROW:
      case flicker::EQ: {
        enterOuterAlt(_localctx, 3);

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
  enterRule(_localctx, 98, flicker::RuleParenthesizedOptionalParamList);
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
    setState(523);
    match(flicker::LEFT_PAREN);
    setState(525);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::IDENTIFIER) {
      setState(524);
      paramList();
    }
    setState(527);
    match(flicker::RIGHT_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LambdaBodyContext ------------------------------------------------------------------

flicker::LambdaBodyContext::LambdaBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

flicker::BraceBodyContext* flicker::LambdaBodyContext::braceBody() {
  return getRuleContext<flicker::BraceBodyContext>(0);
}

flicker::BlockContext* flicker::LambdaBodyContext::block() {
  return getRuleContext<flicker::BlockContext>(0);
}


size_t flicker::LambdaBodyContext::getRuleIndex() const {
  return flicker::RuleLambdaBody;
}

void flicker::LambdaBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLambdaBody(this);
}

void flicker::LambdaBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLambdaBody(this);
}


std::any flicker::LambdaBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitLambdaBody(this);
  else
    return visitor->visitChildren(this);
}

flicker::LambdaBodyContext* flicker::lambdaBody() {
  LambdaBodyContext *_localctx = _tracker.createInstance<LambdaBodyContext>(_ctx, getState());
  enterRule(_localctx, 100, flicker::RuleLambdaBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(531);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::LEFT_BRACE: {
        enterOuterAlt(_localctx, 1);
        setState(529);
        braceBody();
        break;
      }

      case flicker::DO:
      case flicker::LINE: {
        enterOuterAlt(_localctx, 2);
        setState(530);
        block();
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

//----------------- BraceBodyContext ------------------------------------------------------------------

flicker::BraceBodyContext::BraceBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::BraceBodyContext::LEFT_BRACE() {
  return getToken(flicker::LEFT_BRACE, 0);
}

tree::TerminalNode* flicker::BraceBodyContext::RIGHT_BRACE() {
  return getToken(flicker::RIGHT_BRACE, 0);
}

std::vector<flicker::StatementContext *> flicker::BraceBodyContext::statement() {
  return getRuleContexts<flicker::StatementContext>();
}

flicker::StatementContext* flicker::BraceBodyContext::statement(size_t i) {
  return getRuleContext<flicker::StatementContext>(i);
}

std::vector<flicker::TerminatorContext *> flicker::BraceBodyContext::terminator() {
  return getRuleContexts<flicker::TerminatorContext>();
}

flicker::TerminatorContext* flicker::BraceBodyContext::terminator(size_t i) {
  return getRuleContext<flicker::TerminatorContext>(i);
}


size_t flicker::BraceBodyContext::getRuleIndex() const {
  return flicker::RuleBraceBody;
}

void flicker::BraceBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBraceBody(this);
}

void flicker::BraceBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBraceBody(this);
}


std::any flicker::BraceBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitBraceBody(this);
  else
    return visitor->visitChildren(this);
}

flicker::BraceBodyContext* flicker::braceBody() {
  BraceBodyContext *_localctx = _tracker.createInstance<BraceBodyContext>(_ctx, getState());
  enterRule(_localctx, 102, flicker::RuleBraceBody);
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
    setState(533);
    match(flicker::LEFT_BRACE);
    setState(542);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(534);
        statement();
        setState(536); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(535);
                  terminator();
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(538); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER); 
      }
      setState(544);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
    }
    setState(546);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 40) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 40)) & 4162717463) != 0)) {
      setState(545);
      statement();
    }
    setState(551);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == flicker::SEMICOLON || _la == flicker::LINE) {
      setState(548);
      terminator();
      setState(553);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(554);
    match(flicker::RIGHT_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TerminatorContext ------------------------------------------------------------------

flicker::TerminatorContext::TerminatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* flicker::TerminatorContext::SEMICOLON() {
  return getToken(flicker::SEMICOLON, 0);
}

flicker::NewlineContext* flicker::TerminatorContext::newline() {
  return getRuleContext<flicker::NewlineContext>(0);
}


size_t flicker::TerminatorContext::getRuleIndex() const {
  return flicker::RuleTerminator;
}

void flicker::TerminatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerminator(this);
}

void flicker::TerminatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerminator(this);
}


std::any flicker::TerminatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitTerminator(this);
  else
    return visitor->visitChildren(this);
}

flicker::TerminatorContext* flicker::terminator() {
  TerminatorContext *_localctx = _tracker.createInstance<TerminatorContext>(_ctx, getState());
  enterRule(_localctx, 104, flicker::RuleTerminator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(558);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::SEMICOLON: {
        setState(556);
        match(flicker::SEMICOLON);
        break;
      }

      case flicker::LINE: {
        setState(557);
        newline();
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

bool flicker::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 37: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool flicker::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 11);
    case 1: return precpred(_ctx, 10);
    case 2: return precpred(_ctx, 9);
    case 3: return precpred(_ctx, 8);
    case 4: return precpred(_ctx, 7);
    case 5: return precpred(_ctx, 6);
    case 6: return precpred(_ctx, 5);
    case 7: return precpred(_ctx, 4);
    case 8: return precpred(_ctx, 3);
    case 9: return precpred(_ctx, 2);
    case 10: return precpred(_ctx, 1);
    case 11: return precpred(_ctx, 16);
    case 12: return precpred(_ctx, 15);
    case 13: return precpred(_ctx, 14);
    case 14: return precpred(_ctx, 13);

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
