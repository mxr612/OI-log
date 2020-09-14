/**
 * B 礼物
 * 搜索
 * ?线段树优化连边
*/

#include <stdio.h>

#include <algorithm>
#include <map>
#include <vector>

int n, d;

struct Edge {
    int u, v;
    bool operator<(const Edge E) const { return u < E.u; }
};
std::vector<Edge> a[2];
std::map<int, int> pa, pb;

int bound(int arr[], int v) {
    int l = 0, r = n - 1, m;
    while (l < r)
        if ((m = (l + r) / 2) <= v)
            l = m;
        else
            r = m - 1;
    return l;
}

std::A

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    scanf("%d%d", &n, &d);

    for (int i = 0, u, v; i < n; ++i)
        scanf("%d%d", &v, &u), a[1].push_back(Edge{u, v});
    for (int i = 0, u, v; i < n; ++i)
        scanf("%d%d", &v, &u), a[0].push_back(Edge{u, v});

    std::sort(&a[0][0], &a[0][n]), std::sort(&a[1][0], &a[1][n]);

    

    return 0;
}