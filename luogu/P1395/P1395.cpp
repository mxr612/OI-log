/**
 * P1395
*/

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

const int MXN = 50012;

int n;

template <typename TYP>
class MemPool {
    int SIZ;
    TYP *s, *e;
    TYP *get_mem() {
        for (s = NULL; !s;) s = (TYP *)calloc(sizeof(TYP), SIZ);
        return e = s + SIZ, s++;
    }

   public:
    MemPool() { SIZ = 1048576 / sizeof(TYP) + 1, s = e = NULL; }
    TYP *operator()() { return (s < e) ? (s++) : (get_mem()); }
};

struct Edge {
    int v;
    Edge *next;
} * edge[MXN] = {};
MemPool<Edge> ep;
inline void add_edge(int u, int v) {
    Edge *p = ep();
    p->v = v;
    p->next = edge[u], edge[u] = p;
}

bool vis[MXN];
int siz[MXN], max[MXN];
int ans[3] = {int(1e9)};
void dfsI(int x) {
    vis[x] = true;
    for (Edge *i = edge[x]; i; i = i->next)
        if (!vis[i->v])
            dfsI(i->v),
                siz[x] += siz[i->v],
                max[x] = std::max(max[x], siz[i->v]);
    max[x] = std::max(max[x], n - ++siz[x]);
    if (max[x] == ans[0])
        ans[1] = std::min(ans[1], x);
    if (max[x] < ans[0])
        ans[0] = max[x], ans[1] = x;
    vis[x] = false;
}
void dfsII(int x, int dep) {
    vis[x] = true;
    ans[2] += dep;
    for (Edge *i = edge[x]; i; i = i->next)
        if (!vis[i->v])
            dfsII(i->v, dep + 1);
    vis[x] = false;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1395.in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1, x, y; i < n; ++i)
        scanf("%d%d", &x, &y),
            add_edge(x, y), add_edge(y, x);

    dfsI(1), dfsII(ans[1], 0);

    printf("%d %d", ans[1], ans[2]);

    return 0;
}