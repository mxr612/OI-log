
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

long long get(int *min, int x) {
    long long res = 1;
    for (int now = min[x], cnt = 0; now; now = min[x], cnt = 0) {
        while (!(x % now)) ++cnt, x /= now;
        res *= cnt + 1;
    }
    return res;
}

signed main() {
    int n, *prm, tot = 0, *min;
    bool *ntp;
    long long ans = 0;

    scanf("%d", &n);
    prm = (int *)calloc(sizeof(int), n);
    min = (int *)calloc(sizeof(int), n + 32);
    ntp = (bool *)calloc(sizeof(bool), n);

    for (int i = 2, j; i <= n; ++i) {
        if (!ntp[i]) prm[tot++] = i, min[i] = i;
        for (j = 0; j < tot && i * prm[j] <= n; ++j)
            ntp[i * prm[j]] = true,
                    min[i * prm[j]] = std::min(min[i], prm[j]);
        ans += (get(min, i) - 1) * (n / i - 1);
    }

    printf("%lld", ans);

    return 0;
}