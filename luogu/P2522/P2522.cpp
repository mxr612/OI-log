/**
 * luoguP2522
 * [HAOI2011]Problem b
*/

const int MXA = 500012;

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

bool ntp[MXA];
int prm[MXA], tot;
short mu[MXA];

long long calc(long long n, long long m) {
    long long res = 0;
    for (int l = 1, r; l <= std::min(n, m); l = r + 1)
        r = std::min(n / (n / l), m / (m / l)),
        res += (n / l) * (m / l) * (mu[r] - mu[l - 1]);
    return res;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P2522.in", "r", stdin);
#endif

    mu[1] = 1;
    for (long long i = 2, j; i < MXA; ++i) {
        if (!ntp[i]) prm[tot++] = i, mu[i] = -1;
        for (j = 0; j < tot && i * prm[j] <= MXA; ++j)
            ntp[i * prm[j]] = true, mu[i * prm[j]] = (i % prm[j] > 0) * -mu[i];
        mu[i] += mu[i - 1];
    }

    int n;
    long long a, b, c, d, k;

    scanf("%d", &n);
    while (n--) {
        scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &k), --a, --c;
        printf("%lld\n", calc(b / k, d / k) - calc(b / k, c / k) + calc(a / k, c / k) - calc(a / k, d / k));
    }

    return 0;
}