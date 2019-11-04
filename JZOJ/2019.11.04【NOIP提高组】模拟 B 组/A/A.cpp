/**
 * 2019.11.04【NOIP提高组】模拟 B 组
 * A 游戏
 * 树上问题
 * 模拟dfs
 */

#include <stdio.h>
#include <stdlib.h>

int T;
int N, Ma, Mb, Ca, Cb;
struct __edge {
	int v;
	__edge *nx;
}*edge[10020] = {NULL};
void _add_edge(int u, int v) {
	__edge *p = (__edge *)calloc(1, sizeof(__edge));
	p->v = v, p->nx = edge[u], edge[u] = p;
}
void _free_edge(__edge *&p) {
	if (p != NULL)
		_free_edge(p->nx), free(p), p = NULL;
}
int node[10020];

void _dfs(int nod, int dep, int dad) {
	node[nod] = dep;
	for (__edge *p = edge[nod]; p != NULL; p = p->nx)
		if (p->v != dad)
			_dfs(p->v, dep + 1, nod);
}

int main() {
	freopen("A.in", "r", stdin);
	scanf("%d", &T);
	while (T-- > 0) {
		Ca = Cb = 0;
		scanf("%d%d%d", &N, &Ma, &Mb);
		for (int i = 1, u, v; i < N; ++i)
			scanf("%d%d", &u, &v), _add_edge(u, v), _add_edge(v, u);
		_dfs(0, 0, 0);
		for (int i = 1, p; i <= Ma; ++i)
			scanf("%d", &p), Ca += node[p];
		for (int i = 1, p; i <= Mb; ++i)
			scanf("%d", &p), Cb += node[p];
		if(Ca<=Cb)
			printf("Bob\n");
		else
			printf("Alice\n");
		for (int i = 0; i < N; ++i)
			_free_edge(edge[i]);
	}
	return 0;
}