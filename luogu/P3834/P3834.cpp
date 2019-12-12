/**
 * P3834 【模板】可持久化线段树 1（主席树）
 */

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int n, m, z = 0;
struct __lsh {
	int u, v, w;
} a[200020];
int fl[200020];
int _cmps1(__lsh x, __lsh y) {return x.u < y.u;}
int _cmps2(__lsh x, __lsh y) {return x.w < y.w;}

struct __node {
	int w;
	__node *l, *r, *x;
}*root[200020] = {NULL};

__node *_build_tree(int L, int R) {
	if (R < L)
		return NULL;
	__node *p = NULL;
	while (p == NULL)p = (__node *)calloc(1, sizeof(__node));
	if (L == R)
		return p;
	p->l = _build_tree(L, (L + R) / 2);
	p->r = _build_tree((L + R) / 2 + 1, R);
	return p;
}
__node *_update(__node *P, int l, int r, int G) {
	if (r < l || r < G || G < l)
		return NULL;
	__node *p = NULL;
	while (p == NULL)p = (__node *)calloc(1, sizeof(__node));
	P->x = p, p->w = P->w + 1;
	if (l == r)
		return p;
	if (G <= (l + r) / 2)
		p->l = _update(P->l, l, (l + r) / 2, G), p->r = P->r;
	else
		p->l = P->l, p->r = _update(P->r, (l + r) / 2 + 1, r, G);
	return p;
}
int _vis(__node *L, __node *R, int K, int l, int r) {
	if (l == r)
		return r;
	if (K <= (R->l->w - L->l->w))
		return _vis(L->l, R->l, K, l, (l + r) / 2);
	return _vis(L->r, R->r, K - (R->l->w - L->l->w), (l + r) / 2 + 1, r);
}
void _free(__node *&p) {
	if (p == NULL)return ;
	for (__node *b = p->x, *c; b != NULL;)
		c = b, b = b->x, free(c);
	_free(p->l), _free(p->r), free(p), p = NULL;
}

signed main() {
	freopen("testdata.in", "r", stdin);
	freopen("P3834.out", "w", stdout);
	scanf("%d%d", &n, &m);
	a[0].u = -(1e9) - 1;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i].u), a[i].w = i;
	std::sort(&a[1], &a[n + 1], _cmps1);
	for (int i = 1; i <= n; ++i)
		a[i].v = (a[i - 1].u < a[i].u) ? ++z : z, fl[z] = a[i].u;
	std::sort(&a[1], &a[n + 1], _cmps2);
	root[0] = _build_tree(1, z);
	for (int i = 1; i <= n; ++i)
		root[i] = _update(root[i - 1], 1, z, a[i].v);
	for (int i = 1, l, r, k; i <= n; ++i)
		scanf("%d%d%d", &l, &r, &k), printf("%d\n", fl[_vis(root[l - 1], root[r], k, 1, z)]);
	_free(root[0]);
	return 0;
}