#include <stdio.h>
#include <string.h>

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        char a[60], b[60];
        int x[60] = {0}, y[60] = {0}, z[120] = {0};
        int la, lb, i, j, k;

        scanf("%s %s", a, b);
        la = (int)strlen(a);
        lb = (int)strlen(b);

        for (i = 0; i < la; i++) x[i] = a[la - 1 - i] - '0';
        for (i = 0; i < lb; i++) y[i] = b[lb - 1 - i] - '0';

        for (i = 0; i < la; i++) {
            for (j = 0; j < lb; j++) {
                z[i + j] += x[i] * y[j];
            }
        }

        for (i = 0; i < la + lb; i++) {
            z[i + 1] += z[i] / 10;
            z[i] %= 10;
        }

        k = la + lb;
        while (k > 0 && z[k] == 0) k--;

        for (i = k; i >= 0; i--) putchar('0' + z[i]);
        putchar('\n');
    }
    return 0;
}