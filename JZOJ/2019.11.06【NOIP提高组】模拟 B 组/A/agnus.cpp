/**
 * 2019.11.06【NOIP提高组】模拟 B 组
 * A 寻找羔羊(agnus)
 */

#include <stdio.h>

char s[30020], goal[] = "agnus";
short a[30020] = {0}, pt = 1, ans = 0;

bool _is_same(char s[], int p) {
	for (int i = 0; i < 5; ++i) {
		if (s[p + i] != goal[i])
			return false;
	}
	return true;
}

int main() {
	freopen("agnus.in", "r", stdin);
	scanf("%s", s);
	for (int i = 0; s[i] != '\0'; ++i, ++pt)
		if (_is_same(s, i))
			a[pt] = 1, i += 5, pt = i;
	for (int i = 2; i <= pt; ++i)
		a[i] += a[i - 1];
	for (int i = 1; i <= pt; ++i)
		for (int j = i; j <= pt; ++j)
			if (a[j] - a[i - 1] > 0)
				++ans;
	printf("%d", ans);
	return 0;
}