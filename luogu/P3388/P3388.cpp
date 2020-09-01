/**
 * P3388 割点
*/

#define MXN (100020)

#include <stdio.h>
#include <string.h>

#include <vector>

int n, m, ans;

std::vector<int> edge[MXN];

int dfn[MXN], now, low[MXN], cnt[MXN];
bool is[MXN];

void dfs(int x, int f) {
    dfn[x] = ++now;
    for (int i = 0, k; i < edge[x].size(); ++i)
        if ((k = edge[x][i]) != f)
            if (dfn[k])
                low[x] = std::min(low[x], dfn[k]);
            else
                ++cnt[x], dfs(k, x), low[x] = std::min(low[x], low[k]), is[x] |= (low[k] >= dfn[x]);
    if (is[x] && (x != f || cnt[x] > 1))
        ++ans;
    else
        is[x] = false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("P3388_1.in", "r", stdin);
#endif

    memset(low, 0x3f, sizeof(low));

    scanf("%d%d", &n, &m);
    for (int i = 0, x, y; i < m; ++i)
        scanf("%d%d", &x, &y), edge[x].push_back(y), edge[y].push_back(x);

    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            now = 0, dfs(i, i);

    printf("%d\n", ans);
    ans = 0;
    for (int i = 1; i <= n; ++i)
        if (is[i])
            printf("%d ", i);

    return 0;
}