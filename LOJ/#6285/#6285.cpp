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

int n;

struct __lsh {
    int a, i;
    bool operator<(__lsh x) { return a < x.a; }
} lsh[MXN];

int arr[MXN], map[MXN];

std::vector<int> apr[MXN];  //存离散值出现的位置
int pos[MXN] = {0};

int cnt[MXN], pre[MXB][MXB];  //pre存block之间众数的离散值

int ll, rr;

int _cnt(int x) {
    if (cnt[x] >= 0) return cnt[x];
    int l, r, m, res;
    for (l = 0, r = apr[x].size() - 1; l < r;)
        if (apr[x][m = ceil((l + r) / 2.0)] <= rr)
            l = m;
        else
            r = m - 1;
    res = l;
    for (l = 0, r = apr[x].size() - 1; l < r;)
        if (apr[x][m = ceil((l + r) / 2.0)] < ll)
            l = m;
        else
            r = m - 1;
    return cnt[x] = res - l;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("#6285.in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", &lsh[i].a), lsh[i].i = i;
    std::sort(&lsh[1], &lsh[1 + n]);
    for (int i = 1, p = 0; i <= n; ++i)
        map[arr[lsh[i].i] = (lsh[i].a == lsh[i - 1].a) ? (p) : (++p)] = lsh[i].a;

    for (int i = 1; i <= n; ++i)
        apr[i].push_back(0);
    for (int i = 1; i <= n; ++i)
        apr[arr[i]].push_back(i), pos[i] = (i - 1) / SIZ + 1;
    pos[n + 1] = pos[n];

    for (int i = 1, j, k, max = 0; i <= n; i += SIZ)
        for (memset(cnt, 0, sizeof(cnt)), j = i; j <= n; pre[pos[i]][pos[j]] = max, j += SIZ)
            for (k = j; k < j + SIZ; ++k)
                if ((cnt[max] == ++cnt[arr[k]]) ? (arr[k] < max) : (cnt[max] < cnt[arr[k]]))
                    max = arr[k];

    for (int i = 0, l, r, m, max = 0; i < n; ++i) {
        scanf("%d%d", &ll, &rr), l = ll, r = rr;
        memset(cnt, -1, sizeof(cnt));
        for (; l <= r && pos[l] == pos[l - 1]; ++l)
            if ((cnt[max] == _cnt(m = arr[l])) ? (m < max) : (cnt[max] < cnt[m]))
                max = m;
        for (; l <= r && pos[r] == pos[r + 1]; --r)
            if ((cnt[max] == _cnt(m = arr[r])) ? (m < max) : (cnt[max] < cnt[m]))
                max = m;
        if (l <= r && ((cnt[max] == _cnt(m = pre[pos[l]][pos[r]])) ? (m < max) : (cnt[max] < cnt[m])))
            max = m;
        printf("%d\n", map[max]);
    }

    return 0;
}