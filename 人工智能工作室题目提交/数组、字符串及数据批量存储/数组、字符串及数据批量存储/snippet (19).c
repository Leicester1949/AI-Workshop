#include <stdio.h>

int main(void) {
    int L, M, l, r, i, ans = 0;
    int tree[10005];
    scanf("%d %d", &L, &M);

    for (i = 0; i <= L; i++) tree[i] = 1;

    while (M--) {
        scanf("%d %d", &l, &r);
        for (i = l; i <= r; i++) tree[i] = 0;
    }

    for (i = 0; i <= L; i++) {
        if (tree[i] == 1) ans++;
    }
    printf("%d\n", ans);
    return 0;
}