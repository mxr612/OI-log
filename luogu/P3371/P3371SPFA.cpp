/**
 * luoguP3371
 * SPFA
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <queue>

const int MXN = 100024;

struct Edge {
    long long v, w;
    Edge* next;
};

template <typename TYP>
class MemPool {
    const int size = 1000;
    TYP *p, *e;
    TYP*& get_mem() {
        p = NULL;
        while (!p) p = (TYP*)calloc(sizeof(TYP), size);
        e = p + size;
        return p;
    }

   public:
    MemPool() { p = e = NULL; }
    TYP* operator()() { return (p == e) ? (get_mem()++) : (p++); }
};

Edge* edge[MXN];
MemPool<Edge> pool;
void add_edge(const int u, const int v, const int w) {
    Edge* p = pool();
    p->v = v, p->w = w;
    p->next = edge[u], edge[u] = p;
}

unsigned path[MXN];

class SPFAque {
    bool isin[MXN];
    long long sum = 0, siz = 0;
    std::deque<int> que;

   public:
    bool empty() { return !siz; }
    void push(int x, int w) {
        if (isin[x]) return;
        if (w * siz < sum)
            que.push_front(x);
        else
            que.push_back(x);
        isin[x] = true, sum += w, ++siz;
    }
    void pop() {
        if (!empty()) isin[que.front()] = false, que.pop_front(), --siz;
    }
    int top() { return que.front(); }
} que;

void SPFA(int s) {
    int v;
    memset(path, 127, sizeof(path));
    que.push(s, path[s] = 0);
    while (!que.empty()) {
        v = que.top(), que.pop();
        for (Edge* i = edge[v]; i; i = i->next)
            if (path[v] + i->w < path[i->v])
                que.push(i->v, path[i->v] = path[v] + i->w);
    }
}
signed main() {
#ifndef ONLINE_JUDGE
    freopen("P3371_3.in", "r", stdin);
#endif

    int n, m, s;

    scanf("%d%d%d", &n, &m, &s);

    for (int i = 0, u, v, w; i < m; ++i)
        scanf("%d%d%d", &u, &v, &w), add_edge(u, v, w);

    SPFA(s);

    for (int i = 1; i <= n; ++i)
        if (path[i] > 1e9)
            printf("%lld ", (1ll << 31) - 1);
        else
            printf("%u ", path[i]);

    return 0;
}