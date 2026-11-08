#include <stdio.h>

int main(void) {
    long long m, n;
    scanf("%lld %lld", &m, &n);
    if (m % n == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
   