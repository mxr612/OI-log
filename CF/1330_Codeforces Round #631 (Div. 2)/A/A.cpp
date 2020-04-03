/**
 * 1330_Codeforces Round #631 (Div. 2) - Thanks, Denis aramis Shitov!
 * A
 */

#include <stdio.h>
#include <string.h>

signed main() {

	freopen("A.in", "r", stdin);

	int T, n, x, a, arr[10][400];
	memset(arr, -1, sizeof(arr));
	scanf("%d", &T);
	for (register int t = 0, i, s; t < T; ++t) {
		scanf("%d%d", &n, &x);
		for (i = 0; i < n; ++i)
			scanf("%d", &a), arr[t][a] = 0;
		for (i = 1, s = 0; s >= -x; ++i)
			s += arr[t][i];
		printf("%d\n", i - 2);
	}

	return 0;

}