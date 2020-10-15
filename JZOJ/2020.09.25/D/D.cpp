/**
 * JZOJ2020.09.25
 * D无题noname
 * JZOJ1460
*/

#include <math.h>
#include <stdio.h>

long long N, ans = 0;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif

    scanf("%lld", &N);

    if (N <= 20000) {
        for (long long i = 1; i <= N; ++i)
            if (((i * i) % N) == 1)
                printf("%lld\n", i);
    } else {
        long long d;
    }

    return 0;
}
