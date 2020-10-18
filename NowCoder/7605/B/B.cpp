/**
 * NowCoder7605
 * B
 * 莫队
*/

#define MXN (100024)

#include <math.h>
#include <stdio.h>

#include <algorithm>

struct Ope {
    int x, y;
} ope[MXN];
struct Qry {
    int l, ll, r, d;
    bool operator<(const Qry q) const { return (ll == q.ll) ? ((ll & 1) ? (r < q.r) : (q.r < r)) : (ll < q.ll); }
} qry[MXN];

int ans[MXN][10];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    int n, m;

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &ope[i].x, &ope[i].y);
    for (int i = 1, sq = sqrt(n); i <= m; ++i)
        scanf("%d%d", &qry[i].l, &qry[i].r), qry[i].ll = (qry[i].l - 1) / sq, qry[i].d = i;
    std::sort(qry + 1, qry + 1 + m);

    int l = 0, r = 0, L[10], R[10], c[10];
    for (int i = 0; i < 10; ++i)
        L[i] = R[i] = i;

    for (int i = 1, j; i <= m; ++i) {
        while (qry[i].l < l) --l, std::swap(L[ope[l].x], L[ope[l].y]);
        while (l < qry[i].l) std::swap(L[ope[l].x], L[ope[l].y]), ++l;
        while (qry[i].r < r) std::swap(R[ope[r].x], R[ope[r].y]), --r;
        while (r < qry[i].r) ++r, std::swap(R[ope[r].x], R[ope[r].y]);
        for (j = 0; j < 10; ++j)
            c[L[j]] = j;
        for (j = 0; j < 10; ++j)
            ans[qry[i].d][j] = c[R[j]];
    }
    for (int i = 1, j; i <= m; ++i, putchar('\n'))
        for (j = 0; j < 10; ++j)
            printf("%d ", ans[i][j]);

    return 0;
}