#include <stdio.h>

int mid[10][10];

void add(int a, int b, int m) {
    mid[a][b] = m;
    mid[b][a] = m;
}

int main(void) {
    char s[35];

    add(1, 3, 2);
    add(1, 7, 4);
    add(1, 9, 5);
    add(2, 8, 5);
    add(3, 7, 5);
    add(3, 9, 6);
    add(4, 6, 5);
    add(7, 9, 8);

    while (scanf("%s", s) == 1) {
        int used[10] = {0};
        int ok = 1;
        int prev = 0;
        int i;

        for (i = 0; s[i] != '\0'; i++) {
            int cur = s[i] - '0';
            if (used[cur]) {
                ok = 0;
                break;
            }
            if (mid[prev][cur] != 0 && !used[mid[prev][cur]]) {
                ok = 0;
                break;
            }
            used[cur] = 1;
            prev = cur;
        }

        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}