
#define MXN (100)
#define MXD (21)

#include <stdio.h>

#include <bitset>

int n, m, d, ans;

std::bitset<MXN> edge[2][MXN], DP[2][1 << MXD];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &d);

    for (int i = 0, u, v, w; i < m; ++i)
        scanf("%d%d%d", &u, &v, &w), edge[w][u][v] = 1, edge[w][v][u] = 1;

    DP[0][0][1] = 1;
    for (int i = 0, ii, j, k, l; i < d; ++i) {
        ii = i & 1;
        for (j = (1 << i) - 1; j >= 0; --j) {
            if (DP[ii][j].any()) {
                for (k = 1; k <= n; ++k) {
                    if (DP[ii][j][k]) {
                        DP[!ii][j] |= edge[0][k];
                        DP[!ii][j + (1 << i)] |= edge[1][k];
                    }
                }
            }
            DP[ii][j].reset();
        }
    }

    for (int i = 0; i < 1 << d; ++i)
        ans += DP[d & 1][i].any();
    printf("%d", ans);
    return 0;
}
