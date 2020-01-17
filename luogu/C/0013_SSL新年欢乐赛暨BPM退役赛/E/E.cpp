/**
 * E
 */

#include <stdio.h>
#include <string.h>
#include <queue>

int n, m;

struct __edge {
	long long u, v, w;
	__edge *t;
} stack[1000020], *edge[100020] = {NULL};
int usage = 0;

void _add_edge(register int u, register int v, register int w) {
	stack[++usage].u = u, stack[usage].v = v, stack[usage].w = w, stack[usage].t = edge[u], edge[u] = &stack[usage];
	stack[++usage].u = v, stack[usage].v = u, stack[usage].w = w, stack[usage].t = edge[v], edge[v] = &stack[usage];
}

bool apr[100020] = {false};
long long ans[100020] = {0};
struct _que {
	long long v, w;
} cmp;
bool operator<(_que a, _que b) {return a.w > b.w;}
std::priority_queue<_que>que;

int main() {

	freopen("E.in", "r", stdin);

	scanf("%d%d", &n, &m);

	for (register int i = 0, u, v, w; i < m; ++i)
		scanf("%d%d%d", &u, &v, &w), _add_edge(u, v, w << 1);
	for (register int i = 1, w; i <= n; ++i)
		scanf("%d", &w), _add_edge(0, i, w);

	memset(ans, 0x6f, sizeof(ans));
	ans[0] = 0, apr[0] = true;
	for (register __edge *i = edge[0]; i != NULL; i = i->t)
		cmp.v = i->v, cmp.w = i->w, que.push(cmp);

	for (register int i = 1, j; i <= n; ++i) {
		while (apr[que.top().v])que.pop();
		cmp = que.top();
		ans[cmp.v] = cmp.w;
		apr[cmp.v] = true;
		j = ans[que.top().v];
		for (register __edge *i = edge[que.top().v]; i != NULL; i = i->t)
			cmp.v = i->v, cmp.w = j + i->w, que.push(cmp);
	}

	for (int i = 1; i <= n; ++i)
		printf("%lld ", ans[i]);

	return 0;
}