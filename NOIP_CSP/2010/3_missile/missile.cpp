#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 110000

struct node
{
	double T0, T1;
} nodes[MAXN];

int qcmp(const void *a, const void *b) {
	return (*(struct node *)a).T0 - (*(struct node *)b).T0;
}

int X0, Y0, X1, Y1, N;
double hz[MAXN] = {0}, ans = 3000000;

int main(int argc, char const *argv[])
{
	memset(nodes, 0, sizeof(nodes));
	freopen("missile.in", "r", stdin);
	// freopen("missile.in", "r", stdin);
	scanf("%d %d %d %d", &X0, &Y1, &X1, &Y1);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int ix, iy;
		scanf("%d %d", &ix, &iy);
		nodes[i].T0 = sqrt((X0 - ix) * (X0 - ix) + (Y0 - iy) * (Y0 - iy));
		nodes[i].T1 = sqrt((X1 - ix) * (X1 - ix) + (Y1 - iy) * (Y1 - iy));
	}
	qsort(&nodes[1], N, sizeof(nodes[0]), qcmp);
	for (int i = N; i > 0; i--) {
		if (nodes[i].T1 > hz[i + 1]) {
			hz[i] = nodes[i].T1;
		} else {
			hz[i] = hz[i + 1];
		}
	}
	for (int i = 0; i <= N; i++) {
		double cmp=nodes[i].T0 * nodes[i].T0 + hz[i + 1]*hz[i + 1];
		if (cmp < ans) {
			ans = cmp;
		}
	}
	printf("%g", ans);
	return 0;
}