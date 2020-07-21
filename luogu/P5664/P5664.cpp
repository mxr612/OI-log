/**
 * CSP-S 2019 D2T1
 * luogu P5664  Emiya 家今天的饭
 * DP
*/

#define MXN (220)
#define MXM (2020)
#define MOD (998244353)

#include <stdio.h>

int n, m;
int a[MXN][MXM];

long long s[MXN];
long long f[MXN][MXN], g[MXN][MXN];
long long ans;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P5664.in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1, j; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]), s[i] = (s[i] + a[i][j]) % MOD;

    f[0][n] = 1;
    for (int c = 1, i, j; c <= m; ++c) {
        for (i = 1; i <= n; ++i)
            for (j = n - i; j <= n + i; ++j)
                f[i][j] = (f[i - 1][j] + ((f[i - 1][j - 1] * a[i][c]) % MOD) + ((f[i - 1][j + 1] * (s[i] - a[i][c])) % MOD)) % MOD;
        for (i = 1; i <= n; ++i)
            ans = (ans - f[n][n + i] + MOD) % MOD;
    }

    for (int i = 1, j; i <= n; ++i)
        for (g[i - 1][0] = j = 1; j <= n; ++j)
            g[i][j] = (g[i - 1][j] + g[i - 1][j - 1] * s[i]) % MOD;
    for (int i = 1; i <= n; ++i)
        ans = (ans + g[n][i]) % MOD;

    printf("%d", ans);

    return 0;
}