/**
 * luogu U142297
*/

#include <stdio.h>

#include <algorithm>

const int MXN = 153,
          MXK = 23,
          MD = 1000000007;

int f[MXN][MXN][MXK][MXK];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("U142297.in", "r", stdin);
#endif

    int n, m, k, ans = 0;

    scanf("%d%d%d", &n, &m, &k);

    f[0][0][0][0] = 1;

    for (int i = 0, j, a, b; i <= n; ++i)
        for (j = 0; j <= m; ++j)
            for (a = 0; a <= k; ++a)
                for (b = 0; b <= k; ++b)
                    (f[i + 1][j][a + 1][std::max(0, b - 1)] += f[i][j][a][b]) %= MD,
                        (f[i][j + 1][std::max(0, a - 1)][b + 1] += f[i][j][a][b]) %= MD;

    for (int i = 0, j; i <= k; ++i)
        for (j = 0; j <= k; ++j)
            (ans += f[n][m][i][j]) %= MD;

    printf("%d", ans);

    return 0;
}