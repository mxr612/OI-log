/**
 * B
 * JZOJ 4081. 【JLOI2015】城池攻占(fall)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

struct __edge {
	int x;
	long long a, v;
	__edge *next;
} *edge[300020] = {NULL};

inline void _add_edge(register int y, register int x) {
	register __edge *p = (__edge *)calloc(sizeof(__edge), 1);
	p->x = x;
	p->next = edge[y];
	edge[y] = p;
}

struct __man {
	long long s;
	int ans;
	long long k, b, g;
	__man *ls, *rs;
} man[300020];

inline void _push(__man *x) {
	x->s = x->k * x->s + x->b, x->ans += x->g;
	if (x->ls != NULL)
		x->ls->k *= x->k, x->ls->b = x->k * x->ls->b + x->b, x->ls->g += x->g;
	if (x->rs != NULL)
		x->rs->k *= x->k, x->rs->b = x->k * x->rs->b + x->b, x->rs->g += x->g;
	x->k = 1, x->b = 0, x->g = 0;
}

__man *_merge(__man *x, __man *y) {
	if (x == NULL)return y; else _push(x);
	if (y == NULL)return x; else _push(y);
	if (x->s > y->s)std::swap(x, y);
	x->ls = _merge(x->ls, y);
	if (rand() & 1)std::swap(x->ls, x->rs);
	return x;
}

inline int _top(__man * x) {
	_push(x);
	return x->s;
}
inline void _pop(__man *&x) {
	_push(x);
	x = _merge(x->ls, x->rs);
}

struct __node {
	long long h, v;
	int  a, f, ans;
	__man *heap = NULL;
} node[300020];

signed main() {

	freopen("fall1.in", "r", stdin);
	freopen("fall.out", "w", stdout);

	memset(man, 0, sizeof(man));
	memset(node, 0, sizeof(node));

	int n, m, c;
	scanf("%d%d", &n, &m);
	for (register int i = 1; i <= n; ++i)
		scanf("%lld", &node[i].h);
	for (register int i = 2; i <= n; ++i)
		scanf("%d%d%lld", &node[i].f, &node[i].a, &node[i].v), _add_edge(node[i].f, i);
	for (register int i = 1; i <= m; ++i)
		scanf("%lld%d", &man[i].s, &c), man[i].k = 1, node[c].heap = _merge(node[c].heap, &man[i]);

	int vis[300020];
	vis[0] = 1;
	for (register int i = 0, in = 1; i < m; ++i)
		for (register __edge *j = edge[i]; j != NULL; j = j->next)
			vis[in++] = j->x;

	for (register int i = m - 1; i > 0; --i) {
		while (node[vis[i]].heap != NULL && _top(node[vis[i]].heap) < node[vis[i]].h)
			_pop(node[vis[i]].heap), ++node[vis[i]].ans;
		if (node[vis[i]].heap != NULL) {
			if (node[vis[i]].a)
				node[vis[i]].heap->k *= node[vis[i]].v, node[vis[i]].heap->b *= node[vis[i]].v;
			else
				node[vis[i]].heap->b += node[vis[i]].v;
			++node[vis[i]].heap->g;
			node[node[vis[i]].f].heap = _merge(node[node[vis[i]].f].heap, node[vis[i]].heap);
		}
	}
	while (node[1].heap != NULL && _top(node[1].heap) < node[1].h)
		_pop(node[1].heap), ++node[1].ans;
	if (node[1].heap != NULL) {
		++node[1].heap->g;
		while (node[1].heap != NULL)
			_pop(node[1].heap);
	}

	for (register int i = 1; i <= n; ++i)
		printf("%d\n", node[i].ans);
	for (register int i = 1; i <= m; ++i)
		printf("%d\n", man[i].ans);

	return 0;

}