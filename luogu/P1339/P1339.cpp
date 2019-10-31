// P1339

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define TOP (pq.top())

struct node {
	int id, ve;
} cmpN;

struct cmpQ {
	bool operator() (node m, node n) {
		return m.ve > n.ve;
	}
};

int T, C, Ts, Te;
int Rs, Re, Ci;
int E[3000][3000];
bool flag[3000] = {false};
int V[3000] ;

priority_queue<node, vector<node>, cmpQ> pq;
int fr;

int main() {
	freopen("P1339.in", "r", stdin);

	scanf("%d %d %d %d\n", &T, &C, &Ts, &Te);
	memset(E, 0x3f, sizeof(E));
	for (int i = 1; i <= C; i++) {
		scanf("%d %d %d\n", &Rs, &Re, &Ci);
		E[Rs][Re] = E[Re][Rs] = Ci;
	}

	memset(V, 0x3f, sizeof(V));
	V[Ts] = 0;
	cmpN.id = Ts; cmpN.ve = 0;
	pq.push(cmpN);

	while (!pq.empty()) {
		if (!flag[TOP.id]) {
			flag[TOP.id] = true;
			fr = TOP.id;
			pq.pop();
			for (cmpN.id = 1; cmpN.id <= T; cmpN.id++) {
				if (V[cmpN.id] > V[fr] + E[fr][cmpN.id] && !flag[cmpN.id]) {
					cmpN.ve = V[cmpN.id] = V[fr] + E[fr][cmpN.id];
					pq.push(cmpN);
				}
			}
		} else {
			pq.pop();
		}
	}

	printf("%d", V[Te]);

	return 0;
}