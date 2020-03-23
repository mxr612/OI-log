/**
 * A
 */

#include <stdio.h>

int main() {

	// freopen("A.in", "r", stdin);

	int t, n, p;
	register int s, c;

	scanf("%d", &t);

	for (register int i = 0; i < t; ++i) {
		s = c = 0;
		scanf("%d", &n);
		for (register int j = 0; j < n; ++j) {
			scanf("%d", &p);
			if (p == 0)++c;
			s += p;
		}
		s += c;
		printf("%d\n", c + ((s == 0) ? (1) : 0));
	}

	return 0;
}