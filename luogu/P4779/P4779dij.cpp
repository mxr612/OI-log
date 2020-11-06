/**
 * luoguP4779
 * dij求最短路
 * 内存池
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <set>

const int MXN = 100024;

struct Edge {
    int v, w;
    Edge* next;
} * edge[MXN];

class MemPool {
#define TYP Edge
    const int size = 1000;

    TYP *p, *e;

    void get_mem() {
        p = NULL;
        while (!p) p = (TYP*)calloc(sizeof(TYP), size);
        e = p + size;
    }

   public:
    MemPool() {
        p = e = NULL;
    }

    TYP* operator()() {
        if (p == e) get_mem();
        return p++;
    }

} pool;

void add_edge(const int u, const int v, const int w) {
    Edge* p = pool();
    p->v = v, p->w = w;
    p->next = edge[u], edge[u] = p;
}

int path[MXN];
void dij(int s) {
    std::set<std::pair<int, int> > set;
    int w, v;
    memset(path, 0x3f, sizeof(path));
    path[s] = 0, set.insert(std::make_pair(0, s));
    while (!set.empty()) {
        w = (*set.begin()).first, v = (*set.begin()).second, set.erase(set.begin());
        for (Edge* i = edge[v]; i; i = i->next)
            if (w + i->w < path[i->v])
                set.erase(std::make_pair(path[i->v], i->v)),
                    set.insert(std::make_pair(path[i->v] = w + i->w, i->v));
    }
}

signed
main() {
#ifndef ONLINE_JUDGE
    freopen("P4779.in", "r", stdin);
#endif

    int n, m, s;

    scanf("%d%d%d", &n, &m, &s);

    for (int i = 0, u, v, w; i < m; ++i)
        scanf("%d%d%d", &u, &v, &w), add_edge(u, v, w);

    dij(s);

    for (int i = 1; i <= n; ++i)
        printf("%d ", path[i]);

    return 0;
}