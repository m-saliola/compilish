#include "lexer.h"

#include <sstream>
#include <cctype>

std::vector<Token> tokenize(std::string source) {
    std::vector<Token> tokens;

    std::istringstream iss(source);
    iss >> std::noskipws;

    std::string buffer;
    while (iss.peek() != EOF) {
        if (std::isspace(iss.peek())) {
            iss.get();
            continue;
        }

        buffer += iss.get();

        if (buffer == ";") {
            tokens.push_back({buffer, TokenType::Semicolon});
            buffer.erase(buffer.begin(), buffer.end());
        } else if (buffer == "(") {
            tokens.push_back({buffer, TokenType::OpenParen});
            buffer.erase(buffer.begin(), buffer.end());
        } else if (buffer == ")") {
            tokens.push_back({buffer, TokenType::CloseParen});
            buffer.erase(buffer.begin(), buffer.end());
        } else if (buffer == "+" || buffer == "-" || buffer == "*" || buffer == "/") {
            tokens.push_back({buffer, TokenType::BinaryOperator});
            buffer.erase(buffer.begin(), buffer.end());
        } else if (buffer == "=") {
            tokens.push_back({buffer, TokenType::AssignmentOperator});
            buffer.erase(buffer.begin(), buffer.end());
        } else if (std::isdigit(buffer[0])) {
            while (iss.peek() != EOF && std::isdigit(iss.peek())) buffer += iss.get();
            tokens.push_back({buffer, TokenType::Number});
            buffer.erase(buffer.begin(), buffer.end());
        } else if (std::isalpha(buffer[0])) {
            while (iss.peek() != EOF && std::isalnum(iss.peek())) buffer += iss.get();
            if (KEYWORDS.find(buffer) != KEYWORDS.end()) {
                tokens.push_back({buffer, KEYWORDS.at(buffer)});
            } else {
                tokens.push_back({buffer, TokenType::Identifier});
            }
            buffer.erase(buffer.begin(), buffer.end());
        }
    }

    return tokens;
}
