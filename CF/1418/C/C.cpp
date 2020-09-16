/**
 * CF1418C
*/

#define MXN (200050)

#include <stdio.h>
#include <string.h>

#include <algorithm>

int t;
int n, a[MXN], f[MXN][2];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif

    scanf("%d", &t);

    f[0][1] = f[1][1] = MXN;
    while (t--) {
        scanf("%d", &n);
        for (int i = 2; i < n + 2; ++i) {
            scanf("%d", &a[i]), a[i] += a[i - 1];
            f[i][0] = std::min(f[i - 1][1], f[i - 2][1]);
            f[i][1] = std::min(f[i - 1][0] + a[i] - a[i - 1], f[i - 2][0] + a[i] - a[i - 2]);
            // printf("%d %d\n", f[i][0], f[i][1]);
        }
        printf("%d\n", std::min(f[n + 1][0], f[n + 1][1]));
    }

    return 0;
}