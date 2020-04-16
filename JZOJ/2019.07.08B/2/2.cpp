// 2?

#include <stdio.h>

#include <algorithm>
using namespace std;

int n, lim;

struct edge {int fr, to;} E[6000];
// from to
struct node {int l, r;} V[3001];
// dad value left right
int DP[4000][4000];
int ans = 0;

#define max(c,d) (((c)>(d))?(c):(d))

int cmpS(edge m, edge n) {
	return (m.fr == n.fr) ? (m.to < n.to) : (m.fr < n.fr);
}

void dfs(int dad, int id) {
	for (int i = V[id].l; i <= V[id].r; ++i) {
		if (E[i].to != dad) {
			dfs(id, E[i].to);
			for (int x = lim; x > 1; --x) {
				for (int y = 1; y < x; y++) {
					DP[id][x] = max(DP[id][x], DP[id][y] + DP[E[i].to][x - y]);
				}
			}
		}
	}
}

int main() {

	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= lim; ++j)
			DP[i][j] = -1e9;
	scanf("%d %d", &n, &lim);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &DP[i][1]);
	for (int i = 1; i < n; ++i)
		scanf("%d %d", &E[i].fr, &E[i].to), E[n - 1 + i] = {E[i].to, E[i].fr};
	sort(&E[1], &E[2 * n - 1], cmpS);
	for (int i = 1; i < 2 * n; ++i) {
		if (E[i].fr != E[i - 1].fr) {
			V[E[i].fr].l = i;
			V[E[i - 1].fr].r = i - 1;
		}
	}
	dfs(0, 1);
	for (int i = 1; i <= 2 * n; ++i)
		for (int i = 1; i <= lim; ++i)
			ans = max(ans, DP[1][i]);
	printf("%d", ans);
	return 0;
}
