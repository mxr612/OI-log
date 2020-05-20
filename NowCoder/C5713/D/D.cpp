/**
 * NowCoder 5713D
 */

#include <stdio.h>
#include <stdlib.h>

#define MXN (100020)

int N, M, ans = 0;
struct __edge {
    int v, c;
    __edge* next;
} * edge[MXN] = {NULL}, *vis[MXN];
void _add_edge(int u, int v) {
    __edge* p = (__edge*)calloc(sizeof(__edge), 1);
    p->v = v, p->next = edge[u], edge[u] = p;
}

int deep[MXN] = {0};

void _dfs(int dep, int nod, int fa) {
    if (deep[nod] == 0) {
        deep[nod] = dep;
        for (__edge* i = edge[nod]; i != NULL; i = i->next)
            if (i->v != fa)
                vis[dep] = i, _dfs(dep + 1, i->v, nod);
        deep[nod] = 0;
    } else
        for (int i = deep[ nod]; i < dep; ++i)
            vis[i]->c = 1;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif

    scanf("%d%d", &N, &M);
    for (int i = 0, u, v; i < M; ++i)
        scanf("%d%d", &u, &v), _add_edge(u, v), _add_edge(v, u);

    _dfs(1, 0, 0);

    for (int i = 0; i <= N; ++i)
        for (__edge* j = edge[i]; j != NULL; j = j->next)
            ans += j->c;

    printf("%d", ans);

    return 0;
}