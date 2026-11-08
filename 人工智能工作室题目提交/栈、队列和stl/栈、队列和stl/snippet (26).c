#include <stdio.h>

int used[9];
int path[8];

void dfs(int depth) {
    int i;
    if (depth == 8) {
        for (i = 0; i < 8; i++) putchar('0' + path[i]);
        putchar('\n');
        return;
    }
    for (i = 1; i <= 8; i++) {
        if (!used[i]) {
            used[i] = 1;
            path[depth] = i;
            dfs(depth + 1);
            used[i] = 0;
        }
    }
}

int main(void) {
    dfs(0);
    return 0;
}