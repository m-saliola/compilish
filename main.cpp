#include <iostream>

#include "parser.h"

int main() {
    for (Token token : tokenize("auto x = \"Hello, World!\";")) std::cout << token.value << std::endl;

    return 0;
}
