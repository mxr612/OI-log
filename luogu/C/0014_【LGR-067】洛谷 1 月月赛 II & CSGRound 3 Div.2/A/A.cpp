/**
 * div.1 A
 */

#include <stdio.h>

long long bank[1000001] = {0};

int main() {

	freopen ("A.in", "r", stdin);

	register int m, t, a, b, ans = 0;

	scanf("%d", &m);

	for (register int i = 1; i <= m; ++i) {
		bank[i] += bank[i - 1];
		scanf("%d", &t);
		switch (t) {
		case 1:
			scanf("%d", &a);
			bank[i] += a;
			break;
		case 2:
			scanf("%d", &a);
			if (bank[i] >= a)
				bank[i] -= a;
			else
				++ans;
			break;
		case 3:
			scanf("%d%d", &a, &b);
			bank[i] -= a;
			bank[b] += a;
			break;
		default: break;
		}
	}

	printf("%d\n", ans);

	return 0;
}