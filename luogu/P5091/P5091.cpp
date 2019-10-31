// P5091 【模板】欧拉定理

#include <iostream>
#include <cstdio>
using namespace std;

unsigned long long a, m, m_, b = 0, phi, ans = 1;
char c;

signed main() {

	freopen("P5091.in", "r", stdin);

	cin >> a >> m;

	a %= m;

	phi = m;
	m_ = m;
	for (int i = 2; i * i <= m_; ++i) {
		if (m_ % i == 0) {
			phi = phi / i * (i - 1);
			while (m_ % i == 0)m_ /= i;
		}
	}
	if (m_ > 1)phi = phi / m_ * (m_ - 1);

	c = getchar();
	while (c < '0' || '9' < c)c = getchar();
	while ('0' <= c && c <= '9') {
		b = (b * 10 + c - '0') % phi;
		c = getchar();
	}

	if (b == 0) {
		cout << 0;
		return 0;
	}


	while (b) {
		if (b & 1)
			ans = (ans * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}

	cout << ans;
	
	return 0;
}