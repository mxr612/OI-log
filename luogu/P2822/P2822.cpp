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
    while (a > 0 && a % k == 0) a /= k, ++res;
    return res;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P2822.in", "r", stdin);
#endif

    scanf("%d%d", &t, &k);

    for (int i = 1, j; i < MXN; ++i)
        for (c[i][0] = cnt(1), j = 1; j <= i; ++j)
            c[i][j] = c[i][j - 1] + cnt(i - j + 1) - cnt(j);
    for (int i = 1; i < MXN; ++i)
        ans[i][0] += ans[i - 1][0];
    for (int i = 1, j; i < MXN; ++i)
        for (j = 1; j < MXN; ++j)
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1] + (c[i][j] > 0);

    for (int i = 0; i < 10; ++i, putchar('\n'))
        for (int j = 0; j < 10; ++j)
            printf("%5d", ans[i][j]);

    for (int n, m; t-- > 0;)
        scanf("%d%d", &n, &m), printf("%d\n", ans[n][m]);

    return 0;
}