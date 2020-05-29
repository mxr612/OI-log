/**
 * luogu P1733
 * 猜数
 */

#include <stdio.h>

int main() {
    for (int l = 1, r = 1000000000, m = (l + r) >> 1, res; l <= r;) {
        printf("%d\n", m = (l + r) >> 1), fflush(stdout);
        scanf("%d", &res);
        if (res == 0)
            return 0;
        else if (res == -1)
            l = m + 1;
        else if (res == 1)
            r = m - 1;
    }
    return 0;
}