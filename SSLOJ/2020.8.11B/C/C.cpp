
#define MXN (100020)

#include <stdio.h>

#include <algorithm>
#include <queue>
#include <vector>

long long n, k;

struct Edge {
    long long v, w;
};

std::vector<Edge> edge[MXN];

long long a[MXN], b[MXN], pa, pb;

bool vis[MXN];
void dfs(int v, int d, long long w) {
    vis[v] = true;
    if (d < 0)
        a[pa++] = w;
    else
        b[pb++] = -w;
    for (int i = edge[v].size() - 1, k; i >= 0; --i)
        if (!vis[k = edge[v][i].v])
            dfs(k, -d, w + d * edge[v][i].w);
}

struct CNT {
    long long s, a, p;
    bool operator<(const CNT c) const { return s > c.s; };
} cmp;

std::priority_queue<CNT> pq;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif

    scanf("%lld%lld", &n, &k);
    for (int i = 1, u, v, w; i < n; ++i)
        scanf("%d%d%d", &u, &v, &w), edge[u].push_back(Edge{v, w}), edge[v].push_back(Edge{u, w});

    dfs(1, 1, 0);

    std::sort(a, a + pa);
    std::sort(b, b + pb);

    // for (int i = 0; i < pa; ++i)
    //     printf("%lld ", a[i]);
    // printf("\n");
    // for (int i = 0; i < pb; ++i)
    //     printf("%lld ", b[i]);
    // printf("\n");

    for (int i = 0; i < pa; ++i)
        pq.push(CNT{a[i] + b[0], a[i], 0});

    for (int i = 1; !pq.empty() && i < k; ++i) {
        cmp = pq.top(), pq.pop();
        // printf("%lld\n", cmp.s);
        if (++cmp.p < pb)
            cmp.s = cmp.a + b[cmp.p], pq.push(cmp);
    }
    if (pq.empty())
        printf("Stupid Mike");
    else
        printf("%lld", pq.top().s);

    return 0;
}
