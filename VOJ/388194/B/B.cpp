/**
 * VOJ
 * 388194B
 * CodeForces - 219D
*/

#include <stdio.h>

#include <vector>

#define MXN (200020)

int n;

struct Edge {
    int v, w;
};
std::vector<Edge> edge[MXN];

int cnt[MXN];
bool vis[MXN];
void dfs1(int v) {
    vis[v] = true;
    for (int i = edge[v].size() - 1; i >= 0; --i)
        if (!vis[edge[v][i].v])
            dfs1(edge[v][i].v), cnt[v] += cnt[edge[v][i].v] + edge[v][i].w;
    vis[v] = false;
}
void dfs2(int v) {
    vis[v] = true;
    for (int i = edge[v].size() - 1; i >= 0; --i)
        if (!vis[edge[v][i].v])
            cnt[edge[v][i].v] = cnt[v] + ((edge[v][i].w) ? (-1) : (1)), dfs2(edge[v][i].v);
    vis[v] = false;
}

int ans = MXN, res[MXN];
signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 1, s, t; i < n; ++i)
        scanf("%d%d", &s, &t), edge[s].push_back({t, 0}), edge[t].push_back({s, 1});

    dfs1(1), dfs2(1);

    for (int i = 1, j; i <= n; ++i) {
        if (cnt[i] < ans) ans = cnt[i], j = 0;
        if (cnt[i] == ans) res[j++] = i;
    }

    printf("%d\n", ans);
    for (int i = 0; res[i] > 0; ++i)
        printf("%d ", res[i]);

    return 0;
}