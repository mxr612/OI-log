
#include <stdio.h>

#include <algorithm>

long long ksm(long long x, long long y, long long mod) {
    long long res = 1;
    while (y) {
        if (y & 1) (res *= x) %= mod;
        (x *= x) %= mod;
        y >>= 1;
    }
    return res;
}

signed main() {
    int T, n, m, k;

    scanf("%d", &T);

    while (T--)
        scanf("%d%d%d", &n, &m, &k),
            printf("%lld\n", std::min((n * ksm(2, k, n + m)) % (n + m), (m * ksm(2, k, n + m)) % (n + m)));

    return 0;
}