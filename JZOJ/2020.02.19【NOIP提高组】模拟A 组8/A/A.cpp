/**
 * A
 */

#include <stdio.h>

long long n, k, a;

signed main() {

	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);

	scanf("%lld%lld", &n, &k);

	n = (n * k) % 1000000006;

	a = 1;
	k = 2;
	while (n > 0) {
		if (n & 1)
			a = (a * k) % 1000000007;
		k = (k * k) % 1000000007;
		n >>= 1;
	}

	printf("%d\n", a);

	return 0;
}