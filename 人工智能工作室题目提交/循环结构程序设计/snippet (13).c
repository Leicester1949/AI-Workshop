#include <stdio.h>

int main(void) {
    char ch;
    int n, i, j;
    scanf(" %c", &ch);
    n = ch - 'A' + 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1 - i; j++) printf(" ");
        for (j = 0; j <= i; j++) printf("%c", 'A' + j);
        for (j = i - 1; j >= 0; j--) printf("%c", 'A' + j);
        printf("\n");
    }
    return 0;
}