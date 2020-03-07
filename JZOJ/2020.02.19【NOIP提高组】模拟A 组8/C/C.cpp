/**
 * C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const short TT = 'z' - 'a' + 1;

int n, Q;
char ss[100020][12];
int usage_str = 0;

struct __Trie {
	int w;
	__Trie *next[TT];
}*Trie[100020] = {NULL};

void _insert_Trie(__Trie *&x, __Trie *X, char s[], int deep) {
	if (deep >= 0 && s[deep] == '\0')return ;
	x = (__Trie *)calloc(sizeof(__Trie), 1);
	if (X == NULL) {
		x->w = 1;
		_insert_Trie(x->next[(int)s[deep + 1] - 'a'], NULL, s, deep + 1);
	} else {
		x->w = X->w + 1;
		for (int i = 0; i < TT; ++i)
			x->next[i] = X->next[i];
		_insert_Trie(x->next[(int)s[deep + 1] - 'a'], X->next[(int)s[deep + 1] - 'a'], s, deep + 1);
	}
}

int _query_Trie(__Trie *x, char s[], int deep) {
	if (x == NULL)return 0;
	if (s[deep + 1] == '\0')return x->w;
	return _query_Trie(x->next[(int)s[deep + 1] - 'a'], s, deep + 1);
}

struct __edge {
	int v, s;
	__edge *next;
}*edge[100020], *cmp;

struct _node {
	int father, deep, size, son;
	int top, id, right;
	int s;
} node[100020];
void _dfs1(int x, int deep) {
	node[x].deep = deep;
	node[x].size = 1;
	for (__edge *i = edge[x]; i != NULL; i = i->next) {
		if (i->v == node[x].father)continue;
		node[i->v].father = x;
		node[i->v].s = i->s;
		_dfs1(i->v, deep + 1);
		node[x].size += node[i->v].size;
		if (node[i->v].size > node[node[x].son].size)
			node[x].son = i->v;
	}
}

int now = 0;
void _dfs2(int x, int top) {
	node[x].top = top;
	node[x].id = ++now;
	_insert_Trie(Trie[now], Trie[now - 1], ss[node[x].s], -1);
	if (node[x].son > 0) {
		_dfs2(node[x].son, top);
		node[x].right = node[node[x].son].right;
		for (__edge *i = edge[x]; i != NULL; i = i->next) {
			if (i->v == node[x].father || i->v == node[x].son)continue;
			_dfs2(i->v, i->v);
		}
	} else
		node[x].right = now;
}

int _query_path(register int x, register int y, char s[]) {
	register int ans = 0;
	while (node[x].top != node[y].top) {
		if (node[node[x].top].deep > node[node[y].top].deep) {
			ans += _query_Trie(Trie[node[x].id], s, -1) - _query_Trie(Trie[node[node[x].top].id - 1], s, -1);
			x = node[node[x].top].father;
		} else {
			ans += _query_Trie(Trie[node[y].id], s, -1) - _query_Trie(Trie[node[node[y].top].id - 1], s, -1);
			y = node[node[y].top].father;
		}
	}
	if (node[x].id < node[y].id)
		return ans + _query_Trie(Trie[node[y].id], s, -1) - _query_Trie(Trie[node[x].id], s, -1);
	else
		return ans + _query_Trie(Trie[node[x].id], s, -1) - _query_Trie(Trie[node[y].id], s, -1);
}

int main() {

	freopen("strings.in", "r", stdin);
	freopen("strings.out", "w", stdout);

	memset(node, 0, sizeof(node));

	scanf("%d", &n);

	int x, y;
	char s[20];
	for (register int i = 1; i < n; ++i) {
		scanf("%d%d%s", &x, &y, ss[++usage_str]);
		cmp = (__edge *)calloc(sizeof(__edge), 1);
		cmp->next = edge[x];
		edge[x] = cmp;
		edge[x]->v = y;
		edge[x]->s = usage_str;
		cmp = (__edge *)calloc(sizeof(__edge), 1);
		cmp->next = edge[y];
		edge[y] = cmp;
		edge[y]->v = x;
		edge[y]->s = usage_str;
	}

	_dfs1(1, 1);
	_dfs2(1, 1);

	scanf("%d", &Q);
	for (register int i = 0; i < Q; ++i) {
		scanf("%d%d%s", &x, &y, s);
		printf("%d\n", _query_path(x, y, s));
	}

	return 0;
}