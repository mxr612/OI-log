/**
 * splay
 */

#include <stdio.h>
#include <stdlib.h>

class __splay {

	struct __node {
		int v, w, s;
		__node *fa, *ls, *rs, **pt;
	}*root = NULL;

	void _print(__node *x) {
		if (x == NULL)return ;
		_print(x->ls), printf("|%d %d|", x->v, x->s), _print(x->rs);
	}

	inline void _update(__node *x) {x->s = ((x->ls == NULL) ? (0) : (x->ls->s)) + x->w + ((x->rs == NULL) ? (0) : (x->rs->s));}

	inline void _rotate(register __node *x) {
		if (x == NULL || x->fa == NULL)return ;
		register __node *y = x->fa, **s = ((x == x->fa->ls) ? (&x->rs) : (&x->ls));
		if (*s != NULL) {
			(*s)->pt = x->pt;
			(*s)->fa = x->fa;
			*(*s)->pt = *s;
		} else
			*x->pt = NULL;
		x->pt = y->pt;
		x->fa = y->fa;
		*x->pt = x;
		y->pt = s;
		y->fa = x;
		*y->pt = y;
		_update(y);
		_update(x);
	}

	void _splay(register __node *x, register __node **p) {
		if (x == NULL)return ;
		while (x != *p)
			if (x->fa == *p)_rotate(x);
			else if ((x == x->fa->ls) == (x->fa == x->fa->fa->ls))
				_rotate(x->fa), _rotate(x);
			else
				_rotate(x), _rotate(x);
		// _print(root);
		// printf("\n");
	}

public:

	void _insert(register int v) {
		register __node *f = NULL, **x = &root;
		while ((*x) != NULL && (*x)->v != v)
			if (v < (*x)->v) f = (*x), x = &(*x)->ls;
			else f = (*x), x = &(*x)->rs;
		while ((*x) == NULL)(*x) = (__node *)calloc(sizeof(__node), 1), (*x)->v = v, (*x)->fa = f, (*x)->pt = x;
		++(*x)->w, ++(*x)->s;
		_splay(*x, &root);
	}

	void _delete(register int v) {
		register __node *x = root;
		while (x != NULL && x->v != v)
			if (v < x->v)x = x->ls;
			else x = x->rs;
		if (x != NULL) {
			--x->w, --x->s;
			if (x->w == 0) {
				if (x->ls == x->rs)
					*x->pt = NULL;
				else if (x->rs == NULL)
					*x->pt = x->ls;
				else if (x->ls == NULL)
					*x->pt = x->rs;
				else {
					register __node *g = x->rs;
					while (g->ls != NULL)g = g->ls;
					_splay(g, &x->rs);
					g->pt = x->pt;
					g->fa = x->fa;
					*g->pt = g;
					g->ls = x->ls;
					x = g;
					_update(x);
				}
			}
			_splay(x, &root);
		}
	}

	int _n2r(register int v) {
		register __node *x = root;
		register int res = 1;
		while (x != NULL && x->v != v)
			if (v < x->v)x = x->ls;
			else res += ((x->ls == NULL) ? (0) : (x->ls->s)) + x->w, x = x->rs;
		return res + ((x == NULL || x->ls == NULL) ? (0) : (x->ls->s));
	}

	int _r2n(register int r) {
		register __node *x = root;
		while (r > 0)
			if (r <= ((x->ls == NULL) ? (0) : (x->ls->s)))
				x = x->ls;
			else if (r <= ((x->ls == NULL) ? (0) : (x->ls->s)) + x->w)
				r = 0;
			else r -= ((x->ls == NULL) ? (0) : (x->ls->s)) + x->w, x = x->rs;
		return x->v;
	}

	int _last(register int v) {
		register __node *x = root;
		register int res;
		while (x != NULL && x->v != v)
			if (v < x->v)x = x->ls;
			else res = x->v, x = x->rs;
		if (x != NULL)x = x->ls;
		while (x != NULL)res = x->v, x = x->rs;
		return res;
	}

	int _next(register int v) {
		register __node *x = root;
		register int res;
		while (x != NULL && x->v != v)
			if (v < x->v)res = x->v, x = x->ls;
			else x = x->rs;
		if (x != NULL)x = x->rs;
		while (x != NULL)res = x->v, x = x->ls;
		return res;
	}

} splay;

signed main() {

	freopen("P3369_3.in", "r", stdin);

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