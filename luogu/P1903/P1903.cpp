/**
 * luogu P1903
 * [国家集训队]数颜色 / 维护队列
*/

#include <math.h>
#include <stdio.h>

#include <algorithm>

#define MXN (200000)
#define MXM (200000)
#define MXA (1000020)

int arr[MXN];
int pos[MXN];

struct __Q {
    int id, l, r;
    int t;  //this query is in the t-th state
    bool operator<(__Q x) { return (pos[l] == pos[x.l]) ? ((pos[r] == pos[x.r]) ? (t < x.t) : ((pos[l] & 1) ? (pos[r] < pos[x.r]) : (pos[r] > pos[x.r]))) : (pos[l] < pos[x.l]); }
} Q[MXM];
struct __R {
    int p, u, v;
} R[MXM];  //R[i]:In i-th operator, arr[p] has replaced form u to v

int cnt[MXA] = {0};

int ans[MXM];

void _read(register int &x) {
    x = 0;
    register char c = getchar();
    while (c < '0' || '9' < c)
        c = getchar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getchar();
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1903.in", "r", stdin);
#endif

    int N, M, q = 0;
    register int t = 0;

    _read(N), _read(M);

    for (register int i = 1; i <= N; ++i)
        _read(arr[i]);
    for (register int i = 0, c, a, b; i < M; ++i) {
        do
            c = getchar();
        while (c != 'Q' && c != 'R');
        _read(a), _read(b);
        if (c == 'Q')
            Q[q].id = q, Q[q].l = a, Q[q].r = b, Q[q++].t = t;
        else
            R[++t].p = a, R[t].u = arr[a], R[t].v = arr[a] = b;
    }

    for (register int i = 1, siz = ceil(exp((log(N) + log(t)) / 3)); i <= N; ++i)
        pos[i] = (i - 1) / siz + 1;
    std::sort(&Q[0], &Q[q]);

    for (register int i = 0, l = 0, r = 0, res = 0; i < q; ++i) {
        while (Q[i].l < l)
            if (cnt[arr[--l]]++ == 0)
                ++res;
        while (r < Q[i].r)
            if (cnt[arr[++r]]++ == 0)
                ++res;
        while (l < Q[i].l)
            if (cnt[arr[l++]]-- == 1)
                --res;
        while (Q[i].r < r)
            if (cnt[arr[r--]]-- == 1)
                --res;
        while (t < Q[i].t) {
            ++t;
            if (l <= R[t].p && R[t].p <= r) {
                if (cnt[R[t].u]-- == 1) --res;
                if (cnt[R[t].v]++ == 0) ++res;
            }
            arr[R[t].p] = R[t].v;
        }
        while (Q[i].t < t) {
            if (l <= R[t].p && R[t].p <= r) {
                if (cnt[R[t].u]++ == 0) ++res;
                if (cnt[R[t].v]-- == 1) --res;
            }
            arr[R[t].p] = R[t].u;
            --t;
        }
        ans[Q[i].id] = res;
    }

    for (register int i = 0; i < q; ++i)
        printf("%d\n", ans[i]);

    return 0;
}
