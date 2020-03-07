/**
 * B
 */

#include <stdio.h>
#include <algorithm>

int t, n, a[1000020];

int main() {

	freopen("B.in", "r", stdin);

	scanf("%d", &t);

	for (register int i = 0, k, ans; i < t; ++i) {
		scanf("%d", &k);
		n = k << 1;
		for (register int j = 0; j < n; ++j)
			scanf("%d", &a[j]);
		std::nth_element(a, a + k, a + n);
		ans = a[k];
		std::nth_element(a, a + k - 1, a + n);
		ans -= a[k - 1];
		printf("%d\n", ans);
	}

	return 0;
}
