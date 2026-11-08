#include <stdio.h>
#include <string.h>

int main(void) {
    int t;
    char s[100005];
    const char *words[5] = {"zero", "two", "four", "six", "nine"};
    const char digits[5] = {'0', '2', '4', '6', '9'};

    scanf("%d", &t);
    while (t--) {
        int i = 0, w;
        scanf("%s", s);

        while (s[i] != '\0') {
            int found = 0;

            if (strchr("02469", s[i]) != NULL) {
                putchar(s[i]);
                i++;
                continue;
            }

            for (w = 0; w < 5; w++) {
                int len = (int)strlen(words[w]);
                if (strncmp(s + i, words[w], (size_t)len) == 0) {
                    putchar(digits[w]);
                    i += len;
                    found = 1;
                    break;
                }
            }

            if (!found) i++;
        }
        putchar('\n');
    }
    return 0;
}