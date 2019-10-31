// A

#include <stdio.h>

unsigned long long f[50] = {0};

unsigned long long a, x, b, k;

int main() {

	f[2] = f[3] = 1;
	for (int i = 4; i <= 30; ++i)
		f[i] = f[i - 1] + f[i - 2];

	freopen("A.in", "r", stdin);

	while (scanf("%lld%lld%lld", &a, &x, &b) != EOF) {
		k = (x - f[a]) / f[a + 1];
		if (f[a] + f[a + 1]*k == x)
			printf("%lld\n", f[b] + f[b + 1]*k);
		else
			printf("-1\n");
	}

	return 0;
}