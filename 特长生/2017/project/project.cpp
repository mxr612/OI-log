// project.in

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int N;
int t[201];
int inV[201] = {0};
int E[201][201];

queue<int>que;
int top;

int V[201] = {0};

int ans = 0;

int main() {
	freopen("project.in", "r", stdin);
	freopen("project.out", "w", stdout);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> t[i];

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			if (i != j)
				cin >> E[i][j], inV[i] += E[i][j];
	for (int i = 1; i <= N; ++i)
		if (inV[i] == 0)
			que.push(i), V[i] = t[i], inV[i]--;
	while (!que.empty()) {
		top = que.front();
		que.pop();
		for (int i = 1; i <= N; ++i) {
			if (E[i][top] == 1)
				V[i] = max(V[i], V[top] + t[i]), inV[i]--;
			if (inV[i] == 0)
				que.push(i), inV[i]--;
		}
	}

	for (int i = 1; ans >= 0 && i <= N; ++i) {
		ans = max(ans, V[i]);
		if (inV[i] > 0)
			ans = -1;
	}

	cout << ans;

	return 0;
}