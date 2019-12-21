/**
 * 2019.12.21【NOIP提高组】模拟B 组
 * A
 * 1256 奶牛的歌声
 */

#include <stdio.h>

unsigned N, h[50020], v[50020], l[50020] = {0}, r[50020] = {0}, s[50020] = {0}, ans = 0;

signed main() {
	freopen("A.in", "r", stdin);

	scanf("%u", &N);
	for (register unsigned i = 1; i <= N; ++i)
		scanf("%u%u", &h[i], &v[i]);

	for (register unsigned i = 1; i <= N; ++i)
		for (register unsigned j = i - 1; l[i] == 0 && j != 0; j = l[j])
			if (h[j] > h[i])
				l[i] = j;
	for (register unsigned i = N; i >= 1; --i)
		for (register unsigned j = i + 1; r[i] == 0 && j != 0; j = r[j])
			if (h[j] > h[i])
				r[i] = j;
	for (register unsigned i = 1; i <= N; ++i)
		s[l[i]] += v[i], s[r[i]] += v[i];

	for (register unsigned i = 1; i <= N; ++i)
		if (ans < s[i])
			ans = s[i];

	printf("%u\n", ans);
	
	return 0;
}