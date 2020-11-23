/**
 * k
*/

#include <stdio.h>

#include <algorithm>

const int MXN = 100;

int edge[MXN][MXN];

signed main() {
    freopen("k.in", "r", stdin);
    freopen("k.out", "w", stdout);

    int R, n, s, t;

    scanf("%d", &R);

    while (R--) {
        scanf("%d%d%d", &n, &s, &t);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &edge[i][j]);
        if (n == 2) {
            if (s & 1) {
                long long res = 0, ans = -1;
                for (int i = s; i <= t; i += s)
                    ans = std::max(ans, res += (edge[1][2] + edge[2][1]) * s / 2);
                printf("%lld\n", ans);
            } else {
                printf("IMPOSSIBLE\n");
            }
        }
    }

    return 0;
}