/**
 * P1908 逆序对
 * 权值线段树
 * 动态开点
 * 离散化
 */

#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

int n;
long long ans = 0;

struct __node {
	long long vl;
	int l, r;
	__node *ls, *rs;
	void _update(int V) {
		if (r < V || V < l || r < l)return ;
		vl++;
		if (l == r) return ;
		if (ls == NULL)ls = (__node *)calloc(1, sizeof(__node)), ls->l = l, ls->r = (l + r) / 2;
		if (rs == NULL)rs = (__node *)calloc(1, sizeof(__node)), rs->l = (l + r) / 2 + 1 , rs->r = r;
		ls->_update(V);
		rs->_update(V);
	} void operator()(int x) {_update(x);}
	int _ask(int L, int R) {
		if (r < L || R < l || r < l) return 0;
		if (L <= l && r <= R) return vl;
		else return ((ls != NULL) ? (ls->_ask(L, R)) : (0)) + ((rs != NULL) ? (rs->_ask(L, R)) : (0));
	} int operator[](int x) {return _ask(x + 1, r);}
} root;
struct __P {
	int id, vl,ls;
} a[500020];
int _cmpSvl(__P x, __P y) {return x.vl < y.vl;}
int _cmpSid(__P x, __P y) {return x.id < y.id;}

int main() {
	freopen("P1908.in", "r", stdin);
	root.l = 1, root.r = 500020;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i].vl), a[i].id = i;
	std::sort(&a[1], &a[n + 1], _cmpSvl);
	for (int i = 1, z = 0; i <= n; ++i) {
		if (a[i].vl != a[i - 1].vl)
			z++;
		a[i].ls = z;
	}
	std::sort(&a[1], &a[n + 1], _cmpSid);
	for (int i = 1; i <= n; ++i) {
		ans+=root[a[i].ls];
		root(a[i].ls);
	}
	printf("%lld", ans);
	return 0;
}