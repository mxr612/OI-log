/**
 * luoguP1850
 * NOIP2016换教室
*/

#include <stdio.h>
#include <string.h>

#include <algorithm>

const int MXN = 2056,
          MXM = 2056,
          MXV = 512;
const double INF = 1e15;

int n, m, v, e;

int c[MXN], d[MXN];
double k[MXN];

int path[MXV][MXV];

void Floyd() {
    for (int i, j, k = 1; k <= v; ++k)
        for (i = 1; i <= v; ++i)
            for (j = i + 1; j <= v; ++j)
                path[j][i] = path[i][j] = std::min(path[i][j], path[i][k] + path[k][j]);
}

double f[MXN][MXM][2];  //到第i个时间段，花费了j个机会，上一次尝试换了没有0/1。期望最短距离
double ans = INF;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1850.in", "r", stdin);
#endif

    memset(path, 32, sizeof(path));

    scanf("%d%d%d%d", &n, &m, &v, &e);

    for (int i = 1; i <= n; ++i)
        scanf("%d", c + i);
    for (int i = 1; i <= n; ++i)
        scanf("%d", d + i);
    for (int i = 1; i <= n; ++i)
        scanf("%lf", k + i);
    for (int i = 0, a, b, w; i < e; ++i)
        scanf("%d%d%d", &a, &b, &w),
            path[a][b] = path[b][a] = std::min(path[a][b], w);

    Floyd();
    for (int i = 1; i <= v; ++i)
        path[i][i] = 0;
    for (int i = 1, j; i <= n; ++i)
        for (j = 0; j <= m; ++j)
            f[i][j][0] = f[i][j][1] = INF;
    f[1][0][0] = f[1][1][1] = 0;

    for (int i = 2, j; i <= n; ++i) {
        for (f[i][0][0] = f[i - 1][0][0] + path[c[i - 1]][c[i]], j = 1; j <= std::min(i, m); ++j) {
            f[i][j][0] = std::min(f[i - 1][j][0] + path[c[i - 1]][c[i]], f[i - 1][j][1] + (1 - k[i - 1]) * path[c[i - 1]][c[i]] + k[i - 1] * path[d[i - 1]][c[i]]);
            f[i][j][1] = std::min(f[i - 1][j - 1][0] + (1 - k[i]) * path[c[i - 1]][c[i]] + k[i] * path[c[i - 1]][d[i]],
                                  f[i - 1][j - 1][1] + (1 - k[i - 1]) * (1 - k[i]) * path[c[i - 1]][c[i]] + (1 - k[i - 1]) * k[i] * path[c[i - 1]][d[i]] + k[i - 1] * (1 - k[i]) * path[d[i - 1]][c[i]] + k[i - 1] * k[i] * path[d[i - 1]][d[i]]);
        }
    }

    for (int i = 0; i <= m; ++i)
        ans = std::min(ans, std::min(f[n][i][0], f[n][i][1]));

    printf("%.2lf", ans);

    return 0;
}