/**
 * P3378
 * heap
 */

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

class __heap {

	int cnt = 0;

	struct __node {
		int v;
		__node *s[2], *f;
	}*root;

	inline __node *_build(register int v) {
		register __node *res = (__node *)calloc(sizeof(__node), 1);
		res->v = v;
		return res;
	}

	__node *_merge(__node *x, __node *y) {
		if (x == NULL)return y;
		if (y == NULL)return x;
		if (x->v > y->v)
			std::swap(x, y);
		x->s[0] = _merge(x->s[0], y);
		if (rand() & 1)std::swap(x->s[0], x->s[1]);
		return x;
	}

public:

	inline void _push(register int x) {
		root = _merge(root, _build(x));
	}

	inline void _pop() {
		if (root != NULL)
			root = _merge(root->s[0], root->s[1]);
	}

	inline int _top() {
		return root->v;
	}

} heap;

signed main() {

	freopen("P3378.in", "r", stdin);

	int N, o, x;

	scanf("%d", &N);

	for (register int i = 0; i < N; ++i) {
		scanf("%d", &o);
		switch (o) {
		case 1:
			scanf("%d", &x);
			heap._push(x);
			break;
		case 2:
			printf("%d\n", heap._top());
			break;
		case 3:
			heap._pop();
			break;
		default:;
		}
	}

	return 0;

}
