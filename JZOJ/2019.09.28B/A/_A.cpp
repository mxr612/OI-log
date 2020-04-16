// A

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

// dfs序+线段树
// 某节点的子树的所有节点在dfs序中必是一个连续的区间

#define LS (id*2)
#define RS (id*2+1)
#define MID ((l+r)/2)

int N, Q;
struct edge {
	int fr, to;
} Edg[200000];
struct node {
	int el, er;
	int fat;
	int tl, tr;
	int ord;
} Nod[200000];
int  siz = 0;
bool Vis[200000] = {false};
struct tree_node {
	int col, lay;
} Tre[400000];
char c;
int op;

int _CmpS(edge a, edge b);
void _Dfs(int id);
void _Update(int L, int R, int col, int lay, int l, int r, int id);
int _Ask(int Gol);

int main() {

	freopen("tree1.in", "r", stdin);

	scanf("%d%d", &N, &Q);

	memset(Edg, 0, sizeof(Edg));
	for (int i = 1, a, b; i < N; ++i) {
		scanf("%d%d", &a, &b);
		Edg[i].fr = Edg[N - 1 + i].to = a;
		Edg[i].to = Edg[N - 1 + i].fr = b;
	}
	sort(&Edg[1], &Edg[N * 2 - 1], _CmpS);

	for (int i = 1; i < N * 2; ++i) {
		if (Edg[i - 1].fr != Edg[i].fr) {
			Nod[Edg[i - 1].fr].er = i - 1;
			Nod[Edg[i].fr].el = i;
		}
	}
	_Dfs(1);
	memset(Tre, -1, sizeof(Tre));
	_Update(1, N, 1, 0, 1, N, 1);
	for (int i = 1; i <= Q; ++i) {
		cin >> c >> op;
		if (c == 'C')
			_Update(Nod[op].tl, Nod[op].tr, op, i, 1, N, 1);
		else
			cout << _Ask(Nod[op].tl) << endl;
	}

	return 0;
}

int _CmpS(edge a, edge b) {
	return a.fr < b.fr;
}

void _Dfs(int id) {
	Vis[id] = true;
	Nod[id].tl = ++siz;
	for (int i = Nod[id].el; i <= Nod[id].er; ++i)
		if (!Vis[Edg[i].to])
			_Dfs(Edg[i].to);
	Nod[id].tr = siz;
}

void _Update(int L, int R, int col, int lay, int l, int r, int id) {
	if (r < l || r < L || R < l)
		return ;
	if (L <= l && r <= R) {
		Tre[id].col = col;
		Tre[id].lay = lay;
	} else {
		_Update(L, R, col, lay, l, MID, LS);
		_Update(L, R, col, lay, MID + 1, r, RS);
	}
}

int _Ask(int Gol) {
	int col = Tre[1].col, lay = Tre[1].lay, l = 1, r = N, id = 1, mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (Gol <= mid) {
			r = mid;
			id = LS;
			if (lay < Tre[id].lay) {
				col = Tre[id].col;
				lay = Tre[id].lay;
			}
		} else {
			l = mid + 1;
			id = RS;
			if (lay < Tre[id].lay) {
				col = Tre[id].col;
				lay = Tre[id].lay;
			}
		}
	}
	return col;
}
