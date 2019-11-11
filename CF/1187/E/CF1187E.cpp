/**
 * CF1187E
 * Tree Painting
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int n;

struct __edge {
	long long v, w;
	__edge *nx, *fb;
}*edge[200020] = {NULL};
__edge *_add_edge(int u, int v) {
	__edge *p = NULL;
	while (p == NULL)p = (__edge *)calloc(1, sizeof(__edge));
	p->v = v, p->nx = edge[u], edge[u] = p;
	return p;
}
void _con_edge(__edge *x, __edge *y) {x->fb = y, y->fb = x;}
void _free_edge(__edge *&p) {
	if (p != NULL)
		_free_edge(p->nx), free(p), p = NULL;
}

long long pre[400020] = {0}, res[400020] = {0}, ans;

int _pre_dfs(int x, int f) {
	int res = 1;
	for (__edge *i = edge[x]; i != NULL; i = i->nx)
		if (i->v != f)
			i->w = _pre_dfs(i->v, x), res += i->w, i->fb->w = n - i->w, pre[x] += pre[i->v];
	pre[x] += res;
	return res;
}

void _ans_dfs(int x, int f, __edge *com) {
	if (com != NULL)
		res[x] = res[f] - com->w + com->fb->w;
	ans = std::max(ans, res[x]);
	for (__edge *i = edge[x]; i != NULL; i = i->nx)
		if (i->v != f)
			_ans_dfs(i->v, x, i);
}

signed main() {
	freopen("CF1187E2.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; ++i)
		scanf("%d%d", &u, &v), _con_edge(_add_edge(u, v), _add_edge(v, u));
	_pre_dfs(1, 1);
	ans = res[1] = pre[1];
	_ans_dfs(1, 1, NULL);
	printf("%d", ans);
	for (int i = 1; i <= n; ++i)
		_free_edge(edge[i]);
	return 0;
}