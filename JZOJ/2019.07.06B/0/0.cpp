// 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vector>
#include <queue>
using namespace std;

int N, M, c;
struct edge {int fr, to, vl;} E[1001];
struct node {int l, r, vl;} V[101];
struct cmpQ {bool operator()(node m, node n){return m.vl < n.vl;}};
priority_queue < node,vector<node>, cmpQ > pq;

int cmpS(const void *m, const void *n) {return ((*(struct edge *)m).fr == (*(struct edge *)n).fr) ? ((*(struct edge *)m).to > (*(struct edge *)n).to) : ((*(struct edge *)m).fr > (*(struct edge *)n).fr);}

int main() {
//file io
	freopen("0.in", "r", stdin);
//	freopen("0.out", "w", stdout);
//int put
	scanf("%d %d %d", &N, &M, &c);
	for (int i = 1; i <= M; ++i)
		scanf("%d %d %d", &E[i].fr, &E[i].to, &E[i].vl);
// make edge
	qsort(&E[1], M, sizeof(E[1]), cmpS);
	for (int i = 1; i <= N; ++i)
		V[i] = {0, -1, (int)1e9};
	for (int i = 1; i <= M + 1; ++i) {
		if (E[i].fr != E[i - 1].fr) {
			V[E[i].fr].l = i;
			V[E[i - 1].fr].r = i - 1;
		}
	}

	V[1].vl = 0;

	return 0;
}
