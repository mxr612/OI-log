// fib

#include <iostream>
using namespace std;

#define LEN 100
#define N 123
#define MOD 10000
// #define int long long
/**
 * LEN 矩阵边长
 * N   第N项
 * MOD 模数(因为太大会爆负)
 */

void _mat_mul(int L[LEN][LEN], int R[LEN][LEN], int A[LEN][LEN], int x, int y, int z);
void _mat_mi(int L[LEN][LEN], int R[LEN][LEN], int A[LEN][LEN], int x, int y, int mi);

int Fib[LEN][LEN], Mat[LEN][LEN] ;

signed main() {

	Fib[1][1] = Fib[1][2] = 1;

	Mat[1][1] = 1; Mat[1][2] = 1;
	Mat[2][1] = 1; Mat[2][2] = 0;

	if (N > 2)
		_mat_mi(Fib, Mat, Fib, 1, 2, N - 2);

	cout << Fib[1][1];

	return 0;

}

void _mat_mul(int L[LEN][LEN], int R[LEN][LEN], int A[LEN][LEN], int x, int y, int z) {
//L[x][y] * R[y][z] = A[x][z]
	long long cmp[LEN][LEN] = {0};
	for (int i = 1; i <= x; ++i)
		for (int j = 1; j <= z; ++j)
			for (int k = 1; k <= y; ++k)
				cmp[i][j] = (cmp[i][j] + L[i][k] * R[k][j]) % MOD;
	for (int i = 1; i <= x; ++i)for (int j = 1; j <= z; ++j)A[i][j] = cmp[i][j];
}

void _mat_mi(int L[LEN][LEN], int R[LEN][LEN], int A[LEN][LEN], int x, int y, int mi) {
// L[x][y] * R[y][y]^mi = A[x][y]
	int cmp[LEN][LEN];
	for (int i = 1; i <= x; ++i)for (int j = 1; j <= y; ++j)cmp[i][j] = L[i][j];
	while (mi > 0) {
		if (mi & 1)
			_mat_mul(cmp, Mat, cmp, x, y, y);
		mi >>= 1;
		_mat_mul(R, R, R, y, y, y);
	}
	for (int i = 1; i <= x; ++i)for (int j = 1; j <= y; ++j)A[i][j] = cmp[i][j];
}