// P2330

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define INF E[0][0]

int n, m;
int E[400][400];

struct edge {
	short u, v;
} cmpE;

struct cmpQ {
	bool operator() (edge m, edge n) {
		return E[m.u][m.v] > E[n.u][n.v];
	}
};

priority_queue< edge, vector<edge>, cmpQ > pq;
edge cmp;
short V[400] = {0};
int cnt = 1;

int ans = 0;

int main() {
	freopen("P2330.in", "r", stdin);
	memset(E, 0x6f, sizeof(E));

	cin >> n >> m;
	for (int i = 1, u, v, c; i <= m; i++) {
		cin >> u >> v >> c;
		E[u][v] = E[v][u] = c;
	}

	V[1] = 1;
	cmpE.u = 1;
	for (cmpE.v = 1; cmpE.v <= n; cmpE.v++)
		if (E[1][cmpE.v] < INF)
			pq.push(cmpE);

	for (int i = 1; i < n; i++) {
		while (V[(pq.top()).u] == V[(pq.top()).v])pq.pop();
		cmp = pq.top();
		pq.pop();
		cmpE.u = V[cmp.v] ? cmp.u : cmp.v;
		for (cmpE.v = 1; cmpE.v <= n; cmpE.v++)
			if (E[cmpE.u][cmpE.v] < INF)
				pq.push(cmpE);
		V[cmp.u] = V[cmp.v] = 1;
		ans = max(ans, E[cmp.u][cmp.v]);
	}

	cout << n - 1 << ' ' << ans;

	return 0;
}