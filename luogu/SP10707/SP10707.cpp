/**
 * luogu SP10707
 * SP10707 COT2 - Count on a tree II
*/

#define MXN (40020)
#define LGN (220)
#define MXM (100000)

#include <math.h>
#include <stdio.h>

#include <algorithm>

int N, M, lg2N;

struct LSH {
    int u, id;
    bool operator<(LSH x) { return u < x.u; }
} lsh[MXN];

struct Node {
    int w;
    struct Edge {
        int v;
        Edge* next;
    }* edge = NULL, ** back = &edge;
    inline void Add_Edge(int x) { ((*back) = (Edge*)calloc(sizeof(Edge), 1))->v = x, back = &((*back)->next); }
    int dep = 0, fr, to;
    int fa[LGN];
} node[MXN];

int eular[MXN << 1], e = 0;

bool vis[MXN] = {false};
void DFS(int x) {  //Eular preLCA
    vis[x] = true;
    eular[node[x].fr = e++] = x;
    node[x].dep = node[node[x].fa[0]].dep;
    for (int i = 1, *fa = node[x].fa; fa[i] > 0; ++i)
        fa[i] = node[fa[i - 1]].fa[i - 1];
    for (Node::Edge* p = node[x].edge; p != NULL; p = p->next)
        if (!vis[p->v]) node[p->v].fa[0] = x, DFS(p->v);
    eular[node[x].to = e++] = x;
    vis[x] = false;
}

int LCA(int x, int y) {
    if (node[y].dep < node[x].dep) x ^= y ^= x ^= y;
    for (int i = lg2N; i >= 0; --i)
        if (node[node[x].fa[i]].dep <= node[y].dep)
            x = node[x].fa[i];

    return x;
}

int pos[MXN << 1];
struct Query {
    int d, x, l, r;
    bool o;
    bool operator<(Query x) { return (pos[l] == pos[x.l]) ? ((pos[l] & 1) ? (r < x.r) : (r > x.r)) : (pos[l] < pos[x.l]); }
} query[MXM];

short apr[MXN] = {0};   //node_apr
int cnt[MXN], res = 0;  //weight_cnt pre_res

void Modify(int x) {  //Node x
    if (apr[x] ^= 1) {
        if (cnt[node[x].w]++ == 0)
            ++res;
    } else {
        if (cnt[node[x].w]-- == 1)
            --res;
    }
}

int ans[MXM];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
#endif

    scanf("%d%d", &N, &M), lg2N = log2(N) + 2;

    for (int i = 1; i <= N; ++i)
        scanf("%d", &lsh[i].u), lsh[i].id = i;
    std::sort(&lsh[1], &lsh[1 + N]);
    for (int i = 1, p = 0; i <= N; ++i)
        node[lsh[i].id].w = (lsh[i].u == lsh[i - 1].u) ? (p) : (++p);

    for (int i = 1, x, y; i < N; ++i)
        scanf("%d%d", &x, &y), node[x].Add_Edge(y), node[y].Add_Edge(x);

    DFS(1);

    for (int i = 1, siz = sqrt(N << 1); i <= N << 1; ++i)
        pos[i] = (i - 1) / siz + 1;

    for (int i = 1, x, y; i <= M; ++i) {
        query[i].d = i;
        scanf("%d%d", &x, &y);
        if (node[y].fr < node[x].fr) x ^= y ^= x ^= y;
        if ((query[i].x = LCA(x, y)) == x)
            query[i].l = node[x].fr, query[i].o = false;
        else
            query[i].l = node[x].to, query[i].o = true;
        query[i].r = node[y].fr;
    }

    std::sort(&query[1], &query[1 + M]);

    for (int i = 1, l = 1, r = 0; i <= M; ++i) {
        while (query[i].l < l) Modify(eular[--l]);
        while (r < query[i].r) Modify(eular[++r]);
        while (l < query[i].l) Modify(eular[l++]);
        while (query[i].r < r) Modify(eular[r--]);
        if (query[i].o) Modify(query[i].x);
        ans[query[i].d] = res;
        if (query[i].o) Modify(query[i].x);
    }

    for (int i = 1; i <= M; ++i)
        printf("%d\n", ans[i]);

    return 0;
}