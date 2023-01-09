#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main () {
    cout << "********************************" << endl;
    cout << "* Welcome to the Guessing Game *" << endl;
    cout << "********************************" << endl;

    cout << "Choose between EASY, MEDIUM and HARD." << endl;

    char difficulty;
    cin >> difficulty;

    int number_of_try = 0;
    if (difficulty == 'EASY') {
        number_of_try = 15;
    } else if (difficulty == 'MEDIUM') {
        number_of_try = 10;
    }
    else {
        number_of_try = 5;
    }

    srand(time(NULL));
    int secret_number = rand() % 100;
    cout << secret_number << endl;
       
    bool wrong = true;
    int attempts = 0;
    double score = 1000.0;

    for (attempts = 1; attempts <= number_of_try; attempts++) {
        int guess;
        cout << "Try "<< attempts << endl;
        cout << "What is your guess?" << endl;
        cin >> guess;
        cout << "Your guess is " << guess << endl;

        double lost_score = abs(guess - secret_number)/2.0;
        score = score - lost_score;

        bool right = guess == secret_number;
        bool guessBigger = guess > secret_number;
        if (right) {
            cout << "You're right!! Congratulations!" << endl;
            wrong = false;
            break;
        } else if (guessBigger) {
            cout << "Your guess is bigger than the secret number." << endl;
        }
        else {
            cout << "Your guess is smaller than the secret number." << endl;
        }
    }

    if (wrong == true) {
        cout << "End Game! Try again." << endl;
    } else {
        cout << "You got it in "<< attempts <<" tries." << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Your score was " << score << endl;
    }
}