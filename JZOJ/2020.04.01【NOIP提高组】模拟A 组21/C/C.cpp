/**
 * C
 */

#include <stdio.h>

#define MXN (200020)

unsigned N, a[MXN] = {0}, b[MXN] = {0}, aa = 0, bb = 0;

signed main() {

	freopen("balance.in", "r", stdin);
	// freopen("balance.out", "w", stdout);

	scanf("%u", &N);

	for (register unsigned i = 1; i <= N; ++i)scanf("%u", &a[i]), a[i] += a[i - 1];
	for (register unsigned i = 1; i <= N; ++i)scanf("%u", &b[i]), b[i] += b[i - 1];
	for (register unsigned i = N; i > 0; --i)if (a[i] == a[i - 1])aa += a[i];
	for (register unsigned i = N; i > 0; --i)if (b[i] == b[i - 1])bb += b[i];
	printf("%u\n%u\n", aa, bb);

	return 0;

}