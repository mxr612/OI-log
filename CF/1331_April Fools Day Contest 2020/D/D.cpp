/**
 * D
 */

#include <stdio.h>

signed main() {

	freopen("D.in", "r", stdin);

	int x;

	getchar();
	scanf("%d", &x);

	if (x & 1)putchar('1');
	else putchar('0');

	return 0;

}