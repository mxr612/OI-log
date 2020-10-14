/**
 * JZOJ2020.09.26_A
 * 4223旅游
 * 贪心, 堆
*/

#define MXQ (5012)
#define MXN (20056)

#include <stdio.h>
#include <stdlib.h>

#include <queue>

struct Edge {
    int x, y, w;
    bool operator<(const Edge e) const { return w > e.w; }
} ee;
struct Query {
    int r, x;
    bool operator<(const Query q) const { return x > q.x; }
} qq;

class Bin {
    int fa[MXN], size[MXN];

   public:
    void build(int n) {
        for (int i = 1; i <= n; ++i)
            fa[i] = i, size[i] = 1;
    }
    int find(int x) { return (fa[x] == x) ? (x) : (fa[x] = find(fa[x])); }
    int get_size(int x) { return size[find(x)]; }
    void merge(int x, int y) {
        if ((x = find(x)) == (y = find(y))) return;
        if (size[x] < size[y]) x ^= y ^= x ^= y;
        size[x] += size[y], fa[y] = x;
    }
} bin;

int ans[MXQ];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    int t, n, m, q;
    scanf("%d", &t);

    std::priority_queue<Edge> edge;
    std::priority_queue<Query> query;
    int res;

    while (t--) {
        scanf("%d%d%d", &n, &m, &q);
        edge.empty(), query.empty(), bin.build(n), res = 0;
        for (int i = 0; i < m; ++i)
            scanf("%d%d%d", &ee.x, &ee.y, &ee.w), edge.push(ee);
        for (qq.r = 0; qq.r < q; ++qq.r)
            scanf("%d", &qq.x), query.push(qq);
        while (query.size() && edge.size()) {
            while (query.size() && query.top().x < edge.top().w)
                ans[query.top().r] = res, query.pop();
            if (bin.find(edge.top().x) != bin.find(edge.top().y))
                res += bin.get_size(edge.top().x) * bin.get_size(edge.top().y) * 2,
                    bin.merge(edge.top().x, edge.top().y);
            edge.pop();
        }
        while (query.size()) ans[query.top().r] = res, query.pop();
        for (int i = 0; i < q; ++i)
            printf("%d\n", ans[i]);
    }

    return 0;
}