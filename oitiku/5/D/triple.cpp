/**
 * triple
*/

#include <stdio.h>

const long long MD = 998244353;

int T, N, M, K, ans;

int mem[128][128][128];

int f(int x, int y, int z) {
    if (z == 0) return 1;
    if (mem[x][y][z]) return mem[x][y][z];
    long long res = 0;
    for (int i = 1, j; i <= x; ++i)
        for (j = 1; j <= y; ++j)
            res = (res + (x - i + 1) * (y - j + 1) % MD * f(i, j, z - 1)) % MD;
    return mem[x][y][z] = res;
}

signed main() {
    freopen("triple.in", "r", stdin);
    freopen("triple.out", "w", stdout);

    for (scanf("%d", &T); T--;) {
        ans = 0;
        scanf("%d%d%d", &N, &M, &K);
        for (int i = 1, j; i <= N; ++i)
            for (j = 1; j <= M; ++j)
                ans = (ans + f(i, j, K)) % MD;
        printf("%d\n", ans);
    }

    return 0;
}