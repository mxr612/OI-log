/**
 * C
 */

#include <stdio.h>

signed main() {

	freopen("C.in", "r", stdin);

	int a, s = 0, h[6] = {4, 1, 3, 2, 0, 5};
	/*
	{1, 4, 2, 3, 5, 0}
	{0, 5, 3, 2, 4, 1}
	 */
	scanf("%d", &a);

	for (register int i = 0; i < 6; ++i)
		if (a & (1 << i))
			s |= 1 << h[i];

	printf("%d\n", s);

	return 0;

}