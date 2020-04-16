// 1

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MOD (10081)

int n;

struct edge {int fr, to;} E[200000];
struct node {int l, r;} V[110000];
int cmpS(edge m, edge n) {return (m.fr == n.fr) ? (m.to < n.to) : (m.fr < n.fr);}

int DP[110000];

void dfs(int dad, int id) {
	int a = 1, b = 1;
	for (int i = V[id].l; i <= V[id].r; ++i) {
		if (E[i].to != dad) {
			dfs(id, E[i].to);
			a = (a * DP[E[i].to]) % MOD;
			for (int j = V[E[i].to].l; j <= V[E[i].to].r; ++j)
				if (E[j].to != E[i].to)
					b = (b * DP[E[j].to]) % MOD;
		}
	}
	DP[id] = (a + b) % MOD;
}

int main() {

	freopen("duliji6.in", "r", stdin);
	freopen("1.out", "w", stdout);

	cin >> n;
	for (int i = 1, a, b; i < n; ++i) {
		cin >> a >> b;
		E[i] = {a, b}; E[n - 1 + i] = {b, a};
	}
	sort(&E[1], &E[2 * n - 2], cmpS);
	for (int i = 1; i <= n; ++i)
		V[i] = {0, -1};
	for (int i = 1; i < 2 * n; ++i) {
		if (E[i].fr != E[i - 1].fr) {
			V[E[i - 1].fr].r = i - 1;
			V[E[i].fr].l = i;
		}
	}

	for (int i = 1; i <= n; ++i)
		DP[i] = 1;
	dfs(0, 1);

	cout << DP[1];

	return 0;

}
