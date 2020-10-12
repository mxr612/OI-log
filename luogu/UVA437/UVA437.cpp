/**
 * luogu UVA437
 * 巴比伦塔 The Tower of Babylon
 * DAG上DP
*/

#define MXN (128)

#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <set>

struct CUB {
    int x, y, z;
    bool operator<(const CUB c) const {
        return x < c.x && y < c.y;
    }
    CUB& operator=(const CUB c) {
        x = std::min(c.x, c.y);
        y = std::max(c.x, c.y);
        z = c.z;
        return *this;
    }
} cub[MXN] = {};
int tot;

struct Edge {
    int v;
    Edge* next;
} * edge[MXN] = {};
void add_edge(int u, int v) {
    Edge* x = NULL;
    while (!x) x = (Edge*)calloc(sizeof(Edge), 1);
    x->v = v, x->next = edge[u], edge[u] = x;
}

int ent[MXN];

std::set<int> set;

int ans[MXN];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("UVA437.in", "r", stdin);
#endif

    int t = 0, n, answ;

    while (scanf("%d", &n), n) {
        tot = answ = 0;
        memset(edge, 0, sizeof(edge));
        memset(ent, 0, sizeof(ent));
        set.empty();
        memset(ans, 0, sizeof(ans));
        for (int i = 0, x, y, z; i < n; ++i)
            scanf("%d%d%d", &x, &y, &z),
                cub[tot++] = CUB{x, y, z},
                cub[tot++] = CUB{y, z, x},
                cub[tot++] = CUB{z, x, y};
        for (int i = 0, j; i < tot; ++i)
            for (j = 0; j < tot; ++j)
                if (cub[i] < cub[j])
                    add_edge(i, j), ++ent[j];
        for (int i = 0; i < tot; ++i)
            if (!ent[i])
                set.insert(i), ans[i] = cub[i].z;
        int x;
        while (set.size()) {
            set.erase(x = *set.begin());
            for (Edge* i = edge[x]; i; i = i->next)
                if (ans[i->v] = std::max(ans[i->v], ans[x] + cub[i->v].z), !--ent[i->v])
                    set.insert(i->v);
        }
        for (int i = 0; i < tot; ++i)
            answ = std::max(answ, ans[i]);
        printf("Case %d: maximum height = %d\n", ++t, answ);
    }

    return 0;
}