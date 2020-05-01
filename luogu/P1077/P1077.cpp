/**
 * luogu P1077
 * DP
 */

#include <stdio.h>

#include <algorithm>

#define MOD (1000007)

int n, m, a, DP[2][120] = {0};

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1077_1.in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    DP[0][0] = DP[1][0] = 1;

    for (register int i = 0, j, s, p; i < n; ++i) {
        for (scanf("%d", &a), j = std::max(m - a + 1, 0), s = 0; j <= m; ++j)
            s += DP[i & 1][j];
        for (j = m; j > 0; --j)
            DP[~i & 1][j] = (s += ((j - a < 0) ? (0) : (DP[i & 1][j - a])) -
                                  DP[i & 1][j + 1]) %
                            MOD;
    }

    printf("%d", DP[n & 1][m]);

    return 0;
}