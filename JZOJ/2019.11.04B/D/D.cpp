/**
 * 2019.11.04【NOIP提高组】模拟 B 组
 * D 有趣的数列
 * 卡特兰数
 * 素数线性筛
 */

#include <stdio.h>

int n, p;
bool isp[2000020] = {false};
int pr[200000], pt = 0;
int mul[200000] = {0};
long long ans = 1;

void _get_pr(int x) {
	for (int i = 2; i <= x; ++i) {
		if (!isp[i])
			pr[++pt] = i;
		for (int j = 1; j <= pt && i * pr[j] <= x; ++j)
			isp[i * pr[j]] = true;
	}
}

int _mi(int a, int b, int c) {
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res *= a;
		a = (a * a) % c;
		b >>= 1;
	}
	return res;
}

int main() {
	freopen("data7.in", "r", stdin);
	// freopen("D.out","w",stdout);
	scanf("%d%d", &n, &p);
	_get_pr(2 * n);
	for (int i = n + 2, cmp; i <= 2 * n; ++i) {
		cmp = i;
		for (int j = 1; cmp > 1 && j <= pt; ++j) {
			while (cmp % pr[j] == 0) {
				cmp /= pr[j];
				++mul[j];
			}
		}
	}
	for (int i = 1, cmp; i <= n; ++i) {
		cmp = i;
		for (int j = 1; cmp > 1 && j <= pt; ++j) {
			while (cmp % pr[j] == 0) {
				cmp /= pr[j];
				--mul[j];
			}
		}
	}
	for (int i = 1; i <= pt; ++i)
		ans = (ans * _mi(pr[i], mul[i], p)) % p;
	printf("%lld", ans);
	return 0;
}