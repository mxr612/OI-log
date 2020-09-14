/**
 * 2020.08.23A
 * B 最优路线
 * luogu T145192 【2020.8.23NOIP模拟赛】最优路线
*/

#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <queue>

#define MXN (520)

int n, m;

struct Edge {
    int v, w;
};
std::vector<Edge> edge[MXN];

unsigned long long node[MXN], f[MXN][MXN], ans[MXN][MXN], bcp;

int rk[MXN];
bool cmp(int x, int y) { return node[x] < node[y]; }

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    memset(f, -1, sizeof(f));
    memset(ans, -1, sizeof(ans));
    bcp = f[0][0];

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", &node[i]);
    for (int i = 0, u, v, w; i < m; ++i)
        scanf("%d%d%d", &u, &v, &w), f[u][v] = f[v][u] = w;

    for (int i = 1; i <= n; ++i)
        rk[i] = i;
    std::sort(rk + 1, rk + 1 + n, cmp);

    for (int i = 1, j; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            ans[i][j] = f[i][j] * std::max(node[i], node[j]);

    for (int i = 1, j, k, x; i <= n; ++i)
        for (x = rk[i], j = 1; j <= n; ++j)
            for (k = 1; k <= n; ++k)
                if (std::max(f[j][x], f[x][k]) <= f[j][k])
                    f[j][k] = std::max(f[j][x], f[x][k]), ans[j][k] = std::min(ans[j][k], f[j][k] * std::max(node[x], std::max(node[j], node[k])));

    for (int i = 1; i <= n; ++i)
        ans[i][i] = 0;
    for (int i = 1, j, k; i <= n; ++i, putchar('\n'))
        for (j = 1; j <= n; ++j)
            printf("%lld ", (ans[i][j] == bcp) ? (-1) : (ans[i][j]));

    return 0;
}