/**
 * luogu36399校测
 * B超级蚯蚓
 * 概率题, 设f_i为剩下i条蚯蚓的不成环概率
 * 递推就好
*/

#include <stdio.h>

signed main() {
    freopen("B.in", "r", stdin);

    int n;
    double ans = 1;

    scanf("%d", &n);

    for (double i = 2; i <= n; ++i)
        ans *= (i * 2 - 2) / (i * 2 - 1);

    printf("%lf", ans);

    return 0;
}
