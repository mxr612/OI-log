/**
 * 2019.11.14【NOIP提高组】模拟 B 组
 * A 街道
 */

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

int M, N;
std::string l, m, r;

int _get_hash(std::string s) {
	int res = 0;
	for (int i = 0; i < (int)s.size(); ++i)
		res = ((res << 8) + (int)s[i]) % 100000;
	return res;
}
int pt = 0;
struct __hash {
	std::string str;
	int id;
	__hash *nx;
}*hash[100020] = {NULL};
__hash *_insert_s(std::string s) {
	int hashed = _get_hash(s);
	__hash *p = NULL;
	while (p == NULL)p = (__hash *)calloc(1, sizeof(__hash));
	p->str = s, p->id = ++pt, p->nx = hash[hashed], hash[hashed] = p;
	return p;
}
void _insert_n() {

}
int _w_vis(std::string s) {
	int hashed = _get_hash(s);
	for (__hash *i = hash[hashed]; i != NULL; i = i->nx)
		if (i->str == s)
			return i->id;
	return _insert_s(s)->id;
}

struct __edge {
	int v;
	__edge *nx;
}*edge[300020];
void _add_edge(int u, int v) {
	__edge *p = NULL;
	while (p == NULL)p = (__edge *)calloc(1, sizeof(__edge));
	p->v = v, p->nx = edge[u], edge[u] = p;
}
void _free_edge(__edge *&p) {
	if (p != NULL)
		_free_edge(p->nx), free(p), p = NULL;
}
void _make_con(std::string l, std::string m, std::string r) {
	int hl = _w_vis(l), hr = _w_vis(r);
	if (m == "parallel")
		_add_edge(hl, ++pt), _add_edge(pt, hl), _add_edge(pt, hr), _add_edge(hr, pt);
	else
		_add_edge(hl, hr), _add_edge(hr, hl);
}

struct __bin {
	int fa[300020], size[300020];
	void operator<<(int x) {fa[x] = x, size[x] = 1;}
	int _root(int x) {
		if (fa[x] != x)
			fa[x] = _root(fa[x]);
		return fa[x];
	} int operator[](int x) {return _root(x);}
	void operator()(int x, int y) {
		if (_root(x) != _root(y)) {
			if (size[fa[x]] < size[fa[y]])
				size[fa[y]] += size[fa[x]], fa[x] = fa[y];
			else
				size[fa[x]] += size[fa[y]], fa[y] = fa[x];
		}
	}
} bin;

int color[300020] = {0};

bool _dfs(int x, int f, int c) {
	if (color[x] > 0)
		return color[x] % 2 == c % 2;
	color[x] = c, bin(x, f);
	for (__edge *i = edge[x]; i != NULL; i = i->nx)
		if (i->v != f && !_dfs(i->v, x, c + 1))
			return false;
	return true;
}

int main() {
	freopen("A.in", "r", stdin);
	scanf("%d%d", &M, &N);
	for (int i = 1; i <= M; ++i)
		std::cin >> l >> r >> m, _make_con(l, m, r);
	for (int i = 1; i <= pt; ++i)
		bin << i;
	for (int i = 1; i <= pt; ++i) {
		if (color[i] == 0) {
			if (!_dfs(i, i, 1)) {
				printf("Waterloo");
				return 0;
			}
		}
	}
	for (int i = 1; i <= M; ++i) {
		std::cin >> l >> r;
		if (bin[_w_vis(l)] == bin[_w_vis(r)]) {
			if (color[_w_vis(l)] % 2 == color[_w_vis(r)] % 2)
				printf("parallel\n");
			else
				printf("intersect\n");
		} else
			printf("unknown\n");
	}
	for (int i = 1; i <= pt; ++i)
		_free_edge(edge[i]);
	return 0;
}