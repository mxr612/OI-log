/**
 * @file D.cpp
 * @author mxr612 (mxr612@icloud.com)
 * @date 2021-07-11
 */

#include <stdio.h>

const int MXN = 100010;
const long long WYC = 998244353;

char s[MXN];

long long jc[MXN], ny[MXN];
long long ksm(long long x, long long y) {
    long long res = 1;
    while (y) {
        if (y & 1)
            res = (res * x) % WYC;
        x = (x * x) % WYC;
        y >>= 1;
    }
    return res;
}

signed
main() {
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif

    jc[0] = ny[0] = jc[1] = 1;
    for (int i = 2; i < MXN; ++i)
        jc[i] = (jc[i - 1] * i) % WYC;
    ny[MXN - 1] = ksm(jc[MXN - 1], WYC - 2);
    for (int i = MXN - 2; i > 0; --i)
        ny[i] = (ny[i + 1] * (i + 1)) % WYC;

    int t, n, cnt, a, b;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        cnt = a = b = 0;
        scanf("%s", s);
        for (int i = 0; s[i]; ++i)
            if (s[i] == '0')
                ++a, cnt = 0;
            else if (!(++cnt & 1))
                ++b;
        printf("%lld\n", jc[a + b] * ny[a] % WYC * ny[b] % WYC);
    }
    return 0;
}