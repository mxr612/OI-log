// fraction

#include <iostream>
using namespace std;

struct __fraction {
	int _gcd(int a, int b) {return (b == 0) ? (a) : (_gcd(b, a % b));}
	int _lcm(int a, int b) {return a * b / _gcd(a, b);}

	int mole, deno;

	void _change_deno(__fraction &x, int m) {
		mole = mole * m / deno, deno = m;
		x.mole = x.mole * m / x.deno, x.deno = m;
	}
	double operator()() {return (double)mole / deno;}
	__fraction operator-(__fraction x) {
		__fraction ans;
		_change_deno(x, _lcm(deno, x.deno));

	}

} a;

int main() {

	cout << a._gcd(6, 15);

	return 0;
}