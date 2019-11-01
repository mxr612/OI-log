// A

#include <stdio.h>
#include <algorithm>

int n, a[1000020], ans = 0;

int main() {
	freopen("team0.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	std::sort(&a[1], &a[n + 1]);
	for (int i = 1, cnt = 0; i <= n; ++i)
		if (++cnt == a[i])
			++ans, cnt = 0;
	printf("%d", ans);
	return 0;
}