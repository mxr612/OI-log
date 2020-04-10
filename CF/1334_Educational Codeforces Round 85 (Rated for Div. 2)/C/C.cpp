/**
 * C
 */

#include <stdio.h>

#include <algorithm>

#define MXN (300020)

int T, n;
long long a[300020], b[300020], c[300020], s, ans;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif

    scanf("%d", &T);

    for (register int t = 0, i; t < T; ++t) {
        scanf("%d", &n);
        for (i = 1; i <= n; ++i)
            scanf("%lld%lld", &a[i], &b[i]);
        for (s = c[1] = std::max(0ll, a[1] - b[n]), i = 2; i <= n; ++i)
            s += c[i] = std::max(0ll, a[i] - b[i - 1]);
        for (ans = a[1] + s - c[1], i = 2; i <= n; ++i)
            ans = std::min(ans, a[i] + s - c[i]);
        printf("%lld\n", ans);
    }

    return 0;
}