#include <iostream>
#include <algorithm>
using namespace std;
int n, cnt;
unsigned long long f[5000005];
void dfs(int lev, unsigned long long sum) {
	f[++cnt] = sum;
	if (lev > 19) return;
	dfs(lev + 1, sum * 10);
	dfs(lev + 1, sum * 10 + 1);
}
int main() {
	freopen("T1.in", "r", stdin);
	cin >> n;
	dfs(1, 1);
	sort(f + 1, f + 1 + cnt);
	for (int i = 1; i <= cnt; i++)
		if (f[i] % n == 0){
			cout << f[i] / n;
			return 0;
		}
	cout << "no solution";
}
