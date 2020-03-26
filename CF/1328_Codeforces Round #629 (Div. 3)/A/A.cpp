/**
 * A
 */

#include <stdio.h>
#include <math.h>

signed main() {

	freopen("A.in", "r", stdin);

	unsigned t;
	double a, b;

	scanf("%u", &t);

	for (register unsigned i = 0; i < t; ++i) {
		scanf("%lf%lf", &a, &b);
		printf("%.0lf\n", b * ceil(a / b) - a);
	}

	return 0;

}