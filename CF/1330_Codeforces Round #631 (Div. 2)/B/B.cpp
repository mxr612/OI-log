/**
 * 1330_Codeforces Round #631 (Div. 2) - Thanks, Denis aramis Shitov!
 * B
 */

#include <stdio.h>
#include <string.h>

int a[200020], l[200020], r[200020], L[200020], R[200020], ans[200020];
signed main() {

	freopen("B.in", "r", stdin);

	int T, n;

	scanf("%d", &T);

	for (register int t = 0, i, j, p, q, cnt; t < T; ++t) {
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		memset(L, 0, sizeof(L));
		memset(R, 0, sizeof(R));
		cnt = 0;
		scanf("%d", &n);
		for (i = 1; i <= n; ++i)
			scanf("%d", &a[i]), ++r[a[i]], R[a[i]] = 1;
		for (i = 1; i < n; ++i)
			for (j = (i & (-i)) >> 1; j > 0; j >>= 1)
				R[i] += R[i - j];
		for (i = 1; i <= n; ++i) {
			if (++l[a[i]] == 1)
				for (j = a[i]; j < n; j += j & (-j))
					++L[j];
			if (--r[a[i]] == 0)
				for (j = a[i]; j < n; j += j & (-j))
					--R[j];
			for (p = 0, j = i; j > 0; j -= j & (-j))
				p += L[j];
			for (q = 0, j = n - i; j > 0; j -= j & (-j))
				q += R[j];
			if (p == i && q == n - i)
				ans[cnt++] = i;
		}

		printf("%d\n", cnt);
		for (i = 0; i < cnt; ++i)
			printf("%d %d\n", ans[i], n - ans[i]);
	}

	return 0;

}