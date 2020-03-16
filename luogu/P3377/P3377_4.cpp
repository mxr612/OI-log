/**
 * P3377
 * 可并堆
 */

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

class __heap {

	int cnt = 0;

	struct __node {
		int v, dis, id;
		bool del;
		__node *ls, *rs, *fa;
	}*node[100020] = {NULL};

	__node *_get_(__node *x) {
		if (x->fa != x)
			x->fa = _get_(x->fa);
		return x->fa;
	}

	__node *_merge_(__node *x, __node *y) {
		if (x == NULL)return y;
		if (y == NULL)return x;

		if (x->v > y->v || (x->v == y->v && x->id > y->id))std::swap(x, y);
		x->rs = _merge_(x->rs, y);
		
		// std::swap(x->ls, x->rs);

		// if (rand() & 1)std::swap(x->ls, x->rs);

		// if (x->ls == NULL || (x->rs != NULL && x->ls->dis < x->rs->dis))std::swap(x->ls, x->rs);
		// if (x->rs != NULL)x->dis = x->rs->dis + 1;

		return x;
	}

public:

	inline void _build(register int X) {
		node[++cnt] = (__node *)calloc(sizeof(__node), 1);
		node[cnt]->v = X;
		node[cnt]->id = cnt;
		node[cnt]->fa = node[cnt];
	}

	inline void _merge(register int X, register int Y) {
		if (node[X]->del || node[Y]->del)return ;
		register __node *x = _get_(node[X]), *y = _get_(node[Y]);
		if (x == y)return ;
		x->fa = y->fa = _merge_(x, y);
	}

	inline int _top_pop(register int X) {
		if (node[X]->del)return -1;
		register __node *x = _get_(node[X]);
		x->del = true;
		x->fa = _merge_(x->ls, x->rs);
		if (x->fa != NULL)x->fa->fa = x->fa;
		return x->v;
	}


} heap;

signed main() {

	freopen("P3377.in", "r", stdin);

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