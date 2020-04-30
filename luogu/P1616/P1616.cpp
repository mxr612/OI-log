/**
 * luogu P1616
 * 疯狂的采药
 */

#include <stdio.h>

#include <algorithm>

#define MXT (10000020)

int t, m, a, b, DP[2][MXT] = {0}, ans = 0;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1616_2.in", "r", stdin);
#endif

    scanf("%d%d", &t, &m);

    for (register int i = 1, j; i <= m; ++i)
        for (scanf("%d%d", &a, &b), j = 1; j <= t; ++j)
            ans = std::max(
                ans, DP[i & 1][j] = std::max(
                         DP[~i & 1][j],
                         (j < a) ? (DP[~i & 1][j]) : (DP[i & 1][j - a] + b)));

    printf("%d", ans);

    return 0;
}