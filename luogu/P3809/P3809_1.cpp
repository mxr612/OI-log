/**
 * P3809
 * Suffix Array
 */

#include <stdio.h>
#include <string.h>

#define MXN (1000020)

char s[MXN];
unsigned sa[MXN], cnt[MXN], rk[2][MXN << 1], id[MXN];

signed main() {

	freopen("P3809.in", "r", stdin);

	scanf("%s", s + 1);
	register unsigned n = strlen(s + 1), m = 200, i, w, r, p;

	for (i = n; i > 0; --i)++cnt[rk[0][i] = s[i]];
	for (i = 1; i <= m; ++i)cnt[i] += cnt[i - 1];
	for (i = n; i > 0; --i)sa[cnt[s[i]]--] = i;

	for (w = 1, r = 0; w < n; w <<= 1, r ^= 1) {
		memset(cnt, 0, sizeof(cnt));//?????第一个循环的顺序??
		for (i = n, p = 0; i > n - w; --i)id[++p] = i;// for (i = n - w, p = 0; i <= n; ++i)id[++p] = i;
		for (i = 1; i <= n; ++i)if (sa[i] > w)id[++p] = sa[i] - w;
		for (i = n; i > 0; --i)++cnt[rk[r][i]];
		for (i = 1; i <= m; ++i)cnt[i] += cnt[i - 1];
		for (i = n; i > 0; --i)sa[cnt[rk[r][id[i]]]--] = id[i];
		for (m = 0, i = 1; i <= n; ++i)
			rk[r ^ 1][sa[i]] = (rk[r][sa[i]] == rk[r][sa[i - 1]] && rk[r][sa[i] + w] == rk[r][sa[i - 1] + w]) ? (m) : (++m);
	}

	for (i = 1; i <= n; ++i)printf("%d ", sa[i]);

	return 0;

}