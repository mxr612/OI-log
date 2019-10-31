// T2 邦德I

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n;

bool vis[30] = {false};
double  ans = 0;
struct node {
	int tsk;
	double vl;
} jim[30][30];

int _cmpS(node m, node n) {
	return m.vl > n.vl;
}

void _dfs(int dep, double res) {
	if (res <= ans)
		return ;
	if (dep > n) {
		ans = res;
		return ;
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[jim[dep][i].tsk]) {
			vis[jim[dep][i].tsk] = true;
			_dfs(dep + 1, res * jim[dep][i].vl);
			vis[jim[dep][i].tsk] = false;
		}
	}
}

int main() {

	freopen("T2.in", "r", stdin);
	// freopen("T2.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> jim[i][j].vl;
			jim[i][j].vl /= 100;
			jim[i][j].tsk = j;
		}
		sort(&jim[i][1], &jim[i][n + 1], _cmpS);
	}

	_dfs(1, 1);

	printf("%.6lf", ans*100);

	return 0;
}