#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;

    // Initialize random number generator
    srand(time(0));
    number = rand() % 100 + 1;  // random number between 1 to 100

    printf("🎮 Welcome to Number Guessing Game!\n");
    printf("I have chosen a number between 1 and 100.\n");

    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > number) {
            printf("Too High 📈\n");
        } 
        else if (guess < number) {
            printf("Too Low 📉\n");
        } 
        else {
            printf("🎉 Correct! You guessed it in %d attempts.\n", attempts);
        }

    } while (guess != number);

    return 0;
}