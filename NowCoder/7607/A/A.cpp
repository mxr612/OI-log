/**
 * NowCoder7607
 * A
 * 線性篩
*/

#include <stdio.h>
#include <stdlib.h>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    int a, b, *prm, tot = 0;
    long long ans = 0;
    bool *is;

    scanf("%d%d", &a, &b);

    is = (bool *)calloc(sizeof(bool), b + 32);
    prm = (int *)calloc(sizeof(int), b + 32);

    for (int i = 2, j; i <= b; ++i) {
        if (!is[i]) prm[tot++] = i;
        for (j = 0; j < tot && i * prm[j] <= b; ++j)
            is[i * prm[j]] = true;
    }

    ans = b - a + 1;
    for (long long i = 0, j; i < tot; ++i)
        for (j = prm[i]; j <= b; j *= prm[i])
            if (a <= j)
                ans += prm[i] - 1;

    printf("%lld", ans);

    return 0;
}