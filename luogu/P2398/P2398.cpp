/**
 * luoguP2398
*/

#define MXN (100020)

#include <stdio.h>

int n;

int prm[MXN], tot;
long long phi[MXN];

long long ans;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P2398_1.in", "r", stdin);
#endif

    scanf("%d", &n);

    phi[1] = 1;
    for (int i = 2, j; i <= n; ++i) {
        if (!phi[i]) prm[tot++] = i, phi[i] = i - 1;
        for (j = 0; j < tot && i * prm[j] <= n; ++j)
            phi[i * prm[j]] = (i % prm[j]) ? (phi[i] * (prm[j] - 1)) : (phi[i] * prm[j]);
        phi[i] += phi[i - 1];
    }

    for (int i = 1; i <= n; ++i)
        ans += i * (2 * phi[n / i] - 1);

    printf("%lld", ans);

    return 0;
}