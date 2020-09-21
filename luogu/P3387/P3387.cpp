/**
 * luoguP3387
 * 求强连通分量Tarjan
*/

#define MXN (10020)

#include <stdio.h>
#include <stdlib.h>

int n, m;

int node[MXN];

struct Edge {
    int v, w;
    Edge* next;
} * edge[MXN];
void add_edge(int u, int v) {
    Edge* x = (Edge*)calloc(sizeof(Edge), 1);
    x->v = v;
    x->next = edge[u], edge[u] = x;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P3387.in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)
        scanf("%d", &node[i]);

    for (int i = 0, u, v; i < m; ++i)
        scanf("%d%d", &u, &v), add_edge(u, v);

    return 0;
}