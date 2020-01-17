/**
 * B
 */

#include <stdio.h>



int _cnt(register int a) {
	register int res = 0;
	while (a > 0)
		res += a % 10, a /= 10;
	return res;
}

int main() {

	freopen("B.in", "r", stdin);

	register int N, k = 0, ans[100];

	scanf("%d", &N);

	for (int i = 81; i >= 0; --i)
		if ((N - i > 0) && (N - i + _cnt(N - i) == N))
			ans[++k] = N - i;

	printf("%d\n", k);

	for (register int i = 1; i <= k; ++i)
		printf("%d\n", ans[i]);

	return 0;
}