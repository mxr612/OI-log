/**
 * SSLOJ2020.09.12A
 * A 背包签到题
 * 数学
*/

#define MXA (120)
#define XJQ (998244353)

#include <stdio.h>

#include <algorithm>
#include <map>

int n;
long long K;
long long f[MXA], ans = 1;

long long ksm(long long x, long long y) {
    x %= XJQ, y %= XJQ - 1;
    long long res = 1;
    while (y) {
        if (y & 1) res = (res * x) % XJQ;
        y >>= 1, x = (x * x) % XJQ;
    }
    return res;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    scanf("%d%lld", &n, &K), K %= XJQ;

    f[0] = 1;
    for (int i = 1; i < MXA; ++i)
        f[i] = (((f[i - 1] * (K + i)) % XJQ) * ksm(i, XJQ - 2)) % XJQ;

    for (int i = 0, j, a; i < n; ++i)
        scanf("%d", &a), ans = (ans * f[a]) % XJQ;

    printf("%lld", ans);

    return 0;
}