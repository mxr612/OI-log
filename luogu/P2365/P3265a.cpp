/**
 * luogu P2365
 * 斜率优化
 * 为什么(y1-y2)/(x1-x2)!=(y2-y1)/(x2-x1)
 * 答：在不等式中乘负号要改向，保持乘过去的值为正
*/

#include <stdio.h>
#include <string.h>

#define MXN (5000)

int T[MXN] = {0}, C[MXN] = {0}, F[MXN];
int Q[MXN] = {0}, l = 0, r = 0;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P2365.in", "r", stdin);
#endif

    int N, S;

    scanf("%d%d", &N, &S);

    for (int i = 1, t, c; i <= N; ++i)
        scanf("%d%d", &t, &c), T[i] = T[i - 1] + t, C[i] = C[i - 1] + c;

    for (int i = 1; i <= N; ++i) {
        // while (l < r && F[Q[l]] - F[Q[l + 1]] <= (S + T[i]) * (C[Q[l]] - C[Q[l + 1]]))
        //     ++l;
        while (l < r && F[Q[l + 1]] - F[Q[l]] <= (S + T[i]) * (C[Q[l + 1]] - C[Q[l]]))
            ++l;
        F[i] = F[Q[l]] - (S + T[i]) * C[Q[l]] + S * C[N] + T[i] * C[i];
        while (l < r && (F[i] - F[Q[r]]) * (C[i] - C[Q[r - 1]]) <= (F[i] - F[Q[r - 1]]) * (C[i] - C[Q[r]]))
            --r;
        Q[++r] = i;
    }
    printf("%d\n", F[N]);

    return 0;
}