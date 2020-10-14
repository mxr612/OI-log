/**
 * JZOJ2020.09.26_B
 * NOIP2020.9.26模拟
 * tom
 * 树形DP求子树大小
*/

#define MXN (100024)

#include <stdio.h>
#include <stdlib.h>

#include <queue>

int n, a, b;

struct Edge {
    int v, w;
    Edge *next, *rev;
} * edge[MXN], *A, ee;
Edge* add_edge(int u, int v) {
    Edge* x = NULL;
    while (!x) x = (Edge*)calloc(sizeof(Edge), 1);
    x->v = v, x->next = edge[u], edge[u] = x;
    return x;
}
void con_edge(Edge* x, Edge* y) {
    if (x && y) x->rev = y, y->rev = x;
}

int dfs(int x, int fa, int& w) {
    for (Edge* i = edge[x]; i; i = i->next)
        if (i->v != fa)
            w += dfs(i->v, x, i->w), i->rev->w = n - i->w;
    return ++w;
}

int ans[MXN];

signed main() {
    freopen("tom.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("tom.out", "w", stdout);
#endif

    scanf("%d%d%d", &n, &a, &b);

    for (int i = 1, x, y; i < n; ++i)
        scanf("%d%d", &x, &y), con_edge(add_edge(x, y), add_edge(y, x));

    dfs(1, 0, *(int*)malloc(sizeof(int)));

    for (int i = 1; !A && i <= n; ++i)
        for (Edge* j = edge[i]; !A && j; j = j->next)
            if (j->w == a) A = j;
    if (A) {
        std::queue<Edge*> que;
        int tot = a;
        que.push(A);
        while (que.size()) {
            ans[que.front()->v] = tot--;
            for (Edge* i = edge[que.front()->v]; i; i = i->next)
                if (i->v != que.front()->rev->v)
                    que.push(i);
            que.pop();
        }
        tot = -b, que.push(A->rev);
        while (que.size()) {
            ans[que.front()->v] = tot++;
            for (Edge* i = edge[que.front()->v]; i; i = i->next)
                if (i->v != que.front()->rev->v)
                    que.push(i);
            que.pop();
        }
        for (int i = 1; i <= n; ++i)
            printf("%d\n", ans[i]);
    } else
        printf("-1");

    return 0;
}
