// P3386 【模板】二分图匹配

#include <iostream>
#include <queue>
using namespace std;

int n, m, e, ans = 0;

bool edge[1001][1001] = {false}, vis[1001] = {false};

int px[1001] = {0}, py[1001] = {0};

int dfs(int node) {
	for (int i = 1; i <= m; ++i) {
		if (edge[node][i] && !vis[i]) {
			vis[i] = true;
			if (py[i] == 0 || dfs(py[i])) {
				px[node] = i;
				py[i] = node;
				vis[i] = false;
				return 1;
			}
		}
	}
	return 0;
}

int main() {

	freopen("P3386.in", "r", stdin);
	freopen("P3386.out", "w", stdout);

	cin >> n >> m >> e;

	for (int i = 1, fr, to; i <= e; ++i) {
		cin >> fr >> to;
		if (fr <= n && to <= m)
			edge[fr][to] = true;
	}

	for (int i = 1; i <= n; ++i)
		ans += dfs(i);

	cout << ans;

	return 0;
}

// 没有理想的人不伤心