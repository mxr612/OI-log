/**
 * diameter
*/
#include <stdio.h>

const int MXN = 200056;

int arr[MXN];

signed main() {
    freopen("diameter.in", "r", stdin);
    freopen("diameter.out", "w", stdout);

    int n, k, tot;

    scanf("%d %d", &n, &k), tot = n;

    for (int i = 0; i < k; ++i)
        printf("%d %d\n", n, arr[i] = --tot);

    for (int i = 0; --tot; ++i)
        printf("%d %d\n", arr[i % k], tot), arr[i % k] = tot;

    return 0;
}