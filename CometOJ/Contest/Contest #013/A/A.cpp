// A

#include <stdio.h>

#include <iostream>
using namespace std;

int n, ans = 0;;
char c;

int main() {

	freopen("A.in", "r", stdin);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> c;
		if (c == 'G')
			++ans;
	}

	cout << ans;

	return 0;

}