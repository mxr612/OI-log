/**
 * luogu P4782
 * 2-SAT模板
*/

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

const int MXN = 2000056;

template <typename TYP>
class MemPool {
    int SIZ;
    TYP *p, *e;
    TYP *&get_mem() {
        p = NULL;
        while (!p) p = (TYP *)calloc(sizeof(TYP), SIZ);
        return e = p + SIZ, p;
    }

   public:
    MemPool() { p = e = NULL, SIZ = 1048576 / sizeof(TYP); }
    TYP *operator()() { return (p < e) ? (p++) : (get_mem()++); }
};

struct Edge {
    int v;
    Edge *next;
} * edge[MXN];
MemPool<Edge> mp;
void add_edge(int u, int v) {
    Edge *p = mp();
    p->v = v;
    p->next = edge[u], edge[u] = p;
}

int dfn[MXN], tod, low[MXN];
int sta[MXN], top, ins[MXN];
int tag[MXN], tot;
void tarjan(int v) {
    low[v] = dfn[v] = ++tod;
    sta[++top] = v, ins[v] = true;
    for (Edge *i = edge[v]; i; i = i->next)
        if (!dfn[i->v])
            tarjan(i->v), low[v] = std::min(low[v], low[i->v]);
        else if (ins[i->v])
            low[v] = std::min(low[v], low[i->v]);
    if (low[v] == dfn[v])
        for (++tot; top && dfn[sta[top]] >= dfn[v]; --top)
            tag[sta[top]] = tot, ins[sta[top]] = false;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P4782.in", "r", stdin);
#endif

    int n, m;

    scanf("%d%d", &n, &m);
    for (int i = 0, x, a, y, b; i < m; ++i)
        scanf("%d%d%d%d", &x, &a, &y, &b),
            add_edge(a * n + x, !b * n + y), add_edge(b * n + y, !a * n + x);

    for (int i = 1; i <= n * 2; ++i)
        if (!dfn[i])
            tarjan(i);

    for (int i = 1; i <= n; ++i)
        if (tag[i] == tag[n + i])
            return printf("IMPOSSIBLE"), 0;

    printf("POSSIBLE\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", tag[i] < tag[n + i]);

    return 0;
}