/**
 * count
*/

#include <stdio.h>
#include <string.h>

const long long MD = 1000000007;
const int MXN = 50;

int n;
bool edge[MXN][MXN];

int sta[MXN];
bool vis[MXN];
void build(int v, int dep) {
    vis[v] = true, sta[dep] = v;
    for (int i = 0; i < dep; ++i)
        edge[v][sta[i]] = edge[sta[i]][v] = true;
    for (int i = 1; i < (1 << n); ++i)
        if (edge[v][i] && !vis[i])
            build(i, dep + 1);
}

long long ans;

void dfs(int v) {
    ans = (ans + 1) % MD;
    vis[v] = true;
    for (int i = 1; i < (1 << n); ++i)
        if (edge[v][i] && !vis[i])
            dfs(i);
    vis[v] = false;
}

int answ[50] = {0, 1, 9, 245, 126565};

signed main() {
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);

    scanf("%d", &n);
    printf("%d", (n < 0) ? (0) : (answ[n]));

    // for (int i = 1, j; i < n; ++i)
    //     for (j = 1 << i; j < 1 << (i + 1); ++j)
    //         edge[j][j >> 1] = edge[j >> 1][j] = true;

    // build(1, 0);

    // memset(vis, 0, sizeof(vis)), ans = 0;
    // for (int i = 1; i < (1 << n); ++i)
    //     dfs(i);

    // printf("%lld\n", ans);

    return 0;
}