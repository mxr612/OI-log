/**
 * luogu
 * P3384
 */

#include <stdio.h>
#include <string.h>

int N, M, R, P, o, x, y, z;

struct __edge {
	int v;
	__edge *next;
} stack_edge[200020], *edge[200020] = {0};
int usage_edge = 0;

inline void _add_edge(register int u, register int v) {
	stack_edge[++usage_edge].next = edge[u];
	edge[u] = &stack_edge[usage_edge];
	edge[u]->v = v;
}

struct __node {
	int w, size, son, father, deep, top, id, right;
} node[100020];
int map[100020];
void _dfs_1(int x, int deep) { //for preprocessing size,son,father,deep
	int a = 0, b = 0;
	node[x].size = 1;
	node[x].deep = deep;
	for (register __edge *i = edge[x]; i != NULL; i = i->next) {
		if (i->v == node[x].father)continue;
		node[i->v].father = x;
		_dfs_1(i->v, deep + 1);
		node[x].size += node[i->v].size;
		if (node[i->v].size > b)
			a = i->v, b = node[i->v].size;
	}
	node[x].son = a;
}
inline int _max(register int a, register int b) {return a > b ? a : b;}
int now = 0;
void _dfs_2(int x, int top) {//for preprocessing top,id,map,right
	node[x].top = top;
	node[x].id = ++now;
	map[now] = x;
	if (node[x].son != 0)
		_dfs_2(node[x].son, top), node[x].right = node[node[x].son].right;
	else
		node[x].right = node[x].id;
	for (register __edge *i = edge[x]; i != NULL; i = i->next) {
		if (i->v == node[x].father || i->v == node[x].son)continue;
		_dfs_2(i->v, i->v);
		node[x].right = _max(node[x].right, node[i->v].right);
	}
}

struct __tree {
	int w, m, l, r, size;
	__tree *left_son, *right_son;
} tree[400020] = {0}, *tree_root = NULL;
int usage_tree = 0;
void _build_tree(__tree *&x, int l, int r) {
	if (r < l) {
		x = NULL;
		return ;
	}
	x = &tree[++usage_tree];
	if (l == r)
		x->w = node[map[l]].w % P;
	else {
		_build_tree(x->left_son, l, (l + r) / 2);
		_build_tree(x->right_son, (l + r) / 2 + 1, r);
		x->w = (((x->left_son == 0) ? (0) : (x->left_son->w)) + ((x->right_son == 0) ? (0) : (x->right_son->w))) % P;
	}
	x->m = 0;
	x->l = l, x->r = r;
	x->size = r - l + 1;
}
void _push_tree(__tree *x) {
	if (x->left_son != NULL) {
		x->left_son->w = (x->left_son->w + x->left_son->size * x->m) % P;
		x->left_son->m = (x->left_son->m + x->m) % P;
	}
	if (x->right_son != NULL) {
		x->right_son->w = (x->right_son->w + x->right_son->size * x->m) % P;
		x->right_son->m = (x->right_son->m + x->m) % P;
	}
	x->m = 0;
}
void _modify_tree(int L, int R, int W, __tree *x) {
	if (x == NULL || x->r < L || R < x->l)return ;
	if (L <= x->l && x->r <= R)
		x->w = (x->w + x->size * W) % P, x->m = (x->m + W) % P;
	else {
		_push_tree(x);
		_modify_tree(L, R, W, x->left_son);
		_modify_tree(L , R , W, x->right_son);
	}
}
int _query_tree(int L, int R, __tree *x) {
	if (x == NULL || x->r < L || R < x->l)return 0;
	if (L <= x->l && x->r <= R)
		return x->w;
	else {
		_push_tree(x);
		return (_query_tree(L, R, x->left_son) + _query_tree(L, R, x->right_son)) % P;
	}
}

int _query_path(register int x, register int y) {
	register int res = 0;
	while (node[x].top != node[y].top)
		if (node[node[x].top].deep > node[node[y].top].deep)
			res += _query_tree(node[node[x].top].id, node[x].id, tree_root), x = node[node[x].top].father;
		else
			res += _query_tree(node[node[y].top].id, node[y].id, tree_root), y = node[node[y].top].father;
	if (node[x].id < node[y].id)
		return res + _query_tree(node[x].id, node[y].id, tree_root);
	else
		return res + _query_tree(node[y].id, node[x].id, tree_root);
}

void _modify_path(register int x, register int y, register int z) {
	while (node[x].top != node[y].top)
		if (node[x].deep > node[y].deep)
			_modify_tree(node[node[x].top].id, node[x].id, z, tree_root), x = node[node[x].top].father;
		else
			_modify_tree(node[node[y].top].id, node[y].id, z, tree_root), y = node[node[y].top].father;
	if (node[x].id < node[y].id)
		_modify_tree(node[x].id, node[y].id, z, tree_root);
	else
		_modify_tree(node[y].id, node[x].id, z, tree_root);
}

int main() {

	freopen("P3384_1.in", "r", stdin);

	memset(node, 0, sizeof(node));
	memset(tree, 0, sizeof(tree));

	scanf("%d%d%d%d", &N, &M, &R, &P);

	for (register int i = 1; i <= N; ++i)
		scanf("%d", &node[i].w);
	for (register int i = 1, x, y; i < N; ++i)
		scanf("%d%d", &x, &y), _add_edge(x, y), _add_edge(y, x);

	_dfs_1(R, 1);
	_dfs_2(R, R);

	_build_tree(tree_root, 1, N);

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
			_modify_tree(node[x].id, node[x].right, z, tree_root);
			break;
		case 4:
			scanf("%d", &x);
			printf("%d\n", _query_tree(node[x].id, node[x].right, tree_root));
			break;
		default:;
		}
	}

	return 0;
}