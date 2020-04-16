/**
 * B
 * Path
 * 深搜暴力程序50pts
 */

#include <stdio.h>

const short WAY[4][2] = {
	{ -1, 0},
	{0, 1},
	{1, 0},
	{0, -1}
};

int n, m, k, X, Y;
bool map[120][120] = {false};

inline int _dfs(register short x, register short y, register short w, register short l, register short r, register short d, register short u) {
	if (map[x][y])
		return 0;
	if (x == X && y == Y)
		return 1;
	register int res = 0;
	if (l < x + WAY[w][0] && x + WAY[w][0] < r && d < y + WAY[w][1] && y + WAY[w][1] < u)
		res += _dfs(x + WAY[w][0], y + WAY[w][1], w, l, r, d, u);
	w = (w + 1) % 4;
	if (l < x + WAY[w][0] && x + WAY[w][0] < r && d < y + WAY[w][1] && y + WAY[w][1] < u) {
		if (w == 0)r = x;
		if (w == 1)d = y;
		if (w == 2)l = x;
		if (w == 3)u = y;
		res += _dfs(x + WAY[w][0], y + WAY[w][1], w, l, r, d, u);
	}
	return res % k;
}

signed main() {

	freopen("B.in", "r", stdin);

	scanf("%d%d%d%d%d\n", &n, &m, &k, &Y, &X);

	for (register int i = 1; i <= n; ++i) {
		for (register int j = 1; j <= m; ++j)
			if (getchar() == '*')
				map[i][j] = true;
		getchar();
	}

	printf("%d\n", _dfs(n, 1, 0, 0, n + 1, 0, m + 1));

	return 0;
}