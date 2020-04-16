// seq.cpp

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

#define MOD (998244353)

typedef unsigned long long ULL;

int n, k, ans = 1;
ULL f[210], b[210];

ULL mat[40][210][210], val[210] = {0};

void _make_mat() {
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j < k; ++j) {
			if (i == j + 1)
				mat[1][i][j] = 1;
			else
				mat[1][i][j] = 0;
		}
	}
	for (int i = 1; i <= k; ++i)
		mat[1][i][k] = b[i];
}

void _mat_mul_f(ULL a[210][210], ULL b[210][210], ULL c[210][210]) {
	ULL cmp[210][210] = {0};
	for (int i = 1; i <= k; ++i)
		for (int j = 1; j <= k; ++j)
			for (int l = 1; l <= k; ++l)
				cmp[i][j] = (cmp[i][j] + a[i][l] * b[l][j]) % (MOD - 1);
	for (int i = 1; i <= k; ++i)
		for (int j = 1; j <= k; ++j)
			c[i][j] = cmp[i][j];
}

void _mat_mul_m(ULL a[210], ULL b[210][210], ULL c[210]) {
	ULL cmp[210] = {0};
	for (int i = 1; i <= k; ++i)
		for (int j = 1; j <= k; ++j)
			cmp[i] = (cmp[i] + a[j] * b[j][i]) % (MOD - 1);
	for (int i = 1; i <= k; ++i)
		c[i] = cmp[i];
}

void _mat_fmi(int mi) {
	for (int i = 1; mi; ++i) {
		if (mi & 1)
			_mat_mul_m(val, mat[i], val);
		mi >>= 1;
	}
}

ULL _fmi(ULL a, ULL b) {
	ULL ret = 1;
	while (b) {
		if (b & 1)
			ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}

int main() {

	freopen("seq.in", "r", stdin);
	// freopen("seq.out", "w", stdout);

	cin >> n >> k;
	for (int i = k; i > 0; --i)
		cin >> b[i];
	for (int i = 1; i <= k; ++i)
		cin >> f[i];

	_make_mat();
	for (int i = 1; i < 30; ++i)
		_mat_mul_f(mat[i], mat[i], mat[i + 1]);

	if (n <= k)
		cout << f[n];
	else {
		_mat_fmi(n - k);
		for (int i = 1; i <= k; ++i) {
			for (int j = 1; j <= k; ++j)
				val[j] = 0;
			val[i] = 1;
			_mat_fmi(n-k);
			ans = (ans * _fmi(f[i], val[k])) % MOD;
		}
		cout << ans;
	}

	return 0;
}