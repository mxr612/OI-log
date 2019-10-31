// P1119

#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 300, MAX_M = 20000;
int INF;

int N, M, Q;
int G_V[MAX_N] = {0};
int G_E[MAX_N][MAX_N];
int x, y, t;

int k = 0;

void _floyd();

int main() {
// Preprocess
	memset(G_E, 0x3f, sizeof(G_E));
	INF = G_E[0][0];
// InPut
	freopen("P1119.in", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> G_V[i];
	for (int m = 0; m < M; m++) {
		int i, j, w;
		cin >> i >> j >> w;
		G_E[i][j] = G_E[j][i] = w;
	}
// Ask
	cin >> Q;
	for (int q = 1; q <= Q; q++) {
		cin >> x >> y >> t;
		_floyd();
		if (G_V[x] > t || G_V[y] > t || G_E[x][y] == INF)
			cout << -1 << endl;
		else
			cout << G_E[x][y] << endl;
	}
	return 0;
}

void _floyd() {
	for (; G_V[k] <= t && k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (G_E[i][j] > G_E[i][k] + G_E[k][j])
					G_E[i][j] = G_E[j][i] = G_E[i][k] + G_E[k][j];
			}
		}
	}
}