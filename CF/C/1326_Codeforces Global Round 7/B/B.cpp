/**
 * B
 */

#include <stdio.h>

signed main() {

	// freopen("B.in", "r", stdin);

	int n, b;

	scanf("%d", &n);

	for (register int i = 0, x = 0; i < n; ++i) {
		scanf("%d", &b);
		printf("%d ", b + x);
		if (x < b + x)x = b + x;
	}

	return 0;

}