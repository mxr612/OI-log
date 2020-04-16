/**
 * B
 * fall
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

struct __edge {
	int v;
	__edge *next;
}*edge[300020] = {NULL};
inline void _add_edge(register int u, register int v) {
	register __edge *p = (__edge *)calloc(sizeof(__edge), 1);
	p->v = v;
	p->next = edge[u];
	edge[u] = p;
}

struct __man {
	int ans, g;
	long long s, k, b;
	__man *ls, *rs;
} *man[300020] = {NULL};

inline void _modify(register __man *x, long long k, long long b, int g) {
	x->s = k * x->s + b;
	x->ans += g;
	x->k *= k;
	x->b = k * x->b + b;
	x->g += g;
}

inline void _push_down_(register __man *x) {
	if (x->ls != NULL)
		_modify(x->ls, x->k, x->b, x->g);
	if (x->rs != NULL)
		_modify(x->rs, x->k, x->b, x->g);
	x->k = 1, x->b = x->g = 0;
}

__man *_merge(__man *x, __man *y) {
	if (x == NULL)return y; else _push_down_(x);
	if (y == NULL)return x; else _push_down_(y);
	if (x->s > y->s)std::swap(x, y);
	x->rs = _merge(x->rs, y);
	if (rand() & 1)std::swap(x->ls, x->rs);
	return x;
}
inline void _pop(register __man *&x) {
	_push_down_(x), x = _merge(x->ls, x->rs);
}

struct __node {
	int f, a, ans;
	long long h, v;
	__man *heap;
} node[300020];

signed main() {

	freopen("fall.in", "r", stdin);
	freopen("fall.out", "w", stdout);

	memset(node, 0, sizeof(node));
	memset(man, 0, sizeof(man));

	int n, m, c;
	scanf("%d%d", &n, &m);
	for (register int i = 1; i <= n; ++i)
		scanf("%lld", &node[i].h);
	for (register int i = 2; i <= n; ++i)
		scanf("%d%d%lld", &node[i].f, &node[i].a, &node[i].v), _add_edge(node[i].f, i);
	for (register int i = 1; i <= m; ++i)
		man[i] = (__man *)calloc(sizeof(__man), 1), man[i]->k = 1, scanf("%lld%d", &man[i]->s, &c), node[c].heap = _merge(node[c].heap, man[i]);

	int vis[300020];
	vis[1] = 1;
	for (register int i = 1, in = 1; i <= m; ++i)
		for (register __edge *j = edge[vis[i]]; j != NULL; j = j->next)
			vis[++in] = j->v;

	for (register int i = m; i > 1; --i) {
		while (node[vis[i]].heap != NULL && node[vis[i]].heap->s < node[vis[i]].h)
			_pop(node[vis[i]].heap), ++node[vis[i]].ans;
		if (node[vis[i]].heap != NULL) {
			if (node[vis[i]].a)
				_modify(node[vis[i]].heap, node[vis[i]].v, 0, 1);
			else
				_modify(node[vis[i]].heap, 1, node[vis[i]].v, 1);
			node[node[vis[i]].f].heap = _merge(node[node[vis[i]].f].heap, node[vis[i]].heap);
		}
	}
	while (node[1].heap != NULL && node[1].heap->s < node[1].h)
		_pop(node[1].heap), ++node[1].ans;
	if (node[1].heap != NULL) {
		_modify(node[1].heap, 1, 0, 1);
		while (node[1].heap != NULL)
			_pop(node[1].heap);
	}

	for (register int i = 1; i <= n; ++i)
		printf("%d\n", node[i].ans);
	for (register int i = 1; i <= m; ++i)
		printf("%d\n", man[i]->ans);

	return 0;
}