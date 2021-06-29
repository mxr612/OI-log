/**
 * @file A.cpp
 * @author mxr612 (mxr612@icloud.com)
 * @date 2021-06-29
 */

#include <stdio.h>

#include <algorithm>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    int t, n, k, l, r, ans;

    scanf("%d", &t);

    while (t--) {
        scanf("%d%d", &n, &k);
        ans = 0;
        while (n--)
            if (scanf("%d%d", &l, &r), l <= k)
                ans = std::max(ans, r - k + 1);
        printf("%d\n", ans);
    }

    return 0;
}