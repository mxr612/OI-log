// B_Block Adventure

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

long long flag, z = 0, T, n, m, k, block[110], g;

int main() {

	// freopen("B_Block Adventure.in", "r", stdin);

	cin >> T;

	for (int t = 0; t < T; ++t) {
		memset(block, 0, sizeof(block));
		flag = 0;
		cin >> n >> m >> k;
		for (int i = 1; i <= n; ++i)
			cin >> block[i];
		for (int i = 1; i <= n; ++i) {
			g = max(z, block[i + 1] - k);
			if (g > m + block[i]) {
				flag = 1;
				break;
			} else
				m += block[i] - g;
		}
		if (flag == 0)
			cout << "Yes" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}