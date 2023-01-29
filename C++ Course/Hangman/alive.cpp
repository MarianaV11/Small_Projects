#include <vector>

extern std::vector <char> wrong_guess;

bool alive () {
    return wrong_guess.size() < 5;
}