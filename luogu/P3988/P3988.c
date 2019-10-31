// P3988.c

#include<stdio.h>

int tree[700001], N = 0, ask, pt = 1, l, r, mid;
char c;

void _put(int p) {
	if (p == 0)
		return ;
	_put(p / 10);
	putchar(p % 10 + '0');
}

#define lowbit(tjq) (tjq&-tjq)
int _ask(int id) {
	int ret = 0;
	for (; id > 0; id -= lowbit(id))
		ret += tree[id];
	return ret;
}

int main() {

	freopen("P3988.in", "r", stdin);
	freopen("P3988.out", "w", stdout);

	c = getchar();
	while (c < '0' || '9' < c)c = getchar();
	while ('0' <= c && c <= '9') {
		N = N * 10 + c - '0';
		c = getchar();
	}

	for (int i = 1; i <= N; ++i)
		tree[i] = lowbit(i);

	for (int i = N; i > 0; --i) {
		ask = 0;
		c = getchar();
		while (c < '0' || '9' < c)c = getchar();
		while ('0' <= c && c <= '9') {
			ask = ask * 10 + c - '0';
			c = getchar();
		}
		ask %= i;
		if ((_ask(N) - _ask(pt)) <= ask) {
			l = 1; r = pt; ask = i - ask;
			while (l <= r) {
				mid = (l + r) / 2;
				if ((_ask(pt) - _ask(mid - 1)) >= ask)
					l = mid + 1;
				else
					r = mid - 1;
			}
			pt = r;
		} else {
			l = pt; r = N; ++ask;
			while (l <= r) {
				mid = (l + r) / 2;
				if ((_ask(mid) - _ask(pt - 1)) >= ask)
					r = mid - 1;
				else
					l = mid + 1;
			}
			pt = l;
		}
		_put(pt); putchar('\n');
		for (int id = pt; id <= N; id += lowbit(id))
			--tree[id];
	}

	return 0;
}