/**
 * 
*/

#include <math.h>
#include <stdio.h>

#include <algorithm>

long long a, b, c, d, ans, x = 1, y = 2;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    scanf("%lld%lld%lld", &a, &b, &c);

    if (abs(a - b) < c)
        d = std::max(a, b) + ((c - abs(a - b)) / y);
    else
        d = std::min(a, b) + c;

    for (long long i = 6000000; !ans && i > 0; --i)
        if (((x + i) * i) / y <= d)
            ans = i;

    printf("%lld", ans);

    return 0;
}