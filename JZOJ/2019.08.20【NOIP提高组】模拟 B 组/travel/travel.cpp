// travel

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>

int N, M, t = 0;

struct node {
	int A, B;
	int x, y;
} City[1010][1010], arr[1000010];

long long DP[1000010], ans = 0;

void _Get_Int(int &p) {
	char c = getchar();
	p = 0;
	while (c < '0' || '9' < c)c = getchar();
	while ('0' <= c && c <= '9') {
		p = p * 10 + c - '0';
		c = getchar();
	}
}

int _cmpS(node m, node n) {
	return m.A < n.A;
}

int main() {

	freopen("travel.in", "r", stdin);

	std::cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			_Get_Int(City[i][j].A);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			_Get_Int(City[i][j].B);

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (City[i][j].A > 0 || City[i][M].B > 0) {
				arr[++t] = City[i][j];
				arr[t].x = i; arr[t].y = j;
			}
		}
	}

	std::sort(&arr[1], &arr[t + 1], _cmpS);

	for (int i = 1; i <= t; ++i) {
		for (int j = 1; j < i && arr[j].A < arr[i].A; ++j) {
			DP[i] = std::max(DP[i], DP[j] + abs(arr[i].x - arr[j].x) + abs(arr[i].y - arr[j].y) + arr[i].B);
		}
		ans = std::max(ans, DP[i]);
		std::cout << arr[i].B << std::endl;
	}

	std::cout << ans;

	return 0;
}