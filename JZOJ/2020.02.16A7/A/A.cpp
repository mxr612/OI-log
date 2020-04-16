/**
 * A
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>

long long n, m, l, r, x, y, z, sb;
char c;
long long k[1000020][6];
long long e[1000020], w[1000020];

struct __tree {
	long long w;
	int l, r;
	__tree *ls, *rs;
} tree[4000020], *root = NULL;
int usage = 0;

void _build_tree(__tree *&x, int l, int r) {
	if (r < l)return ;
	x = &tree[++usage];
	x->l = l;
	x->r = r;
	if (l == r)
		x->w = l;
	else
		_build_tree(x->ls, l, (l + r) / 2), _build_tree(x->rs, (l + r) / 2 + 1, r);
}
void _tree_modify(int W, int L, int R, __tree *x) {
	if (x == NULL || x->r < L || R < x->l)return ;
	else if (L <= l && r <= R)
		x->w = W;
	else {
		x->ls->w = x->rs->w = x->w;
		x->w = 0;
		_tree_modify(W, L, R, x->ls);
		_tree_modify(W, L, R, x->rs);
	}
}
int _tree_query(int V, __tree *x) {
	if (x == NULL || x->r < V || V < x->l)return 0;
	else if (x->w > 0)
		return x->w;
	else
		return std::max(_tree_query(V, x->ls), _tree_query(V, x->rs));
}

int main() {

	freopen("query1.in", "r", stdin);

	std::cin >> n >> m;

	_build_tree(root, 1, n);

	for (register int i = 1; i <= n; ++i)
		k[i][0] = 1;
	for (register int i = 1; i < 6; ++i)
		for (register int j = 1; j <= n; ++j)
			k[j][i] = (k[j][i - 1] * j) % 1000000007;
	for (register int i = 0; i < 6; ++i)
		for (register int j = 1; j <= n; ++j)
			k[j][i] = (k[j - 1][i] + k[j][i]) % 1000000007;

	for (int i = 1; i <= n; ++i)
		std::cin >> w[i], e[i] = i;

	for (register int i = 0; i < m; ++i) {
		std::cin >> c >> l >> r >> x;
		if (c == '=') {
			z = _tree_query(l, root);
			if (z < l)
				e[z] = l - 1;
			z = _tree_query(r, root);
			if (r < e[r]) {
				w[r + 1] = w[z];
				e[r + 1] = e[z];
				_tree_modify(r + 1, r + 1, e[z], root);
			}
			e[l] = r;
			w[l] = x % 1000000007;
			_tree_modify(l, l, r, root);
		} else {
			z = _tree_query(l, root);
			if (r <= e[z])
				printf("%lld\n", (w[z]*k[r - l + 1][x]) % 1000000007);
			else {
				y = (w[z] * k[e[z] - l + 1][x]) % 1000000007;
				sb = l;
				l = e[z] + 1;
				z = e[z] - sb + 1;
				while (e[l] < r) {
					y = (y + w[l] * (k[e[l] - l + 1 + z][x] - k[z][x])) % 1000000007;
					z += e[l] - l + 1;
					l = e[l] + 1;
				}
				printf("%lld\n", (y + w[l] * (k[r - l + 1 + z][x] - k[z][x])) % 1000000007);
			}
		}
	}
	return 0;
}
