// 2

#include <iostream>
using namespace std;


#define LEN 200
#define MOD 30011

unsigned int n, m;

int mat[LEN][LEN] = {0}, ans[LEN][LEN];

void _make(int A[LEN][LEN], int B[LEN][LEN], int len);
void _mul(int L[LEN][LEN], int R[LEN][LEN], int A[LEN][LEN], int x, int y, int z);
void _mi(int L[LEN][LEN], int R[LEN][LEN], int A[LEN][LEN], int x, int y, int m);

int main() {
	freopen("2.in", "r", stdin);
	cin >> n >> m;
	if (m == 1) {
		cout << ((n == 1) ? (1) : (0));
		return 0;
	}
	_make(mat, ans, n);
	_mi(ans, mat, ans, 1, 2 * n, m - 3);
	cout << (ans[1][n - 1] + ans[1][n]) % MOD;
	return 0;
}

void _make(int A[LEN][LEN], int B[LEN][LEN], int len) {
	for (int i = 1; i <= len; ++i) {
		for (int j = 1; j <= len; ++j) {
			if (i == j)
				A[i][j] = A[len + i][j] = A[i][len + j] = 1;
			if (i - j == 1 || j - i == 1)
				A[i][j] = 1;
		}
	}
	B[1][1] = B[1][2] = B[1][len + 1] = 1;
}

void _mul(int L[LEN][LEN], int R[LEN][LEN], int A[LEN][LEN], int x, int y, int z) {
	long long cmp[LEN][LEN] = {0};
	for (int i = 1; i <= x; ++i)
		for (int j = 1; j <= z; j++)
			for (int k = 1; k <= y; k++)
				cmp[i][j] = (cmp[i][j] + L[i][k] * R[k][j]) % MOD;
	for (int i = 1; i <= x; ++i)
		for (int j = 1; j <= z; ++j)
			A[i][j] = cmp[i][j];
}

void _mi(int L[LEN][LEN], int R[LEN][LEN], int A[LEN][LEN], int x, int y, int m) {
	int cmp[LEN][LEN];
	for (int i = 1; i <= x; ++i)
		for (int j = 1; j <= y; ++j)
			cmp[i][j] = L[i][j];
	while (m > 0) {
		if (m & 1)
			_mul(cmp, R, cmp, x, y, y);
		m >>= 1;
		_mul(R, R, R, y, y, y);
	}
	for (int i = 1; i <= x; ++i)
		for (int j = 1; j <= y; ++j)
			A[i][j] = cmp[i][j];
}
