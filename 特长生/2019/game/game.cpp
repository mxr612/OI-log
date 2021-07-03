// game

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 200000;

int n, ans;
int V[MAX] = {0};
int sign[MAX] = {0};
int mem[MAX] = {0};

void _dfs(int g, int e, int dep) {
	if (mem[e] == 1 || sign[e] == 1)
		return ;
	mem[e] = 1;
	if (g == e) {
		for (int i = 1; i <= n; i++)
			if (mem[i] == 1)
				sign[i] = 1;
		ans = min(ans, dep);
		return ;
	}
	_dfs(g, V[e], dep + 1);
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	memset(&ans, 0x6f, sizeof(ans));
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> V[i];
	for (int i = 1; i <= n; i++) {
		if (sign[i] == 0) {
			memset(mem, 0, sizeof(mem));
			_dfs(i, V[i], 1);
		}
	}
	cout << ans;
	return 0;
}