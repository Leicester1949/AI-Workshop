#include <stdio.h>

int main(void) {
    int L, R, i, t;
    long long ans = 0;
    scanf("%d %d", &L, &R);
    for (i = L; i <= R; i++) {
        t = i;
        while (t > 0) {
            if (t % 10 == 2) ans++;
            t /= 10;
        }
    }
    printf("%lld\n", ans);
    return 0;
}