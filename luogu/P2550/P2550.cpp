/**
 * P2550
 */
#include <stdio.h>
int n, g, ans[10];
long long m[70], a[1020];
signed main() {
	freopen("P2550.in", "r", stdin);
	// freopen("P2550.out", "w", stdout);
	scanf("%d", &n);
	m[0] = 1;
	for (register int i = 1; i <= 60; ++i)
		m[i] = m[i - 1] << 1;
	for (register int i = 0, j; i <= n; ++i)
		for (j = 0; j < 7; ++j)
			scanf("%d", &g), a[i] |= m[g];
	for (register int i = 1; i <= n; ++i)
		a[i] &= a[0];
	for (register int i = 1, k; i <= n; ++i, ++ans[k])
		for (k = 0; a[i] > 0; ++k)a[i] -= a[i] & (-a[i]);
	for (register int i = 7; i > 0; --i)
		printf("%d ", ans[i]);
	return 0;

}