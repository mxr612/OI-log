/**
 * 2019.11.04【NOIP提高组】模拟 B 组
 * B 阅读程序写结果
 *
 */

#include <stdio.h>
#include <math.h>
#include <iostream>

const long long MOD = 2009, PHI = 2003, LCM = 4024027;


long long P, mi_phi[3000], mi_10[3000],ans_ = 0, ans;

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
		for (int i = 1; i <=size; ++i) {
			mod = mod * 10 + num[i];
			div = (div*10+mod/LCM) % MOD;
			mod %= LCM;
			printf("%10d%10d\n",div,mod);
		}
	}
} N;


signed main() {
	freopen("B.in", "r", stdin);
	// freopen("B.out", "w", stdout);
	N._get();
	scanf("%d", &P);
	mi_10[0] = mi_phi[0] = 1;
	for (int i = 1; i <= PHI; ++i)
		mi_phi[i] = (mi_phi[i - 1] * P) % MOD;
	for (int i = 1; i <= 1024; ++i)
		mi_10[i] = (mi_10[i - 1] * 10) % LCM;
	N._div();
	printf("%20d%20d\n", N.div, N.mod);
	printf("%20d%20d\n", (124124312 / LCM) % MOD, 124124312 % LCM);
	// for (int i = 1; i <= LCM; ++i)
	// 	ans_ = (ans_ + mi_phi[i % PHI] * (i % MOD)) % MOD;
	return 0;
}