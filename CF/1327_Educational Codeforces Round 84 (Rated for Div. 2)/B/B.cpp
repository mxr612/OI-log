/**
 * 1327
 * B
 */

#include <stdio.h>
#include <string.h>

signed main() {

	freopen("B.in", "r", stdin);

	int T, n, e, g, cnt;
	bool p[2][100020];

	scanf("%d", &T);

	for (register int t = 0, i, j, k; t < T; ++t) {
		memset(p, 0, sizeof(p));
		cnt = 0;
		scanf("%d", &n);
		for (i = 1; i <= n; ++i) {
			scanf("%d", &e);
			for (j = 0; j < e; ++j) {
				scanf("%d", &g);
				if (!(p[0][i] || p[1][g]))p[0][i] = p[1][g] = true, ++cnt;
			}
		}
		if (cnt == n)
			printf("OPTIMAL\n");
		else {
			printf("IMPROVE\n");
			for (i = 1; i <= n && p[0][i]; ++i);
			for (j = 1; j <= n && p[1][j]; ++j);
			printf("%d %d\n", i, j);
		}
	}


	return 0;

}