// T2

#include <iostream>
using namespace std;

unsigned long long n, m, ans = 0;

bool dis[30][30] = {false};
unsigned long long DP[1 << 21] = {0}, lev;

#define lowbit(zz) (zz&(-zz))

int level(int n) {
	int ret = 0;
	while (n > 0)ret++, n -= lowbit(n);
	return ret;
}

int main() {

	freopen("T2.in", "r", stdin);
	// freopen("T2.out", "w", stdout);

	cin >> n >> m;

	for (int i = 1, a, b; i <= m; ++i)
		cin >> a >> b, dis[a][b] = true;

	DP[0] = 1;
	for (int i = 0; i < (1 << n); ++i) {
		ans = max(ans, DP[i]);
		lev = level(i);
		for (int j = 0; j < n; ++j) {
			if ((!((i >> j) & 1 )) && (!dis[lev + 1][j + 1])) {
				DP[i + (1 << j)] += DP[i];
			}
		}
	}

	cout << ans;

	return 0;

}