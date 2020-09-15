/**
 * luogu P3853
 * [TJOI2007]路标设置
*/

#define MXN (100020)

#include <math.h>
#include <stdio.h>

#include <algorithm>

int L, N, K;
int block[MXN];
int ans;

bool check(double l) {
    int cnt = 0;
    for (int i = N; cnt <= K && i >= 0 && l < block[i]; --i)
        cnt += ceil(block[i] / l) - 1;
    return cnt <= K;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P3853.in", "r", stdin);
#endif

    scanf("%d%d%d", &L, &N, &K);

    int las = -1;
    for (int i = 0, x; i < N; ++i)
        scanf("%d", &x), block[i] = x - las, las = x;
    block[N] = L - las;
    std::sort(block, block + N + 1);

    int l = 1, r = L, m;
    while (l < r)
        if (check(m = (l + r) / 2))
            r = m;
        else
            l = m + 1;

    printf("%d", l);

    return 0;
}