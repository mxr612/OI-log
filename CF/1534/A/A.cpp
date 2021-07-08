/**
 * @file A.cpp
 * @author mxr612 (mxr612@icloud.com)
 * @date 2021-07-03
 */

#include <stdio.h>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    int t, n, a, s;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n), n *= 2;
        s = 0;
        while (n--)
            scanf("%d", &a), s += a & 1 ? -1 : 1;
        printf("%s\n", s ? "No" : "Yes");
    }

    return 0;
}