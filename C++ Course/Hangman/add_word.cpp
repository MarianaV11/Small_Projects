#include <iostream>
#include "save_file.hpp"
#include "read_file.hpp"

void add_word () {
    std::cout << "Write the new word in capital letters." << std::endl;
    std::string new_word;
    std::cin >> new_word;

    std::vector <std::string> list_of_words = read_file();
    list_of_words.push_back(new_word);

    save_file(list_of_words);
}