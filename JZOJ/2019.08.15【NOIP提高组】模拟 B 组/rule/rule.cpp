// rule

#include <iostream>
#include <cstdio>
using namespace std;

#define LEN 10000
#define YA 1000000000000

int N;
int p[800000] = {0}, pri[60000], top = 0;
long long a[60000] = {0};
long long res[LEN + 1] = {0};

void _mul(long long x[], int y) {
	long long cmp = x[1] * y;
	x[1] = cmp % YA;
	cmp /= YA;
	for (int i = 2; i <= LEN; ++i) {
		x[i] = cmp % YA;
		cmp /= YA;
	}
}

void _print(long long x[]) {
	int pt = LEN;
	// while (x[pt] == 0)pt--;
	printf("%lld", x[pt--]);
	for (; pt > 0; --pt)
		printf("%012lld", x[pt--]);
}

int main() {

	freopen("rule.in", "r", stdin);
	freopen("rule.out", "w", stdout);

	cin >> N;

	for (int i = 2; i <= N; ++i) {
		if (!p[i]) {
			pri[++top] = i;
			p[i] = top;
			for (int j = 2; i * j <= N; ++j)
				p[i * j] = true;
		}
	}

	for (int i = 2, cmp; i <= N; ++i) {
		cmp = i;
		for (int j = 1; pri[j]*pri[j] <= i; ++j)
			while (cmp % pri[j] == 0)++a[j], cmp /= pri[j];
		if (cmp > 1)++a[p[cmp]];
	}

	res[1] = 1;

	for (int i = 1; i <= top; ++i)
		_mul(res, 2 * a[i] + 1);

	_print(res);

	return 0;
}