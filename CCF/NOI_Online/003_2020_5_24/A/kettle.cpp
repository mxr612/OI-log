/**
 * GD-00147
 * u3vEf45E
 * A kettle
 */

#include <stdio.h>

#include <algorithm>

#define MXN (1000000)

int n, k, arr[MXN] = {0}, ans = 0;

signed main() {
    freopen("kettle.in", "r", stdin);
    freopen("kettle.out", "w", stdout);

    scanf("%d%d", &n, &k), ++k;

    for (int i = 1; i < k; ++i)
        scanf("%d", &arr[i]), arr[i] += arr[i - 1];
    for (int i = k; i <= n; ++i)
        scanf("%d", &arr[i]),
            ans = std::max(ans, (arr[i] += arr[i - 1]) - arr[i - k]);

    printf("%d\n", ans);

    return 0;
}