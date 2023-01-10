#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    printf("******************************\n");
    printf("*Welcome to the Guessing Game*\n");
    printf("******************************\n");

    int number_of_try;
    printf("Choose between EASY(1), MEDIUM(2) and HARD(3).\n");
    scanf("%d", &number_of_try);

    if (number_of_try == 1) {
        number_of_try = 10;
    } else if (number_of_try == 2) {
        number_of_try = 5;
    } else {
        number_of_try = 3;
    }

    srand(time(0));
    int secret_number = rand() % 100;
    printf("%d\n",secret_number);

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
}