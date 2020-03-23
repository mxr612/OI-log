/**
 * 1327
 * A
 */

#include <stdio.h>

signed main() {

	freopen("A.in", "r", stdin);

	long long t, n, k;

	scanf("%lld", &t);

	for (register int i = 0; i < t; ++i) {
		scanf("%lld%lld", &n, &k);
		if (n >= k && (n - k) % 2 == 0 && n >= k * k)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;

}