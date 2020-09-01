/**
 * SSLOJ2020.8.17A
 * 祝他生日快乐
 * A 图
 * 解方程
 * http://10.156.31.134/contestnew.aspx?cid=176
 * https://www.cnblogs.com/mxxr/p/13519612.html
*/

#define MXN (100020)

#include <math.h>
#include <stdio.h>
#include <string.h>

#include <vector>

int n;

struct Edge {
    int v, w;
} cer[MXN];
std::vector<Edge> edge[MXN];
int cnt;

int nc;
bool vis[MXN], in;
void dfs1(int x, int f) {
    if (vis[x]) {
        nc = x;
    } else {
        vis[x] = true;
        for (int i = edge[x].size() - 1; !nc && i >= 0; --i) {
            if (edge[x][i].v != f) {
                dfs1(edge[x][i].v, x);
                if (in) cer[++cnt] = edge[x][i];
            }
        }
        vis[x] = false;
    }
    if (x == nc) in = !in;
}

double ans[MXN];

void dfs2(int x) {
    vis[x] = true;
    for (int i = edge[x].size() - 1; i >= 0; --i)
        if (!vis[edge[x][i].v])
            ans[edge[x][i].v] = edge[x][i].w - ans[x], dfs2(edge[x][i].v);
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0, x, y, w; i < n; ++i)
        scanf("%d%d%d", &x, &y, &w), edge[x].push_back(Edge{y, w}), edge[y].push_back(Edge{x, w});

    dfs1(1, 0);

    for (int i = 1, p = -1; i <= cnt; ++i)
        ans[cer[1].v] += (p *= -1) * cer[i].w;
    ans[cer[1].v] /= 2.0;

    dfs2(cer[1].v);

    for (int i = 1; i <= n; ++i)
        printf("%g\n", ans[i]);

    return 0;
}