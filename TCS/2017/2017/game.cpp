// game.in

#include <iostream>
#include <cstdio>
using namespace std;

int K, num[5];
int cmp[5];
bool flag, vis[5] = {false};

void _DfsCom(int dep, int ans) {
	if (dep > 3) {
		if (ans == 24)
			flag = false;
		return ;
	}
	if (flag)
		_DfsCom(dep + 1, ans + cmp[dep]);
	if (flag)
		_DfsCom(dep + 1, ans - cmp[dep]);
	if (flag)
		_DfsCom(dep + 1, ans * cmp[dep]);
	if (flag && ans % cmp[dep] == 0)
		_DfsCom(dep + 1, ans / cmp[dep]);
}

void _DfsNum(int dep) {
	if (dep > 4) {
		_DfsCom(1, 0);
		return ;
	}
	for (int i = 1; flag && i < 5; i++) {
		if (!vis[i]) {
			vis[i] = true;
			cmp[dep] = num[i];
			_DfsNum(dep + 1);
			vis[i] = false;
		}
	}
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out","w",stdout);

	cin >> K;

	for (int k = 0; k < K; ++k) {
		flag = true;
		cin >> num[1] >> num[2] >> num[3] >> num[4];
		_DfsNum(1);
		cout<<(flag?0:1)<<endl;
	}

	return 0;
}