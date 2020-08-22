/**
 * A 
*/

#define MXN (100020)

#include <stdio.h>

#include <vector>

int n, m;

std::vector<int> edge[MXN];

int due[MXN];

int ans[MXN], cnt;

// Sub3
bool vis[MXN], incer[MXN], in, out;
int h;
void findcer(int x, int f) {
    if (vis[x])
        h = x, out = true;
    vis[x] = true;
    for (int i = edge[x].size() - 1; !out && i >= 0; --i)
        if (edge[x][i] != f)
            findcer(edge[x][i], x);
    incer[x] = in;
    if (in) ++cnt;
    if (x == h) in = !in;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0, x, y; i < m; ++i)
        scanf("%d%d", &x, &y), edge[x].push_back(y), edge[y].push_back(x), ++due[x], ++due[y];

    if (m == n - 1) {
        for (int i = 1; i <= n; ++i)
            if (due[i] == 1)
                ans[cnt++] = i;
        printf("%d\n", cnt);
        for (int i = 0; i < cnt; ++i)
            printf("%d ", ans[i]);
    } else if (m == n) {
        findcer(1, 0);
        printf("%d\n", cnt);
        for (int i = 1; i <= n; ++i)
            if (incer[i] && due[i] < 3)
                printf("%d ", i);
    } else if (n <= 1000 && m <= 1000) {
    } else {
    }

    return 0;
}