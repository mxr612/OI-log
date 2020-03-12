/**
 * B
 */

#include <stdio.h>
#include <stdlib.h>
#include <stack>

typedef unsigned long long ULL;

ULL n, ans = -1, res[1000020] = {0};

inline ULL min(ULL a, ULL b) {
	return a < b ? a : b;
}

struct __edge {
	int v;
	int size;
	ULL ans;
	__edge *next, *reve;
}*edge[1000020] = {NULL}, *root = (__edge *)calloc(sizeof(__edge), 1), *buf = (__edge *)calloc(sizeof(__edge), 1);

void _add_edge(int x, int y) {
	__edge *tx = (__edge *)calloc(sizeof(__edge), 1);
	__edge *ty = (__edge *)calloc(sizeof(__edge), 1);
	tx->v = x;
	tx->reve = ty;
	tx->next = edge[y];
	edge[y] = tx;
	ty->v = y;
	ty->reve = tx;
	ty->next = edge[x];
	edge[x] = ty;
}

void _get_size(__edge *x, int f) {
	for (__edge *i = edge[x->v]; i != NULL; i = i->next) {
		if (i->v == f)continue;
		_get_size(i, x->v);
		i->reve->size = n - i->size;
		x->size += i->size;
	}
	++x->size;
}

void _get_ans_down(__edge *x) {
	int size = x->size - 1;
	for (__edge *i = edge[x->v]; i != NULL; i = i->next) {
		if (i == x->reve)continue;
		_get_ans_down(i);
		x->ans += i->size * (size - i->size) + i->ans;
		size -= i->size;
	}
}

void _get_ans_all(__edge *x) {
	res[x->v] = x->ans + (x->size - 1) * (n - x->size) + x->reve->ans;
	for (__edge *i = edge[x->v]; i != NULL; i = i->next) {
		if (i == x->reve)continue;
		i->reve->ans = res[x->v] - i->size * (n - 1 - i->size) - i->ans;
		_get_ans_all(i);
	}
}

signed main() {

	freopen("B.in", "r", stdin);

	scanf("%llu", &n);

	int x, y;
	for (register int i = 1; i < n; ++i)
		scanf("%d%d", &x, &y), _add_edge(x, y);

	root->v = 1;
	root->reve = buf;

	_get_size(root, 0);

	_get_ans_down(root);

	_get_ans_all(root);

	for (register int i = 2; i <= n; ++i) {
		ans = min(ans, res[i]);
		// printf("%llu\n", res[i]);
	}

	printf("%llu\n", min(ans, root->ans) + n * (n - 1) / 2);

	return 0;

}