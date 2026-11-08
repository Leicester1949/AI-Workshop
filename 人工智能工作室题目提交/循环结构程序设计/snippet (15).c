#include <stdio.h>

int main(void) {
    int n, i, j;
    while (scanf("%d", &n) == 1) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= 2 * (n - i + 1); j++) printf(" ");
            for (j = 1; j <= i; j++) printf("*");
            printf("\n");
        }
        for (j = 1; j <= n + 1; j++) printf("*");
        printf("\n");
        for (i = n; i >= 1; i--) {
            for (j = 1; j <= 2 * (n - i + 1); j++) printf(" ");
            for (j = 1; j <= i; j++) printf("*");
            printf("\n");
        }
    }
    return 0;
}