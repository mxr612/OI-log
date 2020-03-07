/**
 * div.2 B
 */

#include <stdio.h>

int num[11] = {0};

int main() {

	freopen("B.in", "r", stdin);

	register int n, ans = 0;
	register bool flag = true;

	scanf("%d", &n);

	for (register int i = 1, a; i <= n; ++i)
		scanf("%d", &a), ++num[a % 10], ans += a;
	ans %= 10;

	for (register int i = 0; i < 10 && flag; ++i) {
		if (num[i] > 0) {
			--num[i];
			if (num[(ans + 10 - i) % 10] > 0)
				flag = false;
			++num[i];
		}
	}
	printf("%d\n", (flag) ? (0) : ((ans == 0) ? (10) : (ans)));

	return 0;
}