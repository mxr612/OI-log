// P3372 【模板】线段树 1
// testdata

#include <stdio.h>
#include <iostream>
using namespace std;

#define MID ((l+r)/2)
#define LS (id*2)
#define RS (id*2+1)
#define SL (((l+r)/2)-l+1)
#define SR (r-((l+r)/2))
#define SZ (r-l+1)

#define LL long long

int N, M, w, x, y;
LL Arr[200000];
struct node {
	LL vl, tg;
} Tree[500000];
LL  k;

void _BuildTree(int lt, int rt, int id);
void _PushDown(int l, int r, int id);
void _Update(int L, int R, LL vl, int l, int r, int id);
LL _Ask(int L, int R, int l, int r, int id);

signed main() {

	freopen("testdata2.in", "r", stdin);

	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; ++i)
		scanf("%lld", &Arr[i]);

	_BuildTree(1, N, 1);

	for (int i = 1; i <= M; ++i) {
		scanf("%d", &w);
		if (w == 1) {
			scanf("%d%d%lld", &x, &y, &k);
			_Update(x, y, k, 1, N, 1);
		} else {
			scanf("%d%d", &x, &y);
			printf("%lld\n", _Ask(x, y, 1, N, 1));
		}
	}

	return 0;
}

void _BuildTree(int l, int r, int id) {
	if (r < l)
		return ;
	Tree[id].tg = 0;
	if (l == r) {
		Tree[id].vl = Arr[l];
	} else {
		_BuildTree(l, MID, LS);
		_BuildTree(MID + 1, r, RS);
		Tree[id].vl = Tree[LS].vl + Tree[RS].vl;
	}
}

void _PushDown(int l, int r, int id) {
	Tree[LS].vl += SL * Tree[id].tg;
	Tree[RS].vl += SR * Tree[id].tg;
	Tree[LS].tg += Tree[id].tg;
	Tree[RS].tg += Tree[id].tg;
	Tree[id].tg = 0;
}

void _Update(int L, int R, LL vl, int l, int r, int id) {
	if (r < l || r < L || R < l)
		return ;
	if (L <= l && r <= R) {
		Tree[id].vl += SZ * vl;
		Tree[id].tg += vl;
	} else {
		_PushDown(l, r, id);
		_Update(L, R, vl, l, MID, LS) ;
		_Update(L, R, vl, MID + 1, r, RS);
		Tree[id].vl = Tree[LS].vl + Tree[RS].vl;
	}
}

LL _Ask(int L, int R, int l, int r, int id) {
	if (r < l || r < L || R < l)
		return 0;
	if (L <= l && r <= R)
		return Tree[id].vl;
	else{
		_PushDown(l, r, id);
		return _Ask(L, R, l, MID, LS) + _Ask(L, R, MID + 1, r, RS);
	}
}
