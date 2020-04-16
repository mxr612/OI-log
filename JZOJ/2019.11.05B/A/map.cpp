/**
 * 2019.11.05【NOIP提高组】模拟 B 组
 * A 地图的密度(MAP)
 * input:map.in
 * output:map.out
 */

#include <stdio.h>

#define low(x) (((x)<0)?(0):(x))
#define top(x) (((x)>n)?(n):(x))

int n, r, f[520][520] = {0}, w[520][520] = {0};

int main() {
	freopen("map.in", "r", stdin);
	freopen("map.out", "w", stdout);
	scanf("%d%d", &n, &r);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &f[i][j]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			w[i][j] = f[i][j] + w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			printf("%d ", w[top(i + r)][top(j + r)] - w[low(i - r - 1)][top(j + r)] - w[top(i + r)][low(j - r - 1)] + w[i - r - 1][low(j - r - 1)]);
		putchar('\n');
	}
	return 0;
}