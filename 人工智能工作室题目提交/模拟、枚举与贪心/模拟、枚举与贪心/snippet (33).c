#include <stdio.h>
#include <string.h>

int main(void) {
    char s[10000];
    char out[10000];
    int olen = 0;
    int in_str = 0;
    int i = 0;
    size_t n;

    n = fread(s, 1, sizeof(s) - 1, stdin);
    s[n] = '\0';

    while (s[i] != '\0') {
        char c = s[i];

        if (in_str) {
            out[olen++] = c;
            if (c == '\\' && s[i + 1] != '\0') {
                out[olen++] = s[i + 1];
                i += 2;
                continue;
            }
            if (c == '"') in_str = 0;
            i++;
        } else {
            if (c == '"') {
                in_str = 1;
                out[olen++] = c;
                i++;
            } else if (c == '/' && s[i + 1] == '*') {
                char *end = strstr(s + i + 2, "*/");
                if (end == NULL) {
                    out[olen++] = '/';
                    out[olen++] = '*';
                    i += 2;
                } else {
                    i = (int)(end - s) + 2;
                }
            } else {
                out[olen++] = c;
                i++;
            }
        }
    }

    fwrite(out, 1, (size_t)olen, stdout);
    return 0;
}