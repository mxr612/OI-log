/**
 * A
 */

#include <stdio.h>

signed main() {

	freopen("A.in", "r", stdin);

	int n, x;

	scanf("%d", &n);

	for (register int i = 0; i < n; ++i) {
		scanf("%d", &x);
		if (x == 1)printf("-1\n");
		else {
			for (register int i = 1; i < x; ++i)
				putchar('9');
			printf("4\n");
		}
	}
	return 0;
}