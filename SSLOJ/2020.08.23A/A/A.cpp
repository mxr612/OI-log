/**
 * 2020.08.23A
 * A 【2020.8.23NOIP模拟赛】失落
*/

#define MXN (1000000)

#include <stdio.h>

#include <algorithm>

long long n, a[MXN], ans = 1;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    scanf("%lld", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &a[i]);

    std::sort(a, a + n);

    for (int i = 0; i < n && ans >= a[i]; ++i)
        ans += a[i];

    printf("%lld", ans);

    return 0;
}