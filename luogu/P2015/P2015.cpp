#include <stdio.h>
#include <string.h>

#include <algorithm>

const int MXN = 128;

int N, Q;
int E[MXN][MXN];

int f[MXN][MXN];
bool vis[MXN];
void dfs(int x) {
    vis[x] = true;
    for (int i = 1, j, k; i <= N; ++i) {
        if (E[x][i] != -1 && !vis[i]) {
            f[i][1] = E[x][i], dfs(i);
            for (j = Q; j > 1; --j)
                for (k = 1; k < j; ++k)
                    f[x][j] = std::max(f[x][j], f[x][k] + f[i][j - k]);
        }
    }
    vis[x] = false;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P2015.in", "r", stdin);
#endif

    memset(E, -1, sizeof(E));

    scanf("%d%d", &N, &Q);
    for (int i = 1, x, y, v; i < N; ++i)
        scanf("%d%d%d", &x, &y, &v), E[x][y] = E[y][x] = v;

    vis[1] = true;
    for (int i = 1, j, k; i <= N; ++i) {
        if (E[1][i] != -1 && !vis[i]) {
            f[i][1] = E[1][i], dfs(i);
            for (j = Q; j >= 1; --j)
                for (k = 0; k <= j; ++k)
                    f[1][j] = std::max(f[1][j], f[1][k] + f[i][j - k]);
        }
    }

    printf("%d", f[1][Q]);

    return 0;
}
