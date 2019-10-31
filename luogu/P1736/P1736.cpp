//P1736

#include <iostream>
#include <cstring>
using namespace std;

int n, m;
short pool[2501][2501];

int cmp[2501] = {0}, cmq = 0;
int l[2501][2501], r[2501][2501];

int DPl[2501][2501] = {0}, DPr[2501][2501] = {0};

int ans = 0;

int main() {
// In
	freopen("P1736.in", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> pool[i][j];
// Pre
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			l[i][j] = r[i][j] = i - cmp[j];
			if (pool[i][j] == 1) cmp[j] = i;
		}
		cmq = 0;
		for (int j = 1; j <= m; j++) {
			l[i][j] = min(l[i][j], j - cmq);
			if (pool[i][j] == 1)
				cmq = j;
		}
		cmq = m + 1;
		for (int j = m; j > 0; j--) {
			r[i][j] = min(r[i][j], cmq - j);
			if (pool[i][j] == 1)
				cmq = j;
		}
	}
// DP
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)if (pool[i][j] == 1)
				DPl[i][j] = min(DPl[i - 1][j - 1] + 1, l[i][j]);
		for (int j = m; j > 0; j--)if (pool[i][j] == 1)
				DPr[i][j] = min(DPr[i - 1][j + 1] + 1, r[i][j]);
	}
// Ans
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans = max(ans, max(DPl[i][j], DPr[i][j]));
// Out
	// for (int i = 1; i <= n; i++){
	// 	for (int j = 1; j <= m; j++){
	// 		printf("%3d",DPr[i][j]);
	// 	}
	// 	cout<<endl;
	// }
	cout << ans;
	return 0;
}