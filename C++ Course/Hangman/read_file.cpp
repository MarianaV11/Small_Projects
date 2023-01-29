#include <iostream>
#include <fstream>
#include <cstdlib>
#include "read_file.hpp"

std::vector <std::string> read_file () {
    std::ifstream file;
    file.open("Hangman_Words.txt");

    if (file.is_open()) {
        int number_words;
        file >> number_words;

        std::vector <std::string> words_of_file;

        for (int i = 0; i < number_words; i++) {
            std::string red_word;
            file >> red_word;

            words_of_file.push_back(red_word);
        }

        file.close();
        return words_of_file;       
    } else {
        std::cout << "Unable to access the word bank." << std::endl;
        exit(0);
    }
}