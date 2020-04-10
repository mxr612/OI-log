/**
 * P3385
 * 负环判断
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MXN (2020)

int N;

struct __edge {
    int v, w;
    __edge* next;
} * edge[2020] = {NULL};

inline void _add_edge(register int u, register int v, register int w) {
    register __edge* p = (__edge*)calloc(sizeof(__edge), 1);
    p->v = v, p->w = w, p->next = edge[u], edge[u] = p;
}

int que[MXN], res[MXN], cnt[MXN];
bool vis[MXN];
bool _SPFA() {
    memset(res, 0x6f, sizeof(res));
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    res[1] = 0, que[0] = 1;
    register __edge* p;
    for (register int o = 0, i = 1; o != i;
         vis[que[o = (o + 1) % MXN]] = false) {
        if (++cnt[que[o]] > N)
            return true;
        else
            for (p = edge[que[o]]; p != NULL; p = p->next) {
                if (res[que[o]] + p->w < res[p->v]) {
                    res[p->v] = res[que[o]] + p->w;
                    if (!vis[p->v])
                        que[i] = p->v, vis[p->v] = true, i = (i + 1) % MXN;
                }
            }
    }
    return false;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P3385.in", "r", stdin);
#endif

    int T, M, u, v, w;

    scanf("%d", &T);

    for (register int t = 0, i; t < T; ++t) {
        memset(edge, 0, sizeof(edge));
        scanf("%d%d", &N, &M);
        for (i = 0; i < M; ++i) {
            scanf("%d%d%d", &u, &v, &w), _add_edge(u, v, w);
            if (w >= 0)
                _add_edge(v, u, w);
        }
        printf("%s\n", (_SPFA()) ? ("YES") : ("NO"));
    }

    return 0;
}