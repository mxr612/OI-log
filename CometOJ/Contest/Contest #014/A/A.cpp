/**
 * Comet OJ - Contest #14
 * A 险恶的迷宫
 */
#include <stdio.h>
long long n, a, b, r, x, y, ans = 0;
int main() {
	freopen("A2.in", "r", stdin);
	scanf("%lld%lld%lld%lld", &n, &a, &b, &r);
	r *= r;
	for (int i = 1; i <= n; ++i)
		scanf("%lld%lld", &x, &y), ans += (((x - a) * (x - a) + (y - b) * (y - b)) <= r) ? 1 : 0;
	printf("%lld", ans);
	return 0;
}