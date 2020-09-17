/**
 * ybtoj2020.09.05B
 * B卡牌选取card
*/

#define MXN (100020)
#define XJQ (998244353)

#include <stdio.h>

#include <algorithm>

int n, k;

long long res, ans;

int cnt[MXN];

long long jc[MXN], ny[MXN];

long long ksm(long long x, long long y) {
    x %= XJQ, y %= XJQ - 1;
    long long res = 1;
    while (y) {
        if (y & 1) res = (res * x) % XJQ;
        x = (x * x) % XJQ;
        y >>= 1;
    }
    return res;
}

inline long long C(int n, int m) { return (m <= n) ? ((((jc[n] * ny[m]) % XJQ) * ny[n - m]) % XJQ) : (0); };

signed main() {
    freopen("card.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("card.out", "w", stdout);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0, j, a; i < n; ++i)
        for (scanf("%d", &a), j = 0; j < 31; ++j)
            cnt[j] += (a >> j) & 1;

    jc[0] = ny[0] = 1;
    for (int i = 1; i <= n; ++i)
        jc[i] = (jc[i - 1] * i) % XJQ;
    ny[n] = ksm(jc[n], XJQ - 2);
    for (int i = n - 1; i > 0; --i)
        ny[i] = (ny[i + 1] * (i + 1)) % XJQ;

    for (int i = 0, j; i < 31; ++i) {
        res = 0;
        for (j = 1; j <= std::min(cnt[i], k); j += 2)
            res = (res + ((C(cnt[i], j) * C(n - cnt[i], k - j)) % XJQ)) % XJQ;
        ans = (ans + res * ((1LL << i) % XJQ)) % XJQ;
    }

    printf("%lld", ans);

    return 0;
}