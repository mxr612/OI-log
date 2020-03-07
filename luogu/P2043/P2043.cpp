/**
 * P2043
 */

#include <stdio.h>
#include <algorithm>

#define MAX 100000

int N;

int pri[10020], top = 0;
bool mark[10020] = {false};
int  ans[10020];

int main() {

	freopen("P2043.in", "r", stdin);

	scanf("%d", &N);

	for (register int i = 2; i <= N; ++i) {
		if (!mark[i])
			pri[++top] = i;
		for (register int j = 1; j <= top && pri[j]*i <= N; ++j)
			mark[pri[j]*i] = true;
	}

	for (int i = 1, cmp; i <= top; ++i) {
		cmp = pri[i];
		while (N >= cmp) {
			ans[i] += N / cmp;
			cmp *= pri[i];
		}
	}

	for (register int i = 1; i <= top; ++i)
		if (ans[i] > 0)
			printf("%d %d\n", pri[i], ans[i]);
	return 0;
}