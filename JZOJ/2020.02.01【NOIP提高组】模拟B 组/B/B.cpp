/**
 * B
 */

#include <stdio.h>
#include <map>

int N, S, ans = 0;
int node[100020];

struct __edge {
	int v;
	__edge *p;
} *edge[100020] = {NULL}, sta[100020];
int te = 0;

inline void _c(register int u, register int v) {
	sta[++te].v = v;
	sta[te].p = edge[u];
	edge[u] = &sta[te];
}

int sum[100020] = {0};
std::map<int, int>m;

bool _bound(register int l, register int r, register int g) {
	register int m;
	while (l < r) {
		m = (l + r) / 2;
		if (sum[m] == g)
			return true;
		if (sum[m] < g)
			l = m + 1;
		else
			r = m - 1;
	}
	return false;
}

inline void _dfs(register int u, register int dep) {
	sum[dep] = sum[dep - 1] + node[u]; ++m[sum[dep]];
	if (sum[dep] >= S && m[sum[dep] - S] > 0)++ans;
	for (register __edge *i = edge[u]; i != NULL; i = i->p)
		_dfs(i->v, dep + 1);
	--m[sum[dep]];
}

int main() {

	freopen("B.in", "r", stdin);

	scanf("%d%d", &N, &S);
	for (register int i = 1; i <= N; ++i)
		scanf("%d", &node[i]);
	for (register int i = 1, x, y; i < N; ++i)
		scanf("%d%d", &x, &y), _c(x, y);

	// for (int i = 1; i <= N; ++i) {
	// 	for (__edge *p = edge[i]; p != NULL; p = p->p) {
	// 		printf("%5d", p->v);
	// 	}
	// 	putchar('\n');
	// }

	++m[0];
	_dfs(1, 1);

	printf("%d\n", ans);

	return 0;
}