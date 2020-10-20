/**
 * NowCoder7607
 * B
 * 位运算
*/

#define MXA (1000024)

#include <stdio.h>
#include <stdlib.h>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    int n, m;
    bool *is = (bool *)calloc(sizeof(bool), MXA + 32);

    scanf("%d%d", &n, &m);

    for (int i = 0, a; i < n; ++i)
        scanf("%d", &a), is[a] = true;

    for (int i = MXA, j; i >= 0; --i)
        for (j = 1; !is[i] && (i | j) <= MXA; j <<= 1)
            is[i] = is[i | j];

    for (int i = 0, x; i < m; ++i)
        scanf("%d", &x),
            printf("%s\n", (is[x]) ? ("yes") : ("no"));

    return 0;
}