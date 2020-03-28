/**
 * A
 */

#include <stdio.h>
#include <algorithm>

unsigned n, ll[1020], rr[1020], ans = 0;
bool vis[1020] = {false};

void _dfs(bool g, unsigned L, unsigned R, unsigned l, unsigned r) {
	if (g)ans = std::max(ans, (R - L) * (r - l));
	for (unsigned i = 0; i < n; ++i)
		if ((!vis[i]) && (ll[i] < l || r < rr[i]))
			vis[i] = true, _dfs(true, std::min(L, ll[i]), std::max(R, rr[i]), std::max(l, ll[i]), std::min(R, rr[i])), vis[i] = false;
}

signed main() {

	freopen("interval1.in", "r", stdin);

	scanf("%d", &n);

	for (register unsigned i = 0; i < n; ++i)
		scanf("%u%u", &ll[i], &rr[i]);

	for (unsigned i = 0; i < n; ++i)
		vis[i] = true, _dfs(false, ll[i], rr[i], ll[i], rr[i]), vis[i] = false;

	printf("%u\n", ans);

	return 0;

}