// dream.cpp

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_NM 210000

int n, m, pd = 1, minn = 1e9, maxx = -1, ans = 0;
int pt[MAX_NM];
struct lr {
	int l, r;
} dm[MAX_NM];
struct _cmpQ {
	bool operator()(lr m, lr n) {
		return m.r > n.r;
	}
};
priority_queue<lr, vector<lr>, _cmpQ>pq;
#define TOP (pq.top())

int _cmpSp(int m, int n) {
	return m < n;
}
int _cmpSd(lr m, lr n) {
	return m.l < n.l;
}

int main() {

	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> dm[i].l >> dm[i].r, minn = min(minn, dm[i].l), maxx = max(maxx, dm[i].r);
	for (int i = 1; i <= m; ++i)
		cin >> pt[i];

	sort(&dm[1], &dm[n + 1], _cmpSd);
	sort(&pt[1], &pt[m + 1], _cmpSp);

	for (int i = 1; i <= m; ++i) {
		while (pd <= n && dm[pd].l <= pt[i])pq.push(dm[pd]), pd++;
		while (!pq.empty() && TOP.r < pt[i])pq.pop();
		if (!pq.empty()) {
			pq.pop();
			ans++;
		}
	}

	cout << ans;

	return 0;
}
