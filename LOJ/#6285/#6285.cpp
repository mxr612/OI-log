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

#define MXN (100000)
#define MXS (1000)

int arr[MXN], pos[MXN] = {0};
int cnt[MXN];

struct __lsh {
    int u, id;
} lsh[MXN];
int map[MXN];

bool _cmpa(__lsh x, __lsh y) {
    return x.u < y.u;
}
bool _cmpb(__lsh x, __lsh y) {
    return x.id < y.id;
}

int pre[MXS][MXS];

std::vector<int> apr[MXN];
std::set<int> set;

int ll, rr;

int _cnt(int x) {
    int ret, l, r, m;
    for (l = 0, r = apr[x].size() - 1; l < r;)
        if (apr[x][m = ceil((l + r) / 1.0)] <= rr)
            l = m;
        else
            r = m - 1;
    ret = r;
    for (l = 0, r = apr[x].size() - 1; l < r;)
        if (apr[x][m = (l + r) >> 1] < ll)
            l = m + 1;
        else
            r = m;
    return ret - r + 1;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("a10.in", "r", stdin);
    FILE* ansf = fopen("a10.out", "r");
    int awsl, dif = 0;
#endif

    int n, siz, l, r, max, maxv, cmp;

    scanf("%d", &n), siz = sqrt(n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        lsh[i].u = arr[i], lsh[i].id = i;
        pos[i] = (i - 1) / siz + 1;
    }
    pos[n + 1] = pos[n];

    std::sort(&lsh[1], &lsh[n + 1], _cmpa);
    lsh[0].u = lsh[1].u - 1;
    for (int i = 1, p = 0; i <= n; ++i)
        map[arr[i] = (lsh[i].u == lsh[i - 1].u) ? (p) : (++p)] = lsh[i].u;
    for (int i = 1; i <= n; ++i)
        apr[arr[i]].push_back(i);

    for (int i = 1; i <= n; i += siz) {
        memset(&cnt, 0, sizeof(cnt)), max = 0;
        for (int j = i; j <= n; j += siz) {
            for (int k = j; k < j + siz; ++k)
                if ((cnt[max] == (++cnt[arr[k]])) ? (k < max)
                                                  : (cnt[max] < cnt[arr[k]]))
                    max = arr[k];
            pre[pos[i]][pos[j]] = max;
        }
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l, &r);
        ll = l, rr = r, set.clear();
        while (l <= r && pos[l] == pos[l - 1])
            set.insert(arr[l++]);
        while (l <= r && pos[r] == pos[r + 1])
            set.insert(arr[r--]);
        if (l <= r)
            set.insert(pre[pos[l]][pos[r]]);
        maxv = 0;
        for (std::set<int>::iterator i = set.begin(); i != set.end(); ++i)
            if ((maxv == (cmp = _cnt(*i))) ? (*i < max) : (maxv < cmp))
                max = *i, maxv = cmp;
#ifndef ONLINE_JUDGE
        fscanf(ansf, "%d", &awsl);
        if (awsl != map[max])
            ++dif;
#else
        printf("%d\n", map[max]);
#endif
    }

#ifndef ONLINE_JUDGE
    printf("%d/%d\n", n - dif, n);
#endif

    return 0;
}