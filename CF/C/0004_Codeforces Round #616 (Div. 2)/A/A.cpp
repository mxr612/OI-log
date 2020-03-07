/**
 * A
 */

#include <stdio.h>

int n, t, a[3020], sum, l, r;
char c[3020];

int main() {

	// freopen("A.in", "r", stdin);

	scanf("%d", &t);

	for (register int i = 0; i < t; ++i) {
		scanf("%d", &n);
		l = r = -1;
		sum = 0;
		scanf("%s", c);
		for (register int j = 1; j <= n; ++j) {
			a[j] = c[j - 1] - '0';
			sum += a[j];
			if (l == -1 && a[j] == 0)
				l = j;
			if (a[j] & 1)
				r = j;
		}
		if (sum & 1) {
			for (register int j = r - 1; j <= n; ++j) {
				if (a[j] & 1 && (!(j == 1 && 2 == l))) {
					a[j] = -1;
					--sum;
					break;
				}
			}
		}
		if (sum & 1 || r == -1)
			printf("-1\n");
		else {
			for (register int j = 1; j <= r; ++j)
				if (a[j] != -1)
					printf("%d", a[j]);
			putchar('\n');
		}

	}



	return 0;
}