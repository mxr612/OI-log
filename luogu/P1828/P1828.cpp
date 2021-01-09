/**
 * P1828
*/

#include <stdio.h>
#include <stdlib.h>

#include <queue>

const int MXP = 1024;

int N, P, C;

int v[MXP];

template <typename TYP>
class MemPool {
    int SIZ;
    TYP *s, *e;
    TYP *get_mem() {
        for (s = NULL; !s;) s = (TYP *)calloc(sizeof(TYP), SIZ);
        return e = s + SIZ, s++;
    }

   public:
    MemPool() { SIZ = 1048576 / sizeof(TYP), s = e = NULL; }
    inline TYP *operator()() { return (s < e) ? (s++) : (get_mem()); }
};

struct Edge {
    int v, w;
    Edge *next;
} * edge[MXP];
MemPool<Edge> ep;
void add_edge(int u, int v, int w) {
    Edge *p = ep();
    p->v = v, p->w = w;
    p->next = edge[u], edge[u] = p;
}

int SPFA(int s) {
    std::queue<int> que;
    for (int x; !que.empty();) {
        x = que.front();
        for (int i =)
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("P1828.in", "r", stdin);
#endif

    scanf("%d%d%d", &N, &P, &C);

    for (int i = 0, x; i < N; ++i)
        scanf("%d", &x), ++v[x];
    for (int i = 0, x, y, w; i < C; ++i)
        scanf("%d%d%d", &x, &y, &w),
            add_edge(x, y, w), add_edge(y, x, w);

    int ans = 1e9;

    return 0;
}