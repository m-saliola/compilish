#include "ast.h"
#include "lexer.h"

class Parser {
private:
    std::vector<Token> tokens;

public:
    Program produceAST(std::string source);
};
