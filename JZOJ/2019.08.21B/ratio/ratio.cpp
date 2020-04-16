// ratio

#include <iostream>
#include <vector>
#include <queue>

int N, M, ans[20];
double bz = 1e5;
int V[20], E[20][20] = {0}, C[20];

struct edge {
	int to, vl;
} cmp;
struct _cmpQ {
	bool operator()(edge m, edge n) {
		return m.vl > n.vl;
	}
};

void sovle() {
	std::priority_queue<edge, std::vector<edge>, _cmpQ>pq;
	bool vised[20] = {false};
	int res[20];
	double sum_edge = 0, sum_node = 0;
	vised[C[1]] = true;
	for (int i = 1; i <= M; ++i) {
		cmp.to = C[i];
		cmp.vl = E[C[1]][cmp.to];
		pq.push(cmp);
	}
	for (int i = 1, now; i < M; ++i) {
		while (vised[pq.top().to])pq.pop();
		now = pq.top().to;
		pq.pop();
		vised[now] = true;
		res[i] = now;
		sum_node += V[now];
		sum_edge += E[res[i - 1]][res[i]];
		for (int j = 1; j <= M; ++j) {
			cmp.to = C[j];
			cmp.vl = E[now][cmp.to];
			pq.push(cmp);
		}
	}
	std::cout << sum_edge / sum_node << std::endl;
	if (sum_edge / sum_node < bz) {
		bz = (1.0 * sum_edge / sum_node);
		for (int i = 1; i <= M; ++i)
			ans[i] = res[i];
	}
}

void dfs(int dep, int dad) {
	if (dep > M) {
		sovle();
		return ;
	}
	for (int i = dad + 1; i <= N; ++i) {
		C[dep] = i;
		dfs(dep + 1, i);
	}
}

int main() {

	freopen("ratio.in", "r", stdin);

	std::cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		std::cin >> V[i];
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			std::cin >> E[i][j];
		}
	}

	dfs(1, 0);

	for (int i = 1; i <= M; ++i) {
		std::cout << ans[i] << ' ';
	}

	return 0;
}