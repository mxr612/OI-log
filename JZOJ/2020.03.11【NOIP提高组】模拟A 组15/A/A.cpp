/**
 * A
 */

#include <stdio.h>
#include <algorithm>

typedef unsigned long long ULL;

int m, n, G = 0;
int X, A, B, C, K;
ULL pre = 1;

struct __work {
	int s, e, p;
	int r, h;
} work[100020];
ULL map[100020];

inline bool _cmp1(__work x, __work y) {return x.p < y.p;}
inline bool _cmp2(__work x, __work y) {return x.r < y.r;}

struct __modify {
	int t, v, w;
} modify[200020];

inline bool _cmp3(__modify x, __modify y) {return x.t < y.t;}

class __tree {

	struct __node {
		int w;
		bool m;
		__node *ls, *rs;
	};

	__node *root[100020] = {NULL}, *T = NULL;

	void _build_tree(__node *&x, int l, int r) {
		if (r < l)return ;
		x = (__node *)calloc(sizeof(__node), 1);
		if (l == r)return ;
		_build_tree(x->ls, l, (l + r) / 2);
		_build_tree(x->rs, (l + r) / 2 + 1, r);
	}

	void _insert(__node *&x, int V, int W, int l, int r) {
		if (r < l || r < V || V < l)return ;
		while (x == NULL)x = (__node *)calloc(sizeof(__node), 1);
		x->w += W;
		x->m = true;
		if (l == r)return ;
		if (V <= (l + r) / 2)
			_insert(x->ls, V, W, l, (l + r) / 2);
		else
			_insert(x->rs, V, W, (l + r) / 2 + 1, r);
	}

	void _merge(__node *H, __node *&x, __node *X) {
		if (H == NULL)return ;
		if (X->m) {
			x = (__node *)calloc(sizeof(__node), 1);
			x->w = H->w + X->w;
			X->w = 0;
			X->m = false;
			_merge(H->ls, x->ls, X->ls);
			_merge(H->rs, x->rs, X->rs);
		} else
			x = H;
	}

	ULL _sum(__node *x, int &K, int l, int r) {
		if (x == NULL || x->w == 0 || r < l || K == 0)return 0;
		ULL cmp = 0;
		if (l == r) {
			if (x->w <= K) {
				K -= x->w;
				return map[l] * x->w;
			} else {
				cmp = K;
				K = 0;
				return map[l] * cmp;
			}
		} else {
			cmp += _sum(x->ls, K, l, (l + r) / 2);
			cmp += _sum(x->rs, K, (l + r) / 2 + 1, r);
			return cmp;
		}
	}

public:

	inline void _build_tree() {_build_tree(root[0], 0, G); _build_tree(T, 0, G);}
	inline void _insert(int v, int w) {_insert(T, v, w, 0, G);}
	inline void _update(int e) {_merge(root[e], root[e + 1], T);}
	inline ULL _query(int T, int K) {return _sum(root[T + 1], K, 0, G);}

} tree;

signed main() {

	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);

	scanf("%d%d", &m, &n);

	for (register int i = 0; i < m; ++i)
		scanf("%d%d%d", &work[i].s, &work[i].e, &work[i].p), work[i].r = i;

	std::sort(work, work + n + 1, _cmp1);
	map[G] = work[0].p;
	for (register int i = 1; i < m; ++i)
		work[i].h = (work[i - 1].p < work[i].p) ? ++G : G, map[G] = work[i].p;

	for (register int i = 0, k = -1; i < m; ++i) {
		modify[++k].t = work[i].s;
		modify[k].v = work[i].h;
		modify[k].w = 1;
		modify[++k].t = work[i].e+1;
		modify[k].v = work[i].h;
		modify[k].w = -1;
	}

	std::sort(modify, modify + (m << 1), _cmp3);

	tree._build_tree();
	for (register int i = 0, j = 0; i <= n; ++i) {
		for (; modify[j].t == i; ++j)
			tree._insert(modify[j].v, modify[j].w);
		tree._update(i);
	}

	for (register int i = 0; i < n; ++i) {
		scanf("%d%d%d%d", &X, &A, &B, &C);
		K = 1 + (A * pre + B) % C;
		pre = tree._query(X, K);
		printf("%d\n", pre);
	}

	return 0;

}