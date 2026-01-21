#include <string>
#include <vector>
#include <unordered_map>

enum class TokenType {
    // Literal Types
    Number,
    String,
    Identifier,

    // Grouping * Operators
    OpenParen,
    CloseParen,
    Semicolon,
    BinaryOperator,
    AssignmentOperator,
    Endfile,

    // Keywords
    Auto
};

const std::unordered_map<std::string, TokenType> KEYWORDS = {
    {"auto", TokenType::Auto}
};

struct Token {
    std::string value;
    TokenType type;
};

std::vector<Token> tokenize(std::string source);
