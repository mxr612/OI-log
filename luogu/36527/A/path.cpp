/**
 * 20201104校测
 * A path 普通快乐
 * 多源Dij
 * 又一场阴间比赛
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
void add_edge(const int u, const int v, const int w) {
    Edge* p = NULL;
    while (!p) p = (Edge*)calloc(sizeof(Edge), 1);
    p->v = v, p->w = w;
    p->next = edge[u], edge[u] = p;
}

std::set<std::pair<int, int> > set;
bool vis[MXN];
int path[MXN];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("path.in", "r", stdin);
#endif

    int n, m, k;

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0, x, y, c; i < m; ++i)
        scanf("%d%d%d", &x, &y, &c),
            add_edge(x, y, c), add_edge(y, x, c);

    for (int i = 0, x; i < k; ++i)
        scanf("%d", &x), set.insert(std::make_pair(0, x));
    memset(path, 0x3f, sizeof(path));

    std::pair<int, int> p;
    int w, v;
    while (!set.empty()) {
        w = (*set.begin()).first, v = (*set.begin()).second;
        set.erase(set.begin());
        for (Edge* i = edge[v]; i; i = i->next) {
            if (!vis[i->v])
        }
    }

    return 0;
}

/*
我看到未来在向我招手
怎样都好 向前走吧
*/