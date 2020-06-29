/**
 * luogu P1725
 * 琪露诺
 * DP 单调队列
*/

#define MXN (200020)

#include <stdio.h>

#include <algorithm>

int N, L, R;
int que[MXN] = {0}, in = 0, ot = 0;
int DP[MXN] = {0}, ans;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1725.in", "r", stdin);
#endif

    scanf("%d%d%d", &N, &L, &R);
    for (int i = 0, x; i < L; ++i)
        scanf("%d", &x), DP[i] = -(1 << 31);
    DP[0] = 0;
    for (int i = L; i <= N; ++i) {
        while (ot <= in && que[ot] < i - R) ++ot;
        while (ot <= in && DP[que[in]] < DP[i - L]) --in;
        que[++in] = i - L;
        scanf("%d", &DP[i]), DP[i] += DP[que[ot]];
    }

    ans = DP[N];
    for (int i = N - R + 1; i < N; ++i)
        ans = std::max(ans, DP[i]);

    printf("%d", ans);

    return 0;
}