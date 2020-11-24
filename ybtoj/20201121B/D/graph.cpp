/**
 * graph
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <queue>

const int MXN = 500012;

template <typename TYP>
class MemPool {
    int SIZ;
    TYP *s, *e;
    TYP *&get_mem() {
        for (s = NULL; !s;) s = (TYP *)calloc(sizeof(TYP), SIZ);
        return e = s + SIZ, s;
    }

   public:
    MemPool() { s = e = NULL, SIZ = 1048576 / sizeof(TYP); }
    TYP *operator()() { return (s < e) ? (s++) : (get_mem()++); }
};

struct Edge {
    int v;
    Edge *next;
} * edge[MXN];
MemPool<Edge> ep;
int ind[MXN];
void add_edge(int u, int v) {
    Edge *p = ep();
    p->v = v;
    p->next = edge[u], edge[u] = p;
    ++ind[v];
}

int sor[MXN], f[MXN], res, ans[2];

signed main() {
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);

    int n, m;

    scanf("%d%d", &n, &m);

    for (int i = 0, u, v; i < m; ++i)
        scanf("%d%d", &u, &v), add_edge(u, v);

    std::queue<int> que;
    for (int i = 1; i <= n; ++i)
        if (!ind[i])
            que.push(i);
    for (int i = 0, v; i < n; ++i) {
        sor[i] = v = que.front(), que.pop();
        for (Edge *p = edge[v]; p; p = p->next)
            if (!--ind[p->v])
                que.push(p->v);
    }

    ans[1] = 1e9;
    for (int i = 1, j; i <= n; ++i) {
        memset(f, 0, sizeof(f)), res = 0;
        for (j = 0; res < ans[1] && j < n; ++j) {
            if (sor[j] == i) f[i] = -1;
            for (Edge *k = edge[sor[j]]; k; k = k->next)
                f[k->v] = std::max(f[k->v], f[sor[j]] + 1);
            res = std::max(res, f[sor[j]]);
        }
        if (res < ans[1]) ans[0] = i, ans[1] = res;
    }

    printf("%d %d\n", ans[0], ans[1]);

    return 0;
}