/**
 * B
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;

struct __edge {
	int v;
	__edge *next;
}*edge[500020] = {NULL};

void _add_edge(register int u, register int v) {
	register __edge *p = (__edge *)calloc(sizeof(__edge), 1);
	p->v = v;
	p->next = edge[u];
	edge[u] = p;
}

struct __node {
	int father;
	int deep, size, son;
	int top, id;
} node[500020];
int mapping[500020];

void _dfs_1(int x, int deep) {
	node[x].deep = deep++;
	node[x].size = 1;
	for (register __edge *i = edge[x]; i != NULL; i = i->next) {
		_dfs_1(i->v, deep);
		node[x].size += node[i->v].size;
		if (node[x].son == 0 || node[node[x].son].size < node[i->v].size)
			node[x].son = i->v;
	}
}

int now = 0;
void _dfs_2(int x, int top) {
	node[x].top = top;
	node[x].id = ++now;
	mapping[now] = x;
	if (node[x].son > 0) {
		_dfs_2(node[x].son, top);
		for (register __edge *i = edge[x]; i != NULL; i = i->next) {
			if (i->v == node[x].son)continue;
			_dfs_2(i->v, i->v);
		}
	}
}

struct __tree {
	int w;
	__tree *ls, *rs;
} *root = (__tree *)calloc(sizeof(__tree), 1);

void _tree_modify(int L, int R, int W, __tree *x, int l, int r) {
	if (r < l || r < L || R < l)return ;
	if (L <= l && r <= R)
		x->w = W;
	else {
		while (x->ls == NULL)x->ls = (__tree *)calloc(sizeof(__tree), 1);
		while (x->rs == NULL)x->rs = (__tree *)calloc(sizeof(__tree), 1);
		if (x->w > 0) {
			x->ls->w = x->rs->w = x->w;
			x->w = 0;
		}
		_tree_modify(L, R, W, x->ls, l, (l + r) / 2);
		_tree_modify(L, R, W, x->rs, (l + r) / 2 + 1, r);
	}
}

void _path_modify(register int x, register int y, register int c) {
	while (node[x].top != node[y].top) {
		if (node[node[x].top].deep > node[node[y].top].deep) {
			_tree_modify(node[node[x].top].id, node[x].id, c, root, 1, n);
			x = node[node[x].top].father;
		} else {
			_tree_modify(node[node[y].top].id, node[y].id, c, root, 1, n);
			y = node[node[y].top].father;
		}
	}
	if (node[x].id < node[y].id)
		_tree_modify(node[x].id, node[y].id, c, root, 1, n);
	if (node[y].id < node[x].id)
		_tree_modify(node[y].id, node[x].id, c, root, 1, n);
}

int ans[500020];
void _tree_print(__tree *x, int l, int r) {
	if (x == NULL || r < l)return ;
	if (l == r || x->w > 0) {
		for (register int i = l; i <= r; ++i)
			ans[mapping[i]] = x->w;
	} else {
		_tree_print(x->ls, l, (l + r) / 2);
		_tree_print(x->rs, (l + r) / 2 + 1, r);
	}
}

int main() {

	freopen("B.in", "r", stdin);

	memset(node, 0, sizeof(node));

	scanf("%d%d", &n, &m);

	for (register int i = 2; i <= n; ++i)
		scanf("%d", &node[i].father), _add_edge(node[i].father, i);

	_dfs_1(1, 1);
	_dfs_2(1, 1);

	int u, v, c;
	for (register int i = 0; i < m; ++i)
		scanf("%d%d%d", &u, &v, &c), _path_modify(u, v, c);

	_tree_print(root, 1, n);

	for (register int i = 2; i <= n; ++i)
		printf("%d\n", ans[i]);

	return 0;
}