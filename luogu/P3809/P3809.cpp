/**
 * P3809
 * Suffix Array
 */

#include <stdio.h>
#include <string.h>

#define MXN (1000020)

char s[MXN];
unsigned sa[MXN], rk[2][MXN << 1] = {0}, cnt[MXN] = {0}, id[MXN];

signed main() {

	freopen("P3809.in", "r", stdin);

	scanf("%s", s + 1);
	register unsigned n = strlen(s + 1), m = 200;

	for (register unsigned i = 1; i <= n; ++i)++cnt[rk[0][i] = s[i]];
	for (register unsigned i = 1; i <= m; ++i)cnt[i] += cnt[i - 1];
	for (register unsigned i = n; i > 0; --i)sa[cnt[s[i]]--] = i;

	for (register unsigned r = 0, w = 1, i, p; w < n; r ^= 1, w <<= 1) {
		memset(cnt, 0, sizeof(cnt));
		for (i = n, p = 0; i > n - w; --i)id[++p] = i;
		for (i = 1; i <= n; ++i)if (sa[i] > w)id[++p] = sa[i] - w;
		for (i = n; i > 0; --i)++cnt[rk[r][i]];
		for (i = 1; i <= m; ++i)cnt[i] += cnt[i - 1];
		for (i = n; i > 0; --i)sa[cnt[rk[r][id[i]]]--] = id[i];
		for (m = 0, i = 1; i <= n; ++i)
			rk[r ^ 1][sa[i]] = (rk[r][sa[i]] == rk[r][sa[i - 1]] && rk[r][sa[i] + w] == rk[r][sa[i - 1] + w]) ? m : ++m;
	}

	for (register unsigned i = 1; i <= n; ++i)
		printf("%d ", sa[i]);

	return 0;

}