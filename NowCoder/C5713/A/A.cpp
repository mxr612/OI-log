/**
 * NowCoder 5713A
 */

#include <math.h>
#include <stdio.h>

#include <algorithm>

#define INF (1e9)

int T, X, Y, ans;
int xx, yy, n;
int x[20], y[20], edge[20][20];
int vis[20] = {0};
bool flag[20] = {false};

void _dfs(int dep, int res) {
    if (dep < n) {
        for (int i = 1; i <= n; ++i) {
            if (!flag[i]) {
                flag[i] = true;
                vis[dep + 1] = i;
                _dfs(dep + 1, res + edge[vis[dep]][i]);
                flag[i] = false;
            }
        }
    } else
        ans = std::min(ans, res + edge[vis[dep]][0]);
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T-- > 0) {
        ans = INF;
        scanf("%d%d", &X, &Y);
        scanf("%d%d", &x[0], &y[0]);
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", &x[i], &y[i]);
        for (int i = 0; i <= n; ++i)
            for (int j = i; j <= n; ++j)
                edge[i][j] = edge[j][i] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        _dfs(0, 0);
        printf("The shortest path has length %d\n", ans);
    }

    return 0;
}