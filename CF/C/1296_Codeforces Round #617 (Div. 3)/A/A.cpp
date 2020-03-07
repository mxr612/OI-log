/**
 * A
 */

#include <stdio.h>

int main() {

	// freopen("A.in", "r", stdin);

	register int t, n, sum;
	register bool ji, ou;
	int a[2020];

	scanf("%d", &t);

	for (register int i = 0; i < t; ++i) {
		sum = ji = ou = false;
		scanf("%d", &n);
		for (register int j = 0, a; j < n; ++j) {
			scanf("%d", &a);
			sum += a;
			if (a & 1)
				ji = true;
			else
				ou = true;
		}
		if (sum & 1 || (ji && ou))
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}