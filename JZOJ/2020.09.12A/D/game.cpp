/**
 * 2020.09.12A
 * D game
 * 叠代加深
*/

#define MXN (50)

#include <stdio.h>

#include <algorithm>

int n, m, w, ans = 100;

short gra[MXN][MXN];

const short way[4][2]{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}};

void dfs(int d, int X, int Y, int cnt) {
    if (d > ans) return;
    if (cnt == w) {
        ans = d;
    } else {
        gra[X][Y] = 2;
        for (int i = 0, x = X, y = Y, cmp; i < 4; ++i) {
            cmp = 0;
            while (!gra[x + way[i][0]][y + way[i][1]])
                gra[x += way[i][0]][y += way[i][1]] = 2, ++cmp;
            if (x != x && y != y)
                dfs(d + 1, x, y, cnt + cmp);
            while (x != X || y != Y) gra[x][y] = 0, x -= way[i][0], y -= way[i][1];
        }
        gra[X][Y] = 0;
    }
}

signed main() {
    freopen("game.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("game.out", "w", stdout);
#endif

    scanf("%d%d\n", &n, &m);

    for (int i = 0; i <= std::max(n, m) + 1; ++i)
        gra[0][i] = gra[i][0] = gra[n + 1][i] = gra[i][m + 1] = -1;

    for (int i = 1, j; i <= n; ++i, getchar())
        for (j = 1; j <= m; ++j)
            if (!(gra[i][j] = getchar() == '*'))
                ++w;

    // for (int i = 0; i <= n + 1; ++i, putchar('\n'))
    //     for (int j = 0; j <= m + 1; ++j)
    //         printf("%3d", gra[i][j]);

    int ct = 0;
    for (int i = 1, j; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            if (!gra[i][j])
                ++ct, dfs(0, i, j, 0);

    if (ans == 100) ans = -1;
    if (!ct) ans = 0;

    printf("%d", ans);

    return 0;
}