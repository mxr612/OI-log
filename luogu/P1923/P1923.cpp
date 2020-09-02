/**
 * luogu P1923
 * 【深基9.例4】求第 k 小的数
*/

#define MXN (5000020)

#include <stdio.h>

#include <algorithm>

int n, k, arr[MXN];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1923.in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    std::nth_element(arr, arr + k, arr + n);

    printf("%d", arr[k]);

    return 0;
}