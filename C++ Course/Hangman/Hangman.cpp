#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "letter_in.hpp"
#include "wrong.hpp"
#include "alive.hpp"
#include "header.hpp"
#include "print_wguesses.hpp"
#include "print_word.hpp"
#include "tries.hpp"
#include "read_file.hpp"
#include "prize_draw.hpp"
#include "save_file.hpp"
#include "add_word.hpp"
using namespace std;

string secret_word;
map <char, bool> tried;
vector <char> wrong_guess;

int main () {
    header();

    prize_draw();

    while (wrong() && alive()) {
        print_wguesses();

        print_word();

        tries();
    }

    cout << "End Game!" << endl;
    cout << "The right word is " << secret_word << endl;
    if (wrong()) {
        cout << "You lost, try it again!" << endl;
    } else {
        cout << "Congratulations! You got the right word!" << endl;
        cout << "Do you want to add a new word to the word bank?" << endl;
        char answer;
        cin >> answer;

        if (answer == wrong()) {
            add_word();
        }
    }
}