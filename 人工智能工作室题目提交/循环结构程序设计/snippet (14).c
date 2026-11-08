#include <stdio.h>

int main(void) {
    int t, n, i, j, mid;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        mid = n / 2;
        for (i = 0; i <= mid; i++) {
            for (j = 0; j < mid - i; j++) printf(" ");
            for (j = 0; j < 2 * i + 1; j++) printf("*");
            printf("\n");
        }
        for (i = mid - 1; i >= 0; i--) {
            for (j = 0; j < mid - i; j++) printf(" ");
            for (j = 0; j < 2 * i + 1; j++) printf("*");
            printf("\n");
        }
    }
    return 0;
}