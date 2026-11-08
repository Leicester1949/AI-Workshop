#include <stdio.h>
#include <stdlib.h>

int a[100005];

int cmp_asc(const void *p, const void *q) {
    int x = *(const int *)p;
    int y = *(const int *)q;
    return (x > y) - (x < y);
}

int main(void) {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    qsort(a, n, sizeof(int), cmp_asc);

    for (i = n - 3; i >= 0; i--) {
        if ((long long)a[i] + a[i + 1] > a[i + 2]) {
            printf("%d %d %d\n", a[i], a[i + 1], a[i + 2]);
            return 0;
        }
    }

    printf("No solution\n");
    return 0;
}