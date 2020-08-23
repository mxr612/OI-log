/**
 * 
*/

#define MXN (1000020)

#include <stdio.h>

#include <algorithm>

int n, a[MXN], mxa;
long long sum, res, ans;

int t[MXN];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]), sum += a[i], mxa = std::max(mxa, a[i]);

    if (n <= 1000 && mxa <= 2000) {  // Sub1
        ans = sum;
        for (int i = 2, j; i <= mxa; ++i) {
            for (res = j = 0; res < ans && j < n; ++j)
                res += (a[j] / i) + (a[j] % i);
            ans = std::min(ans, res);
        }
        printf("%lld", ans);
    } else {
        for (int i = 0; i < n; ++i)
            ++t[a[i]];
        for (int i = mxa; i >= 0; --i)
            t[i] += t[i + 1];
        ans = sum;
        for (int i = 2, j; i <= mxa; ++i) {
            for (res = sum, j = i; j <= mxa; j += i)
                res -= (i - 1) * t[j];
            ans = std::min(ans, res);
        }
        printf("%lld", ans);
    }

    return 0;
}