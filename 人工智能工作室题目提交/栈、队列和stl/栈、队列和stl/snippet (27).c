#include <stdio.h>
#include <stdlib.h>

int a[100005], b[100005], diff[100005];

int cmp_desc(const void *p, const void *q) {
    int x = *(const int *)p;
    int y = *(const int *)q;
    return (y > x) - (y < x);
}

int main(void) {
    int n, k, i;
    long long ans = 0;
    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < n; i++) scanf("%d", &b[i]);

    for (i = 0; i < n; i++) {
        diff[i] = a[i] - b[i];
        ans += b[i];
    }

    qsort(diff, n, sizeof(int), cmp_desc);

    for (i = 0; i < k; i++) ans += diff[i];
    printf("%lld\n", ans);
    return 0;
}