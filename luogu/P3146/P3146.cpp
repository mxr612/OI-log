/**
 * luogu P3146
 * [USACO16OPEN]
 * 248 G
 */

#include <stdio.h>

#include <algorithm>

#define MXN (300)

int N;
int DP[MXN][MXN] = {0}, ans = 0;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P3146.in", "r", stdin);
#endif

    scanf("%d", &N);

    for (int i = 1; i <= N; ++i)
        scanf("%d", &DP[i][i]);

    for (register int i = 1, j, k; i < N; ++i)
        for (j = N - i; j > 0; --j)
            for (k = j + i; k > j; --k)
                if (DP[j][k - 1] > 0 && DP[j][k - 1] == DP[k][j + i])
                    ans = std::max(ans, DP[j][j + i] = std::max(
                                            DP[j][j + i], DP[j][k - 1] + 1));

    printf("%d\n", ans);

    return 0;
}