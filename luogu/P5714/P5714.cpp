/**
 * luogu P5714
 * 水题
 */

#include <stdio.h>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P5714.in", "r", stdin);
#endif

    double m, h;
    scanf("%lf%lf", &m, &h);
    m /= h * h;
    if (m < 18.5)
        printf("Underweight");
    else if (m >= 24)
        printf("%g\nOverweight", m);
    else
        printf("Normal\n");

    return 0;
}