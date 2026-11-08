#include <stdio.h>

int main(void) {
    int n, i;
    int a[1005];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    if (n == 1) {
        if (a[0] == 0) printf("UP\n");
        else if (a[0] == 15) printf("DOWN\n");
        else printf("-1\n");
    } else {
        if (a[n - 1] > a[n - 2]) printf("UP\n");
        else printf("DOWN\n");
    }
    return 0;
}