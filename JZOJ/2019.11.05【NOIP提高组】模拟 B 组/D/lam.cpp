/**
 * 2019.11.05【NOIP提高组】模拟 B 组
 * D 平坦的折线（lam）
 * input:lam.in
 * output:lam.out
 */

#include <stdio.h>
#include <math.h>
#include <algorithm>

int n;

struct __bin {
	int fa[30020], size[30020], cnt = 0;
	void operator<<(int x) {fa[x] = x, size[x] = 1, ++cnt;}
	int _root(int x) {
		if (fa[x] != x)fa[x] = _root(fa[x]);
		return fa[x];
	}
	bool _merge(int x, int y) {
		if (_root(x) == _root(y))
			return false;
		if (size[fa[x]] > size[fa[y]]) {
			fa[fa[y]] = fa[fa[x]];
			size[fa[x]] += size[fa[y]];
		} else {
			fa[fa[x]] = fa[fa[y]];
			size[fa[y]] += size[fa[x]];
		}
		--cnt;
		return true;
	} bool operator()(int x, int y) {return _merge(x, y);}
	int operator()() {return cnt;}
} bin;

struct __node {
	int x, y;
	bool v = true;
} node[30020];

int _cmpS(__node a, __node b) {return a.x < b.x;}

int main() {
	freopen("lam.in", "r", stdin);
	// freopen("lam.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &node[i].x, &node[i].y), bin << i;

	std::sort(&node[1], &node[n + 1], _cmpS);

	for (int i = 2; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			if (node[j].v && abs(node[i].x - node[j].x) >= abs(node[i].y - node[j].y) && bin(i, j))
				node[j].v = false;

	printf("%d", bin());

	return 0;
}