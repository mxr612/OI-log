/**
 * LOJ #6285
 * 分块9
 */

#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <vector>

#define MXN (100100)
#define SIZ (55)
#define MXB (2000)

struct __lsh {
    int u, d;
    bool operator<(__lsh x) { return u < x.u; }
} lsh[MXN];

int map[MXN], arr[MXN];

std::vector<int> apr[MXN];
int pos[MXN] = {0};

int cnt[MXN], pre[MXB][MXB];

#define que cnt
bool vis[MXN] = {false};

signed
main() {
#ifndef ONLINE_JUDGE
    freopen("a10.in", "r", stdin);
    FILE* ansf = fopen("a10.out", "r");
    int ans, dif = 0;
#endif

    int n;
    scanf("%d", &n);

    for (register int i = 1; i <= n; ++i)
        scanf("%d", &lsh[i].u), lsh[i].d = i;
    std::sort(&lsh[1], &lsh[n + 1]);
    for (register int i = 1, p = 0; i <= n; ++i)
        map[arr[lsh[i].d] = (lsh[i].u == lsh[i - 1].u) ? (p) : (++p)] = lsh[i].u;

    for (register int i = 1; i <= n; ++i)
        apr[arr[i]].push_back(i), pos[i] = (i - 1) / SIZ + 1;
    pos[n + 1] = pos[n];

    for (register int i = 1, j, k, max = 0; i <= n; i += SIZ)
        for (memset(cnt, 0, sizeof(cnt)), j = i + SIZ - 1, k = i; j <= n; pre[pos[i]][pos[j]] = max, j += SIZ)
            for (; k <= j; ++k)
                if ((cnt[max] == cnt[arr[k]]) ? (arr[k] < max) : (cnt[max] < cnt[arr[k]]))
                    max = arr[k];

    int ll, rr, res, max, maxv = 0;

    for (register int i = 0, j = 0, l, r, m, q; i < n; ++i, maxv = j = 0) {
        scanf("%d%d", &ll, &rr), l = ll, r = rr;
        for (; l <= r && pos[l] == pos[l - 1]; ++l)
            if (!vis[arr[l]])
                que[j++] = arr[l], vis[arr[l]] = true;
        for (; l <= r && pos[r] == pos[r + 1]; --r)
            if (!vis[arr[r]])
                que[j++] = arr[r], vis[arr[r]] = true;
        if (l <= r && !vis[pre[pos[l]][pos[r]]])
            que[j++] = pre[pos[l]][pos[r]];
        while (--j >= 0) {
            vis[que[j]] = false;
            for (l = 0, r = apr[q = que[j]].size() - 1; l < r;)
                if (apr[q][m = ceil((l + r) / 2.0)] <= rr)
                    l = m;
                else
                    r = m - 1;
            for (res = l, l = 0, r = apr[q].size() - 1; l < r;)
                if (apr[q][m = (l + r) >> 1] < ll)
                    l = m + 1;
                else
                    r = m;
            if ((maxv == (res -= r - 1)) ? (q < max) : (maxv < res))
                max = q, maxv = res;
        }
#ifndef ONLINE_JUDGE
        fscanf(ansf, "%d", &ans);
        if (ans != map[max]) ++dif;
#else
        printf("%d\n", map[max]);
#endif
    }

#ifndef ONLINE_JUDGE
    printf("%d/%d\n", dif, n);
#endif

    return 0;
}