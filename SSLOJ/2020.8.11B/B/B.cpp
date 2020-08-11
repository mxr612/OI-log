#include <stdio.h>

#include <queue>
#include <vector>

#define MXN (400)

int n, ans;
struct Edge {
    int u, v, w;
    bool operator<(const Edge e) const { return w > e.w; }
} top;

std::priority_queue<Edge> edge;

bool vis[MXN];

signed main() {
    freopen("B.in", "r", stdin);

    scanf("%d", &n);
    for (int i = 1, w; i <= n; ++i)
        scanf("%d", &w), edge.push({0, i, w}), edge.push({i, 0, w});
    for (int i = 1, j, w; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            scanf("%d", &w), edge.push({i, j, w});

    for (int i = 0; i < n; ++i) {
        while((vis[edge.top().u] && vis[edge.top().v]) || (edge.top().u == edge.top().v)) edge.pop();
        vis[edge.top().u] = vis[edge.top().v] = true, ans += edge.top().w;
    }

    printf("%d", ans);

    return 0;
}
