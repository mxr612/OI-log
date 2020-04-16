// 1

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n, m, a, p;

short ans[100000] = {0}, flag[100000];
int cnt = 0;

int main() {

	freopen("running.in", "r", stdin);
	freopen("running.out", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		cin >> a;
		memset(flag, 0, sizeof(flag));
		p = 0;
		while ((p & 1) ? !((flag[p >> 1] >> 1) & 1) : !(flag[p >> 1] & 1)) {
			if (p & 1)flag[p >> 1] += 2; else flag[p >> 1]++;
			if (p & 1) {
				if (ans[p >> 1] < 0)ans[p >> 1] += 2;
			} else {
				if (!(ans[p >> 1] & 1))ans[p >> 1]++;
			}
			p = (p + a) % n;
		}
	}

	for (int i = 0; i < n; ++i) {
		if ((p & 1) ? (ans[p >> 1] < 2) : !(ans[p >> 1] & 1)) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}