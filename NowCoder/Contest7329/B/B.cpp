/**
 * NowCoder7329B
*/

#define MXN (100000)

#include <stdio.h>

#include <algorithm>

int n, x, y;
long long arr[MXN], ans;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    std::sort(arr, arr + n);

    for (int i = n - 1; i >= 0; --i)
        arr[i] += arr[i + 1];

    scanf("%d%d", &x, &y);

    for (int i = 1, j; i <= x; ++i)
        for (j = 1; j <= y && i * j <= n; ++j)
            ans += arr[n - i * j];

    printf("%lld", ans);

    return 0;
}