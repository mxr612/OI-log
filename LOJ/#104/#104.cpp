/**
 * LOJ
 * #104
 * 普通平衡树
 * Splay
 */

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

class __splay {

	struct __node {
		int v, w, s;
		__node *ls, *rs, *fa, **pt;
	}*root = NULL;

	inline void _rotate(register __node *x) {
		if (x == NULL || x->fa == NULL)return;
		register __node *y = x->fa, **s = (x == y->ls) ? (&x->rs) : (&x->ls);
		if (*s != NULL)(*s)->fa = y, (*s)->pt = x->pt; *x->pt = *s;
		x->pt = y->pt, x->fa = y->fa, *y->pt = x;
		y->pt = s, y->fa = x, *s = y;
		y->s = ((y->ls == NULL) ? (0) : (y->ls->s)) + y->w + ((y->rs == NULL) ? (0) : (y->rs->s));
		x->s = ((x->ls == NULL) ? (0) : (x->ls->s)) + x->w + ((x->rs == NULL) ? (0) : (x->rs->s));
	}

	void _splay(__node *x, __node **p) {
		if (x == NULL || x->fa == NULL)return;
		while (x->fa != NULL && x != *p)
			if (x->fa == *p)_rotate(x);
			else if ((x == x->fa->ls) == (x->fa == x->fa->fa->ls))_rotate(x->fa), _rotate(x);
			else _rotate(x), _rotate(x);
	}

public:

	inline void _insert(register int v) {
		register __node **x = &root, *y = NULL;
		while (*x != NULL && (*x)->v != v)
			if (v < (*x)->v)y = *x, x = &(*x)->ls;
			else y = *x, x = &(*x)->rs;
		if (*x == NULL)(*x) = (__node*)calloc(sizeof(__node), 1), (*x)->v = v, (*x)->fa = y, (*x)->pt = x;
		_splay(*x, &root);
		++root->w, ++root->s;
	}

	inline void _delete(register int v) {
		register __node *x = root;
		while (x != NULL && x->v != v)
			if (v < x->v)x = x->ls;
			else x = x->rs;
		if (x == NULL)return;
		_splay(x, &root), --x->w, --x->s;
		if (x->w > 0)return;
		if (x->rs == NULL)root = x->ls, root->fa = NULL, root->pt = &root;
		else if (x->ls == NULL)root = x->rs, root->fa = NULL, root->pt = &root;
		else {
			x = x->rs;
			while (x->ls != NULL)x = x->ls;
			_splay(x, &root->rs);
			root->ls->fa = x, root->ls->pt = &x->ls, x->ls = root->ls;
			root = x->rs, root->fa = NULL, root->pt = &root;
		}
	}

	inline int _query_rnk(register int x) {return 0;}
	inline int _query_num(register int x) {return 0;}
	inline int _query_pre(register int x) {return 0;}
	inline int _query_nxt(register int c) {return 0;}

} splay;

signed main() {

#ifndef ONLINE_JUDGE
	freopen("#104.in", "r", stdin);
#endif

	int n, o, x;

	scanf("%d", &n);
	
	for (register int i = 0; i < n; ++i) {
		scanf("%d%d", &o, &x);
		switch (o) {
		case 1:
			splay._insert(x);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			;
		}
	}

	return 0;

}