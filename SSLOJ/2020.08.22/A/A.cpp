/**
 * 
*/

#define MXN (1000020)

#include <stdio.h>

#include <algorithm>

int n, a[MXN], mxa;
long long res, ans;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]), mxa = std::max(mxa, a[i]);

    if (n <= 1000 && mxa <= 2000) {  // Sub1
        for (int i = 0; i < n; ++i)
            ans += a[i];
        for (int i = 2, j; i <= mxa; ++i) {
            for (res = j = 0; res < ans && j < n; ++j)
                res += (a[j] / i) + (a[j] % i);
            ans = std::min(ans, res);
        }
        printf("%lld", ans);
    }

    return 0;
}