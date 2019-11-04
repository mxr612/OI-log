/**
 * 2019.11.04【NOIP提高组】模拟 B 组
 * B 阅读程序写结果
 * 高精度除法
 * phi
 */

#include <stdio.h>
#include <math.h>
#include <iostream>

const long long MOD = 2009, PHI = 1680, LCM = 482160;


long long P, mi[10000], mi_10[3000], ans = 0;

struct _num {
	long long num[1024], size, div, mod;
	void _get() {
		size = 0;
		char c = getchar();
		while (c < '0' || '9' < c)c = getchar();
		while ('0' <= c && c <= '9') {
			num[++size] = c - '0';
			c = getchar();
		}
	}
	void _div() {
		div = mod = 0;
		for (int i = 1; i <= size; ++i) {
			mod = mod * 10 + num[i];
			mod %= LCM;
		}
	}
} N;


signed main() {
	freopen("data5.in", "r", stdin);
	// freopen("B.out", "w", stdout);
	N._get();
	scanf("%d", &P);
	mi_10[0] = mi[0] = 1;
	for (int i = 1; i < 10000; ++i)
		mi[i] = (mi[i - 1] * P) % MOD;
	N._div();
	for (int i = 1; i <= N.mod; ++i)
		ans = (ans + mi[(i % PHI) + PHI] * (i % MOD)) % MOD;
	// for (int i = 1; i < 10000; ++i)
	printf("%lld\n", ans);
	return 0;
}