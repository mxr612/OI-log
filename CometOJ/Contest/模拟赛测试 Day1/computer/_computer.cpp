// computer

#include <iostream>
using namespace std;

#define ULL unsigned long long
#define MOD 1000000007

ULL n;

ULL _Mi(int a, int x);

int main() {

	freopen("computer.in", "r", stdin);

	cin >> n;

	if (n <= 4) {
		cout << n;
	} else if (n % 3 == 0) {
		cout << _Mi(3, (n / 3) % (MOD - 1));
	} else if (n % 3 == 1) {
		cout << (4 * _Mi(3, ((n - 4) / 3) % (MOD - 1))) % MOD;
	} else {
		cout << (2 * _Mi(3, ((n - 2) / 3) % (MOD - 1))) % MOD;
	}
	return 0;
}

ULL _Mi(int a, int x) {
	ULL ret = 1;
	while (x > 0) {
		if (x & 1)
			ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		x>>=1;
	}
	return ret;
}
