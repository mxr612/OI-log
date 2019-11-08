/**
 * Comet OJ - Contest #14
 * B 夕日的光辉
 */

#include <stdio.h>
#include <algorithm>

int T, n, l[10], r[10];
char str[1000020];

int main() {
	freopen("B1.in", "r", stdin);
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%d%s", &n, str);
		l[1] = l[2] = l[3] = l[4] = r[1] = r[2] = r[3] = r[4] = -1;
		for (int i = 0; i < n && l[4] == -1; ++i) {
			if (l[1] == -1 && str[i] == 'p')l[1] = i;
			if (l[1] != -1 && l[2] == -1 && str[i] == 'i')l[2] = i;
			if (l[2] != -1 && l[3] == -1 && str[i] == 'n')l[3] = i;
			if (l[3] != -1 && l[4] == -1 && str[i] == 'k')l[4] = i;
		}
		for (int i = n - 1; i >= 0 && r[1] == -1; --i) {
			if (r[4] == -1 && str[i] == 'k')r[4] = i;
			if (r[4] != -1 && r[3] == -1 && str[i] == 'n')r[3] = i;
			if (r[3] != -1 && r[2] == -1 && str[i] == 'i')r[2] = i;
			if (r[2] != -1 && r[1] == -1 && str[i] == 'p')r[1] = i;
		}
		if (l[1] == -1 || l[2] == -1 || l[3] == -1 || l[4] == -1 || r[1] == -1 ||  r[2] == -1 || r[3] == -1 || r[4] == -1)
			printf("-1\n");
		else
			printf("%d\n", std::max(std::max(r[2] - l[1] - 1, r[3] - l[2] - 1), r[4] - l[3] - 1));
	}
	return 0;
}