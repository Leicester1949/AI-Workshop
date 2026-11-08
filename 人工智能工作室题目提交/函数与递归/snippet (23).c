#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned long long ull;

ull mulmod(ull a, ull b, ull m) {
    return (ull)((__int128)a * b % m);
}

ull powmod(ull a, ull d, ull m) {
    ull result = 1 % m;
    while (d > 0) {
        if (d & 1) result = mulmod(result, a, m);
        a = mulmod(a, a, m);
        d >>= 1;
    }
    return result;
}

int is_prime(ull n) {
    int small[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    int i, s, r;
    ull d, x;

    if (n < 2) return 0;
    for (i = 0; i < 12; i++) {
        if (n % small[i] == 0) return n == (ull)small[i];
    }

    d = n - 1;
    s = 0;
    while ((d & 1) == 0) {
        s++;
        d >>= 1;
    }

    for (i = 0; i < 12; i++) {
        ull a = (ull)small[i];
        if (a >= n) continue;
        x = powmod(a, d, n);
        if (x == 1 || x == n - 1) continue;
        for (r = 1; r < s; r++) {
            x = mulmod(x, x, n);
            if (x == n - 1) break;
        }
        if (r == s) return 0;
    }
    return 1;
}

int main(void) {
    ull t;
    char s[30], p[40];
    int len, i;
    ull palindrome;

    scanf("%llu", &t);
    sprintf(s, "%llu", t);
    len = (int)strlen(s);

    for (i = 0; i < len; i++) p[i] = s[i];
    for (i = len - 2; i >= 0; i--) p[len + (len - 2 - i)] = s[i];
    p[2 * len - 1] = '\0';

    palindrome = strtoull(p, NULL, 10);
    if (is_prime(palindrome)) printf("prime\n");
    else printf("noprime\n");

    return 0;
}