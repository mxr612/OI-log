/**
 * Comet OJ - Contest #14
 * C 序列
 */
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2077, mod = 20050321;
int n, m;
ll a[N], b[N];
int main() {
	freopen("C3.in", "r", stdin);
	scanf("%d%d", &n, &m);
	int t = 1;
	a[1] = 1;
	for (int i = 1; i <= m; i++) {
		int l, r, yjy = 0;
		scanf("%d%d", &l, &r);
		for (int j = 1; j <= n; j++)
			b[j] = a[j];
		for (int j = l + 1; j <= r; j++)
			a[j] = 0;
		a[l] = t; a[r + 1] = t;
		t = t * 2 % mod;
		for (int j = 1; j <= n; j++)
			a[j] = (a[j] + b[j]) % mod, yjy = (yjy + a[j]) % mod;
		printf("%d\n", yjy);
	}
}
//一人AC全员共享