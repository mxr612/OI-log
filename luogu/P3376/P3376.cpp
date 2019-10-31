// P3376

#include <stdio.h>
#include <string.h>

#include <iostream>
#include <queue>
using namespace std;

#define INF (1e9)

int N, M, S, T;

struct __edge {
	int u, v, w;
	__edge *next, *back;
} Ex[400000];
__edge* E[40000] = {NULL};

bool _bfs(int flag[]);
int _dfs(int node, int flag[], int ans);
int _dinic();

int main() {

	freopen("P3376.in", "r", stdin);

	cin >> N >> M >> S >> T;

	for (int i = 1; i <= M; ++i) {
		cin >> Ex[M + i].v >> Ex[i].v >> Ex[i].w, Ex[M + i].w = 0;
		Ex[i].next = E[Ex[M + i].v], E[Ex[M + i].v] = &Ex[i], Ex[i].back = &Ex[M + i];
		Ex[M + i].next = E[Ex[i].v], E[Ex[i].v] = &Ex[M + i], Ex[M + i].back = &Ex[i];
	}

	cout << _dinic();

	return 0;

}

bool _bfs(int flag[]) {

	queue<int>goal;

	goal.push(S);
	fill(&flag[1], &flag[N + 1], 0);
	flag[S] = 1;
	while (!goal.empty()) {
		for (__edge* now = E[goal.front()]; now != NULL; now = now->next) {
			if (flag[now->v] == 0 && now->w > 0) {
				flag[now->v] = flag[goal.front()] + 1;
				goal.push(now->v);
			}
		}
		goal.pop();
	}

	return false;

}

int _dfs(int node, int flag[], int ans) {
	int res;
	if (node == T)
		return ans;
	for (__edge* now = E[node]; now != NULL; now = now->next) {
		if (flag[now->v] - flag[node] == 1) {
			res = _dfs(now->v, flag, min(ans, now->w));
			if (res > 0) {
				now->w -= res;
				now->back->w += res;
				return res;
			}
		}
	}
	return -1;
}

int _dinic() {

	int res = 0, flag[20000];

	while (_bfs(flag))res += _dfs(S,flag, INF);

	return res;

}
