
#include <stdio.h>

#include <algorithm>

const int MD = 1000000007;

inline long long lowbit(long long x) { return x & -x; }

long long ksm(long long x, long long y) {
    x %= MD, y %= MD - 2;
    long long res = 1;
    while (y) {
        if (y & 1) (res *= x) %= MD;
        (x *= x) %= MD;
        y >>= 1;
    }
    return res;
}

long long sovle(long long a, long long b, long long n) {
    if ((a ^ b) & 1) return 0;
    if (n & 1) return lowbit(a - b) % MD;
    return lowbit(a - b) % MD * lowbit(a + b) % MD * lowbit(n / 2) % MD;
}

signed main() {
    freopen("journey.in", "r", stdin);
    freopen("journey.out", "w", stdout);

    int T, a, b, ka, kb, n;

    scanf("%d", &T);

    while (T--) {
        scanf("%d%d%d", &a, &b, &n);
        ka = lowbit(a), kb = lowbit(b);
        printf("%lld\n", ksm(std::min(ka, kb), n) % MD * sovle(a / ka, b / kb, n) % MD);
    }

    return 0;
}
