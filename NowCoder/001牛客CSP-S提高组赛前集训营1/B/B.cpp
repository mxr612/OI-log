// B

#include <stdlib.h>

#include <iostream>
using namespace std;

#define MOD (1000000007)

struct __edge {
	int v;
	__edge *nx = NULL;
} *edge[100020] = {NULL}, *p;

int n, k;
unsigned int ans[100020];

int _dfs(int dep, int id, int fa, int nw) {
	if (dep > k)
		return 0;
	int res = 1;
	for (__edge *i = edge[id]; i != NULL; i = i->nx)
		if (i->v != fa)
			res += _dfs(dep + 1, i->v, id, nw);
	ans[nw] = (ans[nw] * (res % MOD)) % MOD;
	return res;
}

int main() {

	freopen("B.in", "r", stdin);

	cin >> n >> k;

	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		p = (__edge *)calloc(1, sizeof(__edge)), p->nx = edge[u], edge[u] = p, p->v = v;
		p = (__edge *)calloc(1, sizeof(__edge)), p->nx = edge[v], edge[v] = p, p->v = u;
	}

	for (int i = 1; i <= n; ++i)
		ans[i] = 1, cout << _dfs(0, i, 0, i) << ' ';
	cout << endl;
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';

	return 0;
}