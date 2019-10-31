// 0

#include <iostream>
using namespace std;

#define MOD 10000
#define TOP 15000

unsigned short fib[15001] = {0};
unsigned int T, fr, to, ans;

int main() {

	freopen("0.in", "r", stdin);
	freopen("0.out", "w", stdout);

	fib[1] = fib[2] = 1;
	for (int i = 3; i <= TOP; ++i)
		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD ;

	cin >> T;

	for (int i = 1; i <= T; ++i) {
		cin >> fr >> to;
		ans = 0;
		fr %= TOP; to %= TOP;
		if (fr <= to) {
			for (int i = fr; i <= to; ++i)
				ans = (ans + fib[i]) % MOD;
		} else {
			for (int i = 0; i <= to; ++i)
				ans = (ans + fib[i]) % MOD;
			for (int i = fr ; i <= TOP; ++i)
				ans = (ans + fib[i]) % MOD;
		}
		cout << ans << endl;
	}

	return 0;

}