/**
 * U94222
 * A U94222 循环往复
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

int n, m, a[100020], p[100020], q[100020], z[100020] = {0};

struct __state {
	unsigned f, x, b;
	unsigned long long co, vl;
	unsigned short vised[7000];
	bool operator[](int x) {return (vised[x / 16] ^ (1 << (x % 16))) > 0;}
} cmp, dis[100020];
__state operator+(__state x, int y) {
	if ((x.vised[y / 16] ^ (1 << (y % 16))) == 0)
		x.vised[y / 16] ^= 1 << (y % 16), x.vl += q[y], x.co += p[y], x.b ^= z[y], x.x = y;
	return x;
}
bool operator<(__state x, __state y) {
	if (x.vl == y.vl)
		return x.co > y.co;
	return x.vl < y.vl;
}
struct __edge {
	int v;
	__edge *nx;
}*edge[100020] = {NULL};
void _add_edge(int u, int v) {
	__edge *p = (__edge *)calloc(1, sizeof(__edge));
	p->v = v, p->nx = edge[u], edge[u] = p;
}
void _free_edge(__edge *&p) {
	if (p != NULL)
		_free_edge(p->nx), free(p), p = NULL;
}

std::priority_queue<__state>pq;

int main() {
	freopen("A.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &p[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &q[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d", &a[i]);
	for (int i = 1, x; i <= m; ++i) {
		scanf("%d", &x);
		while (x > 0)
			_add_edge(x, (x + a[i]) > n ? (x + a[i] - n) : (x + a[i])), scanf("%d", &x);
	}
	for (int i = 1; i <= n; ++i)
		scanf("%d", &z[i]);

	memset(dis, -1, sizeof(dis));
	memset(&cmp, 0, sizeof(cmp));
	for (int i = 1; i <= n; ++i)
		cmp.x = i, cmp.f = i, pq.push(cmp + i), printf("%d\n",(cmp+i).co);
	while (!pq.empty()) {
		dis[pq.top().x] = pq.top();
		for (__edge *i = edge[pq.top().x]; i != NULL; i = i->nx)
			pq.push(dis[pq.top().x] + (i->v));
		while (!pq.empty() && !(pq.top() < dis[pq.top().x]))pq.pop();
	}

	for (int i = 1; i <= n; ++i)
		printf("%5d%5d%5d%5d%5d\n", dis[i].f, i, dis[i].vl, dis[i].co, dis[i].b);

	for (int i = 1; i <= n; ++i)
		_free_edge(edge[i]);

	return 0;
}