/**
 * wormhole
*/

#include <stdio.h>

#include <algorithm>

const int MXM = 1000024;

int l[MXM], r[MXM];

signed main() {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);

    int n, m;
    int ans = 0, res;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i)
        scanf("%d%d", l + i, r + i), ans = std::max(ans, r[i] - l[i]);

    for (int i = 1, j, k; i <= n; ++i)
        for (j = i; j <= n; ans = std::min(ans, res), ++j)
            for (res = k = 0; res < ans && k < m; ++k)
                res = std::max(res, std::min(r[k] - l[k], std::min(abs(l[k] - i), abs(l[k] - j)) + std::min(abs(r[k] - i), abs(r[k] - j))));

    printf("%d", ans);

    return 0;
}