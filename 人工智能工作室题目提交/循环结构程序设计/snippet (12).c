#include <stdio.h>

int main(void) {
    int n, i, j, num = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%4d", num);
            num++;
        }
        printf("\n");
    }
    return 0;
}