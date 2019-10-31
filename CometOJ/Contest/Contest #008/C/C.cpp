// C 符文能量

#include <iostream>
using namespace std;

long long n, k, p, a[100077], b[100077], f[100077][3] = {0};

int main() {

	freopen("C.in", "r", stdin);

	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i];

	for (int i = 1; i <= n; ++i) {
		p = b[i] * a[i + 1];
		f[i][0] = f[i - 1][0] + p;
		f[i][1] = min(f[i - 1][0] + k * p, f[i - 1][1] + k * k * p);
		f[i][2] = min(f[i - 1][1] + k * p, f[i - 1][2] + p);
	}

	cout << min(f[n][0], min(f[n][1], f[n][2]));

	return 0;
}