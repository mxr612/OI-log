// P1064

#include <iostream>
using namespace std;

int N, m;

int v[100] = {0}, vp[100] = {0}, q[100][3] = {0};

int DP[40000] = {0};

int main() {
	freopen("testdata.in", "r", stdin);
	cin >> N >> m;
	for (int i = 1; i <= m; i++) {
		int cv, cp, cq;
		cin >> cv >> cp >> cq;
		v[i] = cv;
		vp[i] = cv * cp;
		if (cq != 0){
			q[i][0] = -1;
			q[cq][++q[cq][0]] = i;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (q[i][0] != -1) {
			for (int j = N; j > 0; j -= 10) {
				if (j - v[i] >= 0)
					DP[j] = max(DP[j], DP[j - v[i]] + vp[i]);
				if (j - v[i] - v[q[i][1]] >= 0)
					DP[j] = max(DP[j], DP[j - v[i] - v[q[i][1]]] + vp[i] + vp[q[i][1]]);
				if (j - v[i] - v[q[i][2]] >= 0)
					DP[j] = max(DP[j], DP[j - v[i] - v[q[i][2]]] + vp[i] + vp[q[i][2]]);
				if (j - v[i] - v[q[i][1]] - v[q[i][2]] >= 0)
					DP[j] = max(DP[j], DP[j - v[i] - v[q[i][1]] - v[q[i][2]]] + vp[i] + vp[q[i][1]] + vp[q[i][2]]);
			}
		}
	}
	cout << DP[N];
	return 0;
}