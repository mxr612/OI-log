/**
 * @file A.cpp
 * @author mxr612 (mxr612@icloud.com)
 * @date 2021-07-10
 */

#include <math.h>
#include <stdio.h>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    int t, xa, ya, xb, yb, xc, yc;

    scanf("%d", &t);

    while (t--) {
        scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
        if (xa == xb && xb == xc && (ya - yc) * (yb - yc) < 0 || ya == yb && yb == yc && (xa - xc) * (xb - xc) < 0)
            printf("%d\n", abs(xa - xb) + abs(ya - yb) + 2);
        else
            printf("%d\n", abs(xa - xb) + abs(ya - yb));
    }

    return 0;
}