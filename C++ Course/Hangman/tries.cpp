#include <iostream>
#include <map>
#include <vector>
#include "letter_in.hpp"
extern std::map <char, bool> tried;
extern std::vector <char> wrong_guess;

void tries () {
    char guess;
    std::cin >> guess;

    tried[guess] = true;

    if (letter_in(guess)) {
        std::cout << "You are right! your guess is in the word." << std::endl;
    }
    else {
        std::cout << "You are wrong! your guess isn't in the word." << std::endl;
        wrong_guess.push_back(guess);
    }
    std::cout << std::endl;
}