/**
 * luogu P3842
 * [TJOI2007]线段
 * 普及/提高-
 * DP
 */

#include <math.h>
#include <stdio.h>

#include <algorithm>

#define MXN (20020)

int n, l[MXN], r[MXN], al[MXN], ar[MXN];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P3842.in", "r", stdin);
#endif

    scanf("%d", &n);

    l[0] = r[0] = 1;
    al[0] = ar[0] = -1;

    for (int i = 1, j; i <= n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
        al[i] = std::min(al[i - 1] + 1 + abs(r[i] - l[i - 1]),
                         ar[i - 1] + 1 + abs(r[i] - r[i - 1])) +
                r[i] - l[i];
        ar[i] = std::min(al[i - 1] + 1 + abs(l[i] - l[i - 1]),
                         ar[i - 1] + 1 + abs(l[i] - r[i - 1])) +
                r[i] - l[i];
    }

    printf("%d", std::min(al[n] + n - l[n], ar[n] + n - r[n]));

    return 0;
}