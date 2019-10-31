#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct _dd {
	unsigned long long vl, wh, ii;
} cmp;
struct _cmpQ {
	bool operator()(_dd a, _dd b) {
		return a.vl < b.vl;
	}
};

int n, m, k, a[200000][10];
unsigned long long mi[200000][10] = {0};

priority_queue<_dd, vector<_dd>, _cmpQ>pq;

unsigned long long _mi(int a, int i) {
	if (mi[a][i] == 0) {
		mi[a][i] = 1;
		while (i > 0) {
			if (i & 1 > 0)
				mi[a][i] *= a;
			a *= a;
			i >>= 1;
		}
	}
	return mi[a][i];
}
unsigned long long _get(int k, int i) {
	unsigned long long ret = 0;
	for (int j = 1; j <= k; ++j)
		ret += a[k][j] * _mi(i, j);
	return ret;
}
int  main() {
	freopen("A.in", "r", stdin);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= k; ++j)
			cin >> a[i][j];

	for (int i = 1; i <= m; ++i) {
		cmp.vl = _get(i, 1), cmp.wh = i, cmp.ii = 1;
		pq.push(cmp);
	}

	for (int i = 1; i < n; ++i) {
		cmp = pq.top(), pq.pop();
		cout << cmp.vl << endl;
		++cmp.ii, cmp.vl = _get(cmp.wh, cmp.ii);
		pq.push(cmp);
	}

	cout << pq.top().vl;

	return 0;

}