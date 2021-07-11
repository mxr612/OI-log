/**
 * @file A.cpp
 * @author mxr612 (mxr612@icloud.com)
 * @date 2021-07-11
 */

#include <math.h>
#include <stdio.h>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    int t, n, s, m, l, r;
    int a[128];

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", a + i);
        s = m = 0;
        for (int i = 1, b; i <= n; ++i)
            scanf("%d", &b), a[i] -= b,
                s += a[i], m += abs(a[i]);
        if (s != 0)
            printf("-1\n");
        else {
            printf("%d\n", m /= 2);
            l = r = 1;
            while (m--) {
                while (a[l] <= 0) ++l;
                while (a[r] >= 0) ++r;
                --a[l], ++a[r];
                printf("%d %d\n", l, r);
            }
        }
    }

    return 0;
}