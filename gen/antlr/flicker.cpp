
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
      "classBody", "companionNamespace", "classItem", "method", "usingStatement", 
      "importList", "importItem", "loopLabel", "doStatement", "blockOrStatement", 
      "ifStmt", "whileStmt", "eachStmt", "forStmt", "breakStmt", "continueStmt", 
      "whenStmt", "returnStmt", "printStmt", "consoleErrorStmt", "passStmt", 
      "whenBody", "whenContents", "whenCase", "elseCase", "expression", 
      "comparisonOperator", "interpolationExpr", "constantExpr", "listOrMapLiteral", 
      "listLiteral", "listItems", "mapLiteral", "mapItems", "mapItem", "lambdaLiteral", 
      "lambdaParams", "parenthesizedOptionalParamList", "blockLambda", "braceLambda", 
      "statementLambdaBody", "exprLambdaBody"
    },
    std::vector<std::string>{
    },
    std::vector<std::string>{
      "", "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET", 
      "LEFT_BRACE", "RIGHT_BRACE", "SEMICOLON", "COMMA", "PLUS", "SLASH", 
      "PERCENT", "PIPE", "CARET", "AMPERSAND", "TILDE", "DOT", "DOT_DOT", 
      "DOT_DOT_LT", "QUEST", "QUEST_COLON", "QUEST_DOT", "COLON", "COLON_COLON", 
      "STAR", "STAR_STAR", "MINUS", "RIGHT_ARROW", "BANG", "BANG_EQ", "EQ", 
      "EQ_EQ", "GT", "GT_EQ", "LT", "LT_EQ", "IDENTIFIER", "STRING", "INTERPOLATION", 
      "CHAR", "NUMBER", "AND", "BREAK", "CLASS", "CONTINUE", "CN", "DO", 
      "EACH", "ELIF", "ELSE", "FALSE", "FOR", "FUN", "IF", "IN", "IS", "NIL", 
      "NOT", "OF", "OR", "OVERRIDE", "PASS", "PRINT", "PRINT_ERROR", "PRIVATE", 
      "RETURN", "SHL", "SHR", "STATIC", "SUPER", "THIS", "TRUE", "USING", 
      "VAL", "VAR", "WHEN", "WHILE", "INDENT", "DEDENT", "LINE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,79,664,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,2,57,7,57,1,0,3,0,118,8,0,1,0,1,0,1,0,5,0,123,8,0,10,0,12,0,126,9,
  	0,1,0,3,0,129,8,0,1,0,1,0,1,1,4,1,134,8,1,11,1,12,1,135,1,2,1,2,3,2,140,
  	8,2,1,3,1,3,3,3,144,8,3,1,3,1,3,1,3,3,3,149,8,3,3,3,151,8,3,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,168,8,4,1,5,1,5,
  	1,5,1,5,3,5,174,8,5,1,5,1,5,3,5,178,8,5,1,6,1,6,1,6,1,7,1,7,1,7,3,7,186,
  	8,7,1,7,1,7,3,7,190,8,7,1,7,1,7,3,7,194,8,7,1,7,1,7,1,8,1,8,1,8,1,9,1,
  	9,1,9,3,9,204,8,9,1,10,1,10,1,10,5,10,209,8,10,10,10,12,10,212,9,10,1,
  	11,1,11,1,11,1,11,1,12,3,12,219,8,12,1,12,1,12,1,12,1,12,1,12,1,13,1,
  	13,1,13,5,13,229,8,13,10,13,12,13,232,9,13,1,13,3,13,235,8,13,1,14,1,
  	14,1,15,1,15,1,15,3,15,242,8,15,1,15,1,15,3,15,246,8,15,1,15,1,15,1,15,
  	1,15,1,15,1,16,1,16,1,16,3,16,256,8,16,1,16,1,16,1,16,5,16,261,8,16,10,
  	16,12,16,264,9,16,1,16,3,16,267,8,16,1,17,1,17,1,17,1,17,1,17,1,17,5,
  	17,275,8,17,10,17,12,17,278,9,17,1,17,3,17,281,8,17,1,17,1,17,1,18,5,
  	18,286,8,18,10,18,12,18,289,9,18,1,18,1,18,3,18,293,8,18,1,19,3,19,296,
  	8,19,1,19,1,19,1,20,1,20,1,20,1,20,1,20,1,20,3,20,306,8,20,3,20,308,8,
  	20,1,20,1,20,1,20,1,20,3,20,314,8,20,1,21,1,21,1,21,5,21,319,8,21,10,
  	21,12,21,322,9,21,1,22,1,22,1,22,1,22,3,22,328,8,22,1,23,1,23,1,23,1,
  	24,1,24,1,24,1,25,1,25,3,25,338,8,25,1,26,1,26,1,26,1,26,1,26,1,26,1,
  	26,1,26,5,26,348,8,26,10,26,12,26,351,9,26,1,26,1,26,1,26,1,26,3,26,357,
  	8,26,1,27,1,27,3,27,361,8,27,1,27,1,27,1,27,1,27,1,27,1,27,3,27,369,8,
  	27,1,28,1,28,3,28,373,8,28,1,28,1,28,1,28,1,28,3,28,379,8,28,1,28,1,28,
  	1,28,1,28,1,29,1,29,3,29,387,8,29,1,29,1,29,3,29,391,8,29,1,29,1,29,3,
  	29,395,8,29,1,29,1,29,3,29,399,8,29,1,29,1,29,1,30,1,30,3,30,405,8,30,
  	1,31,1,31,3,31,409,8,31,1,32,1,32,1,32,1,32,1,33,1,33,3,33,417,8,33,1,
  	34,1,34,1,34,1,35,1,35,1,35,1,36,1,36,1,37,1,37,1,37,1,37,1,37,1,38,1,
  	38,1,38,4,38,435,8,38,11,38,12,38,436,1,38,1,38,3,38,441,8,38,1,38,3,
  	38,444,8,38,1,39,1,39,1,39,1,40,1,40,1,40,1,41,1,41,1,41,1,41,1,41,1,
  	41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,3,41,469,8,
  	41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,
  	41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,3,41,496,8,
  	41,1,41,1,41,1,41,1,41,1,41,3,41,503,8,41,1,41,1,41,1,41,1,41,1,41,1,
  	41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,
  	41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,5,41,533,8,41,10,41,12,41,
  	536,9,41,3,41,538,8,41,1,41,1,41,1,41,1,41,1,41,1,41,5,41,546,8,41,10,
  	41,12,41,549,9,41,1,41,1,41,1,41,1,41,5,41,555,8,41,10,41,12,41,558,9,
  	41,1,42,1,42,1,43,1,43,3,43,564,8,43,4,43,566,8,43,11,43,12,43,567,1,
  	43,1,43,1,44,1,44,1,45,1,45,3,45,576,8,45,1,46,1,46,3,46,580,8,46,1,46,
  	1,46,1,47,1,47,1,47,5,47,587,8,47,10,47,12,47,590,9,47,1,47,3,47,593,
  	8,47,1,48,1,48,1,48,3,48,598,8,48,1,48,1,48,1,49,1,49,1,49,5,49,605,8,
  	49,10,49,12,49,608,9,49,1,49,3,49,611,8,49,1,50,1,50,1,50,1,50,1,51,1,
  	51,1,51,3,51,620,8,51,1,52,1,52,3,52,624,8,52,1,53,1,53,3,53,628,8,53,
  	1,53,1,53,1,54,1,54,1,54,1,54,3,54,636,8,54,1,55,1,55,1,55,3,55,641,8,
  	55,1,55,1,55,1,56,1,56,1,56,3,56,648,8,56,1,56,1,56,1,56,5,56,653,8,56,
  	10,56,12,56,656,9,56,1,57,3,57,659,8,57,1,57,1,57,1,57,1,57,0,1,82,58,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,
  	50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,
  	96,98,100,102,104,106,108,110,112,114,0,12,2,0,51,51,58,58,1,0,73,74,
  	2,0,22,22,27,27,3,0,15,15,26,26,28,28,1,0,17,18,2,0,10,10,24,24,2,0,9,
  	9,26,26,1,0,66,67,1,0,12,14,2,0,16,16,21,21,2,0,29,29,31,35,5,0,37,37,
  	40,40,50,50,56,56,71,71,720,0,117,1,0,0,0,2,133,1,0,0,0,4,139,1,0,0,0,
  	6,141,1,0,0,0,8,167,1,0,0,0,10,169,1,0,0,0,12,179,1,0,0,0,14,182,1,0,
  	0,0,16,197,1,0,0,0,18,203,1,0,0,0,20,205,1,0,0,0,22,213,1,0,0,0,24,218,
  	1,0,0,0,26,230,1,0,0,0,28,236,1,0,0,0,30,238,1,0,0,0,32,255,1,0,0,0,34,
  	268,1,0,0,0,36,287,1,0,0,0,38,295,1,0,0,0,40,313,1,0,0,0,42,315,1,0,0,
  	0,44,327,1,0,0,0,46,329,1,0,0,0,48,332,1,0,0,0,50,337,1,0,0,0,52,339,
  	1,0,0,0,54,358,1,0,0,0,56,370,1,0,0,0,58,384,1,0,0,0,60,402,1,0,0,0,62,
  	406,1,0,0,0,64,410,1,0,0,0,66,414,1,0,0,0,68,418,1,0,0,0,70,421,1,0,0,
  	0,72,424,1,0,0,0,74,426,1,0,0,0,76,434,1,0,0,0,78,445,1,0,0,0,80,448,
  	1,0,0,0,82,468,1,0,0,0,84,559,1,0,0,0,86,565,1,0,0,0,88,571,1,0,0,0,90,
  	575,1,0,0,0,92,577,1,0,0,0,94,583,1,0,0,0,96,594,1,0,0,0,98,601,1,0,0,
  	0,100,612,1,0,0,0,102,616,1,0,0,0,104,623,1,0,0,0,106,625,1,0,0,0,108,
  	631,1,0,0,0,110,637,1,0,0,0,112,647,1,0,0,0,114,658,1,0,0,0,116,118,3,
  	2,1,0,117,116,1,0,0,0,117,118,1,0,0,0,118,124,1,0,0,0,119,120,3,4,2,0,
  	120,121,3,2,1,0,121,123,1,0,0,0,122,119,1,0,0,0,123,126,1,0,0,0,124,122,
  	1,0,0,0,124,125,1,0,0,0,125,128,1,0,0,0,126,124,1,0,0,0,127,129,3,4,2,
  	0,128,127,1,0,0,0,128,129,1,0,0,0,129,130,1,0,0,0,130,131,5,0,0,1,131,
  	1,1,0,0,0,132,134,5,79,0,0,133,132,1,0,0,0,134,135,1,0,0,0,135,133,1,
  	0,0,0,135,136,1,0,0,0,136,3,1,0,0,0,137,140,3,8,4,0,138,140,3,82,41,0,
  	139,137,1,0,0,0,139,138,1,0,0,0,140,5,1,0,0,0,141,143,5,36,0,0,142,144,
  	5,19,0,0,143,142,1,0,0,0,143,144,1,0,0,0,144,150,1,0,0,0,145,146,7,0,
  	0,0,146,148,5,36,0,0,147,149,5,19,0,0,148,147,1,0,0,0,148,149,1,0,0,0,
  	149,151,1,0,0,0,150,145,1,0,0,0,150,151,1,0,0,0,151,7,1,0,0,0,152,168,
  	3,10,5,0,153,168,3,14,7,0,154,168,3,30,15,0,155,168,3,40,20,0,156,168,
  	3,52,26,0,157,168,3,54,27,0,158,168,3,56,28,0,159,168,3,58,29,0,160,168,
  	3,60,30,0,161,168,3,62,31,0,162,168,3,64,32,0,163,168,3,66,33,0,164,168,
  	3,68,34,0,165,168,3,70,35,0,166,168,3,72,36,0,167,152,1,0,0,0,167,153,
  	1,0,0,0,167,154,1,0,0,0,167,155,1,0,0,0,167,156,1,0,0,0,167,157,1,0,0,
  	0,167,158,1,0,0,0,167,159,1,0,0,0,167,160,1,0,0,0,167,161,1,0,0,0,167,
  	162,1,0,0,0,167,163,1,0,0,0,167,164,1,0,0,0,167,165,1,0,0,0,167,166,1,
  	0,0,0,168,9,1,0,0,0,169,170,7,1,0,0,170,173,5,36,0,0,171,172,5,22,0,0,
  	172,174,3,6,3,0,173,171,1,0,0,0,173,174,1,0,0,0,174,177,1,0,0,0,175,176,
  	5,30,0,0,176,178,3,82,41,0,177,175,1,0,0,0,177,178,1,0,0,0,178,11,1,0,
  	0,0,179,180,7,0,0,0,180,181,5,36,0,0,181,13,1,0,0,0,182,183,5,52,0,0,
  	183,185,5,36,0,0,184,186,3,12,6,0,185,184,1,0,0,0,185,186,1,0,0,0,186,
  	187,1,0,0,0,187,189,5,1,0,0,188,190,3,20,10,0,189,188,1,0,0,0,189,190,
  	1,0,0,0,190,191,1,0,0,0,191,193,5,2,0,0,192,194,3,16,8,0,193,192,1,0,
  	0,0,193,194,1,0,0,0,194,195,1,0,0,0,195,196,3,18,9,0,196,15,1,0,0,0,197,
  	198,7,2,0,0,198,199,5,36,0,0,199,17,1,0,0,0,200,204,3,50,25,0,201,202,
  	5,30,0,0,202,204,3,82,41,0,203,200,1,0,0,0,203,201,1,0,0,0,204,19,1,0,
  	0,0,205,210,3,22,11,0,206,207,5,8,0,0,207,209,3,22,11,0,208,206,1,0,0,
  	0,209,212,1,0,0,0,210,208,1,0,0,0,210,211,1,0,0,0,211,21,1,0,0,0,212,
  	210,1,0,0,0,213,214,5,36,0,0,214,215,5,22,0,0,215,216,3,6,3,0,216,23,
  	1,0,0,0,217,219,5,46,0,0,218,217,1,0,0,0,218,219,1,0,0,0,219,220,1,0,
  	0,0,220,221,3,2,1,0,221,222,5,77,0,0,222,223,3,26,13,0,223,224,5,78,0,
  	0,224,25,1,0,0,0,225,226,3,4,2,0,226,227,3,2,1,0,227,229,1,0,0,0,228,
  	225,1,0,0,0,229,232,1,0,0,0,230,228,1,0,0,0,230,231,1,0,0,0,231,234,1,
  	0,0,0,232,230,1,0,0,0,233,235,3,4,2,0,234,233,1,0,0,0,234,235,1,0,0,0,
  	235,27,1,0,0,0,236,237,5,64,0,0,237,29,1,0,0,0,238,239,5,43,0,0,239,241,
  	5,36,0,0,240,242,3,12,6,0,241,240,1,0,0,0,241,242,1,0,0,0,242,245,1,0,
  	0,0,243,244,5,55,0,0,244,246,3,6,3,0,245,243,1,0,0,0,245,246,1,0,0,0,
  	246,247,1,0,0,0,247,248,3,2,1,0,248,249,5,77,0,0,249,250,3,32,16,0,250,
  	251,5,78,0,0,251,31,1,0,0,0,252,253,3,34,17,0,253,254,3,2,1,0,254,256,
  	1,0,0,0,255,252,1,0,0,0,255,256,1,0,0,0,256,262,1,0,0,0,257,258,3,36,
  	18,0,258,259,3,2,1,0,259,261,1,0,0,0,260,257,1,0,0,0,261,264,1,0,0,0,
  	262,260,1,0,0,0,262,263,1,0,0,0,263,266,1,0,0,0,264,262,1,0,0,0,265,267,
  	3,36,18,0,266,265,1,0,0,0,266,267,1,0,0,0,267,33,1,0,0,0,268,269,5,45,
  	0,0,269,270,3,2,1,0,270,276,5,77,0,0,271,272,3,36,18,0,272,273,3,2,1,
  	0,273,275,1,0,0,0,274,271,1,0,0,0,275,278,1,0,0,0,276,274,1,0,0,0,276,
  	277,1,0,0,0,277,280,1,0,0,0,278,276,1,0,0,0,279,281,3,36,18,0,280,279,
  	1,0,0,0,280,281,1,0,0,0,281,282,1,0,0,0,282,283,5,78,0,0,283,35,1,0,0,
  	0,284,286,3,28,14,0,285,284,1,0,0,0,286,289,1,0,0,0,287,285,1,0,0,0,287,
  	288,1,0,0,0,288,292,1,0,0,0,289,287,1,0,0,0,290,293,3,10,5,0,291,293,
  	3,38,19,0,292,290,1,0,0,0,292,291,1,0,0,0,293,37,1,0,0,0,294,296,5,60,
  	0,0,295,294,1,0,0,0,295,296,1,0,0,0,296,297,1,0,0,0,297,298,3,14,7,0,
  	298,39,1,0,0,0,299,300,5,72,0,0,300,307,5,37,0,0,301,305,5,51,0,0,302,
  	306,5,16,0,0,303,306,5,24,0,0,304,306,3,42,21,0,305,302,1,0,0,0,305,303,
  	1,0,0,0,305,304,1,0,0,0,306,308,1,0,0,0,307,301,1,0,0,0,307,308,1,0,0,
  	0,308,314,1,0,0,0,309,310,5,72,0,0,310,311,5,36,0,0,311,312,5,30,0,0,
  	312,314,3,6,3,0,313,299,1,0,0,0,313,309,1,0,0,0,314,41,1,0,0,0,315,320,
  	3,44,22,0,316,317,5,8,0,0,317,319,3,44,22,0,318,316,1,0,0,0,319,322,1,
  	0,0,0,320,318,1,0,0,0,320,321,1,0,0,0,321,43,1,0,0,0,322,320,1,0,0,0,
  	323,328,5,36,0,0,324,325,5,36,0,0,325,326,5,27,0,0,326,328,5,36,0,0,327,
  	323,1,0,0,0,327,324,1,0,0,0,328,45,1,0,0,0,329,330,5,22,0,0,330,331,5,
  	36,0,0,331,47,1,0,0,0,332,333,5,46,0,0,333,334,3,4,2,0,334,49,1,0,0,0,
  	335,338,3,24,12,0,336,338,3,48,24,0,337,335,1,0,0,0,337,336,1,0,0,0,338,
  	51,1,0,0,0,339,340,5,53,0,0,340,341,3,82,41,0,341,349,3,50,25,0,342,343,
  	3,2,1,0,343,344,5,48,0,0,344,345,3,82,41,0,345,346,3,50,25,0,346,348,
  	1,0,0,0,347,342,1,0,0,0,348,351,1,0,0,0,349,347,1,0,0,0,349,350,1,0,0,
  	0,350,356,1,0,0,0,351,349,1,0,0,0,352,353,3,2,1,0,353,354,5,49,0,0,354,
  	355,3,50,25,0,355,357,1,0,0,0,356,352,1,0,0,0,356,357,1,0,0,0,357,53,
  	1,0,0,0,358,360,5,76,0,0,359,361,3,46,23,0,360,359,1,0,0,0,360,361,1,
  	0,0,0,361,362,1,0,0,0,362,363,3,82,41,0,363,368,3,50,25,0,364,365,3,2,
  	1,0,365,366,5,49,0,0,366,367,3,50,25,0,367,369,1,0,0,0,368,364,1,0,0,
  	0,368,369,1,0,0,0,369,55,1,0,0,0,370,372,5,47,0,0,371,373,3,46,23,0,372,
  	371,1,0,0,0,372,373,1,0,0,0,373,374,1,0,0,0,374,378,5,36,0,0,375,376,
  	5,3,0,0,376,377,5,36,0,0,377,379,5,4,0,0,378,375,1,0,0,0,378,379,1,0,
  	0,0,379,380,1,0,0,0,380,381,5,54,0,0,381,382,3,82,41,0,382,383,3,50,25,
  	0,383,57,1,0,0,0,384,386,5,51,0,0,385,387,3,46,23,0,386,385,1,0,0,0,386,
  	387,1,0,0,0,387,390,1,0,0,0,388,391,3,10,5,0,389,391,3,82,41,0,390,388,
  	1,0,0,0,390,389,1,0,0,0,390,391,1,0,0,0,391,392,1,0,0,0,392,394,5,7,0,
  	0,393,395,3,82,41,0,394,393,1,0,0,0,394,395,1,0,0,0,395,396,1,0,0,0,396,
  	398,5,7,0,0,397,399,3,82,41,0,398,397,1,0,0,0,398,399,1,0,0,0,399,400,
  	1,0,0,0,400,401,3,50,25,0,401,59,1,0,0,0,402,404,5,42,0,0,403,405,3,46,
  	23,0,404,403,1,0,0,0,404,405,1,0,0,0,405,61,1,0,0,0,406,408,5,44,0,0,
  	407,409,3,46,23,0,408,407,1,0,0,0,408,409,1,0,0,0,409,63,1,0,0,0,410,
  	411,5,75,0,0,411,412,3,82,41,0,412,413,3,74,37,0,413,65,1,0,0,0,414,416,
  	5,65,0,0,415,417,3,82,41,0,416,415,1,0,0,0,416,417,1,0,0,0,417,67,1,0,
  	0,0,418,419,5,62,0,0,419,420,3,82,41,0,420,69,1,0,0,0,421,422,5,63,0,
  	0,422,423,3,82,41,0,423,71,1,0,0,0,424,425,5,61,0,0,425,73,1,0,0,0,426,
  	427,3,2,1,0,427,428,5,77,0,0,428,429,3,76,38,0,429,430,5,78,0,0,430,75,
  	1,0,0,0,431,432,3,78,39,0,432,433,3,2,1,0,433,435,1,0,0,0,434,431,1,0,
  	0,0,435,436,1,0,0,0,436,434,1,0,0,0,436,437,1,0,0,0,437,440,1,0,0,0,438,
  	441,3,78,39,0,439,441,3,80,40,0,440,438,1,0,0,0,440,439,1,0,0,0,440,441,
  	1,0,0,0,441,443,1,0,0,0,442,444,3,2,1,0,443,442,1,0,0,0,443,444,1,0,0,
  	0,444,77,1,0,0,0,445,446,3,82,41,0,446,447,3,50,25,0,447,79,1,0,0,0,448,
  	449,5,49,0,0,449,450,3,50,25,0,450,81,1,0,0,0,451,452,6,41,-1,0,452,453,
  	5,36,0,0,453,454,5,23,0,0,454,469,5,36,0,0,455,469,5,36,0,0,456,469,3,
  	88,44,0,457,469,3,86,43,0,458,469,3,90,45,0,459,469,3,102,51,0,460,461,
  	5,1,0,0,461,462,3,82,41,0,462,463,5,2,0,0,463,469,1,0,0,0,464,465,7,3,
  	0,0,465,469,3,82,41,13,466,467,5,57,0,0,467,469,3,82,41,3,468,451,1,0,
  	0,0,468,455,1,0,0,0,468,456,1,0,0,0,468,457,1,0,0,0,468,458,1,0,0,0,468,
  	459,1,0,0,0,468,460,1,0,0,0,468,464,1,0,0,0,468,466,1,0,0,0,469,556,1,
  	0,0,0,470,471,10,20,0,0,471,472,7,4,0,0,472,555,3,82,41,21,473,474,10,
  	15,0,0,474,475,5,20,0,0,475,555,3,82,41,16,476,477,10,14,0,0,477,478,
  	5,25,0,0,478,555,3,82,41,14,479,480,10,12,0,0,480,481,7,5,0,0,481,555,
  	3,82,41,13,482,483,10,11,0,0,483,484,7,6,0,0,484,555,3,82,41,12,485,486,
  	10,10,0,0,486,487,7,7,0,0,487,555,3,82,41,11,488,489,10,9,0,0,489,490,
  	7,8,0,0,490,555,3,82,41,10,491,495,10,8,0,0,492,496,5,55,0,0,493,494,
  	5,55,0,0,494,496,5,57,0,0,495,492,1,0,0,0,495,493,1,0,0,0,496,497,1,0,
  	0,0,497,555,3,82,41,9,498,502,10,7,0,0,499,503,5,54,0,0,500,501,5,57,
  	0,0,501,503,5,54,0,0,502,499,1,0,0,0,502,500,1,0,0,0,503,504,1,0,0,0,
  	504,555,3,82,41,8,505,506,10,6,0,0,506,507,3,84,42,0,507,508,3,82,41,
  	7,508,555,1,0,0,0,509,510,10,5,0,0,510,511,5,41,0,0,511,555,3,82,41,6,
  	512,513,10,4,0,0,513,514,5,59,0,0,514,555,3,82,41,5,515,516,10,2,0,0,
  	516,517,5,53,0,0,517,518,3,82,41,0,518,519,5,49,0,0,519,520,3,82,41,3,
  	520,555,1,0,0,0,521,522,10,1,0,0,522,523,5,30,0,0,523,555,3,82,41,1,524,
  	525,10,19,0,0,525,526,7,9,0,0,526,555,5,36,0,0,527,528,10,18,0,0,528,
  	537,5,1,0,0,529,534,3,82,41,0,530,531,5,8,0,0,531,533,3,82,41,0,532,530,
  	1,0,0,0,533,536,1,0,0,0,534,532,1,0,0,0,534,535,1,0,0,0,535,538,1,0,0,
  	0,536,534,1,0,0,0,537,529,1,0,0,0,537,538,1,0,0,0,538,539,1,0,0,0,539,
  	555,5,2,0,0,540,541,10,17,0,0,541,542,5,3,0,0,542,547,3,82,41,0,543,544,
  	5,8,0,0,544,546,3,82,41,0,545,543,1,0,0,0,546,549,1,0,0,0,547,545,1,0,
  	0,0,547,548,1,0,0,0,548,550,1,0,0,0,549,547,1,0,0,0,550,551,5,4,0,0,551,
  	555,1,0,0,0,552,553,10,16,0,0,553,555,3,110,55,0,554,470,1,0,0,0,554,
  	473,1,0,0,0,554,476,1,0,0,0,554,479,1,0,0,0,554,482,1,0,0,0,554,485,1,
  	0,0,0,554,488,1,0,0,0,554,491,1,0,0,0,554,498,1,0,0,0,554,505,1,0,0,0,
  	554,509,1,0,0,0,554,512,1,0,0,0,554,515,1,0,0,0,554,521,1,0,0,0,554,524,
  	1,0,0,0,554,527,1,0,0,0,554,540,1,0,0,0,554,552,1,0,0,0,555,558,1,0,0,
  	0,556,554,1,0,0,0,556,557,1,0,0,0,557,83,1,0,0,0,558,556,1,0,0,0,559,
  	560,7,10,0,0,560,85,1,0,0,0,561,563,5,38,0,0,562,564,3,82,41,0,563,562,
  	1,0,0,0,563,564,1,0,0,0,564,566,1,0,0,0,565,561,1,0,0,0,566,567,1,0,0,
  	0,567,565,1,0,0,0,567,568,1,0,0,0,568,569,1,0,0,0,569,570,5,37,0,0,570,
  	87,1,0,0,0,571,572,7,11,0,0,572,89,1,0,0,0,573,576,3,92,46,0,574,576,
  	3,96,48,0,575,573,1,0,0,0,575,574,1,0,0,0,576,91,1,0,0,0,577,579,5,3,
  	0,0,578,580,3,94,47,0,579,578,1,0,0,0,579,580,1,0,0,0,580,581,1,0,0,0,
  	581,582,5,4,0,0,582,93,1,0,0,0,583,588,3,82,41,0,584,585,5,8,0,0,585,
  	587,3,82,41,0,586,584,1,0,0,0,587,590,1,0,0,0,588,586,1,0,0,0,588,589,
  	1,0,0,0,589,592,1,0,0,0,590,588,1,0,0,0,591,593,5,8,0,0,592,591,1,0,0,
  	0,592,593,1,0,0,0,593,95,1,0,0,0,594,597,5,3,0,0,595,598,5,27,0,0,596,
  	598,3,98,49,0,597,595,1,0,0,0,597,596,1,0,0,0,598,599,1,0,0,0,599,600,
  	5,4,0,0,600,97,1,0,0,0,601,606,3,100,50,0,602,603,5,8,0,0,603,605,3,100,
  	50,0,604,602,1,0,0,0,605,608,1,0,0,0,606,604,1,0,0,0,606,607,1,0,0,0,
  	607,610,1,0,0,0,608,606,1,0,0,0,609,611,5,8,0,0,610,609,1,0,0,0,610,611,
  	1,0,0,0,611,99,1,0,0,0,612,613,3,82,41,0,613,614,5,27,0,0,614,615,3,82,
  	41,0,615,101,1,0,0,0,616,619,5,52,0,0,617,620,3,110,55,0,618,620,3,108,
  	54,0,619,617,1,0,0,0,619,618,1,0,0,0,620,103,1,0,0,0,621,624,3,20,10,
  	0,622,624,3,106,53,0,623,621,1,0,0,0,623,622,1,0,0,0,624,105,1,0,0,0,
  	625,627,5,1,0,0,626,628,3,20,10,0,627,626,1,0,0,0,627,628,1,0,0,0,628,
  	629,1,0,0,0,629,630,5,2,0,0,630,107,1,0,0,0,631,635,3,104,52,0,632,636,
  	3,50,25,0,633,634,5,30,0,0,634,636,3,82,41,0,635,632,1,0,0,0,635,633,
  	1,0,0,0,636,109,1,0,0,0,637,640,5,5,0,0,638,641,3,112,56,0,639,641,3,
  	114,57,0,640,638,1,0,0,0,640,639,1,0,0,0,641,642,1,0,0,0,642,643,5,6,
  	0,0,643,111,1,0,0,0,644,645,3,104,52,0,645,646,5,27,0,0,646,648,1,0,0,
  	0,647,644,1,0,0,0,647,648,1,0,0,0,648,654,1,0,0,0,649,650,3,4,2,0,650,
  	651,5,7,0,0,651,653,1,0,0,0,652,649,1,0,0,0,653,656,1,0,0,0,654,652,1,
  	0,0,0,654,655,1,0,0,0,655,113,1,0,0,0,656,654,1,0,0,0,657,659,3,104,52,
  	0,658,657,1,0,0,0,658,659,1,0,0,0,659,660,1,0,0,0,660,661,5,30,0,0,661,
  	662,3,82,41,0,662,115,1,0,0,0,76,117,124,128,135,139,143,148,150,167,
  	173,177,185,189,193,203,210,218,230,234,241,245,255,262,266,276,280,287,
  	292,295,305,307,313,320,327,337,349,356,360,368,372,378,386,390,394,398,
  	404,408,416,436,440,443,468,495,502,534,537,547,554,556,563,567,575,579,
  	588,592,597,606,610,619,623,627,635,640,647,654,658
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
    setState(117);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::LINE) {
      setState(116);
      newline();
    }
    setState(124);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(119);
        codeItem();
        setState(120);
        newline(); 
      }
      setState(126);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(128);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -2072608623799795702) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & 4033) != 0)) {
      setState(127);
      codeItem();
    }
    setState(130);
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
    setState(133); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(132);
              match(flicker::LINE);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(135); 
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
    setState(139);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(137);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(138);
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
    setState(141);
    match(flicker::IDENTIFIER);
    setState(143);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(142);
      match(flicker::QUEST);
      break;
    }

    default:
      break;
    }
    setState(150);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(145);
      _la = _input->LA(1);
      if (!(_la == flicker::FOR

      || _la == flicker::OF)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(146);
      match(flicker::IDENTIFIER);
      setState(148);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
      case 1: {
        setState(147);
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
    setState(167);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::VAL:
      case flicker::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(152);
        variableDecl();
        break;
      }

      case flicker::FUN: {
        enterOuterAlt(_localctx, 2);
        setState(153);
        functionDecl();
        break;
      }

      case flicker::CLASS: {
        enterOuterAlt(_localctx, 3);
        setState(154);
        classDecl();
        break;
      }

      case flicker::USING: {
        enterOuterAlt(_localctx, 4);
        setState(155);
        usingStatement();
        break;
      }

      case flicker::IF: {
        enterOuterAlt(_localctx, 5);
        setState(156);
        ifStmt();
        break;
      }

      case flicker::WHILE: {
        enterOuterAlt(_localctx, 6);
        setState(157);
        whileStmt();
        break;
      }

      case flicker::EACH: {
        enterOuterAlt(_localctx, 7);
        setState(158);
        eachStmt();
        break;
      }

      case flicker::FOR: {
        enterOuterAlt(_localctx, 8);
        setState(159);
        forStmt();
        break;
      }

      case flicker::BREAK: {
        enterOuterAlt(_localctx, 9);
        setState(160);
        breakStmt();
        break;
      }

      case flicker::CONTINUE: {
        enterOuterAlt(_localctx, 10);
        setState(161);
        continueStmt();
        break;
      }

      case flicker::WHEN: {
        enterOuterAlt(_localctx, 11);
        setState(162);
        whenStmt();
        break;
      }

      case flicker::RETURN: {
        enterOuterAlt(_localctx, 12);
        setState(163);
        returnStmt();
        break;
      }

      case flicker::PRINT: {
        enterOuterAlt(_localctx, 13);
        setState(164);
        printStmt();
        break;
      }

      case flicker::PRINT_ERROR: {
        enterOuterAlt(_localctx, 14);
        setState(165);
        consoleErrorStmt();
        break;
      }

      case flicker::PASS: {
        enterOuterAlt(_localctx, 15);
        setState(166);
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
    setState(169);
    _la = _input->LA(1);
    if (!(_la == flicker::VAL

    || _la == flicker::VAR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(170);
    match(flicker::IDENTIFIER);
    setState(173);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(171);
      match(flicker::COLON);
      setState(172);
      type();
      break;
    }

    default:
      break;
    }
    setState(177);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(175);
      match(flicker::EQ);
      setState(176);
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
    setState(179);
    _la = _input->LA(1);
    if (!(_la == flicker::FOR

    || _la == flicker::OF)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(180);
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
    setState(182);
    match(flicker::FUN);
    setState(183);
    match(flicker::IDENTIFIER);
    setState(185);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::FOR

    || _la == flicker::OF) {
      setState(184);
      typeParam();
    }
    setState(187);
    match(flicker::LEFT_PAREN);
    setState(189);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::IDENTIFIER) {
      setState(188);
      paramList();
    }
    setState(191);
    match(flicker::RIGHT_PAREN);
    setState(193);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON

    || _la == flicker::RIGHT_ARROW) {
      setState(192);
      funcReturnType();
    }
    setState(195);
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
    setState(197);
    _la = _input->LA(1);
    if (!(_la == flicker::COLON

    || _la == flicker::RIGHT_ARROW)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(198);
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
    setState(203);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::DO:
      case flicker::LINE: {
        enterOuterAlt(_localctx, 1);
        setState(200);
        blockOrStatement();
        break;
      }

      case flicker::EQ: {
        enterOuterAlt(_localctx, 2);
        setState(201);
        match(flicker::EQ);
        setState(202);
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
    setState(205);
    param();
    setState(210);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == flicker::COMMA) {
      setState(206);
      match(flicker::COMMA);
      setState(207);
      param();
      setState(212);
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
    setState(213);
    match(flicker::IDENTIFIER);
    setState(214);
    match(flicker::COLON);
    setState(215);
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
    setState(218);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::DO) {
      setState(217);
      match(flicker::DO);
    }
    setState(220);
    newline();
    setState(221);
    match(flicker::INDENT);
    setState(222);
    blockBody();
    setState(223);
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
    setState(230);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(225);
        codeItem();
        setState(226);
        newline(); 
      }
      setState(232);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
    setState(234);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -2072608623799795702) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & 4033) != 0)) {
      setState(233);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(236);
    match(flicker::PRIVATE);
   
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
    setState(238);
    match(flicker::CLASS);
    setState(239);
    match(flicker::IDENTIFIER);
    setState(241);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::FOR

    || _la == flicker::OF) {
      setState(240);
      typeParam();
    }
    setState(245);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::IS) {
      setState(243);
      match(flicker::IS);
      setState(244);
      type();
    }
    setState(247);
    newline();
    setState(248);
    match(flicker::INDENT);
    setState(249);
    classBody();
    setState(250);
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
    setState(255);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::CN) {
      setState(252);
      companionNamespace();
      setState(253);
      newline();
    }
    setState(262);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(257);
        classItem();
        setState(258);
        newline(); 
      }
      setState(264);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
    setState(266);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 52) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 52)) & 6295809) != 0)) {
      setState(265);
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
    setState(268);
    match(flicker::CN);
    setState(269);
    newline();
    setState(270);
    match(flicker::INDENT);
    setState(276);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(271);
        classItem();
        setState(272);
        newline(); 
      }
      setState(278);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
    setState(280);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 52) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 52)) & 6295809) != 0)) {
      setState(279);
      classItem();
    }
    setState(282);
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
    enterOuterAlt(_localctx, 1);
    setState(287);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == flicker::PRIVATE) {
      setState(284);
      accessSpecifier();
      setState(289);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(292);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::VAL:
      case flicker::VAR: {
        setState(290);
        variableDecl();
        break;
      }

      case flicker::FUN:
      case flicker::OVERRIDE: {
        setState(291);
        method();
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

//----------------- MethodContext ------------------------------------------------------------------

flicker::MethodContext::MethodContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

flicker::FunctionDeclContext* flicker::MethodContext::functionDecl() {
  return getRuleContext<flicker::FunctionDeclContext>(0);
}

tree::TerminalNode* flicker::MethodContext::OVERRIDE() {
  return getToken(flicker::OVERRIDE, 0);
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
  enterRule(_localctx, 38, flicker::RuleMethod);
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
    setState(295);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::OVERRIDE) {
      setState(294);
      match(flicker::OVERRIDE);
    }
    setState(297);
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
  enterRule(_localctx, 40, flicker::RuleUsingStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(313);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(299);
      match(flicker::USING);
      setState(300);
      match(flicker::STRING);
      setState(307);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
      case 1: {
        setState(301);
        match(flicker::FOR);
        setState(305);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case flicker::DOT: {
            setState(302);
            match(flicker::DOT);
            break;
          }

          case flicker::STAR: {
            setState(303);
            match(flicker::STAR);
            break;
          }

          case flicker::IDENTIFIER: {
            setState(304);
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
      setState(309);
      match(flicker::USING);
      setState(310);
      match(flicker::IDENTIFIER);
      setState(311);
      match(flicker::EQ);
      setState(312);
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
  enterRule(_localctx, 42, flicker::RuleImportList);

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
    setState(315);
    importItem();
    setState(320);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(316);
        match(flicker::COMMA);
        setState(317);
        importItem(); 
      }
      setState(322);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
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
  enterRule(_localctx, 44, flicker::RuleImportItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(327);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(323);
      match(flicker::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(324);
      match(flicker::IDENTIFIER);
      setState(325);
      match(flicker::RIGHT_ARROW);
      setState(326);
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
  enterRule(_localctx, 46, flicker::RuleLoopLabel);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(329);
    match(flicker::COLON);
    setState(330);
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
  enterRule(_localctx, 48, flicker::RuleDoStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(332);
    match(flicker::DO);
    setState(333);
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
  enterRule(_localctx, 50, flicker::RuleBlockOrStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(337);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(335);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(336);
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
  enterRule(_localctx, 52, flicker::RuleIfStmt);

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
    setState(339);
    match(flicker::IF);
    setState(340);
    expression(0);
    setState(341);
    blockOrStatement();
    setState(349);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(342);
        newline();
        setState(343);
        match(flicker::ELIF);
        setState(344);
        expression(0);
        setState(345);
        blockOrStatement(); 
      }
      setState(351);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
    setState(356);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(352);
      newline();
      setState(353);
      match(flicker::ELSE);
      setState(354);
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
  enterRule(_localctx, 54, flicker::RuleWhileStmt);
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
    setState(358);
    match(flicker::WHILE);
    setState(360);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(359);
      loopLabel();
    }
    setState(362);
    expression(0);
    setState(363);
    blockOrStatement();
    setState(368);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      setState(364);
      newline();
      setState(365);
      match(flicker::ELSE);
      setState(366);
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
  enterRule(_localctx, 56, flicker::RuleEachStmt);
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
    setState(370);
    match(flicker::EACH);
    setState(372);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(371);
      loopLabel();
    }
    setState(374);
    match(flicker::IDENTIFIER);
    setState(378);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::LEFT_BRACKET) {
      setState(375);
      match(flicker::LEFT_BRACKET);
      setState(376);
      match(flicker::IDENTIFIER);
      setState(377);
      match(flicker::RIGHT_BRACKET);
    }
    setState(380);
    match(flicker::IN);
    setState(381);
    expression(0);
    setState(382);
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
  enterRule(_localctx, 58, flicker::RuleForStmt);
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
    setState(384);
    match(flicker::FOR);
    setState(386);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(385);
      loopLabel();
    }
    setState(390);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::VAL:
      case flicker::VAR: {
        setState(388);
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
      case flicker::NOT:
      case flicker::TRUE: {
        setState(389);
        expression(0);
        break;
      }

      case flicker::SEMICOLON: {
        break;
      }

    default:
      break;
    }
    setState(392);
    match(flicker::SEMICOLON);
    setState(394);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 221803862531538954) != 0) || _la == flicker::TRUE) {
      setState(393);
      expression(0);
    }
    setState(396);
    match(flicker::SEMICOLON);
    setState(398);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 221803862531538954) != 0) || _la == flicker::TRUE) {
      setState(397);
      expression(0);
    }
    setState(400);
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
  enterRule(_localctx, 60, flicker::RuleBreakStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(402);
    match(flicker::BREAK);
    setState(404);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      setState(403);
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
  enterRule(_localctx, 62, flicker::RuleContinueStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(406);
    match(flicker::CONTINUE);
    setState(408);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      setState(407);
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
  enterRule(_localctx, 64, flicker::RuleWhenStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(410);
    match(flicker::WHEN);
    setState(411);
    expression(0);
    setState(412);
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
  enterRule(_localctx, 66, flicker::RuleReturnStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(414);
    match(flicker::RETURN);
    setState(416);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      setState(415);
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
  enterRule(_localctx, 68, flicker::RulePrintStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(418);
    match(flicker::PRINT);
    setState(419);
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
  enterRule(_localctx, 70, flicker::RuleConsoleErrorStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(421);
    match(flicker::PRINT_ERROR);
    setState(422);
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
  enterRule(_localctx, 72, flicker::RulePassStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(424);
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
  enterRule(_localctx, 74, flicker::RuleWhenBody);

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
    newline();
    setState(427);
    match(flicker::INDENT);
    setState(428);
    whenContents();
    setState(429);
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
  enterRule(_localctx, 76, flicker::RuleWhenContents);
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
    setState(434); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(431);
              whenCase();
              setState(432);
              newline();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(436); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(440);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
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
      case flicker::NOT:
      case flicker::TRUE: {
        setState(438);
        whenCase();
        break;
      }

      case flicker::ELSE: {
        setState(439);
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
    setState(443);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::LINE) {
      setState(442);
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
  enterRule(_localctx, 78, flicker::RuleWhenCase);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(445);
    expression(0);
    setState(446);
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
  enterRule(_localctx, 80, flicker::RuleElseCase);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(448);
    match(flicker::ELSE);
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

tree::TerminalNode* flicker::BitShiftExprContext::SHL() {
  return getToken(flicker::SHL, 0);
}

tree::TerminalNode* flicker::BitShiftExprContext::SHR() {
  return getToken(flicker::SHR, 0);
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

tree::TerminalNode* flicker::AssignmentContext::EQ() {
  return getToken(flicker::EQ, 0);
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
  size_t startState = 82;
  enterRecursionRule(_localctx, 82, flicker::RuleExpression, precedence);

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
    setState(468);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ScopedIdentifierContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(452);
      match(flicker::IDENTIFIER);
      setState(453);
      match(flicker::COLON_COLON);
      setState(454);
      match(flicker::IDENTIFIER);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<IdentifierContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(455);
      match(flicker::IDENTIFIER);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ConstantContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(456);
      constantExpr();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<InterpolationContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(457);
      interpolationExpr();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ListOrMapContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(458);
      listOrMapLiteral();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<LambdaContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(459);
      lambdaLiteral();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(460);
      match(flicker::LEFT_PAREN);
      setState(461);
      expression(0);
      setState(462);
      match(flicker::RIGHT_PAREN);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<PrefixExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(464);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 335577088) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(465);
      expression(13);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<NotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(466);
      match(flicker::NOT);
      setState(467);
      expression(3);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(556);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(554);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<RangeExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(470);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(471);
          _la = _input->LA(1);
          if (!(_la == flicker::DOT_DOT

          || _la == flicker::DOT_DOT_LT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(472);
          expression(21);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<NilCoalescingOpContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(473);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(474);
          match(flicker::QUEST_COLON);
          setState(475);
          expression(16);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<PowerExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(476);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(477);
          match(flicker::STAR_STAR);
          setState(478);
          expression(14);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<FactorExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(479);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(480);
          _la = _input->LA(1);
          if (!(_la == flicker::SLASH

          || _la == flicker::STAR)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(481);
          expression(13);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<TermExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(482);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(483);
          _la = _input->LA(1);
          if (!(_la == flicker::PLUS

          || _la == flicker::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(484);
          expression(12);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BitShiftExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(485);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(486);
          _la = _input->LA(1);
          if (!(_la == flicker::SHL

          || _la == flicker::SHR)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(487);
          expression(11);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BitwisExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(488);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(489);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 28672) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(490);
          expression(10);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<IsExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(491);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(495);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
          case 1: {
            setState(492);
            match(flicker::IS);
            break;
          }

          case 2: {
            setState(493);
            match(flicker::IS);
            setState(494);
            match(flicker::NOT);
            break;
          }

          default:
            break;
          }
          setState(497);
          expression(9);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<InExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(498);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(502);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case flicker::IN: {
              setState(499);
              match(flicker::IN);
              break;
            }

            case flicker::NOT: {
              setState(500);
              match(flicker::NOT);
              setState(501);
              match(flicker::IN);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(504);
          expression(8);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<ComparisonContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(505);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(506);
          comparisonOperator();
          setState(507);
          expression(7);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(509);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(510);
          match(flicker::AND);
          setState(511);
          expression(6);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(512);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(513);
          match(flicker::OR);
          setState(514);
          expression(5);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<IfExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(515);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(516);
          match(flicker::IF);
          setState(517);
          expression(0);
          setState(518);
          match(flicker::ELSE);
          setState(519);
          expression(3);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<AssignmentContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(521);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(522);
          match(flicker::EQ);
          setState(523);
          expression(1);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<MemberContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(524);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(525);
          _la = _input->LA(1);
          if (!(_la == flicker::DOT

          || _la == flicker::QUEST_DOT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(526);
          match(flicker::IDENTIFIER);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<CallContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(527);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(528);
          match(flicker::LEFT_PAREN);
          setState(537);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 221803862531538954) != 0) || _la == flicker::TRUE) {
            setState(529);
            expression(0);
            setState(534);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == flicker::COMMA) {
              setState(530);
              match(flicker::COMMA);
              setState(531);
              expression(0);
              setState(536);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(539);
          match(flicker::RIGHT_PAREN);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<ArrayAccessContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(540);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(541);
          match(flicker::LEFT_BRACKET);

          setState(542);
          expression(0);
          setState(547);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == flicker::COMMA) {
            setState(543);
            match(flicker::COMMA);
            setState(544);
            expression(0);
            setState(549);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(550);
          match(flicker::RIGHT_BRACKET);
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<LambdaCallContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(552);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(553);
          braceLambda();
          break;
        }

        default:
          break;
        } 
      }
      setState(558);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
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
  enterRule(_localctx, 84, flicker::RuleComparisonOperator);
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
    setState(559);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 67108864000) != 0))) {
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
  enterRule(_localctx, 86, flicker::RuleInterpolationExpr);
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
    setState(565); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(561);
      match(flicker::INTERPOLATION);
      setState(563);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx)) {
      case 1: {
        setState(562);
        expression(0);
        break;
      }

      default:
        break;
      }
      setState(567); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == flicker::INTERPOLATION);
    setState(569);
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
  enterRule(_localctx, 88, flicker::RuleConstantExpr);
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
    setState(571);
    _la = _input->LA(1);
    if (!(((((_la - 37) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 37)) & 17180401673) != 0))) {
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
  enterRule(_localctx, 90, flicker::RuleListOrMapLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(575);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(573);
      listLiteral();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(574);
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
  enterRule(_localctx, 92, flicker::RuleListLiteral);
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
    setState(577);
    match(flicker::LEFT_BRACKET);
    setState(579);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 221803862531538954) != 0) || _la == flicker::TRUE) {
      setState(578);
      listItems();
    }
    setState(581);
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
  enterRule(_localctx, 94, flicker::RuleListItems);
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
    setState(583);
    expression(0);
    setState(588);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(584);
        match(flicker::COMMA);
        setState(585);
        expression(0); 
      }
      setState(590);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
    }
    setState(592);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COMMA) {
      setState(591);
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
  enterRule(_localctx, 96, flicker::RuleMapLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(594);
    match(flicker::LEFT_BRACKET);
    setState(597);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::RIGHT_ARROW: {
        setState(595);
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
      case flicker::NOT:
      case flicker::TRUE: {
        setState(596);
        mapItems();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(599);
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
  enterRule(_localctx, 98, flicker::RuleMapItems);
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
    setState(601);
    mapItem();
    setState(606);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(602);
        match(flicker::COMMA);
        setState(603);
        mapItem(); 
      }
      setState(608);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx);
    }
    setState(610);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COMMA) {
      setState(609);
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
  enterRule(_localctx, 100, flicker::RuleMapItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(612);
    expression(0);
    setState(613);
    match(flicker::RIGHT_ARROW);
    setState(614);
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
  enterRule(_localctx, 102, flicker::RuleLambdaLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(616);
    match(flicker::FUN);
    setState(619);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::LEFT_BRACE: {
        setState(617);
        braceLambda();
        break;
      }

      case flicker::LEFT_PAREN:
      case flicker::IDENTIFIER: {
        setState(618);
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
  enterRule(_localctx, 104, flicker::RuleLambdaParams);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(623);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(621);
        paramList();
        break;
      }

      case flicker::LEFT_PAREN: {
        enterOuterAlt(_localctx, 2);
        setState(622);
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
  enterRule(_localctx, 106, flicker::RuleParenthesizedOptionalParamList);
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
    match(flicker::LEFT_PAREN);
    setState(627);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::IDENTIFIER) {
      setState(626);
      paramList();
    }
    setState(629);
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
  enterRule(_localctx, 108, flicker::RuleBlockLambda);

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
    lambdaParams();
    setState(635);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::DO:
      case flicker::LINE: {
        setState(632);
        blockOrStatement();
        break;
      }

      case flicker::EQ: {
        setState(633);
        match(flicker::EQ);
        setState(634);
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
  enterRule(_localctx, 110, flicker::RuleBraceLambda);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(637);
    match(flicker::LEFT_BRACE);
    setState(640);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx)) {
    case 1: {
      setState(638);
      statementLambdaBody();
      break;
    }

    case 2: {
      setState(639);
      exprLambdaBody();
      break;
    }

    default:
      break;
    }
    setState(642);
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
  enterRule(_localctx, 112, flicker::RuleStatementLambdaBody);
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
    setState(647);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx)) {
    case 1: {
      setState(644);
      lambdaParams();
      setState(645);
      match(flicker::RIGHT_ARROW);
      break;
    }

    default:
      break;
    }
    setState(654);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -2072608623799795702) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & 4033) != 0)) {
      setState(649);
      codeItem();
      setState(650);
      match(flicker::SEMICOLON);
      setState(656);
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
  enterRule(_localctx, 114, flicker::RuleExprLambdaBody);
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
    setState(658);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::LEFT_PAREN

    || _la == flicker::IDENTIFIER) {
      setState(657);
      lambdaParams();
    }
    setState(660);
    match(flicker::EQ);
    setState(661);
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
    case 41: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool flicker::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 20);
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
    case 12: return precpred(_ctx, 2);
    case 13: return precpred(_ctx, 1);
    case 14: return precpred(_ctx, 19);
    case 15: return precpred(_ctx, 18);
    case 16: return precpred(_ctx, 17);
    case 17: return precpred(_ctx, 16);

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
