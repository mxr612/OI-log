// Miller_Rabin

#include <iostream>
#include <cmath>
using namespace std;

#define T 100007

const int prime[8] = {1, 2, 3, 5, 7, 11, 13, 17};

long long _fast_mul(long long a, long long b, long long m) {
	long long res = 0;
	while (b) {
		if (b & 1)
			res = (res + a) % m;
		a = (a << 1) % m;
		b >>= 1;
	}
	return res;
}

long long _fast_pow(long long n, long long p, long long m) {
	long long res = 1;
	n %= m;
	while (p) {
		if (p & 1)
			res = _fast_mul(res, n, m);
		n = _fast_mul(n, n, m);
		p >>= 1;
	}
	return res;
}

bool _Is_Prime(long long n) {
	int u = n - 1, t = 0, a, cmp;
	if (u == 2)
		return true;
	if ((u & 1))
		while (!(u & 1)) {
			u >>= 1;
			++t;
		}
	for (int i = 0; i < 7 && prime[i] < n; ++i) {
		a = _fast_pow(prime[i], u, n);
		for (int j = 1; j <= t ; ++j) {
			cmp = _fast_mul(a, a, n);
			if (1 < u && u < n - 1 &&  cmp == 1)
				return false;
			a = cmp;
		}
		if (a > 1)
			return false;
	}
	return true;
}

int main() {

	cout << (_Is_Prime(T) ? 'Y' : 'N');

	return 0;
}