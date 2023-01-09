#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

const string SECRET_WORD = "APPLE";
map <char, bool> tried;
vector <char> wrong_guess;


bool letter_in(char guess) {
    for (char word : SECRET_WORD) {
        if (guess == word) {
            return true;
        }
    }
    return false;
}

bool wrong () {
    for (char word : SECRET_WORD) {
        if (!tried[word]) {
            return true;
        }
    }
    return false;
}

bool live () {
    return wrong_guess.size() < 5;
}

void header () {
    cout << "**************************" << endl;
    cout << "* Welcome to the Hangman *" << endl;
    cout << "**************************" << endl;
    cout << endl;
    cout << "Say your guess to the secret word!" << endl;
}

void print_wguesses () {
    cout << "Wrong guesses: ";
    for (char word : wrong_guess) {
        cout << word << " ";
    }
    cout << endl;
}

void print_word () {
    for (char word : SECRET_WORD) {
        if (tried[word]) {
        cout << word << "";
        } else {
             cout << "_ ";
        }
    }
    cout << endl;
}

void tries () {
    char guess;
    cin >> guess;

    tried[guess] = true;

    if (letter_in(guess)) {
        cout << "You are right! your guess is in the word." << endl;
    }
    else {
        cout << "You are wrong! your guess isn't in the word." << endl;
        wrong_guess.push_back(guess);
    }
    cout << endl;
}

int main () {
    header();

    while (wrong() && live()) {
        print_wguesses();

        print_word();

        tries();
    }

    cout << "End Game!" << endl;
    cout << "The right word is " << SECRET_WORD << endl;
    if (wrong()) {
        cout << "You lost, try it again!" << endl;
    } else {
        cout << "Congratulations! You got the right word!" << endl;
    }
}
