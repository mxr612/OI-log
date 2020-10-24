/**
 * luoguP1829
 * [国家集训队]Crash的数字表格 / JZPTAB
 * 求区间lcm和
 * 莫比乌斯
*/

const long long MD = 20101009,
                MXN = 10000024;

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

long long *sum;

inline long long g(long long a, long long b) { return (a * (a + 1) / 2 % MD) * (b * (b + 1) / 2 % MD) % MD; }

long long f(long long a, long long b) {
    long long res = 0;
    for (int l = 1, r; l <= std::min(a, b); l = r + 1)
        r = std::min(a / (a / l), b / (b / l)),
        res = (res + (sum[r] - sum[l - 1] + 2 * MD) % MD * g(a / l, b / l)) % MD;
    return res;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1829.in", "r", stdin);
#endif

    int n, m;

    scanf("%d%d", &n, &m);

    bool *flg = (bool *)calloc(sizeof(bool), std::min(n, m) + 32);
    int *prm = (int *)calloc(sizeof(int), std::min(n, m)), tot = 0;
    short *mu = (short *)calloc(sizeof(short), std::min(n, m) + 32);
    sum = (long long *)calloc(sizeof(long long), std::min(n, m) + 32);

    mu[1] = sum[1] = 1;
    for (long long i = 2, j; i <= std::min(n, m); ++i) {
        if (!flg[i]) prm[tot++] = i, mu[i] = -1;
        for (j = 0; j < tot && i * prm[j] <= std::min(n, m); ++j)
            flg[i * prm[j]] = true, mu[i * prm[j]] = (i % prm[j] > 0) * -mu[i];
        sum[i] = (sum[i - 1] + i * i % MD * (mu[i] + MD)) % MD;
    }

    long long res = 0;

    for (long long l = 1, r; l <= std::min(n, m); l = r + 1)
        r = std::min(n / (n / l), m / (m / l)),
        res = (res + (l + r) * (r - l + 1) / 2 % MD * f(n / l, m / l)) % MD;

    printf("%lld", res);

    return 0;
}