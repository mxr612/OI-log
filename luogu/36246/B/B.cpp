
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool dfs(char *s, char *res, int IV, int VII, const bool up) {
    if (IV + VII < 1) return *res = 0, true;
    if (up) {
        if (IV)
            return *res = '4', dfs(s + 1, res + 1, IV - 1, VII, true);
        else
            return *res = '7', dfs(s + 1, res + 1, IV, VII - 1, true);
    } else {
        if (IV && *s < '4' && dfs(s + 1, res + 1, IV - 1, VII, true))
            return *res = '4', true;
        else if (IV && *s == '4' && dfs(s + 1, res + 1, IV - 1, VII, false))
            return *res = '4', true;
        else if (VII && *s < '7')
            return *res = '7', dfs(s + 1, res + 1, IV, VII - 1, true);
        else if (VII && *s == '7')
            return *res = '7', dfs(s + 1, res + 1, IV, VII - 1, false);
        else
            return false;
    }
}

signed main() {
    char *s = (char *)calloc(sizeof(char), 100024),
         *res = (char *)calloc(sizeof(char), 100024);

    int len;

    while (scanf("%s", s) != EOF) {
        len = strlen(s);
        if (len & 1 || !dfs(s, res, len / 2, len / 2, false)) {
            for (int i = 0; i <= len / 2; ++i)
                putchar('4');
            for (int i = 0; i <= len / 2; ++i)
                putchar('7');
            putchar('\n');
        } else {
            printf("%s\n", res);
        }
    }

    return 0;
}