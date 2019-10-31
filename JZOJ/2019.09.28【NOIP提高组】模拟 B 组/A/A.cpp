// A

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int N, Q;
struct edge {
	int fr, to;
} Edg[300000];
int L[200000], R[200000];
int  Fat[200000] = {0}, FAT[200000];
struct Operation {
	char typ;
	int id;
} Ope[200000];
int Ans[200000], pt = 0;

int _CmpS(edge a, edge b);
bool Vis[200000] = {false};
void _Dfs(int id);
int _Ask(int id);

int main() {

	freopen("tree1.in", "r", stdin);
	freopen("A.out", "w", stdout);

	cin >> N >> Q;

	memset(Edg, -1, sizeof(Edg));

	for (int i = 1, a, b; i < N; ++i) {
		cin >> a >> b;
		Edg[i].fr = Edg[N - 1 + i].to = a;
		Edg[i].to = Edg[N - 1 + i].fr = b;
	}
	sort(&Edg[1], &Edg[2 * N - 1], _CmpS);
	memset(L, -1, sizeof(L));
	memset(R, -1, sizeof(R));
	for (int i = 1; i <= 2 * N - 1; ++i) {
		if (Edg[i].fr != Edg[i - 1].fr) {
			L[Edg[i].fr] = i;
			R[Edg[i - 1].fr] = i - 1;
		}
	}
	Fat[1] = 1;
	_Dfs(1);
	for (int i = 1; i <= N; ++i)
		FAT[i] = Fat[i];
	for (int i = 1; i <= Q; ++i) {
		cin >> Ope[i].typ >> Ope[i].id;
		if (Ope[i].typ == 'C')
			Fat[Ope[i].id] = Ope[i].id;
	}
	for (int i = Q; i > 0; --i) {
		if (Ope[i].typ == 'C')
			Fat[Ope[i].id] = _Ask(FAT[Ope[i].id]);
		else
			Ans[++pt] = _Ask(Ope[i].id);
	}
	for (int i = pt; i > 0; --i)
		cout << Ans[i] << endl;

	return 0;
}

int _CmpS(edge a, edge b) {
	return a.fr < b.fr;
}

void _Dfs(int id) {
	Vis[id] = true;
	for (int i = L[id]; i <= R[id]; ++i) {
		if (!Vis[Edg[i].to]) {
			Fat[Edg[i].to] = id;
			_Dfs(Edg[i].to);
		}
	}
}

int _Ask(int id) {
	if (Fat[id] != id)
		Fat[id] = _Ask(Fat[id]);
	return Fat[id];
}
