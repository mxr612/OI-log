/**
 * NowCoder 5713B
 * a^b<b^a <=> log(a)/a<log(b)/b
 */

#include <math.h>
#include <stdio.h>

double x, y, xx, yy;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("E.in", "r", stdin);
#endif

    scanf("%lf%lf", &x, &y);
    xx = log(x) / x, yy = log(y) / y;
    if (xx == yy)
        putchar('=');
    else if (xx < yy)
        putchar('<');
    else
        putchar('>');

    return 0;
}