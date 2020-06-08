/**
 * luogu P2365
*/

#include <stdio.h>
#include <string.h>

#include <algorithm>

#define MXN (5020)

int T[MXN] = {0}, C[MXN] = {0}, DP[MXN];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P2365.in", "r", stdin);
#endif

    int n, s;

    scanf("%d%d", &n, &s);

    for (int i = 1, t, c; i <= n; ++i)
        scanf("%d%d", &t, &c), T[i] = T[i - 1] + t, C[i] = C[i - 1] + c;

    memset(DP, 0x7f, sizeof(DP)), DP[0] = 0;

    for (int i = 1, j; i <= n; ++i)
        for (j = 0; j < i; ++j)
            DP[i] = std::min(DP[i], DP[j] + T[i] * (C[i] - C[j]) + s * (C[n] - C[j]));

    printf("%d", DP[n]);

    return 0;
}