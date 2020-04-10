/**
 * P1271
 */

#include <stdio.h>

#define MXN (1020)

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1271.in", "r", stdin);
#endif

    int n, m, c, cnt[MXN] = {0};

    scanf("%d%d", &n, &m);

    for (register int i = 0; i < m; ++i)
        scanf("%d", &c), ++cnt[c];

    for (register int i = n - 1; i > 0; --i)
        cnt[i] += cnt[i + 1];

    for (register int i = 1; i <= n; ++i)
        while (cnt[i]-- > cnt[i + 1])
            printf("%d ", i);

    return 0;
}