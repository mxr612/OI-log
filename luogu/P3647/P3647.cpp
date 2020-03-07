/**
 * P3647 [APIO2014]连珠线
 * 树形DP
 * 换根DP
 */

#include <stdio.h>
#include <stdlib.h>

int n;
struct __edge {
	int v;
	__edge *nx;
}*edge[200020] = {NULL}, *p;
int DP[200020][2] = {0};

int _dfs(int x, int d) {
	int res = 0;
	for (__edge *i = edge[x]; i != 0; i = i->nx) {
		if (i->v != d) {
			res += _dfs(i->v, x);
			DP[]
		}
	}
	return res + DP[x][0];
}

int main() {
	freopen("P3647.in", "w", stdin);
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		p = (__edge *)calloc(1, sizeof(__edge)), p->v = v, p->nx = edge[u], edge[u] = p;
		p = (__edge *)calloc(1, sizeof(__edge)), p->v = v, p->nx = edge[u], edge[u] = p;
	}



	return 0;
}