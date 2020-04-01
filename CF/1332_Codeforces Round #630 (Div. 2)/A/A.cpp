/**
 * 1332
 * Codeforces Round #630 (Div. 2)
 * A
 */

#include <stdio.h>

int T, a, b, c, d, X, Y, x[2], y[2];

signed main() {

	freopen("A.in", "r", stdin);

	scanf("%u", &T);

	for (register int t = 0; t < T; ++t) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		scanf("%d%d%d%d%d%d", &X, &Y, &x[0], &y[0], &x[1], &y[1]);
		if ((x[0] <= b - a && b - a <= x[1]) && (y[0] <= d - c && d - c <= y[1]) && ((a == 0 && b == 0) || x[0] < X || X < x[1]) && ((c == 0 && d == 0) || y[0] < Y || Y < y[1]))
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;

}
