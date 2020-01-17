/**
 * C
 */

#include <stdio.h>

int n, q;
int a[1000020], c[1000020];
int keep[100] = {0}, mark[100] = {0};

int _get_top(register int a) {
	for (register int i = 30; i >= 0; --i)
		if ((a & (1 << i)) == (1 << i))
			return i;
	return 35;
}
void _p(register int g) {
	if (g == 0 || g + 1 > n)return;
	if (a[g] <= a[g + 1])
		++keep[_get_top(a[g] ^ a[g + 1])];
	else
		++mark[_get_top(a[g] ^ a[g + 1])];
}
void _m(register int g) {
	if (g == 0 || g + 1 > n)return;
	if (a[g] <= a[g + 1])
		--keep[_get_top(a[g] ^ a[g + 1])];
	else
		--mark[_get_top(a[g] ^ a[g + 1])];
}
bool _cheak() {
	for (int i = 0; i < 31; ++i)
		if (keep[i] > 0 && mark[i] > 0)
			return false;
	return true;
}
void _print() {
	if (_cheak()) {
		register int res = 0;
		for (int i = 31; i >= 0; --i)
			if (mark[i] > 0)
				res |= (1 << i);
		printf("%d\n", res);
	} else
		printf("-1\n");
}

int main() {
	freopen("C.in", "r", stdin);
	scanf("%d", &n);
	for (register int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (register int i = 1; i < n; ++i)
		_p(i);
	_print();
	scanf("%d", &q);
	for (register int i = 0, x, y; i < q; ++i) {
		scanf("%d%d", &x, &y);
		_m(x - 1), _m(x);
		a[x] = y;
		_p(x - 1), _p(x);
		_print();
	}
	return 0;
}