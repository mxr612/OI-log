/**
 * D
 */

#include <stdio.h>

inline int min(register int x, register int y) {
	return x < y ? x : y;
}
inline int max(register int x, register int y) {
	return x > y ? x : y;
}

int t;
char s[1000020], ss[2000020];
int man[2000020];

signed main() {

	freopen("D.in", "r", stdin);

	scanf("%d", &t);

	ss[0] = '\2';
	for (register int i = 0, j, k, b, e, id, mx, ans; i < t; ++i) {
		mx = 0;
		scanf("%s", s);
		for (j = 0; s[j] != '\0'; ++j);
		for (b = -1, e = j; b < e && s[b + 1] == s[e - 1]; ++b, --e);
		if (b < e) {
			for (j = b + 1, k = 1; j < e; ++j)
				ss[k++] = s[j], ss[k++] = '\1';
			ss[k] = '\0';
			for (j = 1; j < k; ++j) {
				if (j < mx)man[j] = min(man[(id << 1) - j], mx - j);
				else man[j] = 1;
				while (ss[j - man[j]] == ss[j + man[j]])++man[j];
				if (j + man[j] > mx)mx = j + man[j], id = j;
			}
			mx = 0;
			for (j = 1; ss[j] != '\0'; ++j)
				if ((ss[j - man[j]] == '\2' || ss[j + man[j]] == '\0') && man[j] > mx)mx = man[j], ans = j;
			for (j = 0; j <= b; ++j)putchar(s[j]);
			for (j = ans - man[ans] + 1; j < ans + man[ans]; ++j)
				if (ss[j] != '\1')
					putchar(ss[j]);
			for (j = e; s[j] != '\0'; ++j)putchar(s[j]);
			putchar('\n');
		} else
			printf("%s\n", s);
	}

	return 0;

}