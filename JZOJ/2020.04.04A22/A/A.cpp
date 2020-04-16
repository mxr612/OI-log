/**
 * A
 */

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MXN (100020)

int N;

struct __node {
	int w;
} node[MXN];

struct __edge {
	int v;
	__edge *next;
}*edge[MXN];

inline void _add_edge(register int u, register int v) {
	register __edge *p = (__edge *)calloc(sizeof(__edge), 1);
	p->v = v;
	p->next = edge[u];
	edge[u] = p;
}

int ord[MXN];
bool vis[MXN] = {false};
void _order() {
	vis[1] = true, ord[N] = 1;
	for (register int i = N, e = N; i > 0; --i)
		for (register __edge *j = edge[ord[i]]; j != NULL; j = j->next)
			if (!vis[j->v])
				vis[j->v] = true, ord[--e] = j->v;
}

void _sovle() {
	int res[MXN];
	for (register int i = 1, j = 0; i <= N; ++i, j = 0) {
		for (register __edge *p = edge[ord[i]]; p != NULL; p = p->next)
;
	}
}

signed main() {

	freopen("A.in", "r", stdin);

	scanf("%d", &N);

	for (int i = 1, x, y; i < N; ++i)
		scanf("%d%d", &x, &y), _add_edge(x, y), _add_edge(y, x);

	_order();

	return 0;

}