/**
 * luogu P2016
 * DP
 */

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

#define MXN (2000)
#define INF (1e9)

struct __edge {
    int v;
    __edge* next;
} * edge[MXN] = {NULL};

inline void _add_edge(int u, int v) {
    __edge* p = (__edge*)calloc(sizeof(__edge), 1);
    p->v = v, p->next = edge[u], edge[u] = p;
}

int DP[MXN][2] = {0};  // 0:未选中 1:已选中
bool vis[MXN] = {false};

void _dfs(int u) {
    vis[u] = true;
    ++DP[u][1];
    for (__edge* p = edge[u]; p != NULL; p = p->next) {
        if (!vis[p->v]) {
            _dfs(p->v);
            DP[u][0] += DP[p->v][1];
            DP[u][1] += std::min(DP[p->v][0], DP[p->v][1]);
        }
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P2016.in", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    for (int i = 0, u, v, k; i < n; ++i) {
        scanf("%d%d", &u, &k);
        while (k-- > 0)
            scanf("%d", &v), _add_edge(u, v), _add_edge(v, u);
    }

    _dfs(0);

    printf("%d", std::min(DP[0][0], DP[0][1]));

    return 0;
}