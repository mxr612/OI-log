// code

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define int long long

int N, cmp, ans = 0;
priority_queue<int>a;
priority_queue<int, vector<int>, greater<int> >b;

signed main() {

	freopen("code.in", "r", stdin);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> cmp, a.push(cmp);
	for (int i = 1; i <= N; ++i)
		cin >> cmp, b.push(cmp);

	for (int i = 1; i <= N; ++i)
		ans += a.top() * b.top(), a.pop(), b.pop();

	cout << ans;

	return 0;
}
