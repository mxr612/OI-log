/**
 * luogu P1832
 * 素数筛 完全背包
 */

#include <stdio.h>

#include <algorithm>

#define MXN (1020)

bool IsPrime[MXN * MXN] = {false};
int Prime[MXN], p = 0;

int n;
long long DP[MXN] = {0};

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1832_2.in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 2, j; i <= n; ++i) {
        if (!IsPrime[i])
            Prime[p++] = i;
        for (j = 0; j < p; ++j)
            IsPrime[Prime[j] * i] = true;
    }

    DP[0] = 1;
    for (int i = 0, j; i < p; ++i)
        for (j = Prime[i]; j <= n; ++j)
            DP[j] += DP[j - Prime[i]];

    printf("%lld", DP[n]);

    return 0;
}