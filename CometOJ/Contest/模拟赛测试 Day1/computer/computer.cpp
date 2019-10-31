// computer

#include <iostream>
using namespace std;

#define MOD (1000000007)

int n;
unsigned long long f[2000000];

int main() {

	freopen("computer.in", "r", stdin);
	// freopen("computer.out", "w", stdout);


	cin >> n;

	f[1] = 1; f[2] = 2; f[3] = 3;
	for (int i = 4; i <= n; ++i)
		for (int j = 1; j <= (i - j); ++j)
			f[i] = max(f[i], f[j] * f[i - j]);

	cout << f[n] % MOD;

	return 0;
}