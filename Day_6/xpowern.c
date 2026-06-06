#include <stdio.h>

int main() {
    int x, n;
    long long result = 1;

    printf("Enter base (x): ");
    scanf("%d", &x);

    printf("Enter exponent (n): ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        result = result * x;
    }

    printf("%d raised to power %d = %lld", x, n, result);

    return 0;
}