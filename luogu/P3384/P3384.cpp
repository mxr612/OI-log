/**
 * P3384
 * 重链剖分
 */
#include <stdio.h>
#include <string.h>
int N, M, R, P;
long long node_w[1000020];
struct __edge {
	int v;
	__edge *next;
} edge_[1000020], *edge[1000020] = {NULL};
int edge_usage = 0;
inline void _add_edge(int u, int v) {
	edge_[++edge_usage].next = edge[u], edge[u] = &edge_[edge_usage], edge[u] -> v = v;
}
struct __node {
	int father, deep, size, son;
	int top, rank, right;
} node[1000020];
int mapping[1000020];
void _dfs_1(int x, int deep) {
	int a = 0, b = 0;
	node[x].deep = deep;
	node[x].size = 1;
	for (__edge *i = edge[x]; i != NULL; i = i->next) {
		if (i->v == node[x].father)continue;
		node[i->v].father = x;
		_dfs_1(i->v, deep + 1);
		node[x].size += node[i->v].size;
		if (a < node[i->v].size)
			a = node[i->v].size, b = i->v;
	}
	node[x].son = b;
}
int now = 0;
void _dfs_2(int x, int top) {
	node[x].top = top;
	node[x].rank = ++now;
	mapping[now] = x;
	if (node[x].son > 0) {
		_dfs_2(node[x].son, top);
		node[x].right = node[node[x].son].right;
		for (__edge *i = edge[x]; i != NULL; i = i->next) {
			if (i->v == node[x].father || i->v == node[x].son)continue;
			_dfs_2(i->v, i->v);
			node[x].right = node[i->v].right;
		}
	} else
		node[x].right = now;
}
struct __tree {
	long long w, m;
	int l, r, size;
	__tree *ls, *rs;
} tree_[4000020], *tree = NULL;
int tree_usage = 0;
void _build_tree(__tree *&x, int l, int r) {
	if (r < l)return ;
	x = &tree_[++tree_usage];
	x->l = l;
	x->r = r;
	x->size = r - l + 1;
	if (l == r) {
		x->w = node_w[mapping[l]] % P;
	} else {
		_build_tree(x->ls, l, (l + r) / 2);
		_build_tree(x->rs, (l + r) / 2 + 1, r);
		x->w = (x->ls->w + x->rs->w) % P;
	}
}
void _push_tree(register __tree *x) {
	if (x->ls != NULL) {
		x->ls->w = (x->ls->w + x->ls->size * x->m) % P;
		x->ls->m = (x->ls->m + x->m) % P;
	}
	if (x->rs != NULL) {
		x->rs->w = (x->rs->w + x->rs->size * x->m) % P;
		x->rs->m = (x->rs->m + x->m) % P;
	}
	x->m = 0;
}
int _query_tree(int L, int R, __tree *x) {
	if (x == NULL || x->r < L || R < x->l)return 0;
	if (L <= x->l && x->r <= R)
		return x->w;
	else {
		_push_tree(x);
		return (_query_tree(L, R, x->ls) + _query_tree(L, R, x->rs)) % P;
	}
}
void _modify_tree(int L, int R, int W, __tree *x) {
	if (x == NULL || x->r < L || R < x->l)return ;
	if (L <= x->l && x->r <= R)
		x->w = (x->w + x->size * W) % P, x->m = (x->m + W) % P;
	else {
		_push_tree(x);
		_modify_tree(L, R, W, x->ls);
		_modify_tree(L, R, W, x->rs);
		x->w = ((x->ls == NULL ? 0 : x->ls->w) + (x->rs == NULL ? 0 : x->rs->w)) % P;
	}
}

int _query_path(register int x, register int y) {
	register int ans = 0;
	while (node[x].top != node[y].top) {
		if (node[node[x].top].deep > node[node[y].top].deep) {
			ans = (ans + _query_tree(node[node[x].top].rank, node[x].rank, tree)) % P;
			x = node[node[x].top].father;
		} else {
			ans = (ans + _query_tree(node[node[y].top].rank, node[y].rank, tree));
			y = node[node[y].top].father;
		}
	}
	if (node[x].rank < node[y].rank)
		return (ans + _query_tree(node[x].rank, node[y].rank, tree) ) % P;
	else
		return (ans + _query_tree(node[y].rank, node[x].rank, tree) ) % P;
}
void _modify_path(register int x, register int y, register int W) {
	while (node[x].top != node[y].top) {
		if (node[node[x].top].deep > node[node[y].top].deep) {
			_modify_tree(node[node[x].top].rank, node[x].rank, W, tree);
			x = node[node[x].top].father;
		} else {
			_modify_tree(node[node[y].top].rank, node[y].rank, W, tree);
			y = node[node[y].top].father;
		}
	}
	if (node[x].rank < node[y].rank)
		_modify_tree(node[x].rank, node[y].rank, W, tree);
	else
		_modify_tree(node[y].rank, node[x].rank, W, tree);
}
signed main() {

	freopen("P3384_2.in", "r", stdin);

	memset(node, 0, sizeof(node));
	memset(tree_, 0, sizeof(tree));

	scanf("%d%d%d%d", &N, &M, &R, &P);

	for (register int i = 1; i <= N; ++i)
		scanf("%d", &node_w[i]);
	for (int i = 1, x, y; i < N; ++i)
		scanf("%d%d", &x, &y), _add_edge(x, y), _add_edge(y, x);

	_dfs_1(R, 1);
	_dfs_2(R, R);

	_build_tree(tree, 1, N);

	int o, x, y, z;
	for (register int i = 0; i < M; ++i) {
		scanf("%d", &o);
		switch (o) {
		case 1:
			scanf("%d%d%d", &x, &y, &z);
			_modify_path(x, y, z);
			break;
		case 2:
			scanf("%d%d", &x, &y);
			printf("%d\n", _query_path(x, y));
			break;
		case 3:
			scanf("%d%d", &x, &z);
			_modify_tree(node[x].rank, node[x].right, z, tree);
			break;
		case 4:
			scanf("%d", &x);
			printf("%d\n", _query_tree(node[x].rank, node[x].right, tree));
			break;
		default:;
		}
	}

	return 0;

}