/**
 * P3369
 * splay
 */

#include <stdio.h>
#include <stdlib.h>

class __splay {

	struct __node {
		int v, w;
		int s;
		__node *f, *l, *r, **p;
	}*root = NULL;

	inline void _rotate(__node *x) {
		if (x == NULL || x->f == NULL)return ;
		register __node *y = x->f, **s = ((x == y->l) ? (&x->r) : (&x->l));
		if (*s != NULL) {
			(*s)->p = x->p;
			*(*s)->p = *s;
			(*s)->f = x->f;
			*s = y;
		} else
			x->p = NULL;
		x->p = y->p;
		x->f = y->f;
		*x->p = x;
		y->f = x;
		x->s = ((x->l == NULL) ? (0) : (x->l->s)) + x->w + ((x->r == NULL) ? (0) : (x->r->s));
		y->s = ((y->l == NULL) ? (0) : (y->l->s)) + y->w + ((y->r == NULL) ? (0) : (y->r->s));
	}

	void _print(__node *x) {
		if (x == NULL)return ;
		_print(x->l);
		printf("%d ", x->v);
		_print(x->r);
	}

	void _splay(register __node *x, register __node **p) {
		if (x == NULL)return ;
		while (x != (*p)) {
			if (x->f->p == p)
				_rotate(x);
			else if ((x == x->f->l) == (x->f == x->f->f->l)) {
				_rotate(x->f);
				_rotate(x);
			}
			else {
				_rotate(x);
				_rotate(x);
			}
		}
		_print(root);
		printf("\n");
	}

	__node *_insert(__node **x, __node *f, int v) {
		if ((*x) == NULL) {
			while ((*x) == NULL)(*x) = (__node *)calloc(sizeof(__node), 1);
			(*x)->v = v;
			(*x)->f = f;
			(*x)->p = x;
			return *x;
		} else {
			++(*x)->s;
			if (v < (*x)->v)
				return _insert(&(*x)->l, *x, v);
			else if ((*x)->v < v)
				return _insert(&(*x)->r, *x, v);
			else {
				++(*x)->w;
				return *x;
			}
		}
	}

	__node *_delete(__node *x, int v) {
		if (x == NULL)return NULL;
		--x->s;
		if (v < x->v)
			return _delete(x->l, v);
		else if (x->v < v)
			return _delete(x->r, v);
		else {
			if (--x->w == 0) {
				if (x->l == x->r)
					*x->p = NULL;
				else if (x->l == NULL) {
					x->r->p = x->p;
					x->r->f = x->f;
					*x->p = x->r;
				} if (x->r == NULL) {
					x->l->p = x->p;
					x->l->f = x->f;
					*x->p = x->l;
				} else {
					register __node *g = x->r;
					while (g->l != NULL)g = g->l;
					if (g->l == g->r)
						*g->p = NULL;
					else {
						x->r->p = x->p;
						x->r->f = x->f;
						*x->p = x->r;
					}
					g->p = x->p;
					g->l = x->l;
					g->r = x->r;
					*x->p = g;
				}
				return NULL;
			} else
				return x;
		}
	}

	__node *_n2r(__node *x, int v, int s) {
		if (x != NULL) {
			if (v < x->v)
				return _n2r(x->l, v, s);
			if (x->v < v)
				return _n2r(x->r, v, ((x->l == NULL) ? (0) : (x->l->s)) + x ->w + s);
		}
		printf("%d\n", s);
		return x;
	}

	__node *_r2n(__node *x, int r) {
		if (x == NULL)return NULL;
		if (r <= ((x->l == NULL) ? (0) : (x->l->s)))
			return _r2n(x->l, r);
		if (r <= ((x->l == NULL) ? (0) : (x->l->s)) + x->w) {
			printf("%d\n", x->v);
			return x;
		}
		return _r2n(x->r, r - ((x->l == NULL) ? (0) : (x->l->s)) - x->w);
	}

public:

	inline void _insert(int v) {_splay(_insert(&root, NULL, v), &root);}
	inline void _delete(int v) {_splay(_delete(root, v), &root);}
	inline void _n2r(int v) {_splay(_n2r(root, v, 1), &root);}
	inline void _r2n(int r) {_splay(_r2n(root, r), &root);}

} splay;

signed main() {

	freopen("P3369.in", "r", stdin);
	// freopen("P3369.out", "w", stdout);

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
			splay._n2r(x);
			break;
		case 4:
			// splay._r2n(x);
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			break;
		}
	}

	return 0;

}