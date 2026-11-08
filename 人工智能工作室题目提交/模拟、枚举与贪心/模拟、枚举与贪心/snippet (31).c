#include <stdio.h>
#include <string.h>

static char s[200005];
static char zheng[200005];
static int a[200005];

void add_one(char *z) {
    int len = (int)strlen(z);
    int i = len - 1;
    while (i >= 0 && z[i] == '9') {
        z[i] = '0';
        i--;
    }
    if (i >= 0) {
        z[i]++;
    } else {
        memmove(z + 1, z, len + 1);
        z[0] = '1';
    }
}

int main(void) {
    int n, t, i, flen, pos;

    scanf("%d %d", &n, &t);
    scanf("%s", s);

    char *dot = strchr(s, '.');
    if (dot != NULL) {
        int zlen = (int)(dot - s);
        strncpy(zheng, s, zlen);
        zheng[zlen] = '\0';
        char *frac = dot + 1;
        flen = (int)strlen(frac);
        for (i = 0; i < flen; i++) a[i] = frac[i] - '0';
    } else {
        strcpy(zheng, s);
        flen = 0;
    }

    pos = -1;
    for (i = 0; i < flen; i++) {
        if (a[i] >= 5) {
            pos = i;
            break;
        }
    }

    if (pos == -1 || t == 0) {
        while (flen > 0 && a[flen - 1] == 0) flen--;
        printf("%s", zheng);
        if (flen > 0) {
            putchar('.');
            for (i = 0; i < flen; i++) putchar('0' + a[i]);
        }
        putchar('\n');
        return 0;
    }

    flen = pos;
    if (flen == 0) {
        add_one(zheng);
        printf("%s\n", zheng);
        return 0;
    }

    a[flen - 1]++;
    i = flen - 1;
    while (i >= 0 && a[i] == 10) {
        a[i] = 0;
        i--;
        if (i >= 0) a[i]++;
        else add_one(zheng);
    }
    t--;

    while (flen > 0 && a[flen - 1] == 0) flen--;

    while (t > 0 && flen > 0 && a[flen - 1] >= 5) {
        flen--;
        t--;
        if (flen == 0) {
            add_one(zheng);
            break;
        }
        a[flen - 1]++;
        i = flen - 1;
        while (i >= 0 && a[i] == 10) {
            a[i] = 0;
            i--;
            if (i >= 0) a[i]++;
            else add_one(zheng);
        }
        while (flen > 0 && a[flen - 1] == 0) flen--;
    }

    printf("%s", zheng);
    if (flen > 0) {
        putchar('.');
        for (i = 0; i < flen; i++) putchar('0' + a[i]);
    }
    putchar('\n');
    return 0;
}