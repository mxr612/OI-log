/**
 * P1972 [SDOI2009]HH的项链
 */

#include <stdio.h>
#include <algorithm>

int N, M;
int a[1000020], last[1000020] = {0}, tree[1000020] = {0};

struct __ask {
	int l, r, id, w;
} b[1000020];

bool _cmpa(__ask x, __ask y) {return x.r < y.r;}
bool _cmpb(__ask x, __ask y) {return x.id < y.id;}

void _update(int x, int w) {
	for (; x > 0 && x <= N; x += x & (-x))
		tree[x] += w;
}
int _ask(int x, int y) {
	int res = 0;
	for (; y > 0; y -= y & (-y))
		res += tree[y];
	for (--x; x > 0; x -= x & (-x))
		res -= tree[x];
	return res;
}





int main() {
	freopen("P1972.in", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &a[i]);
	scanf("%d", &M);
	for (int i = 1; i <= M; ++i)
		scanf("%d%d", &b[i].l, &b[i].r), b[i].id = i;
	std::sort(&b[1], &b[M + 1], _cmpa);
	for (int i = 1, j = 1; i <= M; ++i) {
		for (; j <= b[i].r && last[j] != j; ++j)
			_update(last[a[j]], -1), _update(j, 1), last[a[j]] = j;
		b[i].w = _ask(b[i].l, b[i].r);
	}
	std::sort(&b[1], &b[M + 1], _cmpb);
	for (int i = 1; i <= M; ++i)
		printf("%d\n", b[i].w);

	return 0;
}