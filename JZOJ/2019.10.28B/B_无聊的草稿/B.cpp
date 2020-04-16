// B

#include <iostream>
using namespace std;

struct __edge {
	int v = 0;
	__edge *nx = NULL;
	int operator()() {return v;}
	void operator++() {++v;}
	void _insert(int x) {
		__edge *p = (__edge *)calloc(1, sizeof(__edge));
		p->v = x, p->nx = nx, nx = p;
	} void operator<<(int x) {_insert(x);}
	void _clear() {
		__edge *p;
		while (nx != NULL)
			p = nx, nx = nx->nx, free(p);
	} void operator--() {_clear();}
} node[1100000];

int N, M, ans[1100000];
bool vis[1100000] = {false};

int _dfs(int id) {
	int res = 0;
	ans[id] = node[id]();
	for (__edge *i = node[id].nx; i != NULL; i = i->nx)
		res, _dfs(i->v), ans[id] = max(ans[id], ans[i->v] + node[id]() - 2);
	for (__edge *i = node[id].nx; i != NULL; i = i->nx) {
		for (__edge *j = i->nx; j != NULL; j = j->nx) {

		}
	}
}

int main() {
	freopen("B.in", "r", stdin);
	cin >> N >> M;
	for (int i = 1, u, v; i <= M; ++i) {
		cin >> u >> v;
		++node[u], node[u] << v;
		++node[v], node[v] << u;
	}

	cout << _dfs(1);

	for (int i = 1; i <= N; ++i)
		--node[i];
	return 0;
}