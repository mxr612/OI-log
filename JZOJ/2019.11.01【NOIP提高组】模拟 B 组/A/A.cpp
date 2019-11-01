// A

#include <stdio.h>
#include <algorithm>

int n, a[1000020], ans = 0;

int main() {
	freopen("A.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	std::sort(&a[1], &a[n + 1]);
	for (int i = n; i > 0; i -= a[i])
		++ans;
	printf("%d", ans);
	return 0;
}