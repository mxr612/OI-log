// B. book

#include <stdio.h>
#include <iostream>
using namespace std;

int n, p, q, x, y, f = 0, t = 0, ans = 0;
char c;
short str[1100000], s;

int main() {

	freopen("book.in", "r", stdin);

	cin >> n >> p >> q >> x >> y;
	for (int i = 1; i <= n; ++i)
		cin >> c, str[i] = (c == '-') ? (-1) : (+1), f += str[i];
	t = p - q;

	if (f < t) {
		for (int i = 1; f != t && i <= n; ++i) {
			if (str[i] == '-') {

			}
		}
	} else if (f > t) {

	}

	return 0;
}