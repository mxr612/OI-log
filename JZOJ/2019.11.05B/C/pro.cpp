/**
 * 2019.11.05【NOIP提高组】模拟 B 组
 * C 矩形
 * pro.pas/cpp
 * input:pro.in
 * output:pro.out
 */

#include <stdio.h>

int n;

struct __rec {
	int xa, ya, xb, yb;
} rec[7020];
struct __bin {
	int fa[7020], size[7020], cnt = 0;
	void operator<<(int x) {fa[x] = x, size[x] = 1, ++cnt;}
	int _root(int x) {
		if (fa[x] != x)fa[x] = _root(fa[x]);
		return fa[x];
	}
	void _merge(int x, int y) {
		if (_root(x) == _root(y))
			return ;
		if (size[fa[x]] > size[fa[y]]) {
			fa[fa[y]] = fa[fa[x]];
			size[fa[x]] += size[fa[y]];
		} else {
			fa[fa[x]] = fa[fa[y]];
			size[fa[y]] += size[fa[x]];
		}
		--cnt;
	} void operator()(int x, int y) {_merge(x, y);}
	int operator()() {return cnt;}
} bin;

bool _is_inter(__rec a, __rec b) {
	if (a.xa > b.xb || b.xa > a.xb || a.ya > b.yb || b.ya > a.yb)return false;
	if ((a.xa == b.xb || a.xb == b.xa) && (a.ya == b.yb || a.yb == b.ya))return false;
	return true;
}

int main() {
	freopen("pro.in", "r", stdin);
	freopen("pro.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d%d%d", &rec[i].xa, &rec[i].ya, &rec[i].xb, &rec[i].yb), bin << i;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (_is_inter(rec[i], rec[j]))
				bin(i, j);
	printf("%d", bin());
	return 0;
}