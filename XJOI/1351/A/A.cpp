/**
 * XJOI1351 _趣味网络邀请赛
 * A
 */

#include <stdio.h>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    printf("%d\n", n * (n + 1) - 1);

    if (n & 1) {
        for (register int i = 1, j, k; i <= n; i += 2) {
            printf("%d %d\n", 1, i);
            for (j = 1, k = 1; j <= n; ++j, k ^= 1)
                printf("%d %d\n", j, i + k);
            for (j = n, k = 0; j > 1; --j, k ^= 1)
                printf("%d %d\n", j, i + k);
        }
    } else {
        for (register int i = 1, j, k; i <= n; i += 2) {
            for (j = 1, k = 0; j <= n; ++j, k ^= 1)
                printf("%d %d\n", j, i + k);
            for (j = n, k = 0; j > 0; --j, k ^= 1)
                printf("%d %d\n", j, i + k);
        }
        for (register int i = 1; i <= n; ++i)
            printf("%d %d\n", i, n + 1);
    }

    return 0;
}