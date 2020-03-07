/**
 * A
 */

#include <stdio.h>
#include <string.h>

int n, m;

unsigned long long res = 0, ans = 0;

int vis[1000020], top = 0;

struct __node {
	unsigned w;
	bool flag;
	int last, next;
} node[2000020];

signed main() {

	freopen("A.in", "r", stdin);

	memset(node, 0, sizeof(node));

	scanf("%d%d", &n, &m);

	int p, b;
	for (register int i = 0; i < n; ++i) {
		scanf("%d%d", &p, &b);
		vis[++top] = p;
		node[p].w = b;
		node[p].flag = true;
	}

	int last = 0;
	for (register int i = 1; i <= m; ++i) {
		if (node[i].flag) {
			if (last > 0) {
				node[last].next = i;
				node[i].last = last;
				res += node[last].w ^ node[i].w;
			}
			last = i;
		}
	}

	ans = res;
	// printf("%llu %lli\n", res, ans);
	for (register int i = top; i > 0; --i) {
		if (node[vis[i]].last > 0)
			res -= node[vis[i]].w ^ node[node[vis[i]].last].w;
		if (node[vis[i]].next > 0)
			res -= node[vis[i]].w ^ node[node[vis[i]].next].w;
		if (node[vis[i]].last > 0 && node[vis[i]].next > 0)
			res += node[node[vis[i]].next].w ^ node[node[vis[i]].last].w;
		ans ^= res;
		node[node[vis[i]].last].next = node[vis[i]].next;
		node[node[vis[i]].next].last = node[vis[i]].last;
		// printf("%d %d %d ", node[vis[i]].last, vis[i], node[vis[i]].next);
		// printf("%llu %llu\n", res, ans);
	}

	printf("%llu\n", ans);

	return 0;

}