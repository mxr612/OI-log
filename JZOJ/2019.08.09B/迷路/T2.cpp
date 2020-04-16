// T2 迷路

#include <iostream>
using namespace std;

#define MOD 2009

int N, T, ans = 0;
short E[20][20], in[20] = {0}, st[20];
char c;

void dfs(int n, int t) {
	if (t > T)
		return ;
	if (t == T && n == N) {
		ans = (ans + 1) % MOD;
		return;
	}
	for (int i = 1; i <= N; ++i)
		if (E[n][i] > 0)
			dfs(i, t + E[n][i]);
}

int main() {

	freopen("T2.in", "r", stdin);
	freopen("T2.out", "w", stdout);

	cin >> N >> T;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> c;
			E[i][j] = c - '0';
			if (E[i][j] > 0)
				in[j]++;
		}
	}

	dfs(1, 0);

	cout << ans;

	return 0;
}