// P1265
// testdata

#include <stdio.h>
#include <math.h>

#define INF 2000000
#define E(i,j) sqrt((long long)(x[i] - x[j]) * (x[i] - x[j]) + (long long)(y[i] - y[j]) * (y[i] - y[j]))

short n,id;
int x[5001], y[5001];
double V[5001] = {0};
double ans = 0;

double min(double a, double b) {return a < b ? a : b;}

signed main() {
	freopen("testdata.in", "r", stdin);
	scanf("%hd", &n);
	for (short i = 1; i <= n; i++) 
		scanf("%d %d\n", &x[i], &y[i]);
	V[0] = INF;
	for (int i = 2; i <= n; i++){
		V[i] = E(1, i);
	}
	for (short i = 1; i < n; i++) {
		id = 0;
		for (short i = 2; i <= n; i++)
			if (V[i] > 0 && V[id] > V[i])
				id = i;
		ans += V[id];
		V[id] = 0;
		for (short i = 2; i <= n; i++)
			V[i] = min(V[i], E(id, i));
	}
	printf("%.2lf", ans);
	return 0;
}
