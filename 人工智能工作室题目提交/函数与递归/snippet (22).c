#include <stdio.h>
#include <string.h>

int is_leap(int y) {
    if (y % 400 == 0) return 1;
    if (y % 100 == 0) return 0;
    return y % 4 == 0;
}

int days_of_month(int y, int m) {
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && is_leap(y)) return 29;
    return days[m];
}

int main(void) {
    int y, m, x;
    while (scanf("%d %d %d", &y, &m, &x) == 3) {
        int ans = 0, d;
        char date[20];
        char target = (char)('0' + x);
        int days = days_of_month(y, m);

        for (d = 1; d <= days; d++) {
            int i;
            sprintf(date, "%04d-%02d-%02d", y, m, d);
            for (i = 0; date[i] != '\0'; i++) {
                if (date[i] == target) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}