// A. Circle of Students

#include <iostream>
using namespace std;

int q, n, p[300], s, a, b;

#define M(tjq) (p[((tjq)%n)+1])

int main() {

	freopen("A.in", "r", stdin);

	cin >> q;

	for (int i = 1; i <= q; ++i) {
		a = b = 1;
		cin >> n;
		for (int j = 1; j <= n; ++j)
			cin >> p[j], s = ((p[j] == 1) ? (j) : (s));
		for (int j = 0; j < n; ++j) {
			if (M(s + j) < M(s + j + 1))
				++a;
			if (M(s + j) > M(s + j + 1))
				++b;
		}
		// cout << n << ' ' << a << ' ' << b << endl;
		if (a == n || b == n)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}