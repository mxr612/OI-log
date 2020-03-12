/**
 * B
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;

ULL n;

class __graph {

	ULL ans = -1;

	struct __edge {
		int v, w;
		ULL path;
		__edge *next, *re;
	} *edge[1000020];

	inline void _conect(__edge *x, __edge *y) {
		x->re = y, y->re = x;
	}

	__edge *_add_edge_(int u, int v) {
		__edge *p = (__edge *)calloc(sizeof(__edge), 1);
		p->v = v;
		p->next = edge[u];
		edge[u] = p;
		return p;
	}

	int _dfs_1(int x, int f) {
		int size = 1;
		for (__edge *i = edge[x]; i != NULL; i = i->next) {
			if (i->v == f)continue;
			i->w = _dfs_1(i->v, x);
			i->re->w = n - i->w;
			size += i->w;
		}
		return size;
	}

	void _dfs_2(int x, int f, int siz, ULL &res) {
		--siz;
		// printf("%d\n", siz);
		for (__edge *i = edge[x]; i != NULL && res < ans; i = i->next) {
			if (i->v == f)continue;
			res += i->w * (siz - i->w);
			siz -= i->w;
			// printf("%d %d\n", i->v, siz);
			_dfs_2(i->v, x, i->w, res);
		}
	}

	inline ULL min(ULL x, ULL y) {
		return x < y ? x : y;
	}

public:

	inline void _add_edge(int x, int y) {
		_conect(_add_edge_(x, y), _add_edge_(y, x));
	}

	inline void _get_size() {
		_dfs_1(1, 0);
	}

	ULL _get_ans() {
		ULL res;
		for (register int i = 1; i <= n; ++i) {
			res = 0;
			_dfs_2(i, 0, n, res);
			printf(" %llu\n", res);
			ans = min(ans, res);
		}
		return ans + (n * (n - 1)) / 2;
	}

} graph;

signed main() {

	freopen("data5.in", "r", stdin);

	int x, y;

	scanf("%llu", &n);

	for (register int i = 1; i < n; ++i)
		scanf("%d%d", &x, &y), graph._add_edge(x, y);

	graph._get_size();

	printf("%llu\n", graph._get_ans());

	return 0;

}