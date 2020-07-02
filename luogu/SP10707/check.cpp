/**
 * 暴力LCA
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <vector>

#define MXN (40020)
#define MXM (100000)

int N, M;

struct LSH {
    int d, u;
    bool operator<(LSH x) { return u < x.u; }
} lsh[MXN];

int val[MXN];
std::vector<int> edge[MXN];

bool vis[MXN] = {false};
int dep[MXN], fa[MXN];
void DFS(int x) {
    vis[x] = true;
    dep[x] = dep[fa[x]] + 1;
    for (int i = 0; i < edge[x].size(); ++i)
        if (!vis[edge[x][i]])
            fa[edge[x][i]] = x, DFS(edge[x][i]);
    vis[x] = false;
}

int apr[MXN];

int ans[MXM];

signed main() {
    freopen("check.in", "r", stdin);

    scanf("%d%d", &N, &M);

    for (int i = 1; i <= N; ++i)
        lsh[i].d = i, scanf("%d", &lsh[i].u);
    std::sort(&lsh[1], &lsh[1 + N]);
    for (int i = 1, p = 0; i <= N; ++i)
        val[lsh[i].d] = (lsh[i].u == lsh[i - 1].u) ? (p) : (++p);

    for (int i = 1, x, y; i < N; ++i)
        scanf("%d%d", &x, &y), edge[x].push_back(y), edge[y].push_back(x);

    DFS(1);

    for (int i = 1, x, y; i <= M; ++i) {
        memset(apr, 0, sizeof(apr));
        scanf("%d%d", &x, &y);
        for (; dep[x] < dep[y]; y = fa[y])
            if (apr[val[y]]++ == 0)
                ++ans[i];
        for (; dep[x] > dep[y]; x = fa[x])
            if (apr[val[x]]++ == 0)
                ++ans[i];
        for (; x != y; x = fa[x], y = fa[y]) {
            if (apr[val[x]]++ == 0)
                ++ans[i];
            if (apr[val[y]]++ == 0)
                ++ans[i];
        }
        if (apr[val[x]]++ == 0)
            ++ans[i];
    }

    freopen("check.out", "r", stdin);
    for (int i = 1, ck; i <= M; ++i) {
        scanf("%d", &ck);
        if (ck != ans[i])
            printf("query: %-10d read: %-10d expected: %-10d\n", i, ck, ans[i]);
    }

    return 0;
}