/**
 * 2020.08.24A B
 * T145305 【2020.8.24NOIP模拟赛】选数排列
*/

#define MXN (500020)

#include <stdio.h>
#include <string.h>

#include <algorithm>

int N, R, C;
int P[MXN];

// Sub1
int a[MXN], f[1024][1024], min, ans = 1e9;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    scanf("%d%d%d", &N, &R, &C);
    for (int i = 0; i < N; ++i)
        scanf("%d", &P[i]);

    std::sort(P, P + N);

    for (int i = C - 1; i < N; ++i)
        a[i] = P[i] - P[i - C + 1];

    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i <= N; ++i)
        f[0][i] = 0;
    for (int i = 1, j; i <= R; ++i)
        for (min = 1e9, j = C - 1; j < N; ++j)
            f[i][j] = std::max(min = std::min(min, f[i - 1][j - C]), a[j]);
    for (int i = 0; i < N; ++i)
        ans = std::min(ans, f[R][i]);

    printf("%d", ans);

    return 0;
}