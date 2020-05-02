/**
 * luogu P1833
 * 混合背包
 */

#include <stdio.h>

#include <algorithm>

#define MXT (1020)
#define MXN (10020)

int sh, sm, eh, em, t, n;
int T, C, P;

int at[MXN], ac[MXN], a = 0;
int bt[MXN * 100], bc[MXN * 100], b = 0;
// a_完全背包 b_01背包

int DP[MXT], ans = 0;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1833.in", "r", stdin);
#endif
    scanf("%d:%d %d:%d %d", &sh, &sm, &eh, &em, &n);

    if ((t = (eh - sh) * 60 + (em - sm)) < 0)
        t += 1440;

    for (register int i = 0, j; i < n; ++i) {
        scanf("%d %d %d", &T, &C, &P);
        if (P > 0) {
            for (j = 1; j <= P; P -= j, j <<= 1)
                bt[b] = j * T, bc[b] = j * C, ++b;
            if (P > 0)
                bt[b] = P * T, bc[b] = P * C, ++b;
        } else
            at[a] = T, ac[a] = C, ++a;
    }

    for (register int i = 0, j; i < a; ++i)
        for (j = at[i]; j <= t; ++j)
            ans = std::max(ans, DP[j] = std::max(DP[j], DP[j - at[i]] + ac[i]));
    for (register int i = 0, j; i < b; ++i)
        for (j = t; j >= bt[i]; --j)
            ans = std::max(ans, DP[j] = std::max(DP[j], DP[j - bt[i]] + bc[i]));

    printf("%d\n", ans);

    return 0;
}