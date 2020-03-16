/**
 * P3377
 * 随机堆
 */

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

class __heap {

	int cnt = 0;

	struct __node {
		int v;
		bool del;
		__node *ls, *rs, *f;
	}*node[100020] = {NULL};

	__node *_get_(__node *x) {
		if (x->f != x)x->f = _get_(x->f);
		return x->f;
	}

	__node *_merge_(__node *x, __node *y) {
		if (x == NULL)return y;
		if (y == NULL)return x;
		if (x->v > y->v)std::swap(x, y);
		if (rand() & 1)std::swap(x->ls, x->rs);
		x->ls =	_merge_(x->ls, y);
		return x;
	}

public:

	inline void _build(register int x) {
		node[++cnt] = (__node *)calloc(sizeof(__node), 1);
		node[cnt]->v = x;
		node[cnt]->f = node[cnt];
	}

	inline void _merge(register int X, register int Y) {
		register __node *x = _get_(node[X]), *y = _get_(node[Y]);
		if (x->del || y->del || x == y)return ;
		x->f = y->f = _merge_(x, y);
	}

	inline int _top_pop(register int X) {
		if (node[X]->del)return -1;
		register __node *x = _get_(node[X]);
		x->del = true;
		if (x->ls == x->rs)return x->v;
		if (x->ls != NULL)x->ls->f = x->ls;
		if (x->rs != NULL)x->rs->f = x->rs;
		x->f = _merge_(x->ls, x->rs);
		return x->v;
	}

} heap;
int main() {

	freopen("P3377_3.in", "r", stdin);

	int n, m, o, x, y;

	scanf("%d%d", &n, &m);

	for (register int i = 0; i < n; ++i)
		scanf("%d", &x), heap._build(x);

	for (register int i = 0; i < m; ++i) {
		scanf("%d", &o);
		if (o & 1)
			scanf("%d%d", &x, &y), heap._merge(x, y);
		else
			scanf("%d", &x), printf("%d\n", heap._top_pop(x));
	}

	return 0;

}