// 2

#include <iostream>
#include <cstring>
using namespace std;

int l1, l2;
int n1[2001], n2[2001];

int P[2001][2001] = {0}, DP[2001][2001];

int main() {

	freopen("2.in", "r", stdin);
	freopen("2.out", "w", stdout);

	cin >> l1 >> l2;
	if (l1 > l2) {
		l1 ^= l2, l2 ^= l1, l1 ^= l2;
		for (int i = l2; i > 0; --i)
			cin >> n2[i], n2[i]--;
		for (int i = l1; i > 0; --i)
			cin >> n1[i], n1[i]--;
	} else {
		for (int i = l1; i > 0; --i)
			cin >> n1[i], n1[i]--;
		for (int i = l2; i > 0; --i)
			cin >> n2[i], n2[i]--;
	}

	memset(DP, 0x6f, sizeof(DP));

	for (int i = 1; i <= l1; ++i) {
		for (int j = 1; j <= l2; ++j) {
			P[i][j] = n1[i] * n2[j] + P[i][j - 1];
		}
	}
	for (int j = 1; j <= l2 - l1 + 1; ++j)
		DP[1][j] = P[1][j];
	for (int i = 2; i <= l1; ++i) {
		for (int j = 1; j <= l2 - l1 + i ; ++j) {
			DP[i][j] = 1e9;
			for (int k = i - 1; k < j; ++k) {
				DP[i][j] = min(DP[i][j], DP[i - 1][k] + P[i][j] - P[i][k]);
			}
		}
	}

	// for (int i = 1; i <= l1; ++i) {
	// 	for (int j = 1; j <= l2; ++j) {
	// 		printf("%12d", DP[i][j]);
	// 	}
	// 	cout << endl;
	// }

	cout << DP[l1][l2];

	return 0;
}
