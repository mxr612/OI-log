// 0

#include <iostream>
#include <cstring>
using namespace std;

unsigned long long mi[70];

short T;
unsigned long long b, a;

short ans[50];

void print() {
	short p = 40;
	while (p > 0 && ans[p] == 0)p--;
	if (p == 0)cout << 0;
	while (p > 0)cout << ans[p--];
	cout << endl;
}

void add(unsigned long long x) {
	short p = 1, up = 0;
	while (x > 0 || up > 0) {
		ans[p] += x % 10 + up;
		up = ans[p] / 10;
		ans[p++] %= 10;
		x /= 10;
	}
}

int main() {

	freopen("0.in", "r", stdin);

	mi[0] = 1;
	for (int i = 1; i <= 60; ++i)
		mi[i] = mi[i - 1] << 1;

	cin >> T;

	for (short i = 1; i <= T; ++i) {
		memset(ans, 0, sizeof(ans));
		for (short j = 1; j < 9; ++j)
			cin >> a, add(mi[a]);
		cin >> b;
		add(b);
		print();
	}

	return 0;

}
