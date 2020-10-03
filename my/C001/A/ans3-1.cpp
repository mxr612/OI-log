
#define II ("09.in")
#define OO ("09.out")

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 19260817, N = 1e6 + 77;
ll b[N];
struct Seg {
    int mi, num, bz;
} tr[N << 2];
int n, q;
struct A {
    int v, id;
} a[N];
void update(int u) {
    int ls = u << 1, rs = u << 1 | 1;
    if (tr[ls].mi == tr[rs].mi)
        tr[u].mi = tr[ls].mi, tr[u].num = tr[ls].num + tr[rs].num;
    else {
        if (tr[ls].mi > tr[rs].mi) swap(ls, rs);
        tr[u].mi = tr[ls].mi, tr[u].num = tr[ls].num;
    }
}
void pushdown(int u) {
    int ls = u << 1, rs = u << 1 | 1;
    tr[ls].mi += tr[u].bz;
    tr[rs].mi += tr[u].bz;
    tr[ls].bz += tr[u].bz;
    tr[rs].bz += tr[u].bz;
    tr[u].bz = 0;
}
void build(int u, int st, int ed) {
    if (st == ed) {
        tr[u].mi = a[st].v;
        tr[u].num = 1;
        return;
    }
    int mid = st + ed >> 1;
    build(u << 1, st, mid);
    build(u << 1 | 1, mid + 1, ed);
    update(u);
}
void ins(int u, int st, int ed, int l, int r, int x) {
    if (l <= st && ed <= r) {
        tr[u].bz += x;
        tr[u].mi += x;
        return;
    }
    pushdown(u);
    int mid = st + ed >> 1;
    if (mid >= l) ins(u << 1, st, mid, l, r, x);
    if (mid < r) ins(u << 1 | 1, mid + 1, ed, l, r, x);
    update(u);
}
int query(int u, int st, int ed, int l, int r) {
    if (l <= st && ed <= r) {
        return tr[u].mi;
    }
    pushdown(u);
    int mid = st + ed >> 1, yjy = 0x3f3f3f3f;
    if (mid >= l) yjy = query(u << 1, st, mid, l, r);
    if (mid < r) yjy = min(yjy, query(u << 1 | 1, mid + 1, ed, l, r));
    update(u);
    return yjy;
}
bool cmp(A x, A y) {
    return b[x.id] < b[y.id];
}
int main() {
    freopen(II, "r", stdin);
    freopen(OO, "w", stdout);
    scanf("%d%d", &n, &q);  //printf("%d %d\n",n,q);
    for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].v), a[i].id = i;
    //	for(int i=1; i<=n; i++) printf("%d ",i); printf("\n");
    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1);
    //	for(int i=1; i<=n; i++) printf("%d ",a[i]); printf("\n");
    build(1, 1, n);
    while (q--) {
        int op;
        ll l, r;
        scanf("%d", &op);
        int t = 1;
        if (op == 1) t = -t;
        scanf("%lld%lld", &l, &r);
        l = lower_bound(b + 1, b + n + 1, l) - b;
        r = upper_bound(b + 1, b + n + 1, r) - b - 1;
        //		printf("%d %d %d\n",op,l,r);
        if (l <= r && (query(1, 1, n, l, r) != 0 || t == 1))
            ins(1, 1, n, l, r, t);
        if (tr[1].mi == 0)
            printf("%d\n", n - tr[1].num);
        else
            printf("%d\n", n);
    }
}