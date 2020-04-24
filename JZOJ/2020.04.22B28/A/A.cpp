/**
 * [USACO18OPEN]Talent Show G
 * luogu P4377
 * JZOJ 6592
 */

#include <stdio.h>
#include <string.h>

#include <algorithm>

#define MXN (300)
#define MXW (1020)

int N, W;
int w[MXN], t[MXN];

long long DP[MXW];
bool _check(long long Z) {
    memset(DP, 128, sizeof(DP));
    DP[0] = 0;
    for (int i = 0, j, k; i < N; ++i)
        for (j = W; j >= 0; --j)
            k = std::min(W, j + w[i]),
            DP[k] = std::max(DP[k], DP[j] + t[i] - Z * w[i]);
    return DP[W] >= 0;
}

int _binary_search() {
    int l = 0, m, r = 100000;
    while (l <= r)
        if (_check(m = (l + r) / 2))
            l = m + 1;
        else
            r = m - 1;
    return l - 1;
}

signed main() {
    freopen("show.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("show.out", "w", stdout);
#endif

    scanf("%d%d", &N, &W);
    for (int i = 0; i < N; ++i)
        scanf("%lld%lld", &w[i], &t[i]), t[i] *= 1000;
    printf("%d", _binary_search());

    return 0;
}