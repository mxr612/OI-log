/**
 * 2020.09.12A
 * C regions
 * 离散化，dfs染色
*/

#define MXN (100)

#include <stdio.h>

#include <map>

int n;

struct Reg {
    int x[2], y[2];
} reg[MXN];

std::map<int, int> map;
int rmap[MXN * 5], lst = 1;

int gra[MXN * 5][MXN * 5];

int way[4][2] = {
    {0, 1},
    {1, 0},
    {-1, 0},
    {0, -1}};

int ans;

void col(int x, int y) {
    if (gra[x][y]) return;
    gra[x][y] = ans;
    for (int i = 0; i < 4; ++i)
        col(x + way[i][0], y + way[i][1]);
}

signed main() {
    freopen("regions.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("regions.out", "w", stdout);
#endif

    scanf("%d", &n);

    for (int i = 0, *x, *y; i < n; ++i) {
        x = reg[i].x, y = reg[i].y;
        scanf("%d%d%d%d", &x[0], &y[0], &x[1], &y[1]);
        map[x[0]] = map[y[0]] = map[x[1]] = map[y[1]] = -1;
    }

    for (auto &i : map)
        i.second = lst++;

    for (int i = 0; i <= 2 * lst; ++i)
        gra[0][i] = gra[i][0] = gra[2 * lst][i] = gra[i][2 * lst] = -1;

    for (int i = 0, j, k, *x, *y; i < n; ++i) {
        x = reg[i].x, y = reg[i].y;
        for (j = 2 * map[x[0]], k = 2 * map[y[1]]; k <= 2 * map[y[0]]; ++k)
            gra[j][k] = -1;
        for (j = 2 * map[x[1]], k = 2 * map[y[1]]; k <= 2 * map[y[0]]; ++k)
            gra[j][k] = -1;
        for (j = 2 * map[x[0]], k = 2 * map[y[0]]; j <= 2 * map[x[1]]; ++j)
            gra[j][k] = -1;
        for (j = 2 * map[x[0]], k = 2 * map[y[1]]; j <= 2 * map[x[1]]; ++j)
            gra[j][k] = -1;
    }

    for (int i = 0; i <= 2 * lst; ++i)
        for (int j = 0; j <= 2 * lst; ++j)
            if (!gra[i][j])
                ++ans, col(i, j);

    // for (int i = 0; i <= 2 * lst; ++i, putchar('\n'))
    //     for (int j = 0; j <= 2 * lst; ++j)
    //         printf("%3d", gra[i][j]);

    printf("%d", ans);

    return 0;
}