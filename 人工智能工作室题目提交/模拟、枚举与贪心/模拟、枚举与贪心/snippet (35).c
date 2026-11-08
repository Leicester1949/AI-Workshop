#include <stdio.h>
#include <stdlib.h>

int main(void) {
    long long cnt[10];
    long long total = 0, half_len;
    int odd[10], odd_cnt = 0;
    int i, d, p;

    for (i = 0; i < 10; i++) {
        scanf("%lld", &cnt[i]);
        total += cnt[i];
        if (cnt[i] % 2 == 1) odd[odd_cnt++] = i;
    }

    if (odd_cnt > 1) {
        printf("-1\n");
        return 0;
    }

    half_len = total / 2;
    if (half_len == 0) {
        if (odd_cnt == 1) printf("%d\n", odd[0]);
        else printf("-1\n");
        return 0;
    }

    char *half = (char *)malloc((size_t)half_len + 2);
    p = 0;
    for (d = 0; d < 10; d++) {
        long long k;
        for (k = 0; k < cnt[d] / 2; k++) half[p++] = (char)('0' + d);
    }
    half[p] = '\0';

    if (half[0] == '0') {
        int start = -1;
        for (d = 1; d <= 9; d++) {
            if (cnt[d] >= 2) {
                start = d;
                break;
            }
        }
        if (start == -1) {
            printf("-1\n");
            free(half);
            return 0;
        }

        char *new_half = (char *)malloc((size_t)half_len + 2);
        int q = 0, removed = 0;
        new_half[q++] = (char)('0' + start);
        for (i = 0; i < p; i++) {
            if (half[i] == (char)('0' + start) && !removed) {
                removed = 1;
            } else {
                new_half[q++] = half[i];
            }
        }
        new_half[q] = '\0';
        free(half);
        half = new_half;
        p = q;
    }

    printf("%s", half);
    if (odd_cnt == 1) putchar('0' + odd[0]);
    for (i = p - 1; i >= 0; i--) putchar(half[i]);
    putchar('\n');

    free(half);
    return 0;
}