/**
 * A
 */

#include <stdio.h>

long long x, a, b, c, n, m, z;
int rep[1000020] = {0};

long long ksm(long long a, long long x, long long m) {
	long long res = 1;
	for (; x > 0; a = (a * a) % m, x >>= 1)
		if (x & 1)
			res = (res * a) % m;
	return res;
}

signed main() {

	freopen("A.in", "r", stdin);

	scanf("%d%d%d%d%d%d", &x, &a, &b, &c, &n, &m);

	x %= m;

	if (4 * a * c + 2 * b == b * b && b % (2 * a) == 0) {
		z = ksm(2, n, m - 1);
		printf("%lld\n", (ksm(a, z - 1, m)*ksm(x + b / 2 / a, z, m) + m - b / 2 / a) % m);
	} else {
		if (m < 1000000) {
			for (register int i = 0; i < n; ++i) {
				if (rep[x] > 0) {
					n = ((n - rep[x]) % (i - rep[x]));
					break;
				}
				rep[x] = i;
				x = (((x * x) % m) * a + x * b + c) % m;
			}
		}
		for (register int i = 0; i < n; ++i)
			x = (((x * x) % m) * a + x * b + c) % m;
		printf("%lld\n", x);
	}


	return 0;
}