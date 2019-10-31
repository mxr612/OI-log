// T4 自行车比赛

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define MXI 10010

int N, M, now;
struct edge {
	unsigned short fr, to;
} E[100010] = {0};
int l[10010] = {0}, r[10010] = {0};

int  st[10010], in[10010] = {0};
unsigned int V[10010] = {0};

long long mi[20];

int _cmpSa(edge m, edge n) {
	return m.fr < n.fr;
}
int _cmpSb(edge m, edge n) {
	return m.to < n.to;
}


int main() {

	freopen("T4.in", "r", stdin);
	// freopen("T4.out", "w", stdout);

	mi[0] = 1;
	for (int i = 1; i <= 10; ++i)
		mi[i] = mi[i - 1] * 10;

	cin >> N >> M;

	for (int i = 1; i <= M; ++i) {
		cin >> E[i].fr >> E[i].to;
		++in[E[i].to];
	}

	sort(&E[1], &E[M + 1], _cmpSa);
	memset(l, 0, sizeof(l));
	memset(r, -1, sizeof(r));
	for (int i = 1; i <= M + 1; ++i) {
		if (E[i].fr != E[i - 1].fr) {
			l[E[i].fr] = i;
			r[E[i - 1].fr] = i - 1;
		}
	}

	for (int i = 1; i <= N; ++i) {
		now = -1;
		for (int j = 1; j <= N; ++j) {
			if (in[j] == 0) {
				now = j;
				break;
			}
		}
		if (now == -1) {
			break;
		}
		st[i] = now;
		--in[now];
		for (int j = l[now]; j <= r[now]; ++j )
			--in[E[j].to];
	}

	sort(&E[1], &E[M + 1], _cmpSb);
	memset(l, 0, sizeof(l));
	memset(r, -1, sizeof(r));
	for (int i = 1; i <= M + 1; ++i) {
		if (E[i].to != E[i - 1].to) {
			l[E[i].to] = i;
			r[E[i - 1].to] = i - 1;
		}
	}

	if (in[2] != -1) {
		cout << "inf";
	} else {
		V[1] = 1;
		for (int i = 2; st[i - 1] != 2; ++i) {
			for (int j = l[st[i]]; j <= r[st[i]]; ++j)
				V[st[i]] += V[E[j].fr];
		}
		for (int i = min(ceil(log10(V[2])),9.0); i > 0; --i)
			cout << (V[2] % mi[i])/mi[i-1];
	}

	return 0;
}