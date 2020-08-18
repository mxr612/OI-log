/**
 * 
*/

#define MXN (100020)

#include <stdio.h>

#include <algorithm>

int n, m;
long long a[MXN];

int check(int lim) {
    int res = 1, i = 0, cnt = 0;
    for (; i < n; ++i)
        if ((cnt += a[i]) > lim)
            cnt = a[i], ++res;
        else if (cnt == lim)
            cnt = 0, ++res;
    return res;
}

long long l, r = MXN * MXN, md;

signed main() {
    freopen("B.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &a[i]), l = std::max(l, a[i]);

    while (l < r) {
        if (check(md = (l + r) / 2) <= m)
            r = md;
        else
            l = md + 1;
    }

    printf("%d", r);

    return 0;
}