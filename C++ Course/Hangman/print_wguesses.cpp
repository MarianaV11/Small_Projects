#include <iostream>
#include <vector>

extern std::vector <char> wrong_guess;

void print_wguesses () {
    std::cout << "Wrong guesses: ";
    for (char word : wrong_guess) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}
