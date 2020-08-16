/**
 * A
*/

#define MXN (3020)

#include <stdio.h>

int n, q;

long long a[MXN][MXN], b[MXN][MXN], ans;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    scanf("%d%d", &n, &q);

    for (int i = 0, r, c, l, s; i < q; ++i) {
        scanf("%d%d%d%d", &r, &c, &l, &s);
        a[1 + r][c] += s;
        a[1 + r + l][c + l] -= s;
        b[1 + r + l][c] -= s;
        b[1 + r + l][c + l] += s;
    }

    for (int i = 1, j; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
            a[1 + i][j] += a[1 + i - 1][j] + a[1 + i - 1][j - 1] - a[1 + i - 2][j - 1];
            b[1 + i][j] += b[1 + i - 1][j] + b[1 + i][j - 1] - b[1 + i - 1][j - 1];
            ans ^= a[1 + i][j] + b[1 + i][j];
        }
    }

    printf("%lld", ans);

    return 0;
}