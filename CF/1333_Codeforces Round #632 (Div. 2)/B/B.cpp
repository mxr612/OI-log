/**
 * A
 */

#include <stdio.h>
#include <map>
#include <math.h>

#define MXN (100020)

int a[MXN], b[MXN];
std::map<int, int>cnt;

signed main() {

#ifndef ONLINE_JUDGE
	freopen("B.in", "r", stdin);
#endif

	int T, n;

	scanf("%d", &T);

	register bool flag = true;
	for (register int t = 0, i; t < T; ++t, flag = true) {
		scanf("%d", &n);
		for (i = 1; i <= n; ++i)
			scanf("%d", &a[i]), ++cnt[a[i]];
		for (i = 1; i <= n; ++i)
			scanf("%d", &b[i]);
		for (i = n;i > 0; --i) {
			--cnt[a[i]];
            // printf("%d %d %d\n", cnt[-1],cnt[0],cnt[1]);
			if (a[i] < b[i] && cnt[+1] == 0)flag = false;
			if (b[i] < a[i] && cnt[-1] == 0)flag = false;
		}
		printf("%s\n", (flag) ? ("YES") : ("NO"));
	}

	return 0;

}