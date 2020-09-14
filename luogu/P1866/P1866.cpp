/**
 * luogu P1866
*/

#define MXN (100)
#define XJQ (1000000007)

#include <stdio.h>

#include <algorithm>

int N, bunny[MXN];
long long ans = 1;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1866.in", "r", stdin);
#endif

    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
        scanf("%d", &bunny[i]);

    std::sort(bunny, bunny + N);

    for (int i = 0; i < N; ++i)
        if ((ans = (ans * (bunny[i] - i)) % XJQ) < 0) ans = 0;

    printf("%d", ans);

    return 0;
}