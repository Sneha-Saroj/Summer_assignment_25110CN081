#include <stdio.h>

int reverse = 0;

void reverseNumber(int n) {
    if (n == 0)
        return;

    reverse = reverse * 10 + n % 10;
    reverseNumber(n / 10);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    reverseNumber(num);

    printf("Reversed number = %d\n", reverse);

    return 0;
}