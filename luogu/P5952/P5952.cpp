/**
 * luoguP5952
 * [POI2018]水箱
 * 在这种记点方式下注意数组大小
 * 写丑了一点吸氧过的
*/

#define MXNM (5000020)
#define XJQ (1000000007)

#include <stdio.h>

#include <queue>

int n, m, H;

int node(int i, int j) { return i * m + j; }

struct Edge {
    int u, v, w;
    bool operator<(const Edge E) const { return w > E.w; }
};

long long f[MXNM], g[MXNM];

std::priority_queue<Edge> edge;

int fa[MXNM];

int find(int x) { return (fa[x] == x) ? (x) : (fa[x] = find(fa[x])); }
void merge(int x, int y, long long h) { x = find(x), y = find(y), f[x] = ((f[x] + h - g[x]) * (f[y] + h - g[y])) % XJQ, g[x] = h, fa[y] = x; }

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P5952.in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &H);

    for (int i = 1, j, w; i <= n; ++i)
        for (j = 1; j < m; ++j)
            scanf("%d", &w), edge.push(Edge{node(i, j), node(i, j + 1), w});
    for (int i = 1, j, w; i < n; ++i)
        for (j = 1; j <= m; ++j)
            scanf("%d", &w), edge.push(Edge{node(i, j), node(i + 1, j), w});
    for (int i = 1, j; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            fa[node(i, j)] = node(i, j), f[node(i, j)] = 1;

    for (int i = n * m; i > 1; --i) {
        while ((!edge.empty()) && (find(edge.top().u) == find(edge.top().v))) edge.pop();
        if (!edge.empty()) merge(edge.top().u, edge.top().v, edge.top().w);
    }

    printf("%lld", (f[find(node(1, 1))] + H - g[find(node(1, 1))]) % XJQ);

    return 0;
}