/**
 * P3369
 * splay
 */

#include <stdio.h>

class __splay {

	struct __node {
		int v, w;
		int s;
		__node *fa, *ls, *rs, **p;
	}*root = NULL;

	inline void _update(__node *x) {//维护SUM值
		x->s = ((x->ls != NULL) ? (x->ls->s) : (0)) + x->w + ((x->rs != NULL) ? (x->rs->s) : (0));
	}

	inline bool _rotate(__node *x) {
		if (x == NULL || x->fa == NULL)return false;
		__node *y = x->fa;
		x->fa = y->fa;
		if (y->fa != NULL) {
			if (y == y->fa->ls)
				y->fa->ls = x;
			else
				y->fa->rs = x;
		} else
			root = x;
		if (x->v < y->v) {
			y->ls = x->rs;
			x->rs->fa = y;
			x->rs = y;
			y->fa = x;
		} else {
			y->rs = x->ls;
			x->ls->fa = y;
			x->ls = y;
			y->fa = x;
		}
		return true;
	}

	void splay(__node *x, __node *y) {

	}

public:

} splay;

signed main() {

	freopen("P3369.in", "r", stdin);



	return 0;

}