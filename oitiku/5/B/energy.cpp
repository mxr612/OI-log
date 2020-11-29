/**
 * energy
*/

#include <math.h>
#include <stdio.h>

const int MXN = 300050,
          MD = 998244353;

inline long long mod(long long x) { return (x % MD + MD) % MD; }

long long mi[MXN] = {1};

int T, n;
long long f[MXN][2] = {};

signed main() {
    freopen("energy.in", "r", stdin);
    freopen("energy.out", "w", stdout);

    for (int i = 1; i < MXN; ++i)
        mi[i] = mi[i - 1] * 2 % MD;

    f[0][0] = 1;
    for (int i = 1; i < MXN; ++i)
        f[i][0] = (f[i - 1][0] + f[i - 1][1]) % MD,
        f[i][1] = f[i - 1][0];

    for (scanf("%d", &T); T--;) {
        scanf("%d", &n);
        printf("%lld\n", mod(mi[n] - f[n - 1][0] - f[n - 1][1]));
        // printf("%lld\n", f[n][0] + f[n][1]);
    }

    return 0;
}