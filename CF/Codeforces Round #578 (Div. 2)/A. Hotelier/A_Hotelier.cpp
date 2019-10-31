#include <iostream>
using namespace std;

int n;

long long mi[20];

long long mem = 0;
char c;

int main() {

	// freopen("A_Hotelier.in", "r", stdin);

	mi[0] = 1;
	for (int i = 1; i < 15; ++i)
		mi[i] = mi[i - 1] << 1;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> c;
		if (c == 'L') {
			for (int i = 0; i < 10; ++i) {
				if (!(mem & mi[i])) {
					mem += mi[i];
					break;
				}
			}
		}
		if (c == 'R') {
			for (int i = 9; i >= 0; --i) {
				if (!(mem & mi[i])) {
					mem += mi[i];
					break;
				}
			}
		}
		if ('0' <= c && c <= '9')
			mem -= mi[c - '0'];
	}

	for (int i = 9; i >= 0; --i) {
		cout << (mem & 1);
		mem >>= 1;
	}

	return 0;
}