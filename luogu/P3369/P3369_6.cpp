/**
 * P3369
 * splay
 */

#include <stdio.h>
#include <stdlib.h>

class __splay {

	struct __node {
		int v, w, s;
		__node *fa, *ls, *rs, **pt;
	}*root = NULL;

	inline void _rotate(register __node *x) {
		if (x == NULL || x->fa == NULL)return ;
		register __node *y = x->fa, **s = ((x == x->fa->ls) ? (&x->rs) : (&x->ls));
		if (*s != NULL) {
			(*s)->fa = x->fa;
			(*s)->pt = x->pt;
			*(*s)->pt = (*s);
		} else
			*x->pt = NULL;
		x->fa = y->fa;
		x->pt = y->pt;
		*x->pt = x;
		y->fa = x;
		y->pt = s;
		*y->pt = y;
		x->s = ((x->ls == NULL) ? (0) : (x->ls->s)) + x->w + ((x->rs == NULL) ? (0) : (x->rs->s));
		y->s = ((y->ls == NULL) ? (0) : (y->ls->s)) + y->w + ((y->rs == NULL) ? (0) : (y->rs->s));
	}

	void _splay(__node *x, __node **p) {
		if (x == NULL)return ;
		while (x != *p)
			if (x->fa == *p)_rotate(x);
			else if ((x == x->fa->ls) == (x->fa == x->fa->fa->ls))
				_rotate(x->fa), _rotate(x);
			else _rotate(x), _rotate(x);
	}

public:

	void _insert(register int v) {
		register __node **x = &root, *f = NULL;
		while ((*x) != NULL && (*x)->v != v)
			if (v < (*x)->v)f = *x, x = &(*x)->ls;
			else f = *x, x = &(*x)->rs;
		if (*x == NULL)
			*x = (__node *)calloc(sizeof(__node), 1), (*x)->v = v, (*x)->pt = x, (*x)->fa = f;
		_splay(*x, &root);
		++root->w, ++root->s;
	}

	void _delete(register int v) {
		register __node *x = root;
		while (x != NULL && x->v != v)
			if (v < x->v)x = x->ls;
			else x = x->rs;
		if (x == NULL)return ;
		_splay(x, &root);
		--x->w, --x->s;
		if (x->w == 0) {
			if (x->ls == x->rs)
				*x->pt = NULL;
			else if (x->ls == NULL)
				x->rs->fa = NULL, x->rs->pt = &root, root = x->rs;
			else if (x->rs == NULL)
				x->ls->fa = NULL, x->ls->pt = &root, root = x->ls;
			else {
				x = x->rs;
				while (x->ls != NULL)x = x->ls;
				_splay(x, &root->rs);
				if (root->ls != NULL)root->ls->fa = x, root->ls->pt = &x->ls;
				x->ls = root->ls, x->fa = NULL, x->pt = &root, root = x;
			}
			if (root != NULL)
				root->s = ((root->ls == NULL) ? (0) : (root->ls->s)) + root->w + ((root->rs == NULL) ? (0) : (root->rs->s));
		}
	}

	int _n2r(register int v) {
		register __node *x = root, *f = NULL;
		while (x != NULL && x->v != v)
			if (v < x->v)f = x, x = x->ls;
			else f = x, x = x->rs;
		if (x == NULL)x = f;
		_splay(x, &root);
		if (v <= x->v)
			return ((x->ls == NULL) ? (0) : (x->ls->s)) + 1;
		else
			return ((x->ls == NULL) ? (0) : (x->ls->s)) + x->w + 1;
	}

	int _r2n(register int r) {
		register __node *x = root;
		while (r > 0)
			if (r <= ((x->ls == NULL) ? (0) : (x->ls->s)))
				x = x->ls;
			else if (r <= ((x->ls == NULL) ? (0) : (x->ls->s)) + x->w)
				r = 0;
			else r -= ((x->ls == NULL) ? (0) : (x->ls->s)) + x->w, x = x->rs;
		_splay(x, &root);
		return x->v;
	}

	int _last(int v) {
		register __node *x = root , *f = NULL;
		register int res;
		while (x != NULL)
			if (v <= x->v)f = x, x = x->ls;
			else res = x->v, f = x, x = x->rs;
		_splay(f, &root);
		return res;
	}

	int _next(int v) {
		register __node *x = root , *f = NULL;
		register int res;
		while (x != NULL)
			if (v < x->v)res = x->v, f = x, x = x->ls;
			else f = x, x = x->rs;
		_splay(f, &root);
		return res;
	}

} splay;

signed main() {

	freopen("P3369_11.in", "r", stdin);

	int n, o, x;

	scanf("%d", &n);

	for (register int i = 0; i < n; ++i) {
		scanf("%d%d", &o, &x);
		switch (o) {
		case 1:
			splay._insert(x);
			break;
		case 2:
			splay._delete(x);
			break;
		case 3:
			printf("%d\n", splay._n2r(x));
			break;
		case 4:
			printf("%d\n", splay._r2n(x));
			break;
		case 5:
			printf("%d\n", splay._last(x));
			break;
		case 6:
			printf("%d\n", splay._next(x));
			break;
		default:
			break;
		}
	}

	return 0;

}