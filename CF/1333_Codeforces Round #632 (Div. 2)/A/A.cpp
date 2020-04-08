/**
 * A
 */

#include <stdio.h>

signed main() {

#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
#endif

	int T, n, m;

	scanf("%d", &T);

	for (register int t = 0, i, j; t < T; ++t) {
		scanf("%d%d", &n, &m);
		putchar('W');
		for (i = 1; i < m; ++i)putchar('B');
		putchar('\n');
		for (i = 1; i < n; ++i) {
			for (j = 0; j < m; ++j)
				putchar('B');
			putchar('\n');
		}
	}

	return 0;

}