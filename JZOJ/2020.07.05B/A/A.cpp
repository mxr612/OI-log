/**
 * JZOJ 2020.7.5B
 * JZOJ 5264 化学
*/

#include <stdio.h>

#include <algorithm>

#define MXN (50)
#define MXB (1 << 21)

int n;
long long m, ans, p[MXN];

long long w1[MXB], w2[MXB];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("chemistry4.in", "r", stdin);
#endif
    scanf("%d%lld", &n, &m);

    for (int i = 0; i < n; ++i)
        scanf("%lld", &p[i]);

    for (int i = 0, j; i < 1 << (n / 2); ++i)
        for (j = 0; j < n / 2; ++j)
            if ((i >> j) & 1)
                w1[i] += p[j];
    for (int i = 0, j; i < 1 << (n - (n / 2)); ++i)
        for (j = n / 2; j <= n; ++j)
            if ((i >> (j - n / 2)) & 1)
                w2[i] += p[j];

    std::sort(&w1[0], &w1[1 << (n / 2)]);
    std::sort(&w2[0], &w2[1 << (n - (n / 2))]);

    for (int i = 0, j = (1 << (n - (n / 2))) - 1; i < 1 << (n / 2); ++i) {
        while ((j >= 0) && (w1[i] + w2[j] > m)) --j;
        ans += j + 1;
    }

    printf("%lld", ans);

    return 0;
}
