// A

#include <iostream>
using namespace std;

short n, maps[2000][2000] = {0};

void dfs(short x, short y, short l) {
	if (!(l & 1)) {
		for (short i = x; i < x + (l >> 1); ++i)
			for (short j = y; j < y + (l >> 1); ++j)
				maps[i][j]++;
		dfs(x + (l >> 1), y, (l >> 1));
		dfs(x, y + (l >> 1), (l >> 1));
		dfs(x + (l >> 1), y + (l >> 1), (l >> 1));
	}
}

signed main() {

	freopen("U75693.in", "r", stdin);
	freopen("U75693.out", "w", stdout);

	cin >> n;

	dfs(1, 1, 1 << n);

	for (int i = 1; i <= 1 << n; ++i) {
		for (int j = 1; j < 1 << n; ++j)
			cout << !maps[i][j] << ' ';
		cout << !maps[i][1 << n] << endl;
	}

	return 0;

}