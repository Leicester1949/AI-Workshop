#include <stdio.h>

int main(void) {
    int x, y, i, n, sum, ans = 0;
    scanf("%d %d", &x, &y);
    if (x > y) {
        int t = x;
        x = y;
        y = t;
    }

    for (i = x; i <= y; i++) {
        n = i;
        sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        if (sum % 5 == 0) ans++;
    }
    printf("%d\n", ans);
    return 0;
}