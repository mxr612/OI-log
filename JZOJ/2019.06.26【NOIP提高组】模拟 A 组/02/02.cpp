// 02

#include <cstdio>
#include <iostream>
using namespace std;

double T, N, M, A, B, C, D;

int main() {

	freopen("02.in", "r", stdin);

	cin >> T >> N >> A >> B >> M >> C >> D;

	cout << ((T - A * N - C * M)*B) / (B + D) + A*N;

	return 0;
}