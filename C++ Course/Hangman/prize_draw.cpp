#include <ctime>
#include <vector>
#include <string>
#include "read_file.hpp"

extern std::string secret_word;

void prize_draw () {
    std::vector <std::string> words = read_file();

    srand(time(NULL));
    int index = rand() % words.size();

    secret_word = words[index];
}