#include <stdio.h>
int main() {
	freopen("prob.in", "r", stdin);
	freopen("prob.out", "w", stdout);
	double n;
	scanf("%lf", &n);
	printf("%.9lf", n = n * (n + 1) / 2 / (2 * n - 1));
	return 0;
}