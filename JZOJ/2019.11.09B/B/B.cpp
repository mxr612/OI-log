

#include <stdio.h>
#include <algorithm>

int n, m, q;

struct __edge {
	int u, v, w;
	bool operator<(__edge x) {return w < x.w;}
} edge[100020];
struct __bin {
	int fa[10020], size[10020];
	void operator<<(int x) {fa[x] = x, size[x] = 1;}
	int _root(int x) {
		if (fa[x] != x)
			fa[x] = _root(fa[x]);
		return fa[x];
	} int operator[](int x) {return _root(x);}
	void operator()(int x, int y) {
		if (_root(x) != _root(y)) {
			if (size[fa[x]] < size[fa[y]])
				fa[x] = fa[y], size[fa[y]] += size[fa[x]];
			else
				fa[y] = fa[x], size[fa[x]] += size[fa[y]];
		}
	}
} bin, use;

int main() {
	freopen("B.in", "r", stdin);
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
	std::sort(&edge[1], &edge[m + 1]);
	for (int i = 1; i <= n; ++i)
		bin << i;
	for (int i = 1, x, y, j; i <= q; ++i) {
		scanf("%d%d", &x, &y);
		use = bin;
		for (int i = 1; i <= n; ++i)
			printf("%d", use[i]);
		for (j = 1; use[x] != use[y] && j <= m; ++j)
			use(edge[j].u, edge[j].v);
		// printf("%d ", edge[j - 1].w);
		for (int i = 1; i <= n; ++i)
			printf("%d", use[i]);
		putchar('\n');
	}
	return 0;
}