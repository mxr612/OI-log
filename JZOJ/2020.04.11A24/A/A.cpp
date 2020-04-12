/**
 * A
 */

#include <stdio.h>
#include <string.h>

#define MXN (1020)
#define MOD (1000000007)

int N, M, cnt = 0;
bool bmap[MXN][MXN];
int vmap[MXN][MXN];
int up[MXN * MXN] = {0};
long long ans[MXN * MXN];

int fa[MXN * MXN];
int _get(int x) {
    return (fa[x] == x) ? (x) : (fa[x] = _get(fa[x]));
}
int _merge(int x, int y) {
    x = _get(x), y = _get(y);
    if (x == 0 || y == 0)
        return x + y;
    if (x == y)
        return x;
    up[x] = _merge(up[x], up[y]);
    ans[y] = 0;
    return fa[y] = x;
}

main() {
    freopen("cave.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("cave.out", "w", stdout);
#endif

    scanf("%d%d", &N, &M);
    for (register int i = 0; i <= N * N; ++i)
        ans[i] = 1, fa[i] = i;
    getchar();
    for (register int i = 1, j; i <= N; ++i, getchar())
        for (j = 1; j <= M; ++j)
            if (bmap[i][j] = (getchar() == '.')) {
                vmap[i][j] = (bmap[i][j - 1]) ? (cnt) : (++cnt);
                if (bmap[i - 1][j])
                    up[cnt] = _merge(up[cnt], vmap[i - 1][j]);
            }
    for (register int i = cnt; i > 0; --i)
        ans[_get(up[i])] = (ans[_get(up[i])] * ++ans[i]) % MOD;
    printf("%d", ans[0]);
    return 0;
}