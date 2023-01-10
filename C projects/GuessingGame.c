#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    printf("******************************\n");
    printf("*Welcome to the Guessing Game*\n");
    printf("******************************\n\n");

    int number_of_try;
    printf("Choose between EASY(1), MEDIUM(2) and HARD(3).\n");
    scanf("%d", &number_of_try);
    switch (number_of_try) {
        case 1:
            number_of_try = 10;
            break;
        case 2:
            number_of_try = 5;
            break;
        default:
            number_of_try = 3;
            break;
    }
    printf("Your number of attempts is %d.\n", number_of_try);

    srand(time(0));
    int secret_number = rand() % 100;

    int guess;
    int tries = 1;


    double score = 1000;

    for (int i = 1; i <= number_of_try; i++) {
        printf("What is your guess?\n");
        printf("Try %d\n", tries);
        
        scanf("%d", &guess);
        printf("Your guess is %d.\n", guess);

        if (guess < 0) {
            printf("You can't guess negative numbers.\n");
            i--;
            continue;
        }

        int right = (guess == secret_number);
        int big = (guess > secret_number);

        if (right) {
            printf("Congratulations! you are right!\n");
            printf("You won in %d tries.\n", tries);
            break;
        } else if (big) {
            printf("Your guess is bigger than the secret number.\n");
        } else {
            printf("You guess is smallest than the secret number.\n");
        }

        tries++;

        double lost_score = abs(guess - secret_number)/(double)2;
        score = score - lost_score;
    }


    printf("End game!\n");
    printf("Score: %.2f \n", score);
    if (guess != secret_number) {
        printf("You lost, try it again. The secret number was %d.\n\n", secret_number);
        printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n\n");
    }
}
