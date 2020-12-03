/**
 * path
*/

#include <stdio.h>
#include <string.h>

#include <algorithm>

const int MXN = 512;

int n, m;

int max[MXN][MXN];
long long v[MXN], ans[MXN][MXN];
std::pair<int, int> p[MXN];

signed main() {
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);

    memset(ans, 32, sizeof(ans));
    memset(max, 127, sizeof(max));

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", v + i), p[i].first = v[i], p[i].second = i;
    for (int i = 0, u, v, w; i < m; ++i)
        scanf("%d%d%d", &u, &v, &w), max[v][u] = max[u][v] = std::min(max[u][v], w);

    std::sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; ++i)
        max[i][i] = 0;
    for (int i = 1, j; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            ans[i][j] = std::min(ans[i][j], std::max(v[i], v[j]) * max[i][j]);

    for (int i, j, k = p[1].second, x = 1; x <= n; k = p[++x].second)
        for (i = 1; i <= n; ++i)
            for (j = 1; j <= n; ++j)
                max[i][j] = std::min(max[i][j], std::max(max[i][k], max[k][j])),
                ans[i][j] = std::min(ans[i][j], std::max(v[k], std::max(v[i], v[j])) * max[i][j]);

    for (int i = 1, j; i <= n; ++i, putchar('\n'))
        for (j = 1; j <= n; ++j)
            if (ans[i][j] > 1e18)
                printf("-1 ");
            else
                printf("%lld ", ans[i][j]);

    return 0;
}