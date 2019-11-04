/**
 * 2019.11.04【NOIP提高组】模拟 B 组
 * B_translate_code
 */

/*
　　const c = 2009;
　　var
　　 n, p, s, i, j, t: integer;
　　begin
　　 read(n, p);
　　 s := 0;
　　 t := 1;
　　 for i := 1 to n do
　　 begin
　　 t := t * p mod c;
　　 for j := 1 to i do
　　 s := (s + t) mod c;
　　 end;
　　 writeln(s);
　　end.
 */

/*
	s=sum(i=1|n|p^i * p)mod 2009
 */

#include <stdio.h>
#include <iostream>

#define c (2009)

int n, p, s = 0, t = 1, ans = 0;

int _sovle(int x) {
	for (int i = 2; i < x; ++i)
		if (x % i == 0)
			return 0;
	return 1;
}

int _gcd(int x, int y) {
	return (y == 0) ? (x) : _gcd(y, x % y);
}

int phi(int x) {
	int ans = x;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			ans = ans / i * (i - 1);
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) ans = ans / x * (x - 1);
	return ans;
}
int main() {
	freopen("B.in", "r", stdin);
	std::cin >> n >> p;
	for (int i = 1; i <= n; ++i) {
		t = t * p % c;
		for (int j = 1; j <= i; ++j)
			s = (s + t) % c;
	}
	// std::cout << s;
	// std::cout << _gcd(2009, 1680);
	std::cout << 2009 * 1680 / _gcd(2009, 1680);
	// std::cout << phi(2009);
	// for (int i = 2; i < c; ++i)
	// 	if (c % i != 0)
	// 		++ans;
	// std::cout << ans;
	return 0;
}