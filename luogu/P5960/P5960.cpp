/**
 * P5960
 * 差分约束
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MXN (5020)

int n;

struct __edge {
    int v, w;
    __edge* next;
} * edge[MXN] = {NULL};

inline void _add_edge(register int u, register int v, register int w) {
    register __edge* p = (__edge*)calloc(sizeof(__edge), 1);
    p->v = v, p->w = w, p->next = edge[u], edge[u] = p;
}

int res[MXN], que[MXN], cnt[MXN];
bool vis[MXN] = {false};
bool _SPFA() {
    memset(res, 0x6f, sizeof(res));
    res[0] = 0, que[0] = 0;
    register __edge* p;
    for (register int o = 0, i = 1; o != i;
         vis[que[o = (o + 1) % MXN]] = false) {
        if (++cnt[que[o]] > n)
            return false;
        for (p = edge[que[o]]; p != NULL; p = p->next) {
            if (res[que[o]] + p->w < res[p->v]) {
                res[p->v] = res[que[o]] + p->w;
                if (!vis[p->v])
                    que[i] = p->v, vis[p->v] = true, i = (i + 1) % MXN;
            }
        }
    }
    return true;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P5960.in", "r", stdin);
#endif

    int m, u, v, w;

    scanf("%d%d", &n, &m);

    for (register int i = 0; i < m; ++i)
        scanf("%d%d%d", &v, &u, &w), _add_edge(u, v, w);
    for (register int i = 1; i <= n; ++i)
        _add_edge(0, i, 0);

    if (_SPFA())
        for (register int i = 1; i <= n; ++i)
            printf("%d ", res[i]);
    else
        printf("NO\n");

    return 0;
}