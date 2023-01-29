#include <iostream>
#include <cstdlib>
#include <fstream>
#include "save_file.hpp"

void save_file (std::vector <std::string> new_list) {
    std::fstream file;
    file.open("Hangman_Words.txt");

    if (file.is_open()) {
        file << new_list.size() << std::endl;

        for (std::string word : new_list) {
            file << word << std::endl;
        }

        file.close();
    } else {
        std::cout << "Unable to access the word bank." << std::endl;
        exit(0);
    }
}