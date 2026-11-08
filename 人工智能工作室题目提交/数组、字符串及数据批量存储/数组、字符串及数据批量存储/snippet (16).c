#include <stdio.h>
#include <limits.h>

void print_i128(__int128 x) {
    char buf[50];
    int len = 0;
    if (x == 0) {
        putchar('0');
        return;
    }
    while (x > 0) {
        buf[len++] = (char)('0' + x % 10);
        x /= 10;
    }
    while (len > 0) {
        putchar(buf[--len]);
    }
}

int main(void) {
    int t, n, i;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        long long mn = LLONG_MAX, mx = LLONG_MIN;
        __int128 sum = 0, sq = 0;
        for (i = 0; i < n; i++) {
            long long x;
            scanf("%lld", &x);
            if (x < mn) mn = x;
            if (x > mx) mx = x;
            sum += x;
            sq += (__int128)x * x;
        }
        __int128 num = (__int128)n * sq - sum * sum;
        __int128 den = (__int128)n * n;
        __int128 scaled = (num * 1000 + den / 2) / den;

        printf("%lld ", mx - mn);
        print_i128(scaled / 1000);
        printf(".%03d\n", (int)(scaled % 1000));
    }
    return 0;
}