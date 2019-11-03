/**
 * CSP-J2 2019 开放模拟训练题1
 * A 简单数学题
 * mt.in/out
 */

#include <stdio.h>
#include <math.h>
#include <algorithm>

char ch;
int b, c, det;
double x1, x2;

int main() {
	freopen("mt.in", "r", stdin);
	freopen("mt.out", "w", stdout);
	scanf("%c%c%c%d%c%d", &ch, &ch, &ch, &b, &ch, &c);
	det = b * b - 4 * c;
	if (det >= 0) {
		x1 = -(-b + sqrt(det)) / 2;
		x2 = -(-b - sqrt(det)) / 2;
		if (det == 0)
			printf("(x%-+g)^2\n", -x1);
		else
			printf("(x%-+g)(x%-+g)", std::max(x1, x2), std::min(x1, x2));
	} else
		printf("-1");
	return 0;
}