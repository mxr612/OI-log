/**
 * ybtoj2020.09.05B
 * A简单游走travel
*/

#define MXN (520)

#include <stdio.h>
#include <string.h>

#include <queue>
#include <vector>

int n, m;

std::vector<std::pair<int, int> > edge[MXN];
bool map[MXN][MXN];
int next(int v, int w) {
    while (map[v][w]) ++w;
    return w;
}

struct Sta {
    int v, w;
    bool operator<(const Sta S) const { return w > S.w; };
};
std::priority_queue<Sta> que;

int f[MXN];

signed main() {
    freopen("travel.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("travel.out", "w", stdout);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0, u, v, w; i < m; ++i)
        scanf("%d%d%d", &u, &v, &w), edge[u].push_back({v, w}), edge[v].push_back({u, w});

    for (int i = 1, j, t; i <= n; ++i)
        for (scanf("%d", &j); j > 0; --j)
            scanf("%d", &t), map[i][t] = true;

    memset(f, 127, sizeof(f));
    que.push({1, 0});

    int x, y;
    while (!que.empty()) {
        f[x = que.top().v] = que.top().w;
        y = next(x, f[x]);
        for (auto i : edge[x])
            que.push({i.first, y + i.second});
        while (!que.empty() && f[que.top().v] <= que.top().w) que.pop();
    }

    printf("%d", f[n]);

    return 0;
}
u