/**
 * P3865
 * ST-RMQ
 */

#include <stdio.h>

#define MXN (1000020)
#define LGN (20)

unsigned N, M, l, r, LOG[MXN] = {0}, MI2[LGN], ST[MXN][LGN];

inline unsigned _max(register unsigned a, register unsigned b) {return a > b ? a : b;}

signed main () {

	freopen("P3865.in", "r", stdin);

	scanf("%u%u", &N, &M);

	for (register unsigned i = 1; i <= N; ++i)
		scanf("%u", &ST[i][0]);
	LOG[2] = MI2[0] = 1;
	for (register unsigned i = 3; i <= N; ++i)LOG[i] = LOG[i / 2] + 1;
	for (register unsigned i = 1; i <= LOG[N]; ++i)MI2[i] = MI2[i - 1] << 1;
	for (register unsigned i, j = 1; j <= LOG[N]; ++j)
		for (i = 1; i + MI2[LOG[j]] - 1 <= N; ++i)
			ST[i][j] = _max(ST[i][j - 1], ST[i + MI2[j - 1]][j - 1]);

	for (register unsigned i = 0, k; i < M; ++i)
		scanf("%u%u", &l, &r), k = LOG[r - l + 1], printf("%u\n", _max(ST[l][k], ST[r - MI2[k] + 1][k]));

	return 0;

}