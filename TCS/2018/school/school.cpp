//school.in

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


int n, k;

int preV[101], qzh[100];

int E[101][101];

int V[101], to;
long long ch, top=0;
#define ab(__________) ((__________)<0?(0):(__________))

int ans = 0;

int main() {
	freopen("school.in", "r", stdin);
	freopen("school.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> preV[i];
	for (int i = 1; i < n; i++)
		cin >> qzh[i], qzh[i] += qzh[i - 1];

	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			E[i][j] = E[j][i] = qzh[j - 1] - qzh[i - 1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			E[i][j] *= preV[i];
	for (int i = 1; i <= n; i++)
		if (top < preV[i])
			top = preV[i], to = i;
	for (int i = 1; i <= n; i++)
		V[i] = E[i][to];

	for (int p = 1; p < k; p++) {
		top = 0;
		for (int i = 1; i <= n; i++) {
			ch = 0;
			for (int j = 1; j <= n; j++)
				ch += ab(V[j] - E[j][i]);
			if (top < ch)
				top = ch, to = i;
		}
		for (int i = 1; i <= n; i++)
			V[i] = min(V[i], E[i][to]);
	}

	for (int i = 1; i <= n; i++)
		ans += V[i];

	cout << ans;

	return 0;
}
