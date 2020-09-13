/**
 * NowCoder 7329A
*/

#include <stdio.h>

int n, t;
double c;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    scanf("%d", &n);
    while (n-- > 0) {
        scanf("%d", &t);
        c = 5.5 * t;
        while (c > 180) c -= 360;
        if (c < 0) c *= -1;
        t = c + 0.5;
        printf("%d\n", t);
    }

    return 0;
}