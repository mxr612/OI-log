/**
 * A
 */

#include <stdio.h>

int a[1000020] = {0};

inline int max(int a, int b) {
	return a > b ? a : b;
}

signed main() {

	freopen("reserve.in", "r", stdin);
	freopen("reserve.out", "w", stdout);

	int N, A, B;

	scanf("%d", &N);

	for (register int i = 0; i < N; ++i)
		scanf("%d%d", &A, &B), ++a[A], --a[B + 1];

	register int ans = 0;
	for (register int i = 1; i <= 1000000; ++i)
		a[i] += a[i - 1], ans = max(ans, a[i]);

	printf("%d\n", ans);

	return 0;

}