//game

#include<iostream>
using namespace std;

int N;
unsigned long long DP[200][200] = {0}, ans = 0;

int main() {

	freopen("game.in", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; ++i) {
		for (int j = i; j <= N; ++j) {
			for (int k = 1; k <= j; ++k) {
				
			}
		}
		ans += DP[i][N];
	}

	return 0;
}