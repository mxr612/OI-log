/**
 * 2019年11月12日提高组Day1
 * C 战略威慑
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, ans = -1;

struct __edge {
	int u, v;
	__edge *nx;
} *edge[220], *mark[220];
void _add_edge(int u, int v) {
	__edge *p = (__edge *)calloc(1, sizeof(__edge));
	p->u = u, p->v = v, p->nx = edge[u], edge[u] = p;
}
void __free_edge(__edge *&p) {
	if (p != NULL)
		__free_edge(p->nx), free(p), p = NULL;
}

int res[220][2];
void _vis(int x, int f) {
	int mx = -1, mc = -1;
	res[x][0] = res[x][1] = 1;
	for (__edge *i = edge[x]; i != NULL; i = i->nx)
		if (i->v != f) {
			_vis(i->v, x);
			res[x][0] = std::max(res[x][0], res[i->v][0]);
			if (res[i->v][1] > mx)mx = res[i->v][1];
			else if (res[i->v][1] > mc)mc = res[i->v][1];
		}
	if (mx > -1) {
		res[x][1] += mx;
		if (mc > -1)
			res[x][0] = std::max(res[x][0], mx + mc + 1);
	}
}

int main() {
	freopen("C3.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; ++i)
		scanf("%d%d", &u, &v), _add_edge(u, v), _add_edge(v, u);
	for (int i = 1; i <= n; ++i)
		for (__edge *j = edge[i]; j != NULL; j=j->nx)
			if (j->u < j->v) 
				memset(res, -1, sizeof(res)), _vis(j->u, j->v), _vis(j->v, j->u), ans = std::max(ans, std::max(res[j->u][0], res[j->v][0]));
	printf("%d", ans);
	for (int i = 1; i <= n; ++i)
		__free_edge(edge[i]);
	return 0;
}