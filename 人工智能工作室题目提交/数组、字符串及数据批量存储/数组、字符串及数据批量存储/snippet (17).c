#include <stdio.h>

int main(void) {
    int n, x, i, t;
    long long ans = 0;
    scanf("%d %d", &n, &x);
    for (i = 1; i <= n; i++) {
        t = i;
        while (t > 0) {
            if (t % 10 == x) ans++;
            t /= 10;
        }
    }
    printf("%lld\n", ans);
    return 0;
}