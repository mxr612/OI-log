/**
 * LOJ#6089
*/

#define MXN (100020)
#define MOD (23333333)

#include <math.h>
#include <stdio.h>

int n, m;

int p[MXN], q[MXN];

int f[MXN];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("#6089.in", "r", stdin);
#endif

    scanf("%d", &n), m = ceil(sqrt(n));

    for (int i = 1, j, k, out, in; i < m; ++i) {
        for (j = 0; j < i; ++j) {
            p[++in] = f[k], q[in] = k;
        }
    }
    for (int i = m; i <= n; ++i) {
    }

    return 0;
}