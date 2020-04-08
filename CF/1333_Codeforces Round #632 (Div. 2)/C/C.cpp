/**
 * C
 */

#include <stdio.h>

#include <map>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif

    int n, x;
    long long s = 0, ans = 0;
    std::map<long long, int> last;

    scanf("%d", &n);
    for (register int i = 1, las = 0; i <= n; ++i) {
        scanf("%d", &x), s += x;
        if (s == 0 || last[s] > 0)
            las = std::max(las, last[s] + 1);
        last[s] = i;
        ans += i - las;
    }

    printf("%lld\n", ans);

    return 0;
}