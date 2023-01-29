#include <map>
#include <string>

extern std::string secret_word;
extern std::map <char, bool> tried;

bool wrong () {
    for (char word : secret_word) {
        if (!tried[word]) {
            return true;
        }
    }
    return false;
}