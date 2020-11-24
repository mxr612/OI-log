/**
 * perm
*/

#include <stdio.h>
#include <stdlib.h>

#include <bitset>
#include <queue>

const int MXN = 5012,
          MD = 998244353;

int n;

template <typename TYP>
class MemPool {
    int SIZ;
    TYP *s, *e;
    TYP*& get_mem() {
        for (s = NULL; !s;) s = (TYP*)calloc(sizeof(TYP), SIZ);
        return e = s + SIZ, s;
    }

   public:
    MemPool() { s = e = NULL, SIZ = 1048576 / sizeof(TYP) + 1; }
    inline TYP* operator()() { return (s < e) ? (s++) : (get_mem()++); }
};

struct Edge {
    int v;
    Edge* next;
} * edge[MXN], *ft[MXN];
MemPool<Edge> ep;
inline void add_edge(Edge** edge, int u, int v) {
    Edge* p = ep();
    p->v = v;
    p->next = edge[u], edge[u] = p;
}

int ind[MXN], sor[MXN];
int l[MXN], r[MXN];

std::bitset<MXN> bs;
int ans, sta[MXN];
inline int min(int x) {  //node x
    int res = l[x];
    for (Edge* i = ft[x]; i; i = i->next)
        res = std::max(res, sta[i->v] + 1);
    return res;
}
void dfs(int x) {
    if (x == n)
        ++ans %= MD;
    else
        for (int i = min(sor[x]); i <= r[sor[x]]; ++i)
            if (!bs[i])
                bs[i] = true,
                sta[sor[x]] = i, dfs(x + 1), bs[i] = false;
}

signed main() {
    freopen("perm.in", "r", stdin);
    freopen("perm.out", "w", stdout);

    scanf("%d", &n);

    for (int i = 1, u, v; i < n; ++i)
        scanf("%d%d", &u, &v),
            add_edge(edge, u, v), ++ind[v],
            add_edge(ft, v, u);

    std::queue<int> que;
    for (int i = 1; i <= n; ++i)
        if (ind[i] == 0)
            que.push(i);
    for (int i = 0, v; i < n; ++i) {
        sor[i] = v = que.front(), que.pop();
        for (Edge* j = edge[v]; j; j = j->next)
            if (--ind[j->v] == 0)
                que.push(j->v);
    }

    for (int i = 0, ii; i < n; ++i) {
        ++l[ii = sor[i]];
        for (Edge* j = edge[ii]; j; j = j->next)
            l[j->v] += l[ii];
    }
    for (int i = n - 1, ii; i >= 0; --i) {
        ++r[ii = sor[i]];
        for (Edge* j = edge[ii]; j; j = j->next)
            r[ii] += r[j->v];
    }
    for (int i = 1; i <= n; ++i)
        r[i] = n - r[i] + 1;

    dfs(0);
    printf("%d", ans);

    return 0;
}