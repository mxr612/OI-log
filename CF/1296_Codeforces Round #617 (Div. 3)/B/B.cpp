/**
 * B
 */

#include <stdio.h>

int main() {

	freopen("B.in", "r", stdin);

	register int t, s, ans;

	scanf("%d", &t);

	for (register int i = 0; i < t; ++i) {
		scanf("%d", &s);
		ans = 0;
		while (s >= 10) {
			ans += s / 10;
			s = (s / 10) + (s % 10);
		}
		printf("%d\n", ans * 10 + s);
	}

	return 0;
}