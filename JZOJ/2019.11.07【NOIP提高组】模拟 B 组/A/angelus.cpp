/**
 * JZOJ_2019.11.07【NOIP提高组】模拟 B 组
 * A 七天使的通讯(angelus)
 * <错解>差分数组贪心
 * <正解>建图染色判断二分图
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>

int t, n, m, u[1020], v[1020], color[1020], cnt;
bool edge[1020][1020] = {false};

bool _dfs(int x, int c) {
	if (color[x] > 0)
		return (c % 2) == (color[x] % 2);
	--cnt;
	color[x] = c;
	for (int i = 1; i <= m; ++i)
		if (edge[x][i] && !_dfs(i, c + 1))
			return false;
	return true;
}
bool _is(int a, int b, int c, int d) {
	if (a < c && c < b && b < d)return true;
	if (c < a && a < d && d < b)return true;
	return false;
}
signed main() {
	freopen("angelus1.in", "r", stdin);
	scanf("%d", &t);
	while (t-- > 0) {
		memset(color, 0, sizeof(color));
		scanf("%d%d", &n, &m);
		cnt = n;
		for (int i = 1; i <= m; ++i)
			scanf("%d%d", &u[i], &v[i]);
		for (int i = 1; i < m; ++i)
			for (int j = i + 1; j <= m; ++j)
				edge[i][j] = edge[j][i] = _is(std::min(u[i], v[i]), std::max(u[i], v[i]), std::min(u[j], v[j]), std::max(u[j], v[j]));
		for (int i = 1; cnt > 0 && i <= m; ++i) {
			if (color[i] == 0 && !_dfs(i, 1))
				printf("non\n"), cnt = -1;
		}
		if (cnt != -1)
			printf("sane\n");
	}
	return 0;
}