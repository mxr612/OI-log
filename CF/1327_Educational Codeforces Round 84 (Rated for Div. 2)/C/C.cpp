/**
 * C
 */

#include <stdio.h>

signed main() {

	freopen("C.in", "r", stdin);

	unsigned short n, m;

	scanf("%hu%hu", &n, &m);
	printf("%hu\n", n * m + n + m - 3);
	register int i, j;
	for (i = 1; i < n; ++i)putchar('D');
	for (i = 1; i < m; ++i)putchar('L');
	for (i = 1; i <= n; ++i) {
		if (i & 1)
			for (j = 1; j < m; ++j)putchar('R');
		else
			for (j = 1; j < m; ++j)putchar('L');
		if (i < n)putchar('U');
	}

	return 0;

}