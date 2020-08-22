/**
 * 
*/

#define MXN (500020)

#include <math.h>
#include <stdio.h>
#include <string.h>

#include <vector>

int n;
std::vector<int> edge[MXN];

// Sub1
bool vis[20], viv[20], flag;
int res[20], ans[MXN];
bool check() {
    memset(viv, 0, sizeof(viv));
    for (int i = 1, j, x; i <= n; ++i) {
        for (x = edge[i][0], j = edge[i].size() - 1; j > 0; --j)
            if (res[edge[i][j]] < res[x]) x = edge[i][j];
        if (viv[x]) return false;
        viv[x] = true;
    }
    return true;
}
void qpl(int dep) {
    if (dep > n) {
        flag = check();
    } else {
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                vis[i] = true;
                ans[dep] = i, res[i] = dep, qpl(dep + 1);
                if (flag) return;
                vis[i] = false;
            }
        }
    }
}

// Sub2
bool isl = true;
int due[MXN], head[5], arr[MXN];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 1, x, y; i < n; ++i)
        scanf("%d%d", &x, &y), edge[x].push_back(y), edge[y].push_back(x), isl &= ((++due[x]) < 3), isl &= ((++due[y]) < 3);

    if (n & 1) {
        printf("-1");
    } else if (n <= 10) {  // Sub1
        qpl(1);
        for (int i = 1; i <= n; ++i)
            printf("%d ", ans[i]);
    } else if (isl) {  // Sub3
        for (int i = 1, j = 0; i <= n; ++i)
            if (due[i] == 1)
                head[j++] = i;
        for (int i = 1, j, x = head[0]; i <= n; ++i)
            for (arr[i] = x, vis[x] = true, j = edge[x].size() - 1; j >= 0; --j)
                if (!vis[edge[x][j]])
                    x = edge[x][j];
        memset(vis, 0, sizeof(vis));
        for (int i = 1, j, x = 1, y = n; i <= n; ++i)
            if (x < n && arr[x] < arr[y])
                ans[i] = arr[x], res[arr[x]] = i, x += 2;
            else
                ans[i] = arr[y], res[arr[y]] = i, y -= 2;
        for (int i = 1; i <= n; ++i)
            printf("%d ", ans[i]);
    }

    return 0;
}