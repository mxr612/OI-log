/**
 * A
 * 网络吞吐量(network)
 * network.in
 * netwoek.out
 * 网络流 拆点
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#define SIZE (100020)
#define INF (1000000000000000)

int n = 0, m;

n = 0;

struct __edge {
	int v;
	unsigned long long w;
	bool flag;
	__edge *next, *reve;
}*edgeA[SIZE] = {NULL}, *edgeB[SIZE << 1] = {NULL};

inline void _reve(register __edge *x, register __edge *y) {
	x->reve = y, y->reve = x;
}
inline __edge *_add_edge_A(register int u, register int v, register int w) {
	register __edge *p = (__edge *)calloc(sizeof(__edge), 1);
	p->v = v, p->w = w, p->next = edgeA[u], edgeA[u] = p;
	return p;
}
inline __edge *_add_edge_B(register int u, register int v, unsigned long long w) {
	register __edge *p = (__edge *)calloc(sizeof(__edge), 1);
	p->v = v, p->w = w, p->next = edgeB[u], edgeB[u] = p;
	return p;
}

int vis[SIZE << 1] = {0};
long long ans = 0;

bool _bfs() {
	std::vector<int>que;
	memset(vis, -1, sizeof(vis));
	vis[1] = 0, que.push_back(1);
	register __edge *p;
	for (register unsigned i = 0; i < que.size(); ++i)
		for (p = edgeB[que[i]]; p != NULL; p = p->next)
			if (vis[p->v] < 0 && p->w > 0)
				vis[p->v] = vis[que[i]] + 1, que.push_back(p->v);
	// for (register int i = 1; i <= n; ++i)
	// 	printf("|%d %d|", i, vis[i]);
	// for (register int i = 1 + SIZE; i <= n + SIZE; ++i)
	// 	printf("|%d %d|", i, vis[i]);
	// printf("\n");
	return vis[n] > -1;
}

inline unsigned long long _min(unsigned long long x, unsigned long long y) {
	return x < y ? x : y;
}

unsigned long long _dfs(int x, unsigned long long lim) {
	if (x == n) {

		return lim;
	}
	// printf("______________________%d %lld\n", x, lim);
	unsigned long long res = 0, cmp;
	for (__edge *p = edgeB[x]; p != NULL && res < lim; p = p->next) {
		// printf("%d %d %lld\n", vis[x], vis[p->v], p->w);
		if (p->w > 0 && vis[x] + 1 == vis[p->v]) {
			cmp = _dfs(p->v, _min(p->w, lim - res));
			// printf("%d %lld|%lld\n", p->v, p->w, lim - res);
			// printf("%lld\n", cmp);
			if (cmp == 0)
				vis[p->v] = 0;
			else
				p->w -= cmp, p->reve->w += cmp, res += cmp;
		}
	}

	return res;
}

signed main() {

	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);

	register __edge *p, *q;

	int a, b, d;
	long long node[SIZE];
	scanf("%d%d", &n, &m);
	for (register int i = 0; i < m; ++i)
		scanf("%d%d%d", &a, &b, &d), _reve(_add_edge_A(a, b, d), _add_edge_A(b, a, d));
	for (register int i = 1; i <= n; ++i)
		scanf("%lld", &node[i]);
	node[1] = node[n] = INF;

	int cos[SIZE];
	bool vis[SIZE] = {false};
	std::vector<int>que;
	memset(cos, 0x6f, sizeof(cos));
	cos[1] = 0, vis[1] = true;
	que.push_back(1);
	for (register unsigned i = 0; i < que.size(); ++i) {
		for (p = edgeA[que[i]]; p != NULL; p = p->next) {
			vis[que[i]] = false;
			if (cos[p->v] > cos[que[i]] + p->w) {
				cos[p->v] = cos[que[i]] + p->w;
				for (q = edgeA[p->v]; q != NULL; q = q->next)q->flag = false;
				if (!vis[p->v])vis[p->v] = true, que.push_back(p->v);
			}
			if (cos[p->v] == cos[que[i]] + p->w)
				p->reve->flag = true;
		}
	}

	for (register int i = 1; i <= n; ++i)
		for (register __edge *p = edgeA[i]; p != NULL; p = p->next)
			if (p->flag == true)
				_reve(_add_edge_B(p->v + SIZE, p->reve->v, INF), _add_edge_B(p->reve->v, p->v + SIZE, 0));
	for (register int i = 1; i <= n; ++i)
		_reve(_add_edge_B(i, i + SIZE, node[i]), _add_edge_B(i + SIZE, i, 0));

	// for (register int i = 1; i <= n; ++i)
	// 	for (p = edgeB[i]; p != NULL; p = p->next)
	// 		printf(" % -10d % -10d % lld\n", i, p->v, p->w);
	// for (register int i = SIZE + 1; i <= SIZE + n; ++i)
	// 	for (p = edgeB[i]; p != NULL; p = p->next)
	// 		printf(" % -10d % -10d % lld\n", i, p->v, p->w);

	while (_bfs())ans += _dfs(SIZE + 1, INF);

	// for (register int i = 1; i <= n; ++i)
	// 	for (p = edgeB[i]; p != NULL; p = p->next)
	// 		printf(" % -10d % -10d % lld\n", i, p->v, p->w);
	// for (register int i = SIZE + 1; i <= SIZE + n; ++i)
	// 	for (p = edgeB[i]; p != NULL; p = p->next)
	// 		printf(" % -10d % -10d % lld\n", i, p->v, p->w);

	printf("%lld\n", ans);

	return 0;

}