// dp

#include <iostream>
using namespace std;

#define MOD 10000

unsigned int T, fr, to, ans;
unsigned int gd[3];

int main() {

	freopen("0.in", "r", stdin);
	// freopen("0.out", "w", stdout);

	cin >> T;

	for (int i = 1; i <= T; ++i) {
		cin >> fr >> to;
		ans = 0;
		gd[1] = gd[2] = 1;
		for (int i = 3; i <= to; ++i) {
			gd[i % 3] = (gd[(i + 1) % 3] + gd[(i + 2) % 3]) % MOD;
			if (i >= fr)ans = (ans + gd[i % 3]) % MOD;
		}
		if (fr < 2)ans += 2;
		if (fr == 2)ans ++;
		cout << ans << endl;
	}

	return 0;

}