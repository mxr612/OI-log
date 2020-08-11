/**
 * 
*/

#define MXN (100020)

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

long long K;
int P, n, m;
int s[MXN];

struct Matrix {
    long long a[2][2];
    long long* operator[](int x) { return a[x]; }
    Matrix operator*(Matrix b) {
        Matrix x;
        x[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % P;
        x[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % P;
        x[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % P;
        x[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % P;
        return x;
    }
    Matrix& operator*=(Matrix x) { return *this = (*this) * x; }
} dy, ss[MXN], sec, ans;

void print(Matrix m) {
    printf("%lld %lld %lld %lld\n", m[0][0], m[0][1], m[1][0], m[1][1]);
}

Matrix make(long long a, long long b) {
    Matrix x;
    x[0][0] = 0, x[0][1] = a, x[1][0] = 1, x[1][1] = b;
    return x;
}

struct Modify {
    long long v;
    int a, w;
    bool operator<(const Modify& m) const { return v < m.v; }
} modify[MXN];

class XDS {
    struct Node {
        Matrix m, re;
        int l, r;
        bool nd;
        Node *ls, *rs;
    } * root;
    Matrix build(Node*& x, int l, int r) {
        if (r < l) return dy;
        x = (Node*)calloc(sizeof(Node), 1);
        x->l = l, x->r = r;
        return x->re = x->m = ((l == r) ? (ss[l]) : (build(x->ls, l, (l + r) / 2) * build(x->rs, (l + r) / 2 + 1, r)));
    }
    Matrix query(Node* x, long long& l, long long& r) {
        if (!x || r < x->l || x->r < l) return dy;
        if (l <= x->l && x->r <= r) return x->m;
        return query(x->ls, l, r) * query(x->rs, l, r);
    }
    Matrix modify(Node* x, long long& v, long long& a, long long& w) {
        if (!x) return dy;
        if (v < x->l || x->r < v) return x->m;
        if (x->l == x->r)
            x->m[a][1] = w;
        else
            x->m = modify(x->ls, v, a, w) * modify(x->rs, v, a, w);
        x->nd = true;
        return x->m;
    }
    void recover(Node* x) {
        if (!x || !x->nd) return;
        x->nd = false;
        x->m = x->re;
        recover(x->ls), recover(x->rs);
    }

   public:
    void build() { build(root, 1, n); }
    Matrix query(long long l, long long r) { return query(root, l %= n, (r %= n) ? (r) : (r = n)); }
    void modify(long long v, long long a, long long w) { modify(root, (v %= n) ? (v) : (v = n), a, w); }
    void recover() { recover(root); }
} xds;

Matrix ksm(long long x) {
    Matrix res = dy, cmp = sec;
    while (x) {
        if (x & 1) res *= cmp;
        cmp *= cmp, x >>= 1;
    }
    return res;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    dy[0][0] = dy[1][1] = 1;

    scanf("%lld%d%d", &K, &P, &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &s[i]);
    scanf("%d", &m);
    for (long long i = 0, v, w; i < m; ++i) {
        scanf("%lld%lld", &v, &w);
        modify[i].w = modify[m + i].w = w;
        modify[i].a = 1, modify[i].v = v;
        modify[m + i].a = 0, modify[m + i].v = v + 1;
    }

    sec = dy, s[n] = s[0];
    for (int i = 1; i <= n; ++i)
        sec *= ss[i] = make(s[i - 1], s[i]);
    xds.build();

    std::sort(modify, modify + (m <<= 1));

    ans[0][1] = 1;
    long long nw = 0, bl;
    for (int i = 0; i < m && nw < K;) {
        if (bl = (modify[i].v - 1) / n - nw / n)
            ans *= ksm(bl), nw += n * bl;
        for (bl = (modify[i].v - 1) / n; i < m && bl == (modify[i].v - 1) / n; ++i)
            xds.modify(modify[i].v, modify[i].a, modify[i].w);
        ans *= xds.query(1, std::min(nw += n, K));
        xds.recover();
    }
    if (nw < K) ans *= ksm((K - 1) / n - nw / n), ans *= xds.query(1, K);

    printf("%lld\n", ans[0][0]);

    return 0;
}