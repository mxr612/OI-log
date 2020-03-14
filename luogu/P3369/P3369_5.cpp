/**
 * 绝对是最后一遍不过我表白DYQ
 */

#include <stdio.h>
#include <stdlib.h>

class __splay {
	struct __node {
		int v, w, s;
		__node *fa, *ls, *rs, **pt;
	}*root = NULL;

	inline void _update(__node *x) {
		x->s = ((x->ls == NULL) ? (0) : (x->ls->s)) + x->w + ((x->rs == NULL) ? (0) : (x->rs->s));
	}

	inline void _rotate(__node *x) {
		if (x == NULL || x->fa == NULL)return ;
		register __node *y = x->fa, **s = ((x == x->fa->ls) ? (&x->rs) : (&x->ls));
		if (*s != NULL) {
			(*s)->fa = x->fa;
			(*s)->pt = x->pt;
			*(*s)->pt = *s;
		} else
			*x->pt = NULL;
		x->fa = y->fa;
		x->pt = y->pt;
		*x->pt = x;
		y->fa = x;
		y->pt = s;
		*y->pt = y;
		_update(y);
		_update(x);
	}

	void _print(__node *x) {
		if (x == NULL)return ;
		_print(x->ls);
		printf("|%7d %7d|", x->v, x->s);
		_print(x->rs);
	}

	void _splay(register __node *x, register __node **p) {
		if (x == NULL)return ;
		while (x != *p) {
			if (x->fa == *p)
				_rotate(x);
			else if ((x == x->fa->ls) == (x->fa == x->fa->fa->ls))
				_rotate(x->fa), _rotate(x);
			else
				_rotate(x), _rotate(x);
		}
		// _print(root);
		// printf("\n");
	}

public:

	void _insert(register int v) {
		register __node **x = &root, *f = NULL;
		while ((*x) != NULL && (*x)->v != v)
			if (v < (*x)->v)f = (*x), x = &(*x)->ls;
			else f = (*x), x = &(*x)->rs;
		if (*x == NULL)
			*x = (__node *)calloc(sizeof(__node), 1), (*x)->v = v, (*x)->fa = f, (*x)->pt = x;
		_splay(*x, &root);
		++root->w, ++root->s;
	}

	void _delete(register int v) {
		register __node *x = root;
		while (x != NULL && x->v != v)
			if (v < x->v)x = x->ls;
			else x = x->rs;
		if (x != NULL) {
			_splay(x, &root);
			--x->w;
			if (root == x && x->w == 0) {
				if (x->ls == x->rs)
					*x->pt = NULL;
				else if (x->ls == NULL)
					x->rs->fa = x->fa, x->rs->pt = x->pt, *x->pt = x->rs;
				else if (x->rs == NULL)
					x->ls->fa = x->fa, x->ls->pt = x->pt, *x->pt = x->ls;
				else {
					x = x->rs;
					while (x->ls != NULL)x = x->ls;
					_splay(x, &root->rs);
					printf("%p\n", &x->ls);
					// x->ls = root->ls;
					// if (x->ls != NULL)x->ls->pt = &x->ls;
					// x->fa = NULL;
					// x->pt = &root;
					// root = x;
				}

			}
			_update(root);
		}
	}

} splay;

signed main() {

	freopen("P3369_2.in", "r", stdin);
	// freopen("P3369.out", "w", stdout);

	int n, o, x;

	scanf("%d", &n);

	for (register int i = 0; i < n; ++i) {
		scanf("%d%d", &o, &x);
		printf("%d\n", i);
		switch (o) {
		case 1:
			splay._insert(x);
			break;
		case 2:
			splay._delete(x);
			break;
		case 3:
			break;
		case 4:
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