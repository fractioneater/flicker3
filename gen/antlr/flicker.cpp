
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
      "variableDecl", "typeParam", "functionDecl", "funcReturnType", "functionContents", 
      "paramList", "param", "block", "blockBody", "accessSpecifier", "classDecl", 
      "classBody", "companionNamespace", "classItem", "method", "usingStatement", 
      "importList", "importItem", "loopLabel", "doStatement", "blockOrStatement", 
      "ifStmt", "whileStmt", "eachStmt", "forStmt", "breakStmt", "continueStmt", 
      "whenStmt", "returnStmt", "printStmt", "consoleErrorStmt", "passStmt", 
      "whenBody", "whenContents", "whenCase", "elseCase", "expression", 
      "comparisonOperator", "interpolationExpr", "constantExpr", "listOrMapLiteral", 
      "listLiteral", "listItems", "mapLiteral", "mapItems", "mapItem", "lambdaLiteral", 
      "lambdaParams", "parenthesizedOptionalParamList", "lambdaBody", "braceBody", 
      "terminator"
    },
    std::vector<std::string>{
    },
    std::vector<std::string>{
      "", "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET", 
      "LEFT_BRACE", "RIGHT_BRACE", "SEMICOLON", "COMMA", "PLUS", "SLASH", 
      "PERCENT", "PIPE", "CARET", "AMPERSAND", "TILDE", "DOT", "DOT_DOT", 
      "DOT_DOT_LT", "QUEST", "QUEST_QUEST", "QUEST_DOT", "COLON", "COLON_COLON", 
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
  	4,1,79,645,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,2,57,7,57,1,0,5,0,118,8,0,10,0,12,0,121,9,0,1,0,1,0,1,0,5,0,126,8,
  	0,10,0,12,0,129,9,0,1,0,1,0,1,1,4,1,134,8,1,11,1,12,1,135,1,2,1,2,3,2,
  	140,8,2,1,2,3,2,143,8,2,1,3,1,3,3,3,147,8,3,1,4,1,4,3,4,151,8,4,1,4,1,
  	4,1,4,3,4,156,8,4,3,4,158,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,3,5,175,8,5,1,6,1,6,1,6,1,6,3,6,181,8,6,1,6,1,6,3,
  	6,185,8,6,1,7,1,7,1,7,1,8,1,8,1,8,3,8,193,8,8,1,8,1,8,3,8,197,8,8,1,8,
  	1,8,3,8,201,8,8,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,10,3,10,211,8,10,1,11,
  	1,11,1,11,5,11,216,8,11,10,11,12,11,219,9,11,1,12,1,12,1,12,1,12,1,13,
  	3,13,226,8,13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,5,14,236,8,14,10,
  	14,12,14,239,9,14,1,15,1,15,1,16,1,16,1,16,3,16,246,8,16,1,16,1,16,3,
  	16,250,8,16,1,16,1,16,1,17,1,17,1,17,3,17,257,8,17,1,17,1,17,1,17,5,17,
  	262,8,17,10,17,12,17,265,9,17,1,18,1,18,1,18,1,18,1,18,1,18,5,18,273,
  	8,18,10,18,12,18,276,9,18,1,18,1,18,1,19,5,19,281,8,19,10,19,12,19,284,
  	9,19,1,19,1,19,3,19,288,8,19,1,20,3,20,291,8,20,1,20,1,20,1,21,1,21,1,
  	21,1,21,1,21,1,21,3,21,301,8,21,3,21,303,8,21,1,21,1,21,1,21,1,21,3,21,
  	309,8,21,1,22,1,22,1,22,5,22,314,8,22,10,22,12,22,317,9,22,1,23,1,23,
  	1,23,1,23,3,23,323,8,23,1,24,1,24,1,24,1,25,1,25,1,25,1,26,1,26,3,26,
  	333,8,26,1,27,1,27,1,27,1,27,1,27,1,27,1,27,5,27,342,8,27,10,27,12,27,
  	345,9,27,1,27,1,27,3,27,349,8,27,1,28,1,28,3,28,353,8,28,1,28,1,28,1,
  	28,1,29,1,29,3,29,360,8,29,1,29,1,29,1,29,1,29,3,29,366,8,29,1,29,1,29,
  	1,29,1,29,1,30,1,30,3,30,374,8,30,1,30,1,30,3,30,378,8,30,1,30,1,30,3,
  	30,382,8,30,1,30,1,30,3,30,386,8,30,1,30,1,30,1,31,1,31,3,31,392,8,31,
  	1,32,1,32,3,32,396,8,32,1,33,1,33,1,33,1,33,1,34,1,34,3,34,404,8,34,1,
  	35,1,35,1,35,1,36,1,36,1,36,1,37,1,37,1,38,1,38,1,38,1,38,1,38,1,39,1,
  	39,1,39,4,39,422,8,39,11,39,12,39,423,1,39,1,39,1,39,3,39,429,8,39,1,
  	40,1,40,1,40,1,41,1,41,1,41,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,
  	42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,3,42,454,8,42,1,42,1,42,1,
  	42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,
  	42,1,42,1,42,1,42,1,42,1,42,3,42,478,8,42,1,42,1,42,1,42,1,42,1,42,3,
  	42,485,8,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,
  	42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,
  	42,1,42,1,42,5,42,515,8,42,10,42,12,42,518,9,42,3,42,520,8,42,1,42,1,
  	42,1,42,1,42,1,42,1,42,5,42,528,8,42,10,42,12,42,531,9,42,1,42,1,42,1,
  	42,1,42,5,42,537,8,42,10,42,12,42,540,9,42,1,43,1,43,1,44,1,44,3,44,546,
  	8,44,1,44,1,44,1,45,1,45,1,46,1,46,3,46,554,8,46,1,47,1,47,3,47,558,8,
  	47,1,47,1,47,1,48,1,48,1,48,5,48,565,8,48,10,48,12,48,568,9,48,1,48,3,
  	48,571,8,48,1,49,1,49,1,49,3,49,576,8,49,1,49,1,49,1,50,1,50,1,50,5,50,
  	583,8,50,10,50,12,50,586,9,50,1,50,3,50,589,8,50,1,51,1,51,1,51,1,51,
  	1,52,1,52,1,52,1,52,1,52,1,52,3,52,601,8,52,1,53,1,53,1,53,3,53,606,8,
  	53,1,54,1,54,3,54,610,8,54,1,54,1,54,1,55,1,55,3,55,616,8,55,1,56,1,56,
  	1,56,4,56,621,8,56,11,56,12,56,622,5,56,625,8,56,10,56,12,56,628,9,56,
  	1,56,3,56,631,8,56,1,56,5,56,634,8,56,10,56,12,56,637,9,56,1,56,1,56,
  	1,57,1,57,3,57,643,8,57,1,57,0,1,84,58,0,2,4,6,8,10,12,14,16,18,20,22,
  	24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,
  	70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,
  	112,114,0,12,2,0,51,51,58,58,1,0,73,74,2,0,22,22,27,27,3,0,15,15,26,26,
  	28,28,1,0,17,18,2,0,10,10,24,24,2,0,9,9,26,26,1,0,66,67,1,0,12,14,2,0,
  	16,16,21,21,2,0,29,29,31,35,5,0,37,37,40,40,50,50,56,56,71,71,696,0,119,
  	1,0,0,0,2,133,1,0,0,0,4,142,1,0,0,0,6,146,1,0,0,0,8,148,1,0,0,0,10,174,
  	1,0,0,0,12,176,1,0,0,0,14,186,1,0,0,0,16,189,1,0,0,0,18,204,1,0,0,0,20,
  	210,1,0,0,0,22,212,1,0,0,0,24,220,1,0,0,0,26,225,1,0,0,0,28,237,1,0,0,
  	0,30,240,1,0,0,0,32,242,1,0,0,0,34,256,1,0,0,0,36,266,1,0,0,0,38,282,
  	1,0,0,0,40,290,1,0,0,0,42,308,1,0,0,0,44,310,1,0,0,0,46,322,1,0,0,0,48,
  	324,1,0,0,0,50,327,1,0,0,0,52,332,1,0,0,0,54,334,1,0,0,0,56,350,1,0,0,
  	0,58,357,1,0,0,0,60,371,1,0,0,0,62,389,1,0,0,0,64,393,1,0,0,0,66,397,
  	1,0,0,0,68,401,1,0,0,0,70,405,1,0,0,0,72,408,1,0,0,0,74,411,1,0,0,0,76,
  	413,1,0,0,0,78,421,1,0,0,0,80,430,1,0,0,0,82,433,1,0,0,0,84,453,1,0,0,
  	0,86,541,1,0,0,0,88,543,1,0,0,0,90,549,1,0,0,0,92,553,1,0,0,0,94,555,
  	1,0,0,0,96,561,1,0,0,0,98,572,1,0,0,0,100,579,1,0,0,0,102,590,1,0,0,0,
  	104,594,1,0,0,0,106,605,1,0,0,0,108,607,1,0,0,0,110,615,1,0,0,0,112,617,
  	1,0,0,0,114,642,1,0,0,0,116,118,3,2,1,0,117,116,1,0,0,0,118,121,1,0,0,
  	0,119,117,1,0,0,0,119,120,1,0,0,0,120,127,1,0,0,0,121,119,1,0,0,0,122,
  	123,3,6,3,0,123,124,3,4,2,0,124,126,1,0,0,0,125,122,1,0,0,0,126,129,1,
  	0,0,0,127,125,1,0,0,0,127,128,1,0,0,0,128,130,1,0,0,0,129,127,1,0,0,0,
  	130,131,5,0,0,1,131,1,1,0,0,0,132,134,5,79,0,0,133,132,1,0,0,0,134,135,
  	1,0,0,0,135,133,1,0,0,0,135,136,1,0,0,0,136,3,1,0,0,0,137,139,3,2,1,0,
  	138,140,5,0,0,1,139,138,1,0,0,0,139,140,1,0,0,0,140,143,1,0,0,0,141,143,
  	5,0,0,1,142,137,1,0,0,0,142,141,1,0,0,0,143,5,1,0,0,0,144,147,3,10,5,
  	0,145,147,3,84,42,0,146,144,1,0,0,0,146,145,1,0,0,0,147,7,1,0,0,0,148,
  	150,5,36,0,0,149,151,5,19,0,0,150,149,1,0,0,0,150,151,1,0,0,0,151,157,
  	1,0,0,0,152,153,7,0,0,0,153,155,5,36,0,0,154,156,5,19,0,0,155,154,1,0,
  	0,0,155,156,1,0,0,0,156,158,1,0,0,0,157,152,1,0,0,0,157,158,1,0,0,0,158,
  	9,1,0,0,0,159,175,3,12,6,0,160,175,3,16,8,0,161,175,3,32,16,0,162,175,
  	3,42,21,0,163,175,3,54,27,0,164,175,3,56,28,0,165,175,3,58,29,0,166,175,
  	3,60,30,0,167,175,3,62,31,0,168,175,3,64,32,0,169,175,3,66,33,0,170,175,
  	3,68,34,0,171,175,3,70,35,0,172,175,3,72,36,0,173,175,3,74,37,0,174,159,
  	1,0,0,0,174,160,1,0,0,0,174,161,1,0,0,0,174,162,1,0,0,0,174,163,1,0,0,
  	0,174,164,1,0,0,0,174,165,1,0,0,0,174,166,1,0,0,0,174,167,1,0,0,0,174,
  	168,1,0,0,0,174,169,1,0,0,0,174,170,1,0,0,0,174,171,1,0,0,0,174,172,1,
  	0,0,0,174,173,1,0,0,0,175,11,1,0,0,0,176,177,7,1,0,0,177,180,5,36,0,0,
  	178,179,5,22,0,0,179,181,3,8,4,0,180,178,1,0,0,0,180,181,1,0,0,0,181,
  	184,1,0,0,0,182,183,5,30,0,0,183,185,3,84,42,0,184,182,1,0,0,0,184,185,
  	1,0,0,0,185,13,1,0,0,0,186,187,7,0,0,0,187,188,5,36,0,0,188,15,1,0,0,
  	0,189,190,5,52,0,0,190,192,5,36,0,0,191,193,3,14,7,0,192,191,1,0,0,0,
  	192,193,1,0,0,0,193,194,1,0,0,0,194,196,5,1,0,0,195,197,3,22,11,0,196,
  	195,1,0,0,0,196,197,1,0,0,0,197,198,1,0,0,0,198,200,5,2,0,0,199,201,3,
  	18,9,0,200,199,1,0,0,0,200,201,1,0,0,0,201,202,1,0,0,0,202,203,3,20,10,
  	0,203,17,1,0,0,0,204,205,7,2,0,0,205,206,5,36,0,0,206,19,1,0,0,0,207,
  	211,3,52,26,0,208,209,5,30,0,0,209,211,3,84,42,0,210,207,1,0,0,0,210,
  	208,1,0,0,0,211,21,1,0,0,0,212,217,3,24,12,0,213,214,5,8,0,0,214,216,
  	3,24,12,0,215,213,1,0,0,0,216,219,1,0,0,0,217,215,1,0,0,0,217,218,1,0,
  	0,0,218,23,1,0,0,0,219,217,1,0,0,0,220,221,5,36,0,0,221,222,5,22,0,0,
  	222,223,3,8,4,0,223,25,1,0,0,0,224,226,5,46,0,0,225,224,1,0,0,0,225,226,
  	1,0,0,0,226,227,1,0,0,0,227,228,3,2,1,0,228,229,5,77,0,0,229,230,3,28,
  	14,0,230,231,5,78,0,0,231,27,1,0,0,0,232,233,3,6,3,0,233,234,3,4,2,0,
  	234,236,1,0,0,0,235,232,1,0,0,0,236,239,1,0,0,0,237,235,1,0,0,0,237,238,
  	1,0,0,0,238,29,1,0,0,0,239,237,1,0,0,0,240,241,5,64,0,0,241,31,1,0,0,
  	0,242,243,5,43,0,0,243,245,5,36,0,0,244,246,3,14,7,0,245,244,1,0,0,0,
  	245,246,1,0,0,0,246,249,1,0,0,0,247,248,5,55,0,0,248,250,3,8,4,0,249,
  	247,1,0,0,0,249,250,1,0,0,0,250,251,1,0,0,0,251,252,3,34,17,0,252,33,
  	1,0,0,0,253,254,3,36,18,0,254,255,3,2,1,0,255,257,1,0,0,0,256,253,1,0,
  	0,0,256,257,1,0,0,0,257,263,1,0,0,0,258,259,3,38,19,0,259,260,3,2,1,0,
  	260,262,1,0,0,0,261,258,1,0,0,0,262,265,1,0,0,0,263,261,1,0,0,0,263,264,
  	1,0,0,0,264,35,1,0,0,0,265,263,1,0,0,0,266,267,5,45,0,0,267,268,3,2,1,
  	0,268,274,5,77,0,0,269,270,3,38,19,0,270,271,3,2,1,0,271,273,1,0,0,0,
  	272,269,1,0,0,0,273,276,1,0,0,0,274,272,1,0,0,0,274,275,1,0,0,0,275,277,
  	1,0,0,0,276,274,1,0,0,0,277,278,5,78,0,0,278,37,1,0,0,0,279,281,3,30,
  	15,0,280,279,1,0,0,0,281,284,1,0,0,0,282,280,1,0,0,0,282,283,1,0,0,0,
  	283,287,1,0,0,0,284,282,1,0,0,0,285,288,3,12,6,0,286,288,3,40,20,0,287,
  	285,1,0,0,0,287,286,1,0,0,0,288,39,1,0,0,0,289,291,5,60,0,0,290,289,1,
  	0,0,0,290,291,1,0,0,0,291,292,1,0,0,0,292,293,3,16,8,0,293,41,1,0,0,0,
  	294,295,5,72,0,0,295,302,5,37,0,0,296,300,5,51,0,0,297,301,5,16,0,0,298,
  	301,5,24,0,0,299,301,3,44,22,0,300,297,1,0,0,0,300,298,1,0,0,0,300,299,
  	1,0,0,0,301,303,1,0,0,0,302,296,1,0,0,0,302,303,1,0,0,0,303,309,1,0,0,
  	0,304,305,5,72,0,0,305,306,5,36,0,0,306,307,5,30,0,0,307,309,3,8,4,0,
  	308,294,1,0,0,0,308,304,1,0,0,0,309,43,1,0,0,0,310,315,3,46,23,0,311,
  	312,5,8,0,0,312,314,3,46,23,0,313,311,1,0,0,0,314,317,1,0,0,0,315,313,
  	1,0,0,0,315,316,1,0,0,0,316,45,1,0,0,0,317,315,1,0,0,0,318,323,5,36,0,
  	0,319,320,5,36,0,0,320,321,5,27,0,0,321,323,5,36,0,0,322,318,1,0,0,0,
  	322,319,1,0,0,0,323,47,1,0,0,0,324,325,5,22,0,0,325,326,5,36,0,0,326,
  	49,1,0,0,0,327,328,5,46,0,0,328,329,3,6,3,0,329,51,1,0,0,0,330,333,3,
  	26,13,0,331,333,3,50,25,0,332,330,1,0,0,0,332,331,1,0,0,0,333,53,1,0,
  	0,0,334,335,5,53,0,0,335,336,3,84,42,0,336,343,3,52,26,0,337,338,5,48,
  	0,0,338,339,3,84,42,0,339,340,3,52,26,0,340,342,1,0,0,0,341,337,1,0,0,
  	0,342,345,1,0,0,0,343,341,1,0,0,0,343,344,1,0,0,0,344,348,1,0,0,0,345,
  	343,1,0,0,0,346,347,5,49,0,0,347,349,3,52,26,0,348,346,1,0,0,0,348,349,
  	1,0,0,0,349,55,1,0,0,0,350,352,5,76,0,0,351,353,3,48,24,0,352,351,1,0,
  	0,0,352,353,1,0,0,0,353,354,1,0,0,0,354,355,3,84,42,0,355,356,3,52,26,
  	0,356,57,1,0,0,0,357,359,5,47,0,0,358,360,3,48,24,0,359,358,1,0,0,0,359,
  	360,1,0,0,0,360,361,1,0,0,0,361,365,5,36,0,0,362,363,5,3,0,0,363,364,
  	5,36,0,0,364,366,5,4,0,0,365,362,1,0,0,0,365,366,1,0,0,0,366,367,1,0,
  	0,0,367,368,5,54,0,0,368,369,3,84,42,0,369,370,3,52,26,0,370,59,1,0,0,
  	0,371,373,5,51,0,0,372,374,3,48,24,0,373,372,1,0,0,0,373,374,1,0,0,0,
  	374,377,1,0,0,0,375,378,3,12,6,0,376,378,3,84,42,0,377,375,1,0,0,0,377,
  	376,1,0,0,0,377,378,1,0,0,0,378,379,1,0,0,0,379,381,5,7,0,0,380,382,3,
  	84,42,0,381,380,1,0,0,0,381,382,1,0,0,0,382,383,1,0,0,0,383,385,5,7,0,
  	0,384,386,3,84,42,0,385,384,1,0,0,0,385,386,1,0,0,0,386,387,1,0,0,0,387,
  	388,3,52,26,0,388,61,1,0,0,0,389,391,5,42,0,0,390,392,3,48,24,0,391,390,
  	1,0,0,0,391,392,1,0,0,0,392,63,1,0,0,0,393,395,5,44,0,0,394,396,3,48,
  	24,0,395,394,1,0,0,0,395,396,1,0,0,0,396,65,1,0,0,0,397,398,5,75,0,0,
  	398,399,3,84,42,0,399,400,3,76,38,0,400,67,1,0,0,0,401,403,5,65,0,0,402,
  	404,3,84,42,0,403,402,1,0,0,0,403,404,1,0,0,0,404,69,1,0,0,0,405,406,
  	5,62,0,0,406,407,3,84,42,0,407,71,1,0,0,0,408,409,5,63,0,0,409,410,3,
  	84,42,0,410,73,1,0,0,0,411,412,5,61,0,0,412,75,1,0,0,0,413,414,3,2,1,
  	0,414,415,5,77,0,0,415,416,3,78,39,0,416,417,5,78,0,0,417,77,1,0,0,0,
  	418,419,3,80,40,0,419,420,3,4,2,0,420,422,1,0,0,0,421,418,1,0,0,0,422,
  	423,1,0,0,0,423,421,1,0,0,0,423,424,1,0,0,0,424,428,1,0,0,0,425,426,3,
  	82,41,0,426,427,3,4,2,0,427,429,1,0,0,0,428,425,1,0,0,0,428,429,1,0,0,
  	0,429,79,1,0,0,0,430,431,3,84,42,0,431,432,3,52,26,0,432,81,1,0,0,0,433,
  	434,5,49,0,0,434,435,3,52,26,0,435,83,1,0,0,0,436,437,6,42,-1,0,437,438,
  	5,36,0,0,438,439,5,23,0,0,439,454,5,36,0,0,440,454,5,36,0,0,441,454,3,
  	90,45,0,442,454,3,88,44,0,443,454,3,92,46,0,444,454,3,104,52,0,445,446,
  	5,1,0,0,446,447,3,84,42,0,447,448,5,2,0,0,448,454,1,0,0,0,449,450,7,3,
  	0,0,450,454,3,84,42,13,451,452,5,57,0,0,452,454,3,84,42,3,453,436,1,0,
  	0,0,453,440,1,0,0,0,453,441,1,0,0,0,453,442,1,0,0,0,453,443,1,0,0,0,453,
  	444,1,0,0,0,453,445,1,0,0,0,453,449,1,0,0,0,453,451,1,0,0,0,454,538,1,
  	0,0,0,455,456,10,19,0,0,456,457,7,4,0,0,457,537,3,84,42,20,458,459,10,
  	14,0,0,459,460,5,25,0,0,460,537,3,84,42,14,461,462,10,12,0,0,462,463,
  	7,5,0,0,463,537,3,84,42,13,464,465,10,11,0,0,465,466,7,6,0,0,466,537,
  	3,84,42,12,467,468,10,10,0,0,468,469,7,7,0,0,469,537,3,84,42,11,470,471,
  	10,9,0,0,471,472,7,8,0,0,472,537,3,84,42,10,473,477,10,8,0,0,474,478,
  	5,55,0,0,475,476,5,55,0,0,476,478,5,57,0,0,477,474,1,0,0,0,477,475,1,
  	0,0,0,478,479,1,0,0,0,479,537,3,84,42,9,480,484,10,7,0,0,481,485,5,54,
  	0,0,482,483,5,57,0,0,483,485,5,54,0,0,484,481,1,0,0,0,484,482,1,0,0,0,
  	485,486,1,0,0,0,486,537,3,84,42,8,487,488,10,6,0,0,488,489,3,86,43,0,
  	489,490,3,84,42,7,490,537,1,0,0,0,491,492,10,5,0,0,492,493,5,41,0,0,493,
  	537,3,84,42,6,494,495,10,4,0,0,495,496,5,59,0,0,496,537,3,84,42,5,497,
  	498,10,2,0,0,498,499,5,53,0,0,499,500,3,84,42,0,500,501,5,49,0,0,501,
  	502,3,84,42,3,502,537,1,0,0,0,503,504,10,1,0,0,504,505,5,30,0,0,505,537,
  	3,84,42,1,506,507,10,18,0,0,507,508,7,9,0,0,508,537,5,36,0,0,509,510,
  	10,17,0,0,510,519,5,1,0,0,511,516,3,84,42,0,512,513,5,8,0,0,513,515,3,
  	84,42,0,514,512,1,0,0,0,515,518,1,0,0,0,516,514,1,0,0,0,516,517,1,0,0,
  	0,517,520,1,0,0,0,518,516,1,0,0,0,519,511,1,0,0,0,519,520,1,0,0,0,520,
  	521,1,0,0,0,521,537,5,2,0,0,522,523,10,16,0,0,523,524,5,3,0,0,524,529,
  	3,84,42,0,525,526,5,8,0,0,526,528,3,84,42,0,527,525,1,0,0,0,528,531,1,
  	0,0,0,529,527,1,0,0,0,529,530,1,0,0,0,530,532,1,0,0,0,531,529,1,0,0,0,
  	532,533,5,4,0,0,533,537,1,0,0,0,534,535,10,15,0,0,535,537,5,20,0,0,536,
  	455,1,0,0,0,536,458,1,0,0,0,536,461,1,0,0,0,536,464,1,0,0,0,536,467,1,
  	0,0,0,536,470,1,0,0,0,536,473,1,0,0,0,536,480,1,0,0,0,536,487,1,0,0,0,
  	536,491,1,0,0,0,536,494,1,0,0,0,536,497,1,0,0,0,536,503,1,0,0,0,536,506,
  	1,0,0,0,536,509,1,0,0,0,536,522,1,0,0,0,536,534,1,0,0,0,537,540,1,0,0,
  	0,538,536,1,0,0,0,538,539,1,0,0,0,539,85,1,0,0,0,540,538,1,0,0,0,541,
  	542,7,10,0,0,542,87,1,0,0,0,543,545,5,38,0,0,544,546,3,84,42,0,545,544,
  	1,0,0,0,545,546,1,0,0,0,546,547,1,0,0,0,547,548,5,37,0,0,548,89,1,0,0,
  	0,549,550,7,11,0,0,550,91,1,0,0,0,551,554,3,94,47,0,552,554,3,98,49,0,
  	553,551,1,0,0,0,553,552,1,0,0,0,554,93,1,0,0,0,555,557,5,3,0,0,556,558,
  	3,96,48,0,557,556,1,0,0,0,557,558,1,0,0,0,558,559,1,0,0,0,559,560,5,4,
  	0,0,560,95,1,0,0,0,561,566,3,84,42,0,562,563,5,8,0,0,563,565,3,84,42,
  	0,564,562,1,0,0,0,565,568,1,0,0,0,566,564,1,0,0,0,566,567,1,0,0,0,567,
  	570,1,0,0,0,568,566,1,0,0,0,569,571,5,8,0,0,570,569,1,0,0,0,570,571,1,
  	0,0,0,571,97,1,0,0,0,572,575,5,3,0,0,573,576,5,27,0,0,574,576,3,100,50,
  	0,575,573,1,0,0,0,575,574,1,0,0,0,576,577,1,0,0,0,577,578,5,4,0,0,578,
  	99,1,0,0,0,579,584,3,102,51,0,580,581,5,8,0,0,581,583,3,102,51,0,582,
  	580,1,0,0,0,583,586,1,0,0,0,584,582,1,0,0,0,584,585,1,0,0,0,585,588,1,
  	0,0,0,586,584,1,0,0,0,587,589,5,8,0,0,588,587,1,0,0,0,588,589,1,0,0,0,
  	589,101,1,0,0,0,590,591,3,84,42,0,591,592,5,27,0,0,592,593,3,84,42,0,
  	593,103,1,0,0,0,594,595,5,52,0,0,595,600,3,106,53,0,596,597,5,27,0,0,
  	597,601,3,110,55,0,598,599,5,30,0,0,599,601,3,84,42,0,600,596,1,0,0,0,
  	600,598,1,0,0,0,601,105,1,0,0,0,602,606,3,22,11,0,603,606,3,108,54,0,
  	604,606,1,0,0,0,605,602,1,0,0,0,605,603,1,0,0,0,605,604,1,0,0,0,606,107,
  	1,0,0,0,607,609,5,1,0,0,608,610,3,22,11,0,609,608,1,0,0,0,609,610,1,0,
  	0,0,610,611,1,0,0,0,611,612,5,2,0,0,612,109,1,0,0,0,613,616,3,112,56,
  	0,614,616,3,26,13,0,615,613,1,0,0,0,615,614,1,0,0,0,616,111,1,0,0,0,617,
  	626,5,5,0,0,618,620,3,10,5,0,619,621,3,114,57,0,620,619,1,0,0,0,621,622,
  	1,0,0,0,622,620,1,0,0,0,622,623,1,0,0,0,623,625,1,0,0,0,624,618,1,0,0,
  	0,625,628,1,0,0,0,626,624,1,0,0,0,626,627,1,0,0,0,627,630,1,0,0,0,628,
  	626,1,0,0,0,629,631,3,10,5,0,630,629,1,0,0,0,630,631,1,0,0,0,631,635,
  	1,0,0,0,632,634,3,114,57,0,633,632,1,0,0,0,634,637,1,0,0,0,635,633,1,
  	0,0,0,635,636,1,0,0,0,636,638,1,0,0,0,637,635,1,0,0,0,638,639,5,6,0,0,
  	639,113,1,0,0,0,640,643,5,7,0,0,641,643,3,2,1,0,642,640,1,0,0,0,642,641,
  	1,0,0,0,643,115,1,0,0,0,72,119,127,135,139,142,146,150,155,157,174,180,
  	184,192,196,200,210,217,225,237,245,249,256,263,274,282,287,290,300,302,
  	308,315,322,332,343,348,352,359,365,373,377,381,385,391,395,403,423,428,
  	453,477,484,516,519,529,536,538,545,553,557,566,570,575,584,588,600,605,
  	609,615,622,626,630,635,642
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
    setState(119);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == flicker::LINE) {
      setState(116);
      newline();
      setState(121);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(127);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -2072608623799795702) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & 4033) != 0)) {
      setState(122);
      topLevel();
      setState(123);
      statementEnd();
      setState(129);
      _errHandler->sync(this);
      _la = _input->LA(1);
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
    setState(142);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::LINE: {
        enterOuterAlt(_localctx, 1);
        setState(137);
        newline();
        setState(139);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          setState(138);
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
        setState(141);
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
    setState(146);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(144);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(145);
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
    setState(148);
    match(flicker::IDENTIFIER);
    setState(150);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::QUEST) {
      setState(149);
      match(flicker::QUEST);
    }
    setState(157);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::FOR

    || _la == flicker::OF) {
      setState(152);
      _la = _input->LA(1);
      if (!(_la == flicker::FOR

      || _la == flicker::OF)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(153);
      match(flicker::IDENTIFIER);
      setState(155);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == flicker::QUEST) {
        setState(154);
        match(flicker::QUEST);
      }
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
    setState(174);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::VAL:
      case flicker::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(159);
        variableDecl();
        break;
      }

      case flicker::FUN: {
        enterOuterAlt(_localctx, 2);
        setState(160);
        functionDecl();
        break;
      }

      case flicker::CLASS: {
        enterOuterAlt(_localctx, 3);
        setState(161);
        classDecl();
        break;
      }

      case flicker::USING: {
        enterOuterAlt(_localctx, 4);
        setState(162);
        usingStatement();
        break;
      }

      case flicker::IF: {
        enterOuterAlt(_localctx, 5);
        setState(163);
        ifStmt();
        break;
      }

      case flicker::WHILE: {
        enterOuterAlt(_localctx, 6);
        setState(164);
        whileStmt();
        break;
      }

      case flicker::EACH: {
        enterOuterAlt(_localctx, 7);
        setState(165);
        eachStmt();
        break;
      }

      case flicker::FOR: {
        enterOuterAlt(_localctx, 8);
        setState(166);
        forStmt();
        break;
      }

      case flicker::BREAK: {
        enterOuterAlt(_localctx, 9);
        setState(167);
        breakStmt();
        break;
      }

      case flicker::CONTINUE: {
        enterOuterAlt(_localctx, 10);
        setState(168);
        continueStmt();
        break;
      }

      case flicker::WHEN: {
        enterOuterAlt(_localctx, 11);
        setState(169);
        whenStmt();
        break;
      }

      case flicker::RETURN: {
        enterOuterAlt(_localctx, 12);
        setState(170);
        returnStmt();
        break;
      }

      case flicker::PRINT: {
        enterOuterAlt(_localctx, 13);
        setState(171);
        printStmt();
        break;
      }

      case flicker::PRINT_ERROR: {
        enterOuterAlt(_localctx, 14);
        setState(172);
        consoleErrorStmt();
        break;
      }

      case flicker::PASS: {
        enterOuterAlt(_localctx, 15);
        setState(173);
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
    setState(176);
    _la = _input->LA(1);
    if (!(_la == flicker::VAL

    || _la == flicker::VAR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(177);
    match(flicker::IDENTIFIER);
    setState(180);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(178);
      match(flicker::COLON);
      setState(179);
      type();
    }
    setState(184);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::EQ) {
      setState(182);
      match(flicker::EQ);
      setState(183);
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
  enterRule(_localctx, 14, flicker::RuleTypeParam);
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
    setState(186);
    _la = _input->LA(1);
    if (!(_la == flicker::FOR

    || _la == flicker::OF)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(187);
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
  enterRule(_localctx, 16, flicker::RuleFunctionDecl);
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
    match(flicker::FUN);
    setState(190);
    match(flicker::IDENTIFIER);
    setState(192);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::FOR

    || _la == flicker::OF) {
      setState(191);
      typeParam();
    }
    setState(194);
    match(flicker::LEFT_PAREN);
    setState(196);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::IDENTIFIER) {
      setState(195);
      paramList();
    }
    setState(198);
    match(flicker::RIGHT_PAREN);
    setState(200);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON

    || _la == flicker::RIGHT_ARROW) {
      setState(199);
      funcReturnType();
    }
    setState(202);
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
  enterRule(_localctx, 18, flicker::RuleFuncReturnType);
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
    setState(204);
    _la = _input->LA(1);
    if (!(_la == flicker::COLON

    || _la == flicker::RIGHT_ARROW)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(205);
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
  enterRule(_localctx, 20, flicker::RuleFunctionContents);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(210);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::DO:
      case flicker::LINE: {
        enterOuterAlt(_localctx, 1);
        setState(207);
        blockOrStatement();
        break;
      }

      case flicker::EQ: {
        enterOuterAlt(_localctx, 2);
        setState(208);
        match(flicker::EQ);
        setState(209);
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
  enterRule(_localctx, 22, flicker::RuleParamList);
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
    setState(212);
    param();
    setState(217);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == flicker::COMMA) {
      setState(213);
      match(flicker::COMMA);
      setState(214);
      param();
      setState(219);
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
  enterRule(_localctx, 24, flicker::RuleParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
    match(flicker::IDENTIFIER);
    setState(221);
    match(flicker::COLON);
    setState(222);
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
  enterRule(_localctx, 26, flicker::RuleBlock);
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
    setState(225);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::DO) {
      setState(224);
      match(flicker::DO);
    }
    setState(227);
    newline();
    setState(228);
    match(flicker::INDENT);
    setState(229);
    blockBody();
    setState(230);
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
  enterRule(_localctx, 28, flicker::RuleBlockBody);
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
    setState(237);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -2072608623799795702) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & 4033) != 0)) {
      setState(232);
      topLevel();
      setState(233);
      statementEnd();
      setState(239);
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
  enterRule(_localctx, 30, flicker::RuleAccessSpecifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(240);
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

flicker::ClassBodyContext* flicker::ClassDeclContext::classBody() {
  return getRuleContext<flicker::ClassBodyContext>(0);
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
  enterRule(_localctx, 32, flicker::RuleClassDecl);
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
    setState(242);
    match(flicker::CLASS);
    setState(243);
    match(flicker::IDENTIFIER);
    setState(245);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::FOR

    || _la == flicker::OF) {
      setState(244);
      typeParam();
    }
    setState(249);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::IS) {
      setState(247);
      match(flicker::IS);
      setState(248);
      type();
    }
    setState(251);
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
  enterRule(_localctx, 34, flicker::RuleClassBody);
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
    setState(256);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::CN) {
      setState(253);
      companionNamespace();
      setState(254);
      newline();
    }
    setState(263);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 52) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 52)) & 6295809) != 0)) {
      setState(258);
      classItem();
      setState(259);
      newline();
      setState(265);
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
  enterRule(_localctx, 36, flicker::RuleCompanionNamespace);
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
    setState(266);
    match(flicker::CN);
    setState(267);
    newline();
    setState(268);
    match(flicker::INDENT);
    setState(274);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 52) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 52)) & 6295809) != 0)) {
      setState(269);
      classItem();
      setState(270);
      newline();
      setState(276);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(277);
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
  enterRule(_localctx, 38, flicker::RuleClassItem);
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
    setState(282);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == flicker::PRIVATE) {
      setState(279);
      accessSpecifier();
      setState(284);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(287);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::VAL:
      case flicker::VAR: {
        setState(285);
        variableDecl();
        break;
      }

      case flicker::FUN:
      case flicker::OVERRIDE: {
        setState(286);
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
  enterRule(_localctx, 40, flicker::RuleMethod);
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
    setState(290);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::OVERRIDE) {
      setState(289);
      match(flicker::OVERRIDE);
    }
    setState(292);
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
  enterRule(_localctx, 42, flicker::RuleUsingStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(308);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(294);
      match(flicker::USING);
      setState(295);
      match(flicker::STRING);
      setState(302);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == flicker::FOR) {
        setState(296);
        match(flicker::FOR);
        setState(300);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case flicker::DOT: {
            setState(297);
            match(flicker::DOT);
            break;
          }

          case flicker::STAR: {
            setState(298);
            match(flicker::STAR);
            break;
          }

          case flicker::IDENTIFIER: {
            setState(299);
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
      setState(304);
      match(flicker::USING);
      setState(305);
      match(flicker::IDENTIFIER);
      setState(306);
      match(flicker::EQ);
      setState(307);
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
  enterRule(_localctx, 44, flicker::RuleImportList);
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
    setState(310);
    importItem();
    setState(315);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == flicker::COMMA) {
      setState(311);
      match(flicker::COMMA);
      setState(312);
      importItem();
      setState(317);
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
  enterRule(_localctx, 46, flicker::RuleImportItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(322);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(318);
      match(flicker::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(319);
      match(flicker::IDENTIFIER);
      setState(320);
      match(flicker::RIGHT_ARROW);
      setState(321);
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
  enterRule(_localctx, 48, flicker::RuleLoopLabel);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
    match(flicker::COLON);
    setState(325);
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
  enterRule(_localctx, 50, flicker::RuleDoStatement);

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
    match(flicker::DO);
    setState(328);
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
  enterRule(_localctx, 52, flicker::RuleBlockOrStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(332);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(330);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(331);
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
  enterRule(_localctx, 54, flicker::RuleIfStmt);

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
    setState(334);
    match(flicker::IF);
    setState(335);
    expression(0);
    setState(336);
    blockOrStatement();
    setState(343);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(337);
        match(flicker::ELIF);
        setState(338);
        expression(0);
        setState(339);
        blockOrStatement(); 
      }
      setState(345);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
    setState(348);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      setState(346);
      match(flicker::ELSE);
      setState(347);
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
  enterRule(_localctx, 56, flicker::RuleWhileStmt);
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
    setState(350);
    match(flicker::WHILE);
    setState(352);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(351);
      loopLabel();
    }
    setState(354);
    expression(0);
    setState(355);
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
  enterRule(_localctx, 58, flicker::RuleEachStmt);
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
    setState(357);
    match(flicker::EACH);
    setState(359);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(358);
      loopLabel();
    }
    setState(361);
    match(flicker::IDENTIFIER);
    setState(365);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::LEFT_BRACKET) {
      setState(362);
      match(flicker::LEFT_BRACKET);
      setState(363);
      match(flicker::IDENTIFIER);
      setState(364);
      match(flicker::RIGHT_BRACKET);
    }
    setState(367);
    match(flicker::IN);
    setState(368);
    expression(0);
    setState(369);
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
  enterRule(_localctx, 60, flicker::RuleForStmt);
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
    setState(371);
    match(flicker::FOR);
    setState(373);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(372);
      loopLabel();
    }
    setState(377);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::VAL:
      case flicker::VAR: {
        setState(375);
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
        setState(376);
        expression(0);
        break;
      }

      case flicker::SEMICOLON: {
        break;
      }

    default:
      break;
    }
    setState(379);
    match(flicker::SEMICOLON);
    setState(381);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 221803862531538954) != 0) || _la == flicker::TRUE) {
      setState(380);
      expression(0);
    }
    setState(383);
    match(flicker::SEMICOLON);
    setState(385);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 221803862531538954) != 0) || _la == flicker::TRUE) {
      setState(384);
      expression(0);
    }
    setState(387);
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
  enterRule(_localctx, 62, flicker::RuleBreakStmt);
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
    setState(389);
    match(flicker::BREAK);
    setState(391);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(390);
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
  enterRule(_localctx, 64, flicker::RuleContinueStmt);
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
    setState(393);
    match(flicker::CONTINUE);
    setState(395);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COLON) {
      setState(394);
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
  enterRule(_localctx, 66, flicker::RuleWhenStmt);

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
    match(flicker::WHEN);
    setState(398);
    expression(0);
    setState(399);
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
  enterRule(_localctx, 68, flicker::RuleReturnStmt);
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
    setState(401);
    match(flicker::RETURN);
    setState(403);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 221803862531538954) != 0) || _la == flicker::TRUE) {
      setState(402);
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
  enterRule(_localctx, 70, flicker::RulePrintStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(405);
    match(flicker::PRINT);
    setState(406);
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
  enterRule(_localctx, 72, flicker::RuleConsoleErrorStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(408);
    match(flicker::PRINT_ERROR);
    setState(409);
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
  enterRule(_localctx, 74, flicker::RulePassStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(411);
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
  enterRule(_localctx, 76, flicker::RuleWhenBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(413);
    newline();
    setState(414);
    match(flicker::INDENT);
    setState(415);
    whenContents();
    setState(416);
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
  enterRule(_localctx, 78, flicker::RuleWhenContents);
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
    setState(421); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(418);
      whenCase();
      setState(419);
      statementEnd();
      setState(423); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 221803862531538954) != 0) || _la == flicker::TRUE);
    setState(428);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::ELSE) {
      setState(425);
      elseCase();
      setState(426);
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
  enterRule(_localctx, 80, flicker::RuleWhenCase);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
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
  enterRule(_localctx, 82, flicker::RuleElseCase);

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
    match(flicker::ELSE);
    setState(434);
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
//----------------- CheckNotNilContext ------------------------------------------------------------------

flicker::ExpressionContext* flicker::CheckNotNilContext::expression() {
  return getRuleContext<flicker::ExpressionContext>(0);
}

tree::TerminalNode* flicker::CheckNotNilContext::QUEST_QUEST() {
  return getToken(flicker::QUEST_QUEST, 0);
}

flicker::CheckNotNilContext::CheckNotNilContext(ExpressionContext *ctx) { copyFrom(ctx); }

void flicker::CheckNotNilContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCheckNotNil(this);
}
void flicker::CheckNotNilContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<flickerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCheckNotNil(this);
}

std::any flicker::CheckNotNilContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<flickerVisitor*>(visitor))
    return parserVisitor->visitCheckNotNil(this);
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
  size_t startState = 84;
  enterRecursionRule(_localctx, 84, flicker::RuleExpression, precedence);

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
    setState(453);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ScopedIdentifierContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(437);
      match(flicker::IDENTIFIER);
      setState(438);
      match(flicker::COLON_COLON);
      setState(439);
      match(flicker::IDENTIFIER);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<IdentifierContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(440);
      match(flicker::IDENTIFIER);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ConstantContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(441);
      constantExpr();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<InterpolationContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(442);
      interpolationExpr();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ListOrMapContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(443);
      listOrMapLiteral();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<LambdaContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(444);
      lambdaLiteral();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(445);
      match(flicker::LEFT_PAREN);
      setState(446);
      expression(0);
      setState(447);
      match(flicker::RIGHT_PAREN);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<PrefixExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(449);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 335577088) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(450);
      expression(13);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<NotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(451);
      match(flicker::NOT);
      setState(452);
      expression(3);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(538);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(536);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<RangeExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(455);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(456);
          _la = _input->LA(1);
          if (!(_la == flicker::DOT_DOT

          || _la == flicker::DOT_DOT_LT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(457);
          expression(20);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PowerExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(458);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(459);
          match(flicker::STAR_STAR);
          setState(460);
          expression(14);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<FactorExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(461);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(462);
          _la = _input->LA(1);
          if (!(_la == flicker::SLASH

          || _la == flicker::STAR)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(463);
          expression(13);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<TermExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(464);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(465);
          _la = _input->LA(1);
          if (!(_la == flicker::PLUS

          || _la == flicker::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(466);
          expression(12);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BitShiftExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(467);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(468);
          _la = _input->LA(1);
          if (!(_la == flicker::SHL

          || _la == flicker::SHR)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(469);
          expression(11);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BitwisExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(470);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(471);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 28672) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(472);
          expression(10);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<IsExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(473);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(477);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
          case 1: {
            setState(474);
            match(flicker::IS);
            break;
          }

          case 2: {
            setState(475);
            match(flicker::IS);
            setState(476);
            match(flicker::NOT);
            break;
          }

          default:
            break;
          }
          setState(479);
          expression(9);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<InExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(480);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(484);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case flicker::IN: {
              setState(481);
              match(flicker::IN);
              break;
            }

            case flicker::NOT: {
              setState(482);
              match(flicker::NOT);
              setState(483);
              match(flicker::IN);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(486);
          expression(8);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<ComparisonContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(487);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(488);
          comparisonOperator();
          setState(489);
          expression(7);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(491);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(492);
          match(flicker::AND);
          setState(493);
          expression(6);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(494);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(495);
          match(flicker::OR);
          setState(496);
          expression(5);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<IfExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(497);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(498);
          match(flicker::IF);
          setState(499);
          expression(0);
          setState(500);
          match(flicker::ELSE);
          setState(501);
          expression(3);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<AssignmentContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(503);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(504);
          match(flicker::EQ);
          setState(505);
          expression(1);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<MemberContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(506);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(507);
          _la = _input->LA(1);
          if (!(_la == flicker::DOT

          || _la == flicker::QUEST_DOT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(508);
          match(flicker::IDENTIFIER);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<CallContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(509);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(510);
          match(flicker::LEFT_PAREN);
          setState(519);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 221803862531538954) != 0) || _la == flicker::TRUE) {
            setState(511);
            expression(0);
            setState(516);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == flicker::COMMA) {
              setState(512);
              match(flicker::COMMA);
              setState(513);
              expression(0);
              setState(518);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(521);
          match(flicker::RIGHT_PAREN);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<ArrayAccessContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(522);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(523);
          match(flicker::LEFT_BRACKET);

          setState(524);
          expression(0);
          setState(529);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == flicker::COMMA) {
            setState(525);
            match(flicker::COMMA);
            setState(526);
            expression(0);
            setState(531);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(532);
          match(flicker::RIGHT_BRACKET);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<CheckNotNilContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(534);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(535);
          match(flicker::QUEST_QUEST);
          break;
        }

        default:
          break;
        } 
      }
      setState(540);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
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
  enterRule(_localctx, 86, flicker::RuleComparisonOperator);
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
    setState(541);
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
  enterRule(_localctx, 88, flicker::RuleInterpolationExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(543);
    match(flicker::INTERPOLATION);
    setState(545);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
    case 1: {
      setState(544);
      expression(0);
      break;
    }

    default:
      break;
    }
    setState(547);
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
  enterRule(_localctx, 90, flicker::RuleConstantExpr);
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
    setState(549);
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
  enterRule(_localctx, 92, flicker::RuleListOrMapLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(553);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(551);
      listLiteral();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(552);
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
  enterRule(_localctx, 94, flicker::RuleListLiteral);
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
    setState(555);
    match(flicker::LEFT_BRACKET);
    setState(557);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 221803862531538954) != 0) || _la == flicker::TRUE) {
      setState(556);
      listItems();
    }
    setState(559);
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
  enterRule(_localctx, 96, flicker::RuleListItems);
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
    setState(561);
    expression(0);
    setState(566);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(562);
        match(flicker::COMMA);
        setState(563);
        expression(0); 
      }
      setState(568);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
    }
    setState(570);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COMMA) {
      setState(569);
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
  enterRule(_localctx, 98, flicker::RuleMapLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(572);
    match(flicker::LEFT_BRACKET);
    setState(575);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::RIGHT_ARROW: {
        setState(573);
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
        setState(574);
        mapItems();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(577);
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
  enterRule(_localctx, 100, flicker::RuleMapItems);
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
    setState(579);
    mapItem();
    setState(584);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(580);
        match(flicker::COMMA);
        setState(581);
        mapItem(); 
      }
      setState(586);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    }
    setState(588);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::COMMA) {
      setState(587);
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
  enterRule(_localctx, 102, flicker::RuleMapItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(590);
    expression(0);
    setState(591);
    match(flicker::RIGHT_ARROW);
    setState(592);
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
  enterRule(_localctx, 104, flicker::RuleLambdaLiteral);

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
    match(flicker::FUN);
    setState(595);
    lambdaParams();
    setState(600);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::RIGHT_ARROW: {
        setState(596);
        match(flicker::RIGHT_ARROW);
        setState(597);
        lambdaBody();
        break;
      }

      case flicker::EQ: {
        setState(598);
        match(flicker::EQ);
        setState(599);
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
  enterRule(_localctx, 106, flicker::RuleLambdaParams);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(605);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(602);
        paramList();
        break;
      }

      case flicker::LEFT_PAREN: {
        enterOuterAlt(_localctx, 2);
        setState(603);
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
  enterRule(_localctx, 108, flicker::RuleParenthesizedOptionalParamList);
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
    setState(607);
    match(flicker::LEFT_PAREN);
    setState(609);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == flicker::IDENTIFIER) {
      setState(608);
      paramList();
    }
    setState(611);
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
  enterRule(_localctx, 110, flicker::RuleLambdaBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(615);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::LEFT_BRACE: {
        enterOuterAlt(_localctx, 1);
        setState(613);
        braceBody();
        break;
      }

      case flicker::DO:
      case flicker::LINE: {
        enterOuterAlt(_localctx, 2);
        setState(614);
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
  enterRule(_localctx, 112, flicker::RuleBraceBody);
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
    setState(617);
    match(flicker::LEFT_BRACE);
    setState(626);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(618);
        statement();
        setState(620); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(619);
                  terminator();
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(622); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER); 
      }
      setState(628);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx);
    }
    setState(630);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 42) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 42)) & 33298058791) != 0)) {
      setState(629);
      statement();
    }
    setState(635);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == flicker::SEMICOLON || _la == flicker::LINE) {
      setState(632);
      terminator();
      setState(637);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(638);
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
  enterRule(_localctx, 114, flicker::RuleTerminator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(642);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case flicker::SEMICOLON: {
        setState(640);
        match(flicker::SEMICOLON);
        break;
      }

      case flicker::LINE: {
        setState(641);
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
    case 42: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool flicker::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 19);
    case 1: return precpred(_ctx, 14);
    case 2: return precpred(_ctx, 12);
    case 3: return precpred(_ctx, 11);
    case 4: return precpred(_ctx, 10);
    case 5: return precpred(_ctx, 9);
    case 6: return precpred(_ctx, 8);
    case 7: return precpred(_ctx, 7);
    case 8: return precpred(_ctx, 6);
    case 9: return precpred(_ctx, 5);
    case 10: return precpred(_ctx, 4);
    case 11: return precpred(_ctx, 2);
    case 12: return precpred(_ctx, 1);
    case 13: return precpred(_ctx, 18);
    case 14: return precpred(_ctx, 17);
    case 15: return precpred(_ctx, 16);
    case 16: return precpred(_ctx, 15);

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
