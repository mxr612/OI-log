/**
 * 牛客CSP-S提高组赛前集训营5
 * B 十二桥问题
 * 与k有关暴力
 * 跑多次最短路
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <iostream>

unsigned long long ans = -1, n, m, k, x[20], y[20], vv[20], cot[50020] = {0}, zdl[30][50020], p = 0;
struct __edge {
	int v, d;
	__edge *nx = NULL;
}*edge[50020] = {NULL};
void _add_edge(int u, int v, int d) {
	__edge *pt = (__edge *)calloc(1, sizeof(__edge));
	pt->v = v, pt->d = d, pt->nx = edge[u], edge[u] = pt;
}
void _free_edge(__edge *&p) {
	if (p != NULL)
		_free_edge(p->nx), free(p), p = NULL;
}
void _zdl(int x) {
	if (cot[x] > 0)
		return ;
	cot[x] = ++p;
	std::queue<int>que;
	bool vis[50020] = {false};
	zdl[p][x] = 0, que.push(x), vis[x] = true;
	while (!que.empty()) {
		for (__edge *pt = edge[que.front()]; pt != NULL; pt = pt->nx) {
			if (zdl[p][pt->v] > zdl[p][que.front()] + pt->d) {
				zdl[p][pt->v] = zdl[p][que.front()] + pt->d;
				if (!vis[pt->v])
					que.push(x), vis[x] = true;
			}
		}
		vis[que.front()] = false;
		que.pop();
	}
}

bool vis[20] = {false};
void _dfs(int id, int dep, int vl) {
	if (vl + zdl[cot[id]][1] >= ans)
		return ;
	if (dep > k)
		ans = vl + zdl[cot[id]][1];
	for (int i = 1; i <= k; ++i) {
		if (!vis[i]) {
			vis[i] = true;
			_dfs(x[i], dep + 1, vl + zdl[cot[id]][cot[y[i]]] + vv[i]);
			_dfs(y[i], dep + 1, vl + zdl[cot[id]][cot[x[i]]] + vv[i]);
			vis[i] = false;
		}
	}
}

int main() {
	freopen("test.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, d; i <= k; ++i)
		scanf("%d%d%d", &x[i], &y[i], &d), vv[i] = d, _add_edge(x[i], y[i], d), _add_edge(y[i], x[i], d);
	for (int i = k, u, v, d; i < m; ++i)
		scanf("%d%d%d", &u, &v, &d), _add_edge(u, v, d), _add_edge(v, u, d);
	memset(zdl, 0x6f, sizeof(zdl));
	_zdl(1);
	for (int i = 1; i <= k; ++i)
		_zdl(x[i]), _zdl(y[i]);
	_dfs(1, 1, 0);
	std::cout << ans;
	for (int i = 1; i <= k; ++i) {
		printf("%-5d", cot[x[i]]);
		for (int j = 1; j <= n; ++j)
			printf("%15d", zdl[cot[x[i]]][j]);
		putchar('\n');
		printf("%-5d", cot[y[i]]);
		for (int j = 1; j <= n; ++j)
			printf("%15d", zdl[cot[y[i]]][j]);
		putchar('\n');
	}
	for (int i = 1; i <= n; ++i)
		_free_edge(edge[i]);
	return 0;
}