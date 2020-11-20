/**
 * JZOJ 20201114 B
 * A shiawase 隐藏指令
*/

#include <stdio.h>

const long long MD = 1000000007,
                MXN = 250;

long long f[MXN][MXN][MXN];
long long jc[2 * MXN], ny[2 * MXN];

long long ksm(long long x, long long y) {
    long long res = 1;
    x %= MD, y %= MD - 1;
    while (y) {
        if (y & 1) res = res * x % MD;
        x = x * x % MD;
        y >>= 1;
    }
    return res;
}

inline long long C(int n, int m) { return jc[n] * ny[n - m] % MD * ny[m] % MD; }

signed main() {
#ifndef ONLINE_JUDGE
    freopen("shiawase19.in", "r", stdin);
#endif

    int d, N;
    long long ans = 0;

    scanf("%d%d", &d, &N);

    jc[0] = 1;
    for (int i = 1; i <= 2 * N; ++i)
        jc[i] = jc[i - 1] * i % MD;
    ny[2 * N] = ksm(jc[2 * N], MD - 2);
    for (int i = 2 * N; i > 0; --i)
        ny[i - 1] = ny[i] * i % MD;

    f[0][0][0] = 1;
    long long g;
    for (int i = 1, j, k, l; i <= d; ++i)  //用了i种, (完成后)已有j对, 这种选k个, 上一种选l个
        for (j = 0; j <= N; ++j)
            for (k = 0; k <= j; ++k)
                for (g = C(2 * j, 2 * k) * jc[2 * k] % MD * ny[k] % MD * ny[k] % MD, l = 0; l <= j - k; ++l)
                    f[i][j][k] = (f[i][j][k] + f[i - 1][j - k][l] * g) % MD;

    for (int i = 0; i <= N; ++i)
        ans = (ans + f[d][N][i]) % MD;

    printf("%lld", ans);

    return 0;
}