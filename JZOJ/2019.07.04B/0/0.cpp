#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
struct o {int k, c;} O[101];
int cmpS(o m, o n) {return m.c < n.c;}
int n, cnt = 0, t[101], T, S = 0;
signed main() {
	freopen("0.in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> O[i].k >> O[i].c;
	cin >> T;
	for (int i = 1; i <= T; ++i)
		cin >> t[i];
	T = 1;
	sort(&O[1], &O[n + 1], cmpS);	for (int i = 1; i <= n; ++i) {
		if (cnt + O[i].k <= t[T]) {
			S += O[i].k * O[i].c * T;
			cnt += O[i].k;
			if (cnt == t[T])T++;
		} else {
			for (int j = 1; j <= O[i].k; ++j) {
				S += O[i].c * T;
				cnt++;
				if (cnt == t[T])T++;
			}
		}
	}
	cout << S;
	return 0;
}