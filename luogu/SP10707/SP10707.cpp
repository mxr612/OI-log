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
#include <vector>

int N, M, lg2N;

struct LSH {
    int u, d;
    bool operator<(LSH x) { return u < x.u; }
} lsh[MXN];

struct Node {
    int w;
    std::vector<int> edge;
    int dep, fr, to, fa[LGN];
} node[MXN];

int eular[MXN], e = 0;

bool vis[MXN];
void DFS(int x) {
    vis[x] = true;
    eular[node[x].fr = e++] = x;
    node[x].dep = node[node[x].fa[0]].dep;
    for (int i = 1, *fa = node[x].fa; fa[i] > 0; --i)
        fa[i] = node[fa[i - 1]].fa[i - 1];
    for (int i = node[x].edge.size() - 1, p; i > 0; --i)
        if (!vis[p = node[x].edge[i]])
            node[p].fa[0] = x, DFS(p);
    eular[node[x].to = e++] = x;
    vis[x] = false;
}

int pos[MXN << 1];

struct Query {
    int d, l, r, f;
    bool b;
    bool operator<(Query x) { return (pos[l] == pos[x.l]) ? ((pos[l] & 1) ? (r < x.r) : (r > x.r)) : (pos[l] < pos[x.l]); }
} query[MXM];

int LCA(int x, int y) {
    if (node[x].dep < node[y].dep) x ^= y ^= x ^= y;
    for (int i = lg2N; i >= 0; --i)
        if (node[node[x].fa[i]].dep <= node[y].dep)
            x = node[x].fa[i];
    if (x != y) {
        for (int i = lg2N; i >= 0; --i)
            if (node[x].fa[i] != node[y].fa[i])
                x = node[x].fa[i], y = node[y].fa[i];
        x = node[x].fa[0], y = node[y].fa[0];
    }
    return x;
}

short apr[MXN];
int cnt[MXN], res;

void modify(int x) {  //node x
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
    freopen("test_in", "r", stdin);
    freopen("test_out", "w", stdout);
#endif

    scanf("%d%d", &N, &M), lg2N = log2(N) + 2;

    for (int i = 1; i <= N; ++i)
        scanf("%d", &lsh[i].u), lsh[i].d = i;
    std::sort(&lsh[1], &lsh[1 + N]);
    for (int i = 1, p = 1; i <= N; ++i)
        node[lsh[i].d].w = (lsh[i].u == lsh[i - 1].u) ? (p) : (++p);

    for (int i = 1, x, y; i < N; ++i)
        scanf("%d%d", &x, &y), node[x].edge.push_back(y), node[y].edge.push_back(x);

    DFS(1);

    for (int i = N << 1, siz = sqrt(N << 1); i > 0; --i)
        pos[i] = (i - 1) / siz + 1;

    for (int i = 1, x, y; i <= M; ++i) {
        query[i].d = i;
        scanf("%d%d", &x, &y);
        if (node[y].fr < node[x].fr) x ^= y ^= x ^= y;
        if ((query[i].f = LCA(x, y)) == x)
            query[i].l = node[x].fr, query[i].b = false;
        else
            query[i].l = node[x].to, query[i].b = true;
        query[i].r = node[y].fr;
    }

    std::sort(&query[1], &query[1 + M]);

    for (int i = 1, l = 1, r = 0; i <= M; ++i) {
        while (query[i].l < l) modify(eular[--l]);
        while (r < query[i].r) modify(eular[++r]);
        while (l < query[i].l) modify(eular[l++]);
        while (query[i].r < r) modify(eular[r--]);
        if (query[i].b) modify(query[i].f);
        ans[query[i].d] = res;
        if (query[i].b) modify(query[i].f);
    }

    for (int i = 1; i <= M; ++i)
        printf("%d\n", ans[i]);

    return 0;
}