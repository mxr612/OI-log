/**
 * 2019.11.06【NOIP提高组】模拟 B 组
 * 统计损失(count)
 */

#include <stdio.h>
#include <stdlib.h>

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

int main() {
	freopen("count.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &v[i]), m[i] = v[i];
	for (int i = 1, u, v; i < n; ++i)
		scanf("%d%d", &u, &v), _add_edge(u, v), _add_edge(v, u);

	for (int i = 1; i <= n; ++i)
		_free_edge(edge[i]);
	return 0;
}