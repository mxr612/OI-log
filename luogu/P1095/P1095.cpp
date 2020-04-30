/**
 * luogu P1095
 * DP
 */

#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>

#define MXT (300020)

int M, S, T;
int DP[MXT][20] = {0};

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1095.in", "r", stdin);
#endif

    memset(DP, 128, sizeof(DP));

    scanf("%d%d%d", &M, &S, &T);

    register int i = 1, j, ans = 0;

    for (DP[0][j = M % 10] = 0; M >= 10 && i <= T; ++i, M -= 10)
        if ((ans = DP[i][j] = DP[i - 1][j] + 60) >= S) {
            printf("Yes\n%d\n", i);
            return 0;
        }

    for (--i; i <= T; ++i) {
        for (j = 0; j < 15; ++j) {
            if (DP[i][j] >= S) {
                printf("Yes\n%d\n", i);
                return 0;
            }
            ans = std::max(ans, DP[i][j]);
            DP[i + 1][j] = std::max(DP[i + 1][j], DP[i][j] + 17);
            if (j < 10)
                DP[i + 1][j + 4] = std::max(DP[i + 1][j + 4], DP[i][j]);
            else
                DP[i + 1][j - 10] = std::max(DP[i + 1][j - 10], DP[i][j] + 60);
        }
    }

    printf("No\n%d\n", ans);

    return 0;
}