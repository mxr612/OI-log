/**
 * CF1418A
*/

#include <math.h>
#include <stdio.h>

#include <iostream>

int t;
long double x, y, k;
long long a;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    scanf("%d", &t);

    while (t--) {
        std::cin >> x >> y >> k;
        a = ceil((k - 1 + y * k) / (x - 1)) + k;
        printf("%lld\n", a);
    }

    return 0;
}