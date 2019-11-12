/**
 * 2019年11月12日提高组Day1
 * A 赛艇表演
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

int n, m;

long long w;
struct __edge {
	int u, v;
	long long w;
	__edge *nx;
}*edge[200020] = {NULL};
struct __node {
	int x;
	long long w;
} cmp;
bool operator<(__node x, __node y) {return x.w > y.w;}

void _add_edge(int u, int v, long long w) {
	__edge *p = (__edge *)calloc(1, sizeof(__edge));
	p->u = u, p->v = v, p->w = w, p->nx = edge[u], edge[u] = p;
}
void _free_edge(__edge *&p) {
	if (p != NULL)
		_free_edge(p->nx), free(p), p = NULL;
}

unsigned long long dis[200020], inf = -1;
void _dij() {
	memset(dis, -1, sizeof(dis));
	std::priority_queue<__node>pq;
	dis[0] = 0;
	for (__edge *i = edge[0]; i != NULL; i = i->nx)
		pq.push({i->v, i->w});
	while (!pq.empty()) {
		dis[pq.top().x] = pq.top().w;
		for (__edge *i = edge[pq.top().x]; i != NULL; i = i->nx)
			pq.push({i->v, pq.top().w + i->w});
		while (!pq.empty() && dis[pq.top().x] < inf)pq.pop();
	}
}
int main() {
	freopen("A1.in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; ++i)
		scanf("%d%d%lld", &u, &v, &w), _add_edge(u, v, w << 1), _add_edge(v, u, w << 1);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &w), _add_edge(0, i, w);
	_dij();
	for (int i = 1; i <= n; ++i)
		printf("%lld ", dis[i]);
	for (int i = 1; i <= n; ++i)
		_free_edge(edge[i]);
	return 0;
}