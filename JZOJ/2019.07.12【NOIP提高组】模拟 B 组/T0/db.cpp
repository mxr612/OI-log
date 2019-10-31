// db.cpp

#include <iostream>
using namespace std;

#define N 5000

unsigned long long a[5001][5001] = {0};

int main() {
	// freopen("T01.out", "w", stdout);

	a[1][0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = i - 1; j <= N; j++) {
			for (int k = 1; k < i; k++) {
				for (int l = 0; l < j; l++) {
					a[i][j] += a[k][l];
				}
			}
			printf("%5d%5d\n",i, j);
		}
	}

	for (int i = 1; i <= N; i++) {
		printf(",{");
		for (int j = 1; j < N; j++)
			printf("%d,", a[i][j]);
		printf("%d}", a[i][N]);
	}

	return 0;
}