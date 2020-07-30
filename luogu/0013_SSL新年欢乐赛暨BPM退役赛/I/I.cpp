/**
 * I
 */

#include <stdio.h>
#include <algorithm>
int main() {

	freopen("I.in", "r", stdin);

	long long n, m, ans;
	while (scanf("%lld%lld", &n, &m) != EOF) {
		ans = 0;
		for (long long i = 1; i <= 2016; ++i)
			for (long long j = 1; j <= 2016; ++j)
				if ((i * j) % 2016 == 0 && i <= n && j <= m)
					ans += ((n - i) / 2016 + 1) * ((m - j) / 2016 + 1);
		printf("%lld\n", ans);
	}

	return 0;
}