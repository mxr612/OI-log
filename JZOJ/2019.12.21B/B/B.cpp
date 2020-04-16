/**
 * 2019.12.21【NOIP提高组】模拟B 组
 * A
 * 1257 滑雪场的缆车
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>

int N, K, A[5020], H[5020];

signed main() {

	freopen("data11.in", "r", stdin);

	memset(A, 0x7f, sizeof(A)); A[1] = 1;

	scanf("%u%u", &N, &K);
	for (register int i = 1; i <= N; ++i)
		scanf("%d", &H[i]);

	register long long a = -2 * 1e9, b = 1;

	for (register int i = 1; i <= N; ++i, a = -2e9, b = 1)
		for (register int j = i + 1; j <= i + K && j <= N; ++j)
			if ((H[j] - H[i]) * b >= a * (j - i))
				A[j] = std::min(A[j], A[i] + 1), a = H[j] - H[i], b = j - i;

	printf("%d", A[N]);

	return 0;
}