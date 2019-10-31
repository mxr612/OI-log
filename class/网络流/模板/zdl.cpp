// 最大流

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

#define MAX_INT 1000
#define TOP (que.front())

int N, M, S, T;

struct edge {int max, now;} edges[MAX_INT][MAX_INT] = {{0, 0}};//from to

int ID[MAX_INT] = {0};

bool bfs() {
	bool end = false;
	queue<int>que;
	memset(ID, 0, sizeof(ID));
	ID[S]=1;
	que.push(S);
	while (!que.empty()) {
		for (int i = 1; i <= N; ++i) {
			if (edges[TOP][i].now < edges[TOP][i].max && ID[i]==0) {
				if (i == T)end = true;
				ID[i]=ID[TOP]+1;
			}
		}
		que.pop();
	}
	return end;
}

int main() {
	freopen("zdl.in", "r", stdin);

	cin >> N >> M >> S >> T;

	for (int i = 1, u, v, w; i <= M; ++i)
		cin >> u >> v >> w, edges[u][v].max = w;

	// while (bfs()) {

	// }

	bfs();

	for(int i=1;i<=N;++i){
		cout<<ID[i]<<endl;
	}


	return 0;
}