// P3381

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <iostream>
#include <queue>
using namespace std;

#define MAX_N 10000
#define MAX_M 200000
#define INF (1e9)

struct __edge {
	int v, w, f;
	__edge *nx = NULL, *fx = NULL;
};

struct __graph {
	int n, m, s, t;
	__edge *E[MAX_N] = {NULL}, *pre[MAX_N] = {NULL};
	int cos[MAX_N];

	void _add_edge(int u, int v, int w, int f) {
		__edge *to = (__edge *)calloc(1, sizeof(__edge)), *bk = (__edge *)calloc(1, sizeof(__edge));
		to->v = v, bk->v = u;
		to->w = w, bk->w = 0;
		to->f = f, bk->f = -f;
		to->nx = E[u], bk->nx = E[v];
		E[u] = to, E[v] = bk;
		to->fx = bk, bk->fx = to;
	}

	void _free_edge() {
		__edge *cmp;
		for (int i = 1; i <= n; ++i) {
			while (E[i] != NULL) {
				cmp = E[i];
				E[i] = E[i]->nx;
				free(cmp);
			}
		}
	}

	void _print() {
		for (int i = 1; i <= n; ++i) {
			for (__edge *j = E[i]; j != NULL; j = j->nx) {
				printf("|%-5d%5d|", j->v, j->w);
			}
			cout << endl;
		}
		cout << endl;
	}

} G;

int ans1, ans2;

bool _SPFA(__graph *g) {

	bool flag[MAX_N] = {false};
	queue<int>vis;

	memset(g->cos, 0x6f, sizeof(g->cos));
	flag[g->s] = true, g->cos[g->s] = 0, vis.push(g->s), g->pre[g->s] = NULL;

	while (!vis.empty()) {
		for (__edge *i = g->E[vis.front()]; i != NULL; i = i->nx) {
			if (i->w > 0 && g->cos[i->v] > g->cos[vis.front()] + i->f) {
				g->cos[i->v] = g->cos[vis.front()] + i->f, g->pre[i->v] = i;
				if (!flag[i->v])
					flag[i->v] = true, vis.push(i->v);
			}
		}
		flag[vis.front()] = false;
		vis.pop();
	}

	if (g->cos[g->t] < INF)
		return true;
	else
		return false;

}

int _dfs(__graph *g, __edge *edge, int lim) {
	if (edge == NULL)
		return lim;
	else {
		lim = _dfs(g, g->pre[edge->fx->v], min(lim, edge->w));
		edge->w -= lim;
		edge->fx->w += lim;
		return lim;
	}
}

void _dinic(__graph g, int &lim, int &cos) {

	int cmp;

	lim = cos = 0;

	while (_SPFA(&g)) {
		cmp = _dfs(&g, g.pre[g.t], INF);
		lim += cmp;
		cos += cmp * g.cos[g.t];
	}

}

int main() {

	freopen("P3381.in", "r", stdin);
	// freopen("P3381.out", "w", stdout);

	cin >> G.n >> G.m >> G.s >> G.t;

	for (int i = 1, u, v, w, f; i <= G.m; ++i)
		cin >> u >> v >> w >> f, G._add_edge(u, v, w, f);

	_dinic(G, ans1, ans2);

	cout << ans1 << ' ' << ans2;

	G._free_edge();

	return 0;

}

