#include <stdio.h>

int main(void) {
    char s[100005];
    int i, balance = 0, ok = 1;

    scanf("%s", s);

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a') {
            balance++;
        } else if (s[i] == 'b') {
            balance--;
            if (balance < 0) {
                ok = 0;
                break;
            }
        } else {
            ok = 0;
            break;
        }
    }

    if (balance != 0) ok = 0;
    printf("%s\n", ok ? "Good" : "Bad");
    return 0;
}