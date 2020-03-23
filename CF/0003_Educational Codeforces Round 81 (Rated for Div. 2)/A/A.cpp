/**
 * A
 */

#include <stdio.h>

int main() {

	freopen("A.in", "r", stdin);

	register int t, n;

	scanf("%d", &t);

	for (register int i = 0; i < t; ++i) {
		scanf("%d", &n);
		if (n & 1) {
			putchar('7');
			for (register int j = 0; j < (n >> 1) - 1; ++j)
				putchar('1');
			putchar('\n');

		} else {
			for (register int j = 0; j < (n >> 1); ++j)
				putchar('1');
			putchar('\n');
		}
	}

	return 0;
}