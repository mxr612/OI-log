/**
 * luogu SP10707
 * SP10707 COT2 - Count on a tree II
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

#include <algorithm>

#define MXN (40020)
#define MXM (100020)
#define LGN (220)

int N, M, lgN;

struct __node {
    int w;
    struct __edge {
        int v;
        __edge* next;
    }* edge = NULL, ** back = &edge;
    void _add_edge(int v) {
        ((*back) = (__edge*)calloc(sizeof(__edge), 1))->v = v, back = &((*back)->next);
    }
    bool vis = true;
    int fr, to;
    int dep, fa[LGN] = {0};
} node[MXN];

int Euler[MXN << 1], e = 0;
void _Euler_LCA(int x, int dep) {
    node[x].dep = dep;
    node[x].vis = false;
    Euler[node[x].fr = ++e] = x;
    for (int i = 1, *fa = node[x].fa; fa[i - 1] != 0; ++i)
        fa[i] = node[fa[i - 1]].fa[i - 1];
    for (__node::__edge* p = node[x].edge; p != NULL; p = p->next)
        if (node[p->v].vis)
            node[p->v].fa[0] = x, _Euler_LCA(p->v, dep + 1);
    Euler[node[x].to = ++e] = x;
    node[x].vis = true;
}

int _LCA(int x, int y) {
    if (node[x].dep < node[y].dep) x ^= y ^= x ^= y;
    for (int d = node[x].dep - node[y].dep; d > 0; d -= (d & (-d)))
        x = node[x].fa[int(log2(d & (-d)))];
    if (x != y) {
        for (int i = lgN; i >= 0; --i)
            if (node[x].fa[i] != node[y].fa[i])
                x = node[x].fa[i], y = node[y].fa[i];
        x = node[x].fa[0], y = node[y].fa[0];
    }
    return x;
}

int pos[MXN];
struct __query {
    int id, l, r, x;
    bool c;
    bool operator<(__query x) { return (pos[l] == pos[x.l]) ? (r < x.r) : (pos[l] < pos[x.l]); }
} query[MXM];

int apr[MXN] = {0};
int l = 1, r = 0, ans = 0;

inline void _modify(register int x) {
    ans -= apr[node[x].w], ans += apr[node[x].w] ^= 1;
    printf("%5d %5d\n", node[x].w, ans);
}

int answ[MXM];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("SP10707.in", "r", stdin);
#endif

    scanf("%d%d", &N, &M), lgN = log2(N);

    for (int i = 1; i <= N; ++i)
        scanf("%d", &node[i].w);
    for (int i = 1, u, v; i < N; ++i)
        scanf("%d%d", &u, &v), node[u]._add_edge(v), node[v]._add_edge(u);

    _Euler_LCA(1, 1);

    for (int i = 1, siz = sqrt(N); i <= N << 1; ++i)
        pos[i] = (i - 1) / siz + 1;
    for (int i = 0, x, y; i < M; ++i) {
        query[i].id = i;
        scanf("%d%d", &x, &y);
        if (node[y].fr < node[x].fr) x ^= y ^= x ^= y;
        if ((query[i].x = _LCA(x, y)) == x)
            query[i].l = node[x].fr, query[i].c = false;
        else
            query[i].l = node[x].to, query[i].c = true;
        query[i].r = node[y].fr;
    }

    std::sort(&query[0], &query[M]);

    for (int i = 0; i < M; ++i) {
        // printf("%5d %5d\n", pos[query[i].l], query[i].r);
        while (query[i].l < l) _modify(Euler[--l]);
        while (r < query[i].r) _modify(Euler[++r]);
        while (l < query[i].l) _modify(Euler[l++]);
        while (query[i].r < r) _modify(Euler[r--]);
        if (query[i].c) _modify(query[i].x);
        printf("%d\n", ans);
        answ[query[i].id] = ans;
        if (query[i].c) _modify(query[i].x);
    }

    for (int i = 0; i < M; ++i)
        printf("%d\n", answ[i]);

    for (int i = 1; i <= N << 1; ++i)
        printf("%5d ", Euler[i]);

    // for (int i = 0; i <= e; ++i)
    //     printf("%5d ", Euler[i]);

    return 0;
}