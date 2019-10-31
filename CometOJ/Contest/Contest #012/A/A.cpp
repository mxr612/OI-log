// A

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int T;
int n;
string s[2000];
bool ans;

bool _Comp(string a, string b);

int main() {

	freopen("A.in", "r", stdin);

	cin >> T;

	for (int t = 0; t < T; ++t) {
		ans = true;
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> s[i];
		for (int i = 1; i < n && ans; ++i)
			for (int j = i + 1; j <= n && ans; ++j)
				ans = _Comp(s[i], s[j]);

		cout << ((ans) ? ("Yes") : ("No")) << endl;
	}

	return 0;
}
bool _Comp(string a, string b) {
	if ((a[0] == b[0]) && (a[1] == b[1]) && (a[2] == b[2]))
		return false;
	else
		return true;
}
