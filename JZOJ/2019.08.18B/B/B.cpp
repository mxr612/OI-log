// B

#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long n, E, ans = 0, S = 0, cnt = 0;

struct sec {
	bool type;
	int id;
} qj[200010];

int _cmpS(sec m, sec n) {
	return m.id < n.id;
}

int main() {

	freopen("B.in", "r", stdin);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> qj[i].id >> qj[n + i].id;
		qj[i].type = true; qj[n + i].type = false;
		S += qj[i].id;
	}

	sort(&qj[1], &qj[n + 1], _cmpS);

	for (int i = 1; i <= 2 * n; ++i) {
		cnt += (qj[i].type) ? (1) : (-1);
		if (qj[i].type)
			S -= qj[i].id;
		if (ans < S + cnt * qj[i].id ) {
			E = qj[i].id;
			ans = S + cnt * qj[i].id;
		}
	}

	cout << E << ' ' << ans;

	return 0;
}