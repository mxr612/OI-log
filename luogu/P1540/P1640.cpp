// P1640 [SCOI2010]连续攻击游戏

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, maxx = -1, ans = 0;

struct lnode {
	int fr, to;
} V[10001];
struct edge {
	int l, r;
} E[2000001];

int pl[10001] = {0}, pr[1000001] = {0};

bool vis[1000001] = {false};

int _cmpS(edge m, edge n) {
	return m.l < n.l;
}

bool dfs(int node) {
	for (int i = V[node].fr; i <= V[node].to; ++i) {
		if (!vis[E[i].r]) {
			vis[E[i].r] = true;
			if (pr[E[i].r] == 0 || dfs(pr[E[i].r])) {
				pl[node] = i;
				pr[E[i].r] = node;
				return true;
			}
		}
	}
	return false;
}

int main() {

	freopen("P1640.in", "r", stdin);
	freopen("P1640.out", "w", stdout);

	cin >> N;

	for (int i = 1; i <= N; ++i) {
		cin >> E[i].l >> E[N + i].l;
		E[i].r = E[N + i].r = i;
		maxx = max(maxx, max(E[i].l , E[N + i].l));
	}

	sort(&E[1], &E[2 * N + 1], _cmpS);
	memset(V, 0, sizeof(V));
	for (int i = 1; i <= 2 * N + 1; ++i) {
		if (E[i].l != E[i - 1].l) {
			V[E[i].l].fr = i;
			V[E[i - 1].l].to = i - 1;
		}
	}

	for (int i = 1; i <= maxx && dfs(i); ++i)
		memset(vis, 0, sizeof(vis)), ++ans;

	cout << ans;

	return 0;
}