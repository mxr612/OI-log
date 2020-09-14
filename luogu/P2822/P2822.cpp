/**
 * luogu P2822
*/

#define MXN (2020)

#include <stdio.h>

#include <bitset>

int t, k;

int c[MXN][MXN], ans[MXN][MXN];

int cnt(int a) {
    int res = 0;
    while (k <= a && a % k == 0) a /= k, ++res;
    return res;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P2822_3.in", "r", stdin);
#endif

    scanf("%d%d", &t, &k);

    c[0][0] = 1;
    for (int i = 1, j; i < MXN; ++i)
        for (c[i][0] = 1, j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
    for (int i = 1, j; i < MXN; ++i)
        for (j = 1; j < MXN; ++j)
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1] + (j <= i && c[i][j] == 0);

    for (int n, m; t-- > 0;)
        scanf("%d%d", &n, &m), printf("%d\n", ans[n][m]);

    return 0;
}