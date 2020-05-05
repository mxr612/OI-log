/**
 * luoguP1941
 * 飞扬的小鸟
 */

#include <stdio.h>
#include <string.h>

#include <algorithm>

#define MXN (10020)
#define MXM (1020)
#define MXA (10000020)

int n, m, k;
int xx[MXN], yy[MXN];
bool is_pipe[MXN] = {false};
int ll[MXN], hh[MXN];
int DP[MXN][MXM], ans = 0;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1941.in", "r", stdin);
    // freopen("P1941.out", "w", stdout);
#endif

    memset(DP, 0x6f, sizeof(DP));

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &xx[i], &yy[i]);
    for (int i = 1; i <= n; ++i)
        ll[i] = 0, hh[i] = m + 1;
    for (int i = 1, p; i <= k; ++i)
        scanf("%d", &p), is_pipe[p] = true, scanf("%d%d", &ll[p], &hh[p]);
    for (int i = 1; i <= m; ++i)
        DP[0][i] = 0;

    bool flag = false;
    for (int i = 1, j, k; i <= n; ++i, flag = false) {
        // printf("%5d%5d%5d%5d\n", ll[i], hh[i], xx[i], yy[i]);
        for (j = ll[i] + 1; j < hh[i]; ++j) {
            DP[i][j] = DP[i - 1][j + yy[i]];
            if (j == m)
                for (k = m; k > 0; --k)
                    DP[i][j] = std::min(DP[i][j], DP[i - 1][k] + 1);
            else
                for (k = j - xx[i]; k > 0; k -= xx[i])
                    DP[i][j] = std::min(DP[i][j], DP[i - 1][k] + 1);
            if (is_pipe[i] && DP[i][j] < MXA)
                flag = true;
        }
        if (flag)
            ++ans;
    }
    // for (int i, j = m; j > 0; --j, putchar('\n')) {
    //     for (int i = 0; i <= n; ++i) {
    //         printf("%15d", DP[i][j]);
    //     }
    // }

    if (ans == k) {
        ans = DP[1][m + 1];
        for (int i = 1; i <= m; ++i)
            ans = std::min(ans, DP[n][i]);
        printf("1\n%d\n", ans);
    } else
        printf("0\n%d", ans);

    return 0;
}