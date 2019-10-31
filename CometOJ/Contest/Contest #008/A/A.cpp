// A 杀手皇后

#include <iostream>
#include <cstring>
using namespace std;

int n;
string ans, cmp;

int main() {
	freopen("A.in", "r", stdin);

	cin >> n;

	cin >> ans;

	for (int i = 1; i < n; ++i) {
		cin >> cmp;
		ans = min(ans, cmp);
	}

	cout << ans;

	return 0;
}