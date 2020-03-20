/**
 * A
 * building4
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned N, A[1000020], B[1000020], a = 0, b = 0, sta[1000020] = {0}, d = 0;
char ans[1000020];
bool _dfs() {
	if (d == N << 1) {
		ans[d + 1] = '\0';
		printf("%s\n", ans + 1);
		return true;
	}
	++d;
	if (A[d] < B[d]) {
		if (++a <= N && sta[d - 1] <= A[d]) {
			ans[d] = 'A';
			sta[d] = A[d];
			if (_dfs())return true;
		}
		--a;
		if (++b <= N && sta[d - 1] <= B[d]) {
			ans[d] = 'B';
			sta[d] = B[d];
			if (_dfs())return true;
		}
		--b;
	} else {
		if (++b <= N && sta[d - 1] <= B[d]) {
			ans[d] = 'B';
			sta[d] = B[d];
			if (_dfs())return true;
		}
		--b;
		if (++a <= N && sta[d - 1] <= A[d]) {
			ans[d] = 'A';
			sta[d] = A[d];
			if (_dfs())return true;
		}
		--a;
	}
	--d;
	return false;
}

signed main() {
	freopen("sample-04-in.txt", "r", stdin);
	scanf("%u", &N);
	for (register unsigned i = 1; i <= N * 2; ++i)
		scanf("%u", &A[i]);
	for (register unsigned i = 1; i <= N * 2; ++i)
		scanf("%u", &B[i]);
	if (!_dfs())
		printf("-1");
	return 0;
}