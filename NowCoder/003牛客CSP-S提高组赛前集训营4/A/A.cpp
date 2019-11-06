/**
 * 牛客CSP-S提高组赛前集训营4
 * A 复读数组
 */

#include <stdio.h>
#include <stdlib.h>

#define MOD (1000000007)

unsigned long long n, k, ans = 0, cnt = {0};
int a[200020];

struct __tree_node {
	bool is = false;
	__tree_node *nx[10] = {NULL};
	bool _ask(int x) {
		if (x == 0)
			return is;
		if (nx[x % 10] == NULL)
			return false;
		return nx[x % 10]->_ask(x / 10);
	} bool operator[](int x) {return _ask(x);}
	void _update(int x) {
		if (x > 0) {
			if (nx[x % 10] == NULL)
				nx[x % 10] = (__tree_node *)calloc(1, sizeof(__tree_node));
			nx[x % 10]->_update(x / 10);
		} else
			is = true;

	} void operator<<(int x) {_update(x);}
	void _free() {
		for (int i = 0; i < 10; ++i)
			if (nx[i] != NULL)
				nx[i]->_free(), free(nx[i]), nx[i] = NULL;
	}
} tree;

int main() {
	freopen("a.in", "r", stdin);

	scanf("%d%d", &n, &k);
	k %= MOD;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), a[n + i] = a[i];
	for (int i = 1; i <= n; ++i)
		if (!tree[a[i]])
			tree << a[i], cnt++;
	ans = cnt * n * k * (n * k - 2 * k + 1) - (2 * k + n * k) * (n * k - 2 * k + 1) / 2;
	tree._free(), cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < (n << 1) - i; ++j) {
			if (!tree[a[i + j]])
				tree << a[i + j], ++cnt;
			if (j < n)
				ans = (ans + cnt * (k % MOD)) % MOD/*, printf("-%5d%5d%5d%5d%5d\n", i, i + j,  (cnt * (k % MOD)) % MOD, cnt, 1)*/;
			else
				ans = (ans + cnt * ((k - 1) % MOD)) % MOD/*, printf("+%5d%5d%5d%5d%5d\n", i, i + j, (cnt * ((k - 1) % MOD)) % MOD, cnt, 1)*/;
		}
		tree._free(), cnt = 0;
	}
	printf("%lld", ans);

	return 0;
}