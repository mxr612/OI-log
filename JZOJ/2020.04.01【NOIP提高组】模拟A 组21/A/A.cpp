/**
 * A
 */

#include <stdio.h>
#include <string.h>

#define MXN (500)
#define ULL unsigned long long
inline unsigned _lowbit(register unsigned x) {return x & (-x);}
inline ULL _max(register unsigned x, register unsigned y) {return x > y ? x : y;}
inline ULL _min(register unsigned x, register unsigned y) {return x < y ? x : y;}

unsigned N, K;
unsigned sna[MXN];

unsigned LOG[MXN] = {0}, ST[MXN][10], sum[MXN] = {0};
ULL res[MXN][MXN], DP[MXN][MXN] = {0};

signed main() {

	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);

	scanf("%u %d", &N, &K), ++K;
	for (register unsigned i = 1; i <= N; ++i)
		scanf("%u", &sna[i]), sum[i] = (ST[i][0] = sna[i]) + sum[i - 1];
	for (register unsigned i = 2; i <= N; ++i)
		LOG[i] = LOG[i / 2] + 1;
	for (register unsigned i, j = 1; j <= LOG[N]; ++j)
		for (i = 1; i + (1 << 1) - 1 <= N; ++i)
			ST[i][j] = _max(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
	for (register unsigned i = 1, j, k; i <= N; ++i)
		for (j = i; j <= N; ++j)
			k = j - i + 1, res[i][j] = k * _max(ST[i][LOG[k]], ST[j - (1 << LOG[k]) + 1][LOG[k]]) + sum[i - 1] - sum[j];
	memset(DP, 0x7f, sizeof(DP));

	for (register unsigned i = 1; i <= N; ++i)
		DP[i][1] = res[1][i];
	for (register unsigned j = 2, i, k; j <= K; ++j)
		for (i = j; i <= N; ++i)
			for (k = j - 1; k < i; ++k)
				DP[i][j] = _min(DP[i][j], DP[k][j - 1] + res[k + 1][i]);

	printf("%llu\n", DP[N][K]);

	return 0;

}