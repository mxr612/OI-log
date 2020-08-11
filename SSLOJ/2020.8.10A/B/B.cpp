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
        Matrix x;
        int l, r;
        Node *ls, *rs;
    } * root;

    Matrix build(Node*& x, int l, int r) {
        if (r < l) return dy;
        x = (Node*)calloc(sizeof(Node), 1), x->l = l, x->r = r;
        return x->x = (l == r) ? (ss[l]) : (build(x->ls, l, (l + r) / 2) * build(x->rs, (l + r) / 2 + 1, r));
    }
    Matrix modify(Node* x, long long& v, int& a, int& w) {
        if (!x) return dy;
        if (v < x->l || x->r < v) return x->x;
        if (x->l == x->r)
            x->x[a][1] = w;
        else
            x->x = modify(x->ls, v, a, w) * modify(x->rs, v, a, w);
        return x->x;
    }
    Matrix query(Node* x, long long& l, long long& r) {
        if (!x || r < x->l || x->r < l) return dy;
        if (l <= x->l && x->r <= r) return x->x;
        return query(x->ls, l, r) * query(x->rs, l, r);
    }

   public:
    void build() { build(root, 0, n - 1); }
    void modify(long long v, int a, int w) { modify(root, v %= n, a, w); }
    Matrix query(long long l, long long r) { return query(root, l %= n, r %= n); }
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
        modify[i].w = modify[n + i].w = w;
        modify[i].v = v = modify[m + i].v = v;
        modify[i].a = 0, modify[n + i].a = 1;
    }
    m <<= 1;
    std::sort(modify, modify + m);

    s[n] = s[0];
    for (int i = 0; i < n; ++i)
        ss[i] = make(s[i], s[i + 1]);

    xds.build();
    sec = xds.query(0, n - 1);

    ans[0][1] = 1;
    long long nw = 0, b;  //现在答案位为f(nw)
    printf("%lld %lld %lld\n", nw, ans[0][0], ans[0][1]);
    for (int i = 0, j; i < m && modify[i].v < K;) {
        if (b = modify[i].v / n - nw / n)
            ans *= ksm(b), nw += b * n;
        printf("%lld %lld %lld\n", nw, ans[0][0], ans[0][1]);
        for (j = i; j < m && modify[j].v / n == modify[i].v / n; ++j)
            xds.modify(modify[j].v + modify[j].a, modify[j].a, modify[j].w);
        for (ans *= xds.query(1, std::min(nw += n, K)); i < j; ++i)
            xds.modify(modify[i].v, modify[i].a, s[(modify[i].v + n - modify[i].a) % n]);
        printf("%lld %lld %lld\n", nw, ans[0][0], ans[0][1]);
    }
    printf("%lld %lld %lld\n", nw, ans[0][0], ans[0][1]);

    return 0;
}