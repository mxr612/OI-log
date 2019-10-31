// P1346

#include <iostream>
#include <cstring>
using namespace std;

int N, A, B;
short E[200][200];
int V[200];
bool U[200] = {false};

int get() {
	int res = 0;
	for (int i = 1; i <= N; i++) {
		if (!U[i] && V[i] <= V[res]) {
			res = i;
		}
	}
	return res;
}

int main() {
	freopen("P1346.in", "r", stdin);
	memset(V, 0x6f, sizeof(V));
	cin >> N >> A >> B;
	for (int i = 1; i <= N; i++) {
		cin >> E[i][0];
		for (int j = 1; j <= E[i][0]; j++) {
			cin >> E[i][j];
		}
	}
	V[A] = 0;
	for (int i = 1, now; i < N; i++) {
		now = get();
		if (E[now][0] > 0){
			V[E[now][1]] = min(V[E[now][1]], V[now]);
			for (int j = 2; j <= E[now][0]; j++) {
				V[E[now][j]] = min(V[E[now][j]], V[now] + 1);
			}
		}
		
		U[now] = true;
	}
	cout << ((V[B] == V[0]) ? -1 : V[B]);
	return 0;
}