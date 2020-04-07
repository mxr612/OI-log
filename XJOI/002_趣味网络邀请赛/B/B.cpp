/**
 * B
 */

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MXN (50020)

int ans[MXN];
bool vis[MXN] = {false};

struct __edge {
	int v, w;
	__edge *next;
}*edge[MXN] = {NULL};

inline void _add_edge(register int u, register int v) {
	register __edge *x = (__edge *)calloc(sizeof(__edge), 1);
	x->v = v, x->next = edge[u], edge[u] = x;
}

int _dfs_1(int x) {
	int res = 0;
	vis[x] = true;
	for (__edge *i = edge[x]; i != NULL; i = i->next)
		if (!vis[i->v])
			i->w = _dfs_1(i->v), res = std::max(res, i->w);
	vis[x] = false;
	return res;
}

void _dfs_2(int x, int f) {
	vis[x] = true;
	ans[x] *= std::max()
	for (__edge *i = edge[x]; i != NULL; i = i->next) {
		if (!vis[i->v]) {
		}
	}
	vis[x] = false;
}

signed main() {

	freopen("B.in", "r", stdin);

	int n;

	scanf("%d", &n);

	for (register int i = 1; i <= n; ++i)
		scanf("%d", &ans[i]);
	for (int i = 1, x, y; i < n; ++i)
		scanf("%d%d", &x, &y), _add_edge(x, y), _add_edge(y, x);

	_dfs_1(1);
	_dfs_2(1, 0);

	return 0;

}