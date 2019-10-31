// solve

#include <iostream>
using namespace std;

unsigned long long n, k, ans = 0, res;

#define D (k/l)

int main() {

	freopen("sovle.in", "r", stdin);

	cin >> n >> k;

	// for (int i = 1; i <= n; ++i)
	// 	ans += k % i;
	// cout << ans << endl;

	res = n * k;
	for (int l = 1, r; l <= n; l = r + 1) {
		if (D != 0)
			r = min(k / D, n);
		else
			r = n;
		res -= D * (r - l + 1) * (l + r) >> 1;
	}

	cout << res;

	return 0;
}