/**
 * B
 * 并查集缩点
 */

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <string.h>

int n, m;

struct __edge {
	int v;
	__edge *next;
}*edge[500020] = {NULL}, *cmp;
inline void _add_edge(int u, int v) {
	cmp = (__edge *)calloc(sizeof(__edge), 1);
	cmp->v = v;
	cmp->next = edge[u];
	edge[u] = cmp;
}

struct __node {
	int father, deep;
} node[500020];

struct __modify {
	int x, y, c;
} modify[500020];

int bin[500020], size;

int ans[500020] = {0};

int _bin_query(int x) {
	if (bin[x] == x)return x;
	bin[x] = _bin_query(bin[x]);
	return bin[x];
}

void _modify_path(register int x, register int y, register int c) {
	x = _bin_query(x);
	y = _bin_query(y);
	while (x != y) {
		if (node[x].deep > node[y].deep) {
			ans[x] = c;
			bin[x] = node[x].father;
			--size;
			x = _bin_query(x);
		} else {
			ans[y] = c;
			bin[y] = node[y].father;
			--size;
			y = _bin_query(y);
		}
	}
}

signed main() {

	freopen("B.in", "r", stdin);

	scanf("%d%d", &n, &m);
	size = n;

	for (register int i = 2; i <= n; ++i)
		scanf("%d", &node[i].father), _add_edge(node[i].father, i);

	std::queue<int>bfs;
	node[1].deep = 1;
	for (register __edge *i = edge[1]; i != NULL; i = i->next)
		bfs.push(i->v);
	while (!bfs.empty()) {
		node[bfs.front()].deep = node[node[bfs.front()].father].deep + 1;
		for (register __edge *i = edge[bfs.front()]; i != NULL; i = i->next)
			bfs.push(i->v);
		bfs.pop();
	}

	for (register int i = 0; i < m; ++i)
		scanf("%d%d%d", &modify[i].x, &modify[i].y, &modify[i].c);

	for (register int i = 1; i <= n; ++i)
		bin[i] = i;

	for (register int i = m - 1; size > 1 && i >= 0; --i)
		_modify_path(modify[i].x, modify[i].y, modify[i].c);

	for (register int i = 2; i <= n; ++i)
		printf("%d\n", ans[i]);

	return 0;

}