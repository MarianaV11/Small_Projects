#include <string>

extern std::string secret_word;

bool letter_in(char guess) {
    for (char word : secret_word) {
        if (guess == word) {
            return true;
        }
    }
    return false;
}