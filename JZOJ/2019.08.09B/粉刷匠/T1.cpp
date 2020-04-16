// T1 粉刷匠

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

char c;
int N, M, T, gx;
int mb[60] = {0};
int ing[60][3500] = {0}, ans[3500] = {0};

int main() {

	freopen("T1.in", "r", stdin);
	freopen("T1.out", "w", stdout);

	cin >> N >> M >> T;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> c;
			mb[j] = mb[j - 1] + c - '0';
		}
		memset(ing, 0, sizeof(ing));
		for (int r = 0; r <= M; ++r)
			for (int l = 0; l < r; ++l) {
				gx = max(mb[r] - mb[l], (r - l) - (mb[r] - mb[l]));
				for (int k = 1; k <= T; ++k)
					ing[r][k] = max(ing[r][k], max(ing[l][k], ing[l][k - 1] + gx));
			}
		for (int j = T; j > 0; --j)
			for (int k = 0; k < j; ++k)
				ans[j] = max(ans[j], ans[k] + ing[M][j - k]);
	}

	cout << ans[T];

	return 0;
}