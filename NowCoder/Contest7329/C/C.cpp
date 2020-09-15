/**
 * NowCoder7329C
 * 最大生成树
*/

#define MXN (500020)

#include <stdio.h>

#include <queue>

int n, m;
long long ans;

struct Edge {
    int x, y, w;
    bool operator<(const Edge E) const { return w < E.w; }
};

std::priority_queue<Edge> edge;

class Bin {
    int fa[MXN];

   public:
    void pre(int n) {
        for (int i = 1; i <= n; ++i)
            fa[i] = i;
    }
    int find(int x) { return (fa[x] == x) ? (x) : (fa[x] = find(fa[x])); }
    void merge(int x, int y) {
        if ((x = find(x)) != (y = find(y))) fa[fa[x]] = fa[y];
    }

} bin;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    bin.pre(n);

    for (int i = 0, x, y, w; i < m; ++i)
        scanf("%d%d%d", &x, &y, &w), edge.push(Edge{x, y, w});

    for (int i = 1; i < n; ++i) {
        while (!edge.empty() && bin.find(edge.top().x) == bin.find(edge.top().y)) edge.pop();
        ans += edge.top().w, bin.merge(edge.top().x, edge.top().y);
    }

    printf("%lld", ans);

    return 0;
}