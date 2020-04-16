/**
 * JZOJ_2019.11.07【NOIP提高组】模拟 B 组
 * B 都市环游(travel)
 * 路径计数
 * 矩阵乘法
 * ！读题警告
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>

int MOD = 10086, n, m, t, hi[1000], mxs = 0, edge[1000][1000] = {0}, node[1000] = {0},  cmp[1000][1000], ans = 0;

int main() {
	freopen("travel1.in", "r", stdin);
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &hi[i]), mxs = std::max(mxs, hi[i]), ++edge[i][i];
	for (int i = 1, u, v; i <= m; ++i)
		scanf("%d%d", &u, &v), ++edge[u][v];
	node[1] = 1;
	for (int i = 1; i <= mxs && i <= t; ++i) {
		memset(cmp, 0, sizeof(cmp[0]));
		for (int x = 1; x <= n; ++x)
			if (hi[x] <= i)
				for (int y = 1; y <= n; ++y)
					cmp[0][x] = (cmp[0][x] + node[y] * edge[y][x]) % MOD;

		for (int x = 1; x <= n; ++x)
			node[x] = cmp[0][x];
	}
	t -= mxs;
	while (t > 0) {
		memset(cmp, 0, sizeof(cmp));
		if (t & 1) {
			for (int x = 1; x <= n; ++x)
				for (int y = 1; y <= n; ++y)
					cmp[0][x] = (cmp[0][x] + node[y] * edge[y][x]) % MOD;
			for (int x = 1; x <= n; ++x)
				node[x] = cmp[0][x];
		}
		t >>= 1;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				for (int k = 1; k <= n; ++k)
					cmp[i][j] = (cmp[i][j] + edge[i][k] * edge[k][j]) % MOD;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				edge[i][j] = cmp[i][j];
	}
	printf("%d", node[n]);
	return 0;
}