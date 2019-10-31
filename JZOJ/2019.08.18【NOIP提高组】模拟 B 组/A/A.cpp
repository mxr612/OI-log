// A

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
bool vis[2000] = {false};
struct node {
	int ned, lim;
	bool son[1010];
} V[1010];

struct _cmpQ {
	bool operator()(node m, node n) {
		return m.ned > n.ned;
	}
};
queue<node>que[1010];

void dfs(int id) {
	int cmp = V[id].lim;
	priority_queue<node, vector<node>, _cmpQ>pq;
	if (V[id].ned <= V[id].lim)
		pq.push(V[id]);
	for (int i = 1; i <= n; ++i) {
		if (V[id].son[i]) {
			dfs(i);
			while (!que[i].empty()) {
				pq.push(que[i].front());
				que[i].pop();
			}
		}
	}
	while (!pq.empty() && pq.top().ned <= cmp) {
		que[id].push(pq.top());
		cmp -= pq.top().ned;
		pq.pop();
	}
}

int main() {

	freopen("A.in", "r", stdin);

	cin >> n;

	for (int i = 1, f; i <= n; ++i) {
		cin >> f >> V[i].ned >> V[i].lim;
		V[f].son[i] = true;
	}

	V[0].lim = 1e9;

	dfs(0);

	cout << que[0].size() - 1;

	return 0;
}