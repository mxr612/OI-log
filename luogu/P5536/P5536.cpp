/**
 * P5536
*/

#include <stdio.h>
#include <stdlib.h>

#include <queue>

const int MXN = 100024;

int n, k;

template <typename TYP>
class MemPool {
    int SIZ;
    TYP *s, *e;
    TYP *get_mem() {
        for (s = NULL; !s;) s = (TYP *)calloc(sizeof(TYP), SIZ);
        return e = s + SIZ, s++;
    }

   public:
    MemPool() { s = e = NULL, SIZ = 1048576 / sizeof(TYP); }
    TYP *operator()() { return (s < e) ? (s++) : (get_mem()); }
};

struct Edge {
    int v;
    Edge *next;
} * edge[MXN];
MemPool<Edge> ep;
inline void add_edge(int u, int v) {
    Edge *p = ep();
    p->v = v;
    p->next = edge[u], edge[u] = p;
}
int ind[MXN];

int res[MXN], ans;
std::queue<int> que;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P5536.in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 1, u, v; i < n; ++i)
        scanf("%d%d", &u, &v),
            add_edge(u, v), add_edge(v, u),
            ++ind[u], ++ind[v];

    for (int i = 1; i <= n; ++i)
        if (ind[i] == 1)
            que.push(i);
    for (int i = 0, v; i < n - k; ++i) {
        v = que.front(), que.pop();
        for (Edge *j = edge[v]; j; j = j->next) {
            if (res[j->v] = std::max(res[j->v], res[v] + 1), --ind[j->v] == 1) {
                que.push(j->v);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        ans = std::max(ans, res[i]);
    printf("%d", ans);

    return 0;
}