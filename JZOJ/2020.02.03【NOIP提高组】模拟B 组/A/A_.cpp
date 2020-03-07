/**
 * A_.cpp
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>

int N, S, K;

int tree[1020] = {0};
#define _lowbit(dfalkjd) ((dfalkjd)&(-(dfalkjd)))
void _insert(register int x, register int w) {
	for (; x <= S; x += _lowbit(x))
		tree[x] += w;
}
int _query(register int l, register int r) {
	register int ret = 0;
	if (r < l)
		return 0;
	for (; r > 0; r -= _lowbit(r))
		ret += tree[r];
	for (--l; l > 0; l -= _lowbit(l))
		ret -= tree[l];
	return ret;
}

int res[1020][1020] = {0};

int dp[1020][1020];

int main() {

	freopen("board.in", "r", stdin);
	// freopen("board.out","w",stdout);

	scanf("%d%d%d", &N, &S, &K);

	for (register int i = 0, ri; i < N; ++i) {
		scanf("%d", &ri);
		_insert(ri, 1);
		for (register int l = ri, a; l > 0; --l) {
			a = _query(l, ri - 1);
			for (register int r = ri; r <= S; ++r) {
				res[l][r] += a;
			}
		}
	}

	// for (register int l = 1; l <= S; ++l) {
	// 	for (register int r = 1; r < S; ++r) {
	// 		printf("%5d", res[l][r]);
	// 	}
	// 	putchar('\n');
	// }

	memset(dp, 0x7f, sizeof(dp));
	dp[0][0] = 0;
	for (register int i = 1; i <= S; ++i) {
		for (register int j = 1; j <= K; ++j) {
			for (register int k = 0; k < i; ++k) {
				dp[i][j] = std::min(dp[i][j], dp[k][j - 1] + res[k + 1][i]);
			}
			// printf("%10d", dp[i][j]);
		}
		// putchar('\n');
	}

	printf("%d\n", dp[S][K]);

	return 0;
}