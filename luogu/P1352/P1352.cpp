/**
 * luogu P1352
 * 没有上司的舞会
 */

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#define MXN (6020)

int n, r[MXN], l, k, f[MXN] = {0};
struct __edge {
    int v;
    __edge* next;
} * edge[MXN] = {NULL};
inline void _add_edge(int u, int v) {
    __edge* p = (__edge*)calloc(sizeof(__edge), 1);
    p->v = v, p->next = edge[u], edge[u] = p;
}
int DP[MXN][2] = {0};

void _dfs(int v) {
    for (__edge* p = edge[v]; p != NULL; p = p->next)
        _dfs(p->v), DP[v][0] += std::max(DP[p->v][0], DP[p->v][1]),
            DP[v][1] += DP[p->v][0];
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1352.in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", &DP[i][1]);

    for (int i = 1; i < n; ++i)
        scanf("%d%d", &l, &k), _add_edge(k, l), f[l] = k;
    for (int i = 1; i <= n; ++i) {
        if (f[i] == 0) {
            _dfs(i);
            printf("%d", std::max(DP[i][0], DP[i][1]));
            break;
        }
    }

    return 0;
}