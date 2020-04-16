/**
 * 2019.11.08【NOIP提高组】模拟 B 组
 * A 修建道路
 */

#include <stdio.h>
#include <math.h>
#include <algorithm>

struct __edge {
	int u, v;
	double w;
	bool operator<(__edge x) {return w < x.w;}
} edge[1020 * 1020];
struct __bin {
	int fa[1020], size[1020], cnt = 0;
	void operator<<(int x) {fa[x] = x, size[x] = 1, ++cnt;}
	int _root(int x) {
		if (fa[x] != x)
			fa[x] = _root(fa[x]);
		return fa[x];
	} int operator[](int x) {return _root(x);}
	void operator()(int x, int y) {
		if (_root(x) == _root(y))
			return ;
		--cnt;
		if (size[fa[x]] < size[fa[y]])
			fa[x] = fa[y], size[fa[y]] += size[fa[x]];
		else
			fa[y] = fa[x], size[fa[x]] += size[fa[y]];
	}
	bool operator()() {return cnt > 1;}
} bin;

int N, M, pt = 0, x[1020], y[1020];
double ans = 0;

int main() {
	freopen("A.in", "r", stdin);
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i)
		scanf("%d%d", &x[i], &y[i]), bin << i;
	for (int i = 1, u, v; i <= M; ++i)
		scanf("%d%d", &u, &v), bin(u, v);
	for (int i = 1; i < N; ++i)
		for (int j = i + 1; j <= N; ++j)
			edge[++pt] = ((__edge) {i, j, sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]))});
	std::sort(&edge[1], &edge[pt + 1]);
	for (int i = 1; i <= pt && bin(); ++i) {
		while (i <= pt && bin[edge[i].u] == bin[edge[i].v])++i;
		bin(edge[i].u, edge[i].v), ans += edge[i].w;
	}
	printf("%.2lf", ((int)(ans * 100)) / 100.0);
	return 0;
}