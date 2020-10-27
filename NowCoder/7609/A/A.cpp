/**
 * NowCoder7609
 * A牛半仙的妹子数
 * 注意到原式每次变化三个量总和不变
 * 先考虑简化问题, 设S=A+B+C, A+B=S-C,原式转为:
 * 若C<=2S, C=2C
 * 若C>2s , C=S-2(S-C)=2C-S
 * 两个式子整合为2C%S
*/

#include <stdio.h>

long long ksm(long long x, long long y, long long m) {
    long long res = 1;
    while (y) {
        if (y & 1) (res *= x) %= m;
        (x *= x) %= m;
        y >>= 1;
    }
    return res;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    long long T, A, B, C, K;

    scanf("%lld", &T);

    while (T--)
        scanf("%lld%lld%lld%lld", &A, &B, &C, &K),
            printf("%lld\n", (C * ksm(2, K, A + B + C)) % (A + B + C));

    return 0;
}