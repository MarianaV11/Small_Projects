#include <iostream>
#include <string>
#include <map>

extern std::map <char, bool> tried;
extern std::string secret_word;

void print_word () {
    for (char word : secret_word) {
        if (tried[word]) {
            std::cout << word << "";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}
