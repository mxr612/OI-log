
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>

const int MXN = 32,
          MXS = 64,
          MXT = 1 << 21;

int n;

struct Work {
    char S[64];
    int D, C;
} work[MXN];

// SubI
int ans, sor[32], answ[32];

void SubI(int dep, int sta, int tim, int res) {
    if (res >= ans || dep >= n) {
        if (res < ans) {
            ans = res;
            for (int i = 0; i < n; ++i)
                answ[i] = sor[i];
        }
    } else {
        for (int i = 0; i < n; ++i)
            if (!(sta & (1 << i)))
                sor[dep] = i,
                SubI(dep + 1, sta | (1 << i), tim + work[i].C, res + std::max(0, tim + work[i].C - work[i].D));
    }
}

int ti[MXT], fr[MXT];
long long dp[MXT];

signed main() {
    freopen("example_work2.in", "r", stdin);
    // freopen("work.out", "w", stdout);

    int T;

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%s%d%d", work[i].S, &work[i].D, &work[i].C);
        if (n <= 10) {  // SubI 30pts
            ans = 1e9;
            SubI(0, 0, 0, 0);
            printf("%lld\n", ans);
            for (int i = 0; i < n; ++i)
                printf("%s\n", work[answ[i]].S);
        } else {
            memset(dp, 0x3f, sizeof(dp)), dp[(1 << n) - 1] = 0;
            memset(ti, 0, sizeof(ti));
            // memset(fr, -1, sizeof(fr));
            for (int i = 0, j; i < (1 << n); ++i)
                for (j = 0; j < n; ++j)
                    if (i & (1 << j))
                        ti[i] += work[j].C;
            long long res;
            for (int i = (1 << n) - 1, j, k; i >= 0; --i)
                for (j = 0, k = i | 1; j < n; k = i | (1 << (++j)))
                    if (i < k && (res = dp[k] + std::max(0, ti[k] - work[j].D)) < dp[i])
                        dp[i] = res, fr[i] = k;
            printf("%lld\n", dp[0]);
            for (int i = 0; fr[i]; i = fr[i])
                printf("%s\n", work[int(log2(i ^ fr[i]))].S);
        }
    }

    return 0;
}
