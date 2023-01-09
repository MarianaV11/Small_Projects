#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

string secret_word;
map <char, bool> tried;
vector <char> wrong_guess;


bool letter_in(char guess) {
    for (char word : secret_word) {
        if (guess == word) {
            return true;
        }
    }
    return false;
}

bool wrong () {
    for (char word : secret_word) {
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
    cout << "The hint is: It is a fruit." << endl;
}

void print_wguesses () {
    cout << "Wrong guesses: ";
    for (char word : wrong_guess) {
        cout << word << " ";
    }
    cout << endl;
}

void print_word () {
    for (char word : secret_word) {
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

vector <string> read_file () {
    ifstream file;
    file.open("Hangman_Words.txt");

    int number_words;
    file >> number_words;

    vector <string> words_of_file;

    for (int i = 0; i < number_words; i++) {
        string red_word;
        file >> red_word;

        words_of_file.push_back(red_word);
    }
    return words_of_file;
}

void prize_draw () {
    vector <string> words = read_file();

    srand(time(NULL));
    int index = rand() % words.size();

    secret_word = words[index];
}

int main () {
    header();

    prize_draw();

    while (wrong() && live()) {
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
    }
}
