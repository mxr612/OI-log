/**
 * B
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>

int N, M;
long long ans = 0;

long long tree[100020];

inline int _lowbit(int x) {
	return x & (-x);
}
void _modify_tree(int x, int w) {
	for (; x <= N; x += _lowbit(x))
		tree[x] += w;
}
long long _query_tree(int l, int r) {
	if (r < l)return 0;
	long long res = 0;
	for (; r > 0; r -= _lowbit(r))
		res += tree[r];
	for (--l; l > 0; l -= _lowbit(l))
		res -= tree[l];
	return res;
}

struct __edge {
	int v, w;
	__edge *next;
}*edge[100020] = {NULL}, *cmp;
inline void _add_edge(int u, int v, int w) {
	cmp = (__edge *)calloc(sizeof(__edge), 1);
	cmp->v = v;
	cmp->w = w;
	cmp->next = edge[u];
	edge[u] = cmp;
}

struct __node {
	int w, father, size, son, deep;
	int id, top;
} node[100020];

void _dfs_1(int x, int deep) {
	node[x].deep = deep;
	node[x].size = 1;
	for (__edge *i = edge[x]; i != NULL; i = i->next) {
		if (i->v == node[x].father)continue;
		node[i->v].w = i->w;
		node[i->v].father = x;
		_dfs_1(i->v, deep + 1);
		node[x].size += node[i->v].size;
		if (node[i->v].size > node[node[x].son].size)
			node[x].son = i->v;
	}
}
int now = 0;
void _dfs_2(int x, int top) {
	node[x].top = top;
	node[x].id = ++now;
	_modify_tree(now, node[x].w);
	if (node[x].son > 0) {
		_dfs_2(node[x].son, top);
		for (__edge *i = edge[x]; i != NULL; i = i->next) {
			if (i->v == node[x].father || i->v == node[x].son)continue;
			_dfs_2(i->v, i->v);
		}
	}
}

long long _query_path(register int x, register int y) {
	long long res = 0;
	while (node[x].top != node[y].top) {
		if (node[node[x].top].deep > node[node[y].top].deep) {
			res += _query_tree(node[node[x].top].id, node[x].id);
			x = node[node[x].top].father;
		} else {
			res += _query_tree(node[node[y].top].id, node[y].id);
			y = node[node[y].top].father;
		}
	}
	return res + _query_tree(std::min(node[x].id + 1, node[y].id + 1), std::max(node[x].id, node[y].id));
}

int main() {

	freopen("B.in", "r", stdin);

	memset(node, 0, sizeof(node));

	scanf("%d%d", &N, &M);

	int x, y, w;
	for (register int i = 1; i < N; ++i) {
		scanf("%d%d%d", &x, &y, &w);
		_add_edge(x, y, w);
		_add_edge(y, x, w);
	}

	_dfs_1(1, 1);
	_dfs_2(1, 1);

	std::set<int>a, b;
	std::set<int>::reverse_iterator re;
	std::set<int>::iterator it, nex;
	int pre;

	for (register int i = 0; i < M; ++i) {
		scanf("%d", &x);
		nex = a.find(x);
		if (a.empty()) {
			a.insert(x);
		} else {
			if (nex == a.end()) {
				a.insert(x);
				it = a.find(x);
				if (it == a.begin())
					pre = *(a.rbegin());
				else
					pre = *(a.lower_bound(x - 1));
				if (++it == a.end())
					it = a.begin();
				ans += _query_path(pre, x) + _query_path(x, *it) - _query_path(pre, *it);
			} else {
				if (it == a.begin())
					pre = *(a.rbegin());
				else
					pre = *(a.lower_bound(x - 1));
				if (++it == a.end())
					it = a.begin();
				ans += _query_path(pre, *it) - _query_path(pre, x) - _query_path(x, *it);
				a.erase(x);
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}