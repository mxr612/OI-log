/**
 * luogu P2676
 * [USACO07DEC]Bookshelf B
 */

#include <stdio.h>

#include <algorithm>

int N, B, H[20020];

bool _cmp(int x, int y) {
    return x > y;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P2676.in", "r", stdin);
#endif

    scanf("%d%d", &N, &B);

    for (register int i = 0; i < N; ++i)
        scanf("%d", &H[i]);

    std::sort(H, H + N, _cmp);

    for (register int i = 0; i < N; ++i)
        printf("%d\n", H[i]);

    for (int i = N - 1, s = 0; i >= 0; --i) {
        s += H[i];  // s=s+H[i]
        if (s >= B) {
            printf("%d\n", N - i);
            break;
        }
    }

    return 0;
}