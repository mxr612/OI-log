/**
 * B
 */

#include <stdio.h>

signed main() {

	freopen("B.in", "r", stdin);

	unsigned long long t, n, k, l, r, m, g;

	scanf("%llu", &t);

	for (unsigned long long i = 0, j; i < t; ++i) {
		scanf("%llu%llu", &n, &k);
		l = 0; r = 100001;
		while (l < r) {
			m = (l + r) >> 1;
			g = (m * m + m) >> 1;
			if (g == k)
				l = r = m;
			else if (g < k)l = m + 1;
			else r = m - 1;
		}
		if ((l * l + l) >> 1 == k)
			r = n - l, l = r - 1;
		else {
			if ((l * l + l) >> 1 > k)--l;
			r = n + ((l * l + l) >> 1) - k;
			l = n - l - 2;
		}
		for (j = 0; j < l; ++j)putchar('a'); putchar('b');
		for (j = l + 1; j < r; ++j)putchar('a'); putchar('b');
		for (j = r + 1; j < n; ++j)putchar('a'); putchar('\n');
	}


	return 0;

}