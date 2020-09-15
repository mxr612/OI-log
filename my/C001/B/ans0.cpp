/**
 * C001B
 * Amazing John的P30拍照贼棒
 * 0-10pts搜索
*/

#define MXN (10000020)

#define II ("02.in")
#define OO ("02.out")

#include <stdio.h>
#include <string.h>

#include <algorithm>

int n, ans;

struct Edge {
    int u, v, w;
} edge[MXN];

bool vis[MXN];

signed main() {
    freopen(II, "r", stdin);
    freopen(OO, "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        edge[i].u = i + 1, scanf("%d%d", &edge[i].v, &edge[i].w);

    for (int i = 0, j, s; i < (1 << n); ++i) {
        for (memset(vis, 0, sizeof(vis)), s = j = 0; j < n; ++j)
            if (i & (1 << j) && !vis[edge[j].u] && !vis[edge[j].v])
                vis[edge[j].u] = vis[edge[j].v] = true, s += edge[j].w;
        ans = std::max(ans, s);
    }

    printf("%d", ans);

    return 0;
}
