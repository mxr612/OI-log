/**
 *
 */

#include <stdio.h>

int dp[2][70][70] = {0};
int mi[100];

inline int _get_top(register long long x) {
	for (int i = 10; i >= 0; --i)
		if ((mi[i]&x) > 0)
			return i;
	return -1;
}

int main() {

	mi[0] = 1;
	for (register int i = 1; i <= 70; ++i)
		mi[i] = mi[i - 1] << 1;

	register long long x = 123;
	dp[1][_get_top(x)][1] = dp[0][_get_top(x)][0] = 1;

	for (register int i = _get_top(x) - 1; i >= 0; --i) {
		for (register int j = 1; j < 70; ++j) {
			dp[0][i][j] = dp[0][i - 1][j] + dp[0][i - 1][j - 1];
		}
	}

	return 0;

}