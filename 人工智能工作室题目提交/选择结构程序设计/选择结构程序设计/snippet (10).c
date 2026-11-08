#include <stdio.h>

int main(void) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    if (y % x == 0) {
        printf("%lld\n", x + y);
    } else {
        printf("%lld\n", y - x);
    }
    return 0;
}