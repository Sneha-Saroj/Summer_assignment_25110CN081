#include <stdio.h>

int main()
{
    int choice;
    int score = 0;

    printf("===== WELCOME TO QUIZ GAME =====\n");

    // Question 1
    printf("\n1. What is the size of int in C (generally)?\n");
    printf("1) 2 bytes\n2) 4 bytes\n3) 8 bytes\n4) 1 byte\n");
    printf("Enter your answer: ");
    scanf("%d", &choice);

    if(choice == 2)
        score++;

    // Question 2
    printf("\n2. Which symbol is used for printf in C?\n");
    printf("1) &\n2) #\n3) %\n4) printf()\n");
    printf("Enter your answer: ");
    scanf("%d", &choice);

    if(choice == 4)
        score++;

    // Question 3
    printf("\n3. Which header file is used for input/output?\n");
    printf("1) stdlib.h\n2) string.h\n3) stdio.h\n4) math.h\n");
    printf("Enter your answer: ");
    scanf("%d", &choice);

    if(choice == 3)
        score++;

    // Final result
    printf("\n===== QUIZ RESULT =====\n");
    printf("Your score: %d / 3\n", score);

    if(score == 3)
        printf("Excellent! 🎉\n");
    else if(score == 2)
        printf("Good job 👍\n");
    else
        printf("Try again 📚\n");

    return 0;
}