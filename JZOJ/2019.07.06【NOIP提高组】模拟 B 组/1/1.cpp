// 1

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int K, A, B;

struct edge {int fr, to;} E[60000];
int cmpS(edge m, edge n) {return (m.fr == n.fr) ? (m.to < n.to) : (m.fr < n.fr);}

struct node {int d, l, r, vl, dep;} V[30001];

queue<int>q;
#define TOP (q.front())

int sovle(int A, int B) {
	int s = 0;
	while (V[A].dep > V[B].dep)s += V[A].vl, A = V[A].d;
	while (V[A].dep < V[B].dep)s += V[B].vl, B = V[B].d;
	while (A != B)s += V[A].vl + V[B].vl, A = V[A].d, B = V[B].d;
	return s + V[A].vl;
}

int main() {

	freopen("1.in", "r", stdin);

	cin >> N >> M;
	for (int i = 1; i < N; ++i)
		cin >> E[i].fr >> E[i].to, E[N - 1 + i] = {E[i].to, E[i].fr};
	for (int i = 1; i <= N; ++i)
		cin >> V[i].vl;
	sort(&E[1], &E[2 * N - 1], cmpS);
	for (int i = 1; i <= N; ++i)
		V[i] = {0, 0, -1, V[i].vl, 1};
	for (int i = 1; i <= 2 * N - 1; ++i) {
		if (E[i].fr != E[i - 1].fr) {
			V[E[i].fr].l = i;
			V[E[i - 1].fr].r = i - 1;
		}
	}

	q.push(1);
	while (!q.empty()) {
		for (int i = V[TOP].l; i <= V[TOP].r; ++i) {
			if (E[i].to != V[TOP].d) {
				V[E[i].to].d = TOP;
				V[E[i].to].dep = V[TOP].dep + 1;
				q.push(E[i].to);
			}
		}
		q.pop();
	}

	for (int i = 1; i <= M; ++i) {
		cin >> K >> A >> B;
		if (K == 1) V[A].vl = B;
		else cout << sovle(A, B) << endl;
	}

	return 0;

}
