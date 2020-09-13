/**
 * luoguP1043
*/

#define MXN (60)
#define XJQ (10)

#include <stdio.h>
#include <string.h>

#include <algorithm>

int n, m;

int arr[2 * MXN];
long long f[2 * MXN][XJQ], g[2 * MXN][XJQ], ff, gg = 10000000000;

int mod(int x) { return ((x % XJQ) + XJQ) % XJQ; }

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1043_6.in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]), arr[n + i] = arr[i];
    for (int i = 1; i <= 2 * n; ++i)
        arr[i] += arr[i - 1];

    for (int s = 0, i, j, k; s < n; ++s) {
        memset(f, 0, sizeof(f)), f[s][0] = 1;
        memset(g, 1, sizeof(g)), g[s][0] = 1;
        for (i = s + 1; i <= s + n; ++i)
            for (f[i][1] = g[i][1] = mod(arr[i] - arr[s]), j = 2; j <= m; ++j)
                for (k = s + j - 1; k < i; ++k)
                    f[i][j] = std::max(f[i][j], f[k][j - 1] * mod(arr[i] - arr[k])),
                    g[i][j] = std::min(g[i][j], g[k][j - 1] * mod(arr[i] - arr[k]));
        ff = std::max(ff, f[s + n][m]), gg = std::min(gg, g[s + n][m]);
    }

    printf("%lld\n%lld", gg, ff);

    return 0;
}