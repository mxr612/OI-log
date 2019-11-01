// B

#include <stdio.h>

int n, ans = 1e9, x, y, cnt;
int main() {
	freopen("B.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		x = i, y = n, cnt = 0;
		while (cnt < ans && x > 0 && y > 0 && (x > 1 || y > 1) ) {
			if (x > y)
				x -= y;
			else
				y -= x;
			cnt++;
		}
		if (x == 1 && y == 1)
			ans = cnt;
	}
	printf("%d", ans);
	return 0;
}