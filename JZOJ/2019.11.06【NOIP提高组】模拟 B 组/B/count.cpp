/**
 * 2019.11.06【NOIP提高组】模拟 B 组
 * 统计损失(count)
 * LCA 非正解
 * 注意读题
 */

#include <stdio.h>
#include <stdlib.h>

const int mi[20] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288};
int n, v[100020], dep[100020] = {0}, fa[100020][20] = {0};
long long m[100020];
struct __edge {
	int v;
	__edge *nx = NULL;
}*edge[100020] = {NULL};

void _add_edge(int u, int v) {
	__edge *p = (__edge *)calloc(1, sizeof(__edge));
	p->v = v, p->nx = edge[u], edge[u] = p;
}
void _free_edge(__edge *&p) {
	if (p != NULL)
		_free_edge(p->nx), free(p), p = NULL;
}
void _dfs_mul(int x, int d) {
	dep[x] = dep[d] + 1;
	m[x] *= m[d];
	for (__edge *p = edge[x]; p != NULL; p = p->nx)
		if (p->v != d)
			_dfs_mul(p->v, x);
}
void _dfs_lca(int x, int d) {
	fa[x][0] = d;
	for (int i = 1; mi[i] <= dep[x]; ++i)
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for (__edge *p = edge[x]; p != NULL; p = p->nx)
		if (p->v != d)
			_dfs_lca(p->v, x);
}
int _lca(int x, int y) {
	if (dep[x] < dep[y]) {

	}
	if (dep[x] > dep[y]) {

	}
	return 0;
}

int main() {
	freopen("count.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &v[i]), m[i] = v[i];
	for (int i = 1, u, v; i < n; ++i)
		scanf("%d%d", &u, &v), _add_edge(u, v), _add_edge(v, u);
	m[0] = 1, dep[0] = -1, _dfs_mul(1, 0);
	_dfs_lca(1, 0);
	for (int i = 1; i <= n; ++i)
		_free_edge(edge[i]);
	return 0;
}