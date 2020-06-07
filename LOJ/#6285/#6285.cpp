/**
 * LOJ #6285
 * 分块9
 */

#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <set>
#include <vector>

#define MXN (100100)
#define SIZ (55)
#define MXB (2000)

struct __lsh {
    int u, d;
    bool operator<(__lsh x) { return u < x.u; }
} lsh[MXN];

int arr[MXN], map[MXN];

std::vector<int> apr[MXN];
int pos[MXN] = {0};

int cnt[MXN], pre[MXB][MXB];

std::set<int> set;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("a10.in", "r", stdin);
    FILE* ansf = fopen("a10.out", "r");
    int awsl, dif = 0;
#endif

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", &lsh[i].u), lsh[i].d = i;
    std::sort(&lsh[0], &lsh[n + 1]);
    for (int i = 1, p = 0; i <= n; ++i)
        map[arr[lsh[i].d] = (lsh[i].u == lsh[i - 1].u) ? (p) : (++p)] = lsh[i].u;

    for (int i = 1; i <= n; ++i)
        apr[arr[i]].push_back(i), pos[i] = (i - 1) / SIZ + 1;
    pos[n + 1] = pos[n];

    for (int i = 1, j, k, max = 0; i <= n; i += SIZ)
        for (memset(cnt, 0, sizeof(cnt)), j = i; j <= n; pre[pos[i]][pos[j]] = max, j += SIZ)
            for (k = j; k < j + SIZ; ++k)
                if ((cnt[max] == cnt[arr[k]]) ? (arr[k] < max) : (cnt[max] < cnt[arr[k]]))
                    max = arr[k];

    int ll, rr, res, max, mav;

    for (register int i = 1, l, r, m, x; i <= n; ++i) {
        scanf("%d%d", &ll, &rr), l = ll, r = rr;
        set.clear(), mav = 0;
        for (; l <= r && pos[l] == pos[l - 1]; ++l)
            set.insert(arr[l]);
        for (; l <= r && pos[r] == pos[r + 1]; --r)
            set.insert(arr[r]);
        if (l <= r)
            set.insert(pre[pos[l]][pos[r]]);
        for (std::set<int>::iterator j = set.begin(); j != set.end(); ++j) {
            for (l = 0, r = apr[x = *j].size() - 1; l < r;)
                if (apr[x][m = ceil((l + r) / 2.0)] <= rr)
                    l = m;
                else
                    r = m - 1;
            for (res = l, l = 0, r = apr[x].size() - 1; l < r;)
                if (apr[x][m = (l + r) >> 1] < ll)
                    l = m + 1;
                else
                    r = m;
            if ((mav == (res -= r - 1)) ? (x < max) : (mav < res))
                max = x, mav = res;
        }
#ifndef ONLINE_JUDGE
        fscanf(ansf, "%d", &awsl);
        if (awsl != map[max])
            ++dif;
#else
        printf("%d\n", map[max]);
#endif
    }

#ifndef ONLINE_JUDGE
    printf("%d\n", dif);
#endif

    return 0;
}