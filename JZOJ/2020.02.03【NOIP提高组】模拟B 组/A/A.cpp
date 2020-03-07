/**
 * A
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>

int N, S, K;
int R[1020];

struct __node {
	int w;
	__node *l, *r;
} nodes[1000000], *root[1020] = {NULL};
int usage = 0;

void _build_tree(register __node *&u, register int l, register int r) {
	if (r < l) return ;
	u = &nodes[++usage];
	if (l < r) _build_tree(u->l, l, (l + r) / 2), _build_tree(u->r, (l + r) / 2 + 1, r);
}
void _insert(register __node *&u, register __node *U, register int l, register int r, register int w) {
	if (r < l || r < w || w < l)
		return ;
	u = &nodes[++usage];
	u->w = U->w + 1;
	if (l == r)
		return ;
	if (w <= (l + r) / 2) {
		_insert(u->l, U->l, l, (l + r) / 2, w);
		u->r = U->r;
	} else {
		u->l = U->l;
		_insert(u->r, U->r, (l + r) / 2 + 1, r, w);
	}
}
int _query(register __node *U, register int l, register int r, register int L, register int R) {
	if (r < l || R < l || r < L || U == NULL) return 0;
	if (L <= l && r <= R) return U->w;
	else return _query(U->l, l, (l + r) / 2, L, R) + _query(U->r, (l + r) / 2 + 1, r, L, R);
}

int res[100][100] = {0}, ans[1020][100];

int main() {

	freopen("board.in", "r", stdin);
	// freopen("board.out","w",stdout);

	memset(nodes, 0, sizeof(nodes));
	memset(ans, 0x6f, sizeof(ans));

	scanf("%d%d%d", &N, &S, &K);

	_build_tree(root[0], 1, S);

	for (register int i = 1; i <= N; ++i)
		scanf("%d", &R[i]), _insert(root[i], root[i - 1], 1, S, R[i]);

	for (register int i = 1; i <= N; ++i) {
		for (register int j = 1; j <= R[i]; ++j) {
			for (register int k = R[i]; k <= S; ++k) {
				res[j][k] += _query(root[i], 1, S, j, R[i] - 1);
			}
		}
	}

	// for (register int i = 1; i <= S; ++i) {
	// 	for (register int j = 1; j <= S; ++j) {
	// 		printf("%5d", res[i][j]);
	// 	}
	// 	putchar('\n');
	// }

	ans[0][0] = 0;
	for (register int i = 1; i <= S; ++i) {
		for (register int j = 1; j <= K; ++j) {
			for (register int k = 0; k < i; ++k) {
				ans[i][j] = std::min(ans[i][j], ans[k][j - 1] + res[k + 1][i]);
			}
		}
	}

	// for (register int i = 1; i <= S; ++i) {
	// 	for (register int j = 1; j <= K; ++j) {
	// 		printf("%5d", ans[i][j]);
	// 	}
	// 	putchar('\n');
	// }

	printf("%d\n", ans[S][K]);

	return 0;
}