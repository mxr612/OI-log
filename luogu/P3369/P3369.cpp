/**
 * P3369
 * BST
 */

#include <stdio.h>
#include <stdlib.h>

class __BST {

	struct __node {
		int v, w;
		int size;
		__node *ls, *rs;
	}*root = NULL;

	void _insert(__node *&x, int v) {
		if (x == NULL) {
			x = (__node *)calloc(sizeof(__node), 1);
			x->v = v;
			x->w = 1;
		} else if (v < x->v)
			_insert(x->ls, v);
		else if (x->v < v)
			_insert(x->rs, v);
		else
			++x->w;
		++x->size;
	}

	__node **_next(__node *x) {
		if (x->rs == NULL || x->rs->ls == NULL)return &x->rs;
		register __node *i = x->rs;
		while (i->ls->ls != NULL)i = i->ls;
		return &i->ls;
	}

	void _delete(__node *&x, int v) {
		if (x == NULL)
			return ;
		else if (v < x->v)
			_delete(x->ls, v);
		else if (x->v < v)
			_delete(x->rs, v);
		else {
			--x->w;
			if (x->w == 0) {
				if (x->ls == NULL)
					x = x->rs;
				else if (x->rs == NULL)
					x = x->ls;
				else {
					__node **cmp = _next(x);
					(*cmp)->ls = x->ls;
					(*cmp)->rs = x->rs;
					x = *cmp;
					*cmp = NULL;
				}
			}
		}
		--x->size;
	}

	inline int _lsize(__node *x) {
		return ((x->ls == NULL) ? (0) : (x->ls->size));
	}

	int _query_n2r(__node *x, int v) {
		if (v < x->v)
			return _query_n2r(x->ls, v) + _lsize(x);
		else if (x->v < v)
			return _query_n2r(x->rs, v) + _lsize(x) + x->w;
		else
			return 0;
	}

	int _query_r2n(__node *x, int r, int now) {
		if (r <= now + _lsize(x))
			return _query_r2n(x->ls, r, now);
		else if (r <= now + _lsize(x) + x->w)
			return x->v;
		else
			return _query_r2n(x->rs, r, now + _lsize(x) + x->w);
	}

	int _query_last(__node *x, int v, int ans) {
		if (x == NULL)
			return ans;
		else if (x->v < v)
			return _query_last(x->rs, v, x->v);
		else
			return _query_last(x->ls, v, ans);
	}

	int _query_next(__node *x, int v, int ans) {
		if (x == NULL)
			return ans;
		else if (v < x->v)
			return _query_next(x->ls, v, x->v);
		else
			return _query_next(x->rs, v, ans);

	}

public:

	void _insert(int v) {
		_insert(root, v);
	}

	void _delete(int v) {
		_delete(root, v);
	}

	int _query_n2r(int v) {
		return _query_n2r(root, v);
	}

	int _query_r2n(int r) {
		return _query_r2n(root, r, 0);
	}

	int _query_last(int v) {
		return _query_last(root, v, 0);
	}

	int _query_next(int v) {
		return _query_next(root, v, 0);

	}

} BST;

int main() {

	freopen("P3369.in", "r", stdin);

	int n, opt, x;

	scanf("%d", &n);

	for (register int i = 0; i < n; ++i) {
		scanf("%d%d", &opt, &x);
		switch (opt) {
		case 1:
			BST._insert(x);
			break;
		case 2:
			BST._delete(x);
			break;
		case 3:
			printf("%d\n", BST._query_n2r(x));
			break;
		case 4:
			printf("%d\n", BST._query_r2n(x));
			break;
		case 5:
			printf("%d\n", BST._query_last(x));
			break;
		case 6:
			printf("%d\n", BST._query_next(x));
			break;
		default:;
		}
	}

	return 0;
}