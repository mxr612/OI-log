/**
 * P5656
*/

#include <math.h>
#include <stdio.h>

long long T, a, b, c;
long long d, x, y, dx, dy, ans[10];

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b) {
        long long d = exgcd(b, a % b, y, x);
        y -= a / b;
        return d;
    } else
        return x = 1, y = 0, a;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P5656.in", "r", stdin);
#endif

    for (scanf("%lld", &T); T--;) {
        scanf("%lld%lld%lld", &a, &b, &c);
        d = exgcd(a, b, x, y);
        if (c % d)
            printf("-1\n");
        else {
            x *= c / d, y *= c / d;
            dx = b / d, dy / a / d;
            ans[0] = floor((y - 1.0) / dy - 1) - ceil((-x + 1.0) / dx) + 1;
            if (ans[0] <= 0) {
                printf("%lld %lld\n", x + ceil((-x + 1.0) / dx) * dx, y - floor((y - 1.0) / dy - 1) * dy);
            } else {
                printf("%lld ", ans[0]);
            }
            printf("-\n");
        }
    }

    return 0;
}