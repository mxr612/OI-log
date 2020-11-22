/**
 * board
*/

#include <math.h>
#include <stdio.h>

const int MXN = 1000024;

int las[2][MXN];  //最后颜色及位置
short col[2][MXN];
int cnt[2][MXN];  //统计数量

signed main() {
    freopen("board.in", "r", stdin);
    // freopen("board.out", "w", stdout);

    int n, m, q;
    long long ans = 0;

    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1, x, y, z; i <= q; ++i)
        scanf("%d%d%d", &x, &y, &z), las[x][y] = i, col[x][y] = z;

    for (int i = 1; i <= n; ++i)
        ++cnt[0][las[0][i]];
    for (int i = 1; i <= m; ++i)
        ++cnt[1][las[1][i]];
    for (int i = 1; i <= q; ++i)
        cnt[0][i] += cnt[0][i - 1];
    for (int i = 1; i <= q; ++i)
        cnt[1][i] += cnt[1][i - 1];

    for (int i = 1; i <= n; ++i)
        if (col[0][i])
            ans += cnt[1][las[0][i]];
    for (int i = 1; i <= m; ++i)
        if (col[1][i])
            ans += cnt[0][las[1][i]];

    printf("%lld\n", ans);

    return 0;
}
