/**
 * 2019年11月4日提高组
 * A 小w的铁路图
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

int n, m;
struct __edge {
	int u, v;
	__edge *nx;
}*edge[1020] = {NULL}, *edge_[1020] = {NULL};
int node[1020], ans;
std::queue<int>que;

__edge *_add_edge(int u, int v) {
	__edge *p = (__edge *)calloc(1, sizeof(__edge));
	p->u = u, p->v = v, p->nx = edge[u], edge[u] = p;
	return p;
}
void _free_edge(__edge *&p) {
	if (p != NULL)
		_free_edge(p->nx), free(p), p = NULL;
}

int main() {
	freopen("A.in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; ++i)
		scanf("%d%d", &u, &v), edge_[i] = _add_edge(u, v);
	for (int i = 1; i <= m; ++i) {
		while (!que.empty())que.pop();
		memset(node, -1, sizeof(node));
		que.push(edge_[i]->u), node[edge_[i]->u] = 0;
		while (!que.empty()) {
			for (__edge *k = edge[que.front()]; k != NULL; k = k->nx)
				if (k != edge_[i] && node[k->v] == -1)
					que.push(k->v), node[k->v] = node[que.front()] + 1;
			que.pop();
		}
		printf("%d ", node[edge_[i]->v]);
	}

	for (int i = 1; i <= n; ++i)
		_free_edge(edge[i]);
	return 0;
}