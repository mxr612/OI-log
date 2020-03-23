/**
 * A
 */

#include <stdio.h>

signed main() {

	freopen("A.in", "r", stdin);

	int n, x;

	scanf("%d", &n);

	for (register int i = 0, j; i < n; ++i) {
		scanf("%d", &x);
		if (x == 1)printf("-1\n");
		else {
			for (j = 1; j < x; ++j)
				putchar('9');
			printf("4\n");
		}
	}
	return 0;
}