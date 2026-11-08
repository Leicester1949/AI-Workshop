#include <stdio.h>
#include <string.h>

int main(void) {
    int n, i, j;
    char a[25][25];
    char ab[60], ba[60], temp[25];

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%s", a[i]);

    /* 冒泡排序：如果 a+b 比 b+a 小，就交换 */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            strcpy(ab, a[j]);
            strcat(ab, a[j + 1]);
            strcpy(ba, a[j + 1]);
            strcat(ba, a[j]);

            if (strcmp(ab, ba) < 0) {
                strcpy(temp, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j + 1], temp);
            }
        }
    }

    for (i = 0; i < n; i++) printf("%s", a[i]);
    printf("\n");
    return 0;
}