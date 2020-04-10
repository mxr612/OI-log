/**
 * A
 */

#include <stdio.h>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    int T, n, p, c;

    scanf("%d", &T);

    register bool flag = true;
    for (register int t = 0, i, pp, cc; t < T; ++t) {
        flag = true, i = pp = cc = 0;
        scanf("%d", &n);
        while (++i <= n) {
            scanf("%d%d", &p, &c);
            if (p < c || p < pp || c < cc || p - pp < c - cc)
                flag = false;
            pp = p, cc = c;
        }
        printf("%s\n", (flag) ? ("YES") : ("NO"));
    }

    return 0;
}