#include <stdio.h>

int main() {
    int n, count = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    while (n > 0) {
        count = count + (n % 2);  // adds 1 if last bit is 1
        n = n / 2;
    }

    printf("Number of set bits = %d", count);

    return 0;
}