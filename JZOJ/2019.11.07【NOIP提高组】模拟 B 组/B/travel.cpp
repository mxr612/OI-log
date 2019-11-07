/**
 * JZOJ_2019.11.07【NOIP提高组】模拟 B 组
 * B 都市环游(travel)
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>

const int MOD = 10086;

int n, m, t;

struct __hi {
	int id, vl;
	bool operator<(__hi x) {return vl < x.vl;}
} hi[1000];

int node[1000] = {0}, edge[1000][1000] = {0}, cmp[1000][1000], ans = 0;

int main() {
	freopen("travel.in", "r", stdin);
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &hi[i].vl), hi[i].id = i;
	for (int i = 1, u, v; i <= m; ++i)
		scanf("%d%d", &u, &v), ++edge[u][v];
	std::sort(&hi[1], &hi[n + 1]);
	node[1] = 1;
	for (int i = 1; i <= hi[n].vl && i <= t; ++i) {
		memset(cmp, 0, sizeof(cmp[0]));
		for (int x = 1; x <= n && hi[x].vl <= i; ++x)
			for (int y = 1; y <= n && hi[y].vl <= i; ++y)
				cmp[0][x] = (cmp[0][x] + node[y] * edge[y][x]) % MOD;
		for (int x = 1; x <= n && hi[x].vl <= i; ++x)
			node[x] = (node[x] + cmp[0][x]) % MOD;
	}

	t -= hi[n].vl;
	while (t > 0) {
		if (t & 1) {
			for (int x = 1; x <= n; ++x) {
				cmp[0][x] = 0;
				for (int y = 1; y <= n; ++y)
					cmp[0][x] = (cmp[0][x] + node[y] * edge[y][x]) % MOD;
			}
			for (int x = 1; x <= n; ++x)
				node[x] = (node[x] + cmp[0][x]) % MOD;
		}
		t >>= 1;
		memset(cmp, 0, sizeof(cmp));
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				for (int k = 1; k <= n; ++k)
					cmp[i][j] = (cmp[i][j] + edge[i][k] * edge[k][j]) % MOD;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				edge[i][j] = cmp[i][j];
	}

	for (int i = 1; i <= n; ++i)
		ans = (ans + node[i]) % MOD;
	printf("%d", ans);
	return 0;
}