/**
 * P3805
 *
 */

#include <stdio.h>
#include <string>
#include <iostream>

inline int min(int x, int y) {
	return x < y ? x : y;
}
inline int max(int x, int y) {
	return x > y ? x : y;
}

char s[11000020], ss[22000020];
int p[22000020];

int main() {

	freopen("P3805.in", "r", stdin);

	scanf("%s", s);

	register int i = 0, j = 1, id, mx = 0, ans = 0;
	while (s[i] != '\0')
		ss[++j] = s[i++], ss[++j] = '\1';
	ss[0] = '\2', ss[1] = '\1', ss[++j] = '\0';

	for (i = 1; ss[i] != '\0'; ++i) {
		if (i < mx)p[i] = min(p[(id << 1) - i], mx - i);
		else p[i] = 1;
		while (ss[i - p[i]] == ss[i + p[i]])++p[i];
		if (i + p[i] > mx) {
			mx = i + p[i];
			id = i;
		}
		if (p[ans] < p[i])
			ans = i;
		// printf("%-5d%c\n", p[i], ss[i]);
	}

	printf("%d\n", p[ans] - 1);

	return 0;

}
/*

 */