/**
 * luoguP1941
 * 飞扬的小鸟
 */

#include <stdio.h>
#include <string.h>

#define MXN (10020)
#define MXM (1020)
#define MXA (10000020)

int n, m, K;
int xx[MXN], yy[MXN];
bool is_pipe[MXN] = {false};
int ll[MXN], hh[MXN];
int DP[MXN][MXM], ans;
int vis[MXN] = {0};

inline int min(int a, int b) {
    return a < b ? a : b;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1941.in", "r", stdin);
    freopen("P1941.out", "w", stdout);
#endif

    memset(DP, 0x6f, sizeof(DP));
    ans = DP[0][0];

    scanf("%d%d%d", &n, &m, &K);

    for (int i = 0; i < n; ++i)
        scanf("%d%d", &xx[i], &yy[i]);
    for (int i = 0; i <= n; ++i)
        ll[i] = 0, hh[i] = m + 1;
    for (int i = 1, p; i <= K; ++i)
        scanf("%d", &p), is_pipe[p] = true, scanf("%d%d", &ll[p], &hh[p]);
    for (int i = 1; i <= m; ++i)
        DP[0][i] = 0;

    for (int i = 0, j, k, l; i < n; ++i) {
        for (j = ll[i] + 1; j < hh[i]; ++j) {
            if (is_pipe[i] && DP[i][j] != ans)
                vis[i] = 1;
            if (j - yy[i] > 0)
                DP[i + 1][j - yy[i]] = min(DP[i + 1][j - yy[i]], DP[i][j]);
            for (k = j + xx[i], l = 1; k <= m; k += xx[i], ++l) {
                DP[i + 1][k] = min(DP[i + 1][k], DP[i][j] + l);
            }
            DP[i + 1][m] = min(DP[i + 1][m], DP[i][j] + l);
        }
    }

    // for (int j = 1, i; j <= m; ++j, putchar('\n'))
    //     for (i = 0; i <= n; ++i)
    //         printf("%15d", DP[i][j]);

    if (is_pipe[n]) {
        for (int i = m; i > 0; --i) {
            if (DP[n][1] > 0)
                vis[n] = 1;
            ans = min(ans, DP[n][i]);
        }
    } else {
        for (int i = 1; i <= m; ++i) {
            ans = min(ans, DP[n][i]);
        }
    }

    for (int i = 1; i <= n; ++i)
        vis[i] += vis[i - 1];

    if (vis[n] == K)
        printf("1\n%d\n", ans);
    else
        printf("0\n%d\n", vis[n]);

    return 0;
}