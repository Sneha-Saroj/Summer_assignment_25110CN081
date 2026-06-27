#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j;
    char str[10][50], temp[50];

    printf("Enter number of words: ");
    scanf("%d", &n);

    printf("Enter %d words:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }

    // Sorting words based on length (Bubble Sort)
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(strlen(str[i]) > strlen(str[j])) {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("\nWords sorted by length:\n");
    for(i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }

    return 0;
}