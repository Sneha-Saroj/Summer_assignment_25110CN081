#include <stdio.h>

int main() {
    long long n, largestPrimeFactor = -1;

    printf("Enter a number: ");
    scanf("%lld", &n);

    while (n % 2 == 0) {
        largestPrimeFactor = 2;
        n /= 2;
    }

    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largestPrimeFactor = i;
            n /= i;
        }
    }

    if (n > 2)
        largestPrimeFactor = n;

    printf("Largest Prime Factor = %lld", largestPrimeFactor);

    return 0;
}