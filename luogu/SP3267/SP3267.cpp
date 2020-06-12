/**
 * luogu remote judge
 * SPOJ3267
*/

#include <math.h>
#include <stdio.h>

#include <algorithm>

#define MXN (30200)
#define MXA (10000010)
#define MXQ (200020)

int n, q, siz;
int arr[MXN] = {0}, pos[MXN];
struct __qus {
    int id, l, r;
    bool operator<(__qus x) { return (pos[l] == pos[x.l]) ? ((pos[l] & 1) ? (r < x.r) : (r > x.r)) : (pos[l] < pos[x.l]); }
} qus[MXQ];

int l = 0, r = 0, cnt[MXA] = {0}, res = 0;
int ans[MXQ];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("SP3267.in", "r", stdin);
#endif

    scanf("%d", &n), siz = sqrt(n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]), pos[i] = (i - 1) / siz + 1;

    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
        scanf("%d%d", &qus[i].l, &qus[i].r), qus[i].id = i;
    std::sort(&qus[0], &qus[q]);

    for (int i = 0, p; i < q; ++i) {
        while (qus[i].l < l)
            if (cnt[arr[--l]]++ == 0)
                ++res;
        while (r < qus[i].r)
            if (cnt[arr[++r]]++ == 0)
                ++res;
        while (l < qus[i].l)
            if (cnt[arr[l++]]-- == 1)
                --res;
        while (qus[i].r < r)
            if (cnt[arr[r--]]-- == 1)
                --res;
        ans[qus[i].id] = res;
    }

    for (int i = 0; i < q; ++i)
        printf("%d\n", ans[i]);

    return 0;
}