/**
 * 2020.08.29
 * https://www.oitiku.com/simulate-contest/1/2
 * B interval
*/

#define MXN (1000020)

#include <math.h>
#include <stdio.h>

#include <algorithm>

int n, x, ans;

int a[MXN];

int min[MXN][25], max[MXN][25];

signed main() {
    freopen("interval.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("interval.out", "w", stdout);
#endif

    scanf("%d%d", &n, &x);

    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]), min[i][0] = max[i][0] = a[i];

    for (int i = 1, ii = 1, j; i <= log2(n); ++i, ii <<= 1)
        for (j = 0; j + ii * 2 - 1 < n; ++j)
            min[j][i] = std::min(min[j][i - 1], min[j + ii][i - 1]), max[j][i] = std::max(max[j][i - 1], max[j + ii][i - 1]);
    for (int i = 0, j, k; i < n; ++i)
        for (j = i; j < n; ++j)
            k = log2(j - i + 1), ans += (std::max(max[i][k], max[j - (1 << k) + 1][k]) + std::min(min[i][k], min[j - (1 << k) + 1][k]) == x);

    printf("%d", ans);

    return 0;
}