// solve

#include <iostream>
using namespace std;

#define A 20
#define B 50
#define C 510

int x, y;

int _exgcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int temp = x, res =	_exgcd(b, a % b, x, y);
	x = y;
	y = temp - a / b * y;
	return res;
}

int main() {

	freopen("solve.in", "r", stdin);

	_exgcd(A, B, x, y);
	cout << x << endl << y;

	return 0;
}