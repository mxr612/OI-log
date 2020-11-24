/**
 * luogu P3387
 * 求强连通分量Tarjan
*/
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <queue>

const int MXN = 10024;

int n, m;

int w[MXN];

template <typename TYP>
class MemPool {
    int size;
    TYP *s, *e;
    TYP*& get_mem() {
        s = NULL;
        while (!s) s = (TYP*)calloc(sizeof(TYP), size);
        return e = s + size, s;
    }

   public:
    inline MemPool() { s = e = NULL, size = 1024 * 1024 / sizeof(TYP); }
    inline TYP* operator()() { return (s < e) ? (s++) : (get_mem()++); }
};

struct Edge {
    int v, w;
    Edge* next;
} * edge[MXN], *ee[MXN];
MemPool<Edge> ep;
void add_edge(Edge** edge, int u, int v) {
    Edge* x = ep();
    x->v = v;
    x->next = edge[u], edge[u] = x;
}

int dfn[MXN], low[MXN], tot, sta[MXN], top;
int nn[MXN], ton;
bool vis[MXN];

void tarjan(int v) {
    low[v] = dfn[v] = ++tot;
    sta[++top] = v, vis[v] = true;
    for (Edge* i = edge[v]; i; i = i->next)
        if (!dfn[i->v])
            tarjan(i->v),
                low[v] = std::min(low[v], low[i->v]);
        else if (vis[i->v])
            low[v] = std::min(low[v], low[i->v]);
    if (low[v] == v) {
        ++ton;
        do
            nn[sta[top]] = ton, vis[sta[top]] = false;
        while (sta[top--] >= 0 && top);
    }
}

int ww[MXN], ind[MXN], f[MXN];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P3387_1.in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)
        scanf("%d", &w[i]);

    for (int i = 0, u, v; i < m; ++i)
        scanf("%d%d", &u, &v), add_edge(edge, u, v);

    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            tarjan(i);

    for (int i = 1; i <= n; ++i) {
        ww[nn[i]] += w[i];
        for (Edge* j = edge[i]; j; j = j->next)
            if (nn[i] != nn[j->v])
                add_edge(ee, nn[i], nn[j->v]), ++ind[nn[j->v]];
    }

    std::queue<int> que;
    int ans = 0;
    for (int i = 1; i <= ton; ++i)
        if (ind[i] == 0) que.push(i);
    for (int i = 0, v; i < ton; ++i) {
        v = que.front(), que.pop();
        ans = std::max(ans, f[v] += ww[v]);
        for (Edge* j = ee[v]; j; j = j->next)
            if (f[j->v] = std::max(f[j->v], f[v]), --ind[j->v] == 0)
                que.push(j->v);
    }

    printf("%d", ans);

    return 0;
}