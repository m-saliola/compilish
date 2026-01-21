#include "parser.h"

Program Parser::produceAST(std::string source) {
    Program program;

    tokens = tokenize(source);

    while (tokens[0].type != TokenType::Endfile) {
        program.body.push_back(/* Get the statement and PUT THAT BASTARD HERE! */);
    }

    return program;
}
