
#include <math.h>
#include <stdio.h>

const long long MD = 1000000007;

int n, m, k;
int g[11][11], f[11][11];
int col[11];

int dfs(int x, int y) {
    if (y > m) y = 1, ++x;
    if (x > n) return 1;
    int res = 0, d = -74751;
    int now = f[x - 1][y] | f[x][y - 1], cnt = 0, can;
    for (int i = now; i; i -= i & -i) ++cnt;
    if (k - cnt < n - x + m - y + 1) return 0;
    can = (~now) & ((1 << k) - 1);
    for (int i = can & -can, ii = log2(i) + 1; can; can -= i, i = can & -can, ii = log2(i) + 1)
        if (g[x][y] == 0 || g[x][y] == ii)
            f[x][y] = now | i,
            (res += ((++col[ii] == 1) ? ((d < 0) ? (d = dfs(x, y + 1)) : (d)) : (dfs(x, y + 1)))) %= MD,
            --col[ii];
    return res;
}

signed main() {
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1, j; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            scanf("%d", &g[i][j]), ++col[g[i][j]];
    printf("%d", dfs(1, 1));

    return 0;
}