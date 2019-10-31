#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 100

int N, maxx = 0, minn = int(1e10);
int sign[3 * MAX_N + 1];
int DPx[3*MAX_N + 1][3 * MAX_N + 1] = {0};
int DPn[3*MAX_N + 1][3 * MAX_N + 1] = {0};
int summ[3*MAX_N] = {0};

int main(int argc, char const *argv[])
{
	// freopen("P1880.in", "r", stdin);
	memset(DPn, 0xf, sizeof(DPn));
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> sign[i];
		sign[N + i] = sign[i];
	}
	for (int i = 1; i <= 2 * N; i++) {
		summ[i] += summ[i - 1] + sign[i];
	}
	for (int i = 1; i <= 2 * N; i++) {
		DPn[i][i] = 0;
	}
	for (int l = 1; l < N; l++) {
		for (int i = 1; i <= 2 * N - l; i++) {
			int j = i + l;
			for (int k = i + 1; k <= j; k++) {
				DPx[i][j] = max(DPx[i][j], DPx[i][k - 1] + DPx[k][j] + summ[j] - summ[i - 1]);
				DPn[i][j] = min(DPn[i][j], DPn[i][k - 1] + DPn[k][j] + summ[j] - summ[i - 1]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		maxx = max(maxx, DPx[i][i + N - 1]);
		minn = min(minn, DPn[i][i + N - 1]);
	}
	cout << minn << endl << maxx;
	return 0;
}