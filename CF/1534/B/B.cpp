/**
 * @file B.cpp
 * @author mxr612 (mxr612@icloud.com)
 * @date 2021-07-03
 */

#include <stdio.h>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    int t, n, a, b, k;
    long long c;

    scanf("%d", &t);

    while (t--) {
        scanf("%d%d%d", &n, &a, &b);
        if (a == 1)
            n = (n - 1) % b;
        else
            for (c = 1; c <= n; c *= a)
                if ((k = (n - c) % b) == 0)
                    n = k, c = 1;
        printf("%s\n", n ? "No" : "Yes");
    }

    return 0;
}