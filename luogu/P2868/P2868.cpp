/**
 * luoguP2868
 * [USACO07DEC]Sightseeing Cows G
 * 0/1分数规划，找负环
*/

#include <stdio.h>
#include <stdlib.h>

int const MXN = 1024;

int F[MXN];

struct Edge {
    int v, T;
    Edge* next;
} * edge[MXN];
inline void add_edge(const int u, const int v, const int T) {
    Edge* p = NULL;
    while (!p) p = (Edge*)calloc(sizeof(Edge), 1);
    p->v = v, p->T = T;
    p->next = edge[u], edge[u] = p;
}

double k;

bool check() {  //是否有负环
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P2868.in", "r", stdin);
#endif

    int n, m;

    for (int i = 1; i <= n; ++i)
        scanf("%d", F + i);
    for (int i = 0, u, v, T; i < m; ++i)
        scanf("%d%d%d", &u, &v, &T), add_edge(u, v, T);

    double l = 0, r = 1e7;

    while (r - l > 0.001) {
        if (k = (l + r) / 2, check())
            l = k;
        else
            r = k;
    }

    return 0;
}