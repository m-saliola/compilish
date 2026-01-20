#include <iostream>

#include "lexer.h"

int main() {
    for (Token token : tokenize("auto x2 = 45a;")) std::cout << token.value << std::endl;

    return 0;
}
