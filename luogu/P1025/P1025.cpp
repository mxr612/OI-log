/**
 * luogu P1025
 * 数的划分DP
*/

#define MXN (300)

#include <stdio.h>

int n, k;

int f[MXN][MXN];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1025.in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    f[0][0] = 1;
    for (int i = 1, j; i <= k; ++i) {
        for (j = 1; j <= n; ++j) {
            f[i][j] = f[i - 1][j - 1];
            if (j - i >= 0) f[i][j] += f[i][j - i];
        }
    }

    printf("%d", f[k][n]);

    return 0;
}