// 1039.in

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int n;
short num[30001];

short Bet[30001][30001] = {0};

int DP[30001];

int main() {
	freopen("1039.in", "r", stdin);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> num[i], num[i] = (num[i] == 0) ? 1 : floor(log2(num[i]) + 1);

	for (int i = 1; i <= n; i++)
		Bet[i][i] = num[i];
	for (int i = 1; i < 256; i++)
		for (int j = 1; j + i <= n; j++)
			Bet[j][j + i] = max(Bet[j + 1][j + i], Bet[j][j + i - 1]);
	memset(DP, 0x6f, sizeof(DP));
	DP[0] = 0;

	for (int k = 1; k <= n; k++)
		for (int i = min(k + 254, n); i >= k; i--)
			for (int j = min(255, i); j > 0; j--)
				DP[i] = min(DP[i], DP[i - j] + 12 + Bet[i - j + 1][i] * j);

	cout << DP[n];

	return 0;
}