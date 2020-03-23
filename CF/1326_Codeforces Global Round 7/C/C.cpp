/**
 * C
 */

#include <stdio.h>
#include <algorithm>

int n, k;

struct __node {
	int v, r;
} node[200020];

bool _cmp1(__node x, __node y) {
	return x.v > y.v;
}
bool _cmp2(__node x, __node y) {
	return x.r < y.r;
}

unsigned long long ans1 = 0, ans2 = 1;

int p[200020];

signed main() {

	// freopen("C.in", "r", stdin);

	scanf("%d%d", &n, &k);

	for (register int i = 1; i <= n; ++i)
		scanf("%d", &node[i].v), node[i].r = i;

	std::sort(&node[1], &node[n + 1], _cmp1);
	std::sort(&node[1], &node[k + 1], _cmp2);

	ans1 += node[1].v;
	register int j = node[1].r;
	for (register int i = 2; i <= k; ++i) 
		ans1 += node[i].v, ans2 = (ans2 * (node[i].r - j)) % 998244353, j = node[i].r;
	
	printf("%llu %llu\n", ans1, ans2);

	return 0;
}