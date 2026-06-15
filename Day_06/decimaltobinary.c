#include <stdio.h>

int main() {
    int n, rem, i = 0;
    int bin[32];

    printf("Enter a decimal number: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Binary = 0");
        return 0;
    }

    while (n > 0) {
        rem = n % 2;
        bin[i] = rem;
        n = n / 2;
        i++;
    }

    printf("Binary = ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bin[j]);
    }

    return 0;
}