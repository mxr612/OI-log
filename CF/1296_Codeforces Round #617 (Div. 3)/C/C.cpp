/**
 * C
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>

int main() {

	freopen("C.in", "r", stdin);

	register int t, n;
	register bool flag;
	char s[100020];
	int a[100020][2];

	scanf("%d", &t);

	for (register int i = 0; i < t; ++i) {
		memset(a, 0, sizeof(a));
		flag = true;
		scanf("%d", &n);
		scanf("%s", s);
		for (register int j = 1; j <= n; ++j) {
			a[j][0] = a[j - 1][0];
			a[j][1] = a[j - 1][1];
			switch (s[j - 1]) {
			case 'U': ++a[j][0]; break;
			case 'D': --a[j][0]; break;
			case 'L': ++a[j][1]; break;
			case 'R': --a[j][1]; break;
			default:;
			}
		}
		for (int j = 1; j <= n && flag; ++j) {
			for (int k = j + 1; k <= n && flag; ++k) {
				if (a[k][0] - a[j - 1][0] == 0 && a[k][1] - a[j - 1][1] == 0)
					printf("%d %d\n", j, k), flag = false;
			}
		}
		if (flag)
			printf("-1\n");
	}

	return 0;
}