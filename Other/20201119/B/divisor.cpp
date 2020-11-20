/**
 * divisor
 * 60%
*/

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

bool *ntp;
int tot;
int *prm, *mip;

int d(int n) {
    int p, res = 1;
    short cnt;
    while (n > 1) {
        p = mip[n], cnt = 0;
        while (n > 1 && p == mip[n])
            ++cnt, n /= mip[n];
        res *= cnt + 1;
    }
    return res;
}

signed main() {
    freopen("divisor.in", "r", stdin);
    freopen("divisor.out", "w", stdout);

    int n;

    scanf("%d", &n);

    ntp = (bool *)calloc(sizeof(bool), n + 32);
    prm = (int *)calloc(sizeof(int), n / 10 + 500);
    mip = (int *)calloc(sizeof(int), n + 32);

    long long k;
    for (int i = 2, j; i <= n; ++i) {
        if (!ntp[i]) prm[tot++] = i, mip[i] = i;
        for (j = 0; j < tot && (k = 1ll * i * prm[j]) <= n; ++j)
            ntp[k] = true, mip[k] = std::min(mip[i], prm[j]);
    }

    long long ans = 0;

    for (int i = 1, j; i <= n; ++i)
        ans += d(i) * (n / i);

    printf("%lld", ans);

    return 0;
}