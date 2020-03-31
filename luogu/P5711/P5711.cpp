/**
 * P5711
 */

#include <stdio.h>

signed main() {

	freopen("P5711.in", "r", stdin);

	unsigned n;

	scanf("%u", &n);

	printf("%u\n", ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0)) ? (1) : (0));

	return 0;

}