// C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <map>
using namespace std;

int n, k, q, l, r;

struct __edge {
	int v;
	__edge *nx;
} *num[100020], *p;

int cnt[100020] = {0}, pp[100020] = {0};

bool vis[100020] = {false};

bool _dfs(int x) {
	for (__edge *i = num[x]; i != NULL; i = i->nx) {
		if (!vis[i->v]) {
			vis[i->v] = true;
			if (pp[i->v] == 0 || _dfs(pp[i->v])) {
				pp[i->v] = x;
				return true;
			}
		}
	}
	return false;
}

bool _xyl(int l, int r) {
	int ans = r - l + 1;
	memset(pp, 0, sizeof(pp));
	for (int i = l; i <= r; ++i) {
		memset(vis, 0, sizeof(vis));
		if (_dfs(i))
			--ans;
	}
	if (ans == 0)
		return true;
	else
		return false;
}

int main() {
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	scanf("%d%d", &n, &k);

	for (int i = 1, a, b; i <= k; ++i) {
		scanf("%d%d", &a, &b);
		p = (__edge *)calloc(1, sizeof(__edge)), p->nx = num[a], num[a] = p, p->v = i;
		cnt[a] = 1;
		if (a != b) {
			p = (__edge *)calloc(1, sizeof(__edge)), p->nx = num[b], num[b] = p, p->v = i;
			cnt[b] = 1;
		}
	}
	for (int i = 2; i <= n; ++i)
		cnt[i] += cnt[i - 1];

	scanf("%d", &q);
	while (q-- > 0) {
		scanf("%d%d", &l, &r);
		if (cnt[r] - cnt[l - 1] >= r - l + 1 && _xyl(l, r))
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}