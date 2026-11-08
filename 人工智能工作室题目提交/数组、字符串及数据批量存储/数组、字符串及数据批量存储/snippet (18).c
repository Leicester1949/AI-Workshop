#include <stdio.h>

int main(void) {
    int n, k, m, i;
    int a[105];
    scanf("%d %d %d", &n, &k, &m);

    for (i = 0; i < n; i++) a[i] = i;

    int len = n;
    int pos = k;
    while (len > 1) {
        pos = (pos + m - 1) % len;
        for (i = pos; i < len - 1; i++) {
            a[i] = a[i + 1];
        }
        len--;
        if (pos == len) pos = 0;
    }

    printf("%d\n", a[0]);
    return 0;
}