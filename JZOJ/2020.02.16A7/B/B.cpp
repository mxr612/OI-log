/**
 * B
 */

#include <stdio.h>
#include <algorithm>

#define INF (1e9)

int N, M, SUM = 0;
int A[100], B[100];

double l = 0, r = 10000, mid;

struct __edge {
	int v;
	double w;
	__edge *next, *reverse;
} edge_[10000], *edge[1000] = {NULL};
int edge_usage = 0, node_usage = 2;
int mapA[100] = {0}, mapB[100] = {0}, S = 1, T = 2;
int remapA[200], remapB[200];

inline void _add_edge(int u, int v) {
	edge_[++edge_usage].next = edge[u], edge[u] = &edge_[edge_usage], edge[u]->v = v;
}
inline void _reverse_edge(int x, int y) {
	edge[x]->reverse = edge[y], edge[y]->reverse = edge[x];
}

void _set_graph(double t) {
	for (register int i = 1; i <= M; ++i)
		for (register __edge *j = edge[mapB[i]]; j != NULL; j = j->next)
			j->w = INF, j->reverse->w = 0;
	for (register __edge *i = edge[S]; i != NULL; i = i->next)
		i->w = t * B[remapB[i->v]], i->reverse->w = 0;
	for (register __edge *i = edge[T]; i != NULL; i = i->next)
		i->w = 0, i->reverse->w = A[remapA[i->v]];
	// for (int i = 1; i <= edge_usage; ++i)
	// 	printf("%-5d%-5d%lf\n", edge_[i].reverse->v,  edge_[i].v, edge_[i].w);
}

bool _bfs(int mark[]) {
	std::fill(mark, mark + 200, 0);
	int que[300], in = 0, out = 0, x;
	mark[S] = 1, que[in++] = S;
	while (out < in) {
		x = que[out++];
		for (__edge *i = edge[x]; i != NULL; i = i->next)
			if (i->w > 0 && mark[i->v] == 0)
				mark[i->v] = mark[x] + 1, que[in++] = i->v;
	}
	// for (int i = 1; i <= node_usage; ++i)
	// 	printf("%d\n", mark[i]);
	// printf("\n");
	return mark[T] > 0;
}

double _dfs(int x, double flow, int mark[]) {
	if (x == T)return flow;
	double ans = 0, cmp;
	for (__edge *i = edge[x]; i != NULL && ans < flow; i = i->next) {
		if (i->w > 0 && mark[i->v] == mark[x] + 1) {
			cmp = _dfs(i->v, std::min(i->w, flow - ans), mark);
			if (cmp == 0)
				mark[i->v] = 0;
			else {
				i->w -= cmp;
				i->reverse->w += cmp;
				ans += cmp;
			}
		}
	}
	return ans;
}

bool _dinic(double t) {
	register double sum = 0;
	int mark[300];
	_set_graph(t);

	while (_bfs(mark))sum += _dfs(S, INF, mark);
	return sum == SUM;
}

signed main() {

	freopen("B.in", "r", stdin);

	scanf("%d%d", &N, &M);

	for (register int i = 1; i <= N; ++i)
		scanf("%d", &A[i]), SUM += A[i], mapA[i] = ++node_usage, remapA[node_usage] = i, _add_edge(T, node_usage), _add_edge(node_usage, T), _reverse_edge(T, node_usage);
	for (register int i = 1; i <= M; ++i)
		scanf("%d", &B[i]), mapB[i] = ++node_usage, remapB[node_usage] = i, _add_edge(S, node_usage), _add_edge(node_usage, S), _reverse_edge(S, node_usage);

	for (int i = 1, a; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			scanf("%d", &a);
			if (a == 1)
				_add_edge(mapB[i], mapA[j]), _add_edge(mapA[j], mapB[i]), _reverse_edge(mapB[i], mapA[j]);
		}
	}

	while (r - l > 0.0005) {
		mid = (l + r) / 2;
		_set_graph(mid);
		if (_dinic(mid))
			r = mid;
		else
			l = mid;
	}
	
	printf("%lf\n", mid);

	return 0;
}