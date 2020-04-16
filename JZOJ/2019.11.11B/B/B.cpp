/**
 * 2019.11.11【NOIP提高组】模拟 B 组
 * B 序列问题
 */

#include <stdio.h>

int n;
unsigned long long a[1020], A_DP[1020][1024] = {0};

int main() {
	freopen("B.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", a[i]);
	// if(n<=60)
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 0; k < 1024; ++k) {
				A_DP[i][k ^ a[i]] += A_DP[j][k];
			}
		}
	}
	return 0;
}