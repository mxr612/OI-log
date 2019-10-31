// P1991

#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define TOP (pq.top())

struct edge {
	int a, b;
	double v;
} cmpE;

struct cmpQ {
	bool operator() (edge m, edge n) {
		return m.v > n.v;
	}
};

priority_queue <edge, vector<edge>, cmpQ> pq;

int S, P;
int X[600], Y[600];
int V[600];
double E[600];

int main() {
	freopen("testdata.in", "r", stdin);

	cin >> S >> P;
	for (int i = 1; i <= P; i++) {
		cin >> X[i] >> Y[i];
	}

	for (int i = 1; i <= P; i++) {
		V[i] = i;
	}
	for (cmpE.a = 1; cmpE.a < P; cmpE.a++) {
		for (cmpE.b = cmpE.a + 1; cmpE.b <= P; cmpE.b++) {
			cmpE.v = sqrt((X[cmpE.a] - X[cmpE.b]) * (X[cmpE.a] - X[cmpE.b]) + (Y[cmpE.a] - Y[cmpE.b]) * (Y[cmpE.a] - Y[cmpE.b]));
			pq.push(cmpE);
		}
	}

	for (int i = 1; i < P; i++) {
		while (V[TOP.a] == V[TOP.b])pq.pop();
		E[i]=TOP.v;
		for(int i=1,C=V[TOP.a];i<=P;i++){
			if(V[i]==C){
				V[i]=V[TOP.b];
			}
		}
		pq.pop();
	}

	sort(&E[1],&E[P]);
	printf("%.2f",E[P-(S==0?1:S)]);

	return 0;
}