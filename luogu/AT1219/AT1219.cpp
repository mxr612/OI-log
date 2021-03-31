/**
 * @file AT1219.cpp
 * @author mxr612 (mxr612@icloud.com)
 * @date 2021-03-31
 * 
 * 歴史の研究
 */

#define MXN (100020)

#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <map>

int N, Q;
int X[MXN];

int pos[MXN];

std::map<int, long long> cnt;

long long res, ans[MXN];

struct Query {
    int l, r, d;
    bool operator<(Query x) { return (pos[l] == pos[x.l]) ? (r < x.r) : (pos[l] < pos[x.l]); }
} query[MXN];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("AT1219.in", "r", stdin);
#endif

    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &X[i]);
    for (int i = 0; i < Q; ++i)
        scanf("%d%d", &query[i].l, &query[i].r), query[i].d = i;

    for (int i = 1, siz = sqrt(N); i <= N; ++i)
        pos[i] = (i - 1) / siz + 1;
    std::sort(&query[0], &query[N]);

    for (int i = 1, j = 0, k, s = sqrt(N) + 1, l, r; i <= pos[N]; ++i, s += sqrt(N)) {
        for (cnt.clear(); pos[query[j].l] == i && pos[query[j].l] == pos[query[j].r]; ++j, cnt.clear())
            for (k = query[j].l; k <= query[j].r; ++k)
                ans[query[j].d] = std::max(ans[query[j].d], cnt[X[k]] += X[k]);
        for (cnt.clear(), res = 0, r = (l = s) - 1; pos[query[j].l] == i; ++j) {
            while (r < query[j].r) ++r, res = std::max(res, cnt[X[r]] += X[r]);
            ans[query[j].d] = res;
            while (query[i].l < l) --l, ans[query[j].d] = std::max(ans[query[j].d], cnt[X[l]] += X[l]);
            while (l < s) cnt[X[l]] -= X[l], ++l;
        }
    }

    for (int i = 0; i < Q; ++i)
        printf("%lld\n", ans[i]);

    return 0;
}