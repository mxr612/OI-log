/**
 * A
 */

#include <stdio.h>

int _gcd(register int m, register int n) {
	return (n == 0) ? (m) : (_gcd(n, m % n));
}

int main() {

	freopen("A.in", "r", stdin);
	// freopen("A.out", "w", stdout);

	register int a, b, c, ab, cd, ac;

	scanf("%d%d%d", &a, &b, &c);

	ab = _gcd(_gcd(a,b), _gcd());


	printf("%d\n", _gcd(24, 14));

	return 0;
}