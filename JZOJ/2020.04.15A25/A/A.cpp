/**
 * 2020.04.15【NOIP提高组】模拟A 组25
 * JZOJ 2020.04.15 A A
 * DP优化
 * 单调队列
 */

#include <stdio.h>

#define MXN (300020)

int n, k, f[MXN] = {0}, s[MXN] = {0};
int Q[MXN] = {0}, O = 0, I = 0;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);
    getchar();
    for (register int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + ((getchar() == 'H') ? (+1) : (-1));
    for (register int i = 1; i <= n; ++i) {
        while (O <= I && i - Q[O] > k)
            ++O;
        f[i] = f[Q[O]] + (s[i] - s[Q[O]] <= 0);
        while (O <= I &&
               (f[i] < f[Q[I]] || (f[i] == f[Q[I]] && s[i] < s[Q[I]])))
            --I;
        Q[++I] = i;
    }

    printf("%d\n", f[n]);

    return 0;
}