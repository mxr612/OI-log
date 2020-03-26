/**
 * C
 */

#include <stdio.h>
#include <string.h>

unsigned ans[2][50020];

signed main() {

	freopen("C.in", "r", stdin);

	unsigned t, n;

	scanf("%u\n", &t);

	for (register unsigned i = 0, j, flag, x; i < t; ++i) {
		scanf("%u\n", &n);
		memset(ans, 0, sizeof(ans)), flag = 0;
		for (j = 0; j < n; ++j) {
			x = getchar() - '0';
			// printf("%u ", x);
			if (flag == 0) {
				if (x == 1)
					ans[0][j] = flag = 1;
				else
					ans[0][j] = ans[1][j] = x >> 1;
			} else
				ans[1][j] = x;
		}
		for (j = 0; j < n; ++j)printf("%u", ans[0][j]); putchar('\n');
		for (j = 0; j < n; ++j)printf("%u", ans[1][j]); putchar('\n');
	}

	return 0;

}