/**
 * A 温暖题
*/

#define MXN (200020)

#include <math.h>
#include <stdio.h>

#include <algorithm>

int n;

struct Node {
    long long x, y;
    bool operator<(const Node N) const { return (std::max(x, y) == std::max(N.x, N.y)) ? ((x == N.x) ? (y > N.y) : (x < N.x)) : (std::max(x, y) < std::max(N.x, N.y)); }
} node[MXN], last[2];

long long way(Node a, Node b) { return abs(a.x - b.x) + abs(a.y - b.y); }

long long f[MXN][2], p = 0;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0, x, y; i < n; ++i)
        scanf("%lld%lld", &node[i].x, &node[i].y);

    std::sort(node, node + n);

    for (int i = 0, j = 0; i <= n; ++i) {
        if (std::max(node[i].x, node[i].y) != std::max(node[i - 1].x, node[i - 1].y)) {
            ++p;
            f[p][0] = way(node[i - 1], node[j]) + std::min(f[p - 1][0] + way(last[0], node[i - 1]), f[p - 1][1] + way(last[1], node[i - 1]));
            f[p][1] = way(node[i - 1], node[j]) + std::min(f[p - 1][0] + way(last[0], node[j]), f[p - 1][1] + way(last[1], node[j]));
            last[0] = node[j], last[1] = node[i - 1];
            j = i;
        }
    }

    printf("%lld", std::min(f[p][0], f[p][1]));

    return 0;
}