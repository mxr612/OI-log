/**
 * luogu30519
 * B
 * 期望DP，先考虑m=0的情况，发现是等差数列求和
 * 然后考虑一般情况，大概就概率乘上期望就好了
 * 发现在式子中，n是可以直接取模的
*/

#define MD (998244353)

#include <stdio.h>
#include <stdlib.h>

long long ksm(long long x, long long y) {
    x %= MD, y %= MD - 1;
    long long res = 1;
    while (y) {
        if (y & 1) res = (res * x) % MD;
        x = (x * x) % MD;
        y >>= 1;
    }
    return res;
}

long long g(long long n) {
    return ((((3 + n) * n) % MD) * ksm(2, MD - 2) + MD - 1) % MD;
}

signed main() {
    long long n, m;

    scanf("%lld%lld", &n, &m), n %= MD;

    long long *f = (long long *)calloc(sizeof(long long), m + 32);

    f[0] = g(n) + 1;
    for (int i = 1; i <= m; ++i)
        f[i] = ((((n * g(n + i)) % MD) + ((i * f[i - 1]) % MD)) * ksm(n + i, MD - 2) + 1) % MD;

    printf("%lld", f[m]);

    return 0;
}