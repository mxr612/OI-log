// line.in

#include <iostream>
#include <cstdio>
using namespace std;

int N;

short E[101][101] = {0};

int DP[200][200] = {0};
#define cr(n) (((n)>100)?((n)-100):(n))

int ans = 0;

int main() {
	freopen("line.in", "r", stdin);
	freopen("line.out", "w", stdout);

	cin >> N;

	for (int i = 1, a, b; i <= N; ++i)
		cin >> a >> b, E[a][b] = E[b][a] = 1;

	for (int i = 1; i <= 100; i++)
		DP[i][i + 1] = E[i][cr(i + 1)];
	for (int k = 2; k < 100; ++k)
		for (int i = 1; i <= 100; ++i)
			for (int m = i + 1, j = i + k; m < j; ++m)
				DP[i][j] = max(DP[i][j], DP[i][m] + DP[m][j] + E[i][cr(j)]);


	for (int i = 1; i <= 100; ++i)
		ans = max(ans, DP[i][i + 99]);
	cout << ans;

	return 0;;
}