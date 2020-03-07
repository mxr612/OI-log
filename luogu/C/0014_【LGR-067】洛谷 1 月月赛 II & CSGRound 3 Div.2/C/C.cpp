/**
 * div.2 C
 * div.1 A
 */

#include <stdio.h>

int n, k, ans = 0, a[1000020];
long long sum1[1000020] = {0}, sum2[1000020] = {0};

inline int _bound(register int l, register int r, register int g) {
	register int m;
	while (l < r) {
		m = (l + r) / 2;
		if (sum1[m] == g)
			return sum1[m];
		if (sum1[m] < m)
			l = m + 1;
		else
			r = m - 1;
	}
	return sum1[l];
}

int main() {

	freopen("C.in", "r", stdin);

	scanf("%d", &n);
	for (register int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), sum1[i] = sum1[i - 1] + a[i];
	scanf("%d", &k);

	// for (int i = 1; i <= n; ++i)
	// 	printf("%d ", sum1[i]);
	// putchar('\n');
	for (register int i = 1, r; i <= n; ++i) {
		r = _bound(i + 1, n, sum1[i] << 1) - sum1[i];
		if (sum1[i] < r)
			++sum2[sum1[i]], --sum2[r];
		// printf("%d ", sum1[i]);
		// printf("%d\n", r);
	}
	for (register int i = 1; i <= k; ++i) {
		sum2[i] += sum2[i - 1];
		if (sum2[i] > 0)
			ans++;
	}
	printf("%d\n", ans);
	for (register int i = 1; i <= k; ++i) {
		if (sum2[i] > 0)
			printf("%d ", i);
	}
	return 0;
}