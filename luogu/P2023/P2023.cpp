/**
 * luogu P2023
 * [AHOI2009] 维护序列
 * 乘法标记线段树
*/

#define MXN (100020)

#include <stdio.h>
#include <stdlib.h>

int n, p, m;
int arr[MXN];

class XDS {
    struct Node {
        int l, r, s;
        long long w, k, b;
        Node *ls, *rs;
    } * root;

    long long build(Node *&x, int l, int r) {
        if (r < l) return 0;
        x = (Node *)calloc(sizeof(Node), 1);
        x->l = l, x->r = r, x->s = r - l + 1, x->k = 1;
        return x->w = ((l == r) ? (arr[l]) : (build(x->ls, l, (l + r) / 2) + build(x->rs, (l + r) / 2 + 1, r))) % p;
    }
    void push(Node *x) {
        if (x) {
            if (x->ls) {
                x->ls->w = (x->k * x->ls->w + x->b * x->ls->s) % p;
                x->ls->k = (x->k * x->ls->k) % p;
                x->ls->b = (x->k * x->ls->b + x->b) % p;
            }
            if (x->rs) {
                x->rs->w = (x->k * x->rs->w + x->b * x->rs->s) % p;
                x->rs->k = (x->k * x->rs->k) % p;
                x->rs->b = (x->k * x->rs->b + x->b) % p;
            }
            x->k = 1, x->b = 0;
        }
    }
    long long modify(Node *x, int &l, int &r, long long k, long long b) {
        if (!x) return 0;
        if (r < x->l || x->r < l) return x->w;
        if (l <= x->l && x->r <= r) {
            x->w = (k * x->w + b * x->s) % p;
            x->k = (k * x->k) % p;
            x->b = (k * x->b + b) % p;
        } else {
            push(x);
            x->w = (modify(x->ls, l, r, k, b) + modify(x->rs, l, r, k, b)) % p;
        }
        return x->w;
    }
    long long query(Node *x, int &l, int &r) {
        if (!x || r < x->l || x->r < l) return 0;
        if (l <= x->l && x->r <= r) return x->w;
        push(x);
        return (query(x->ls, l, r) + query(x->rs, l, r)) % p;
    }

   public:
    void build() { build(root, 1, n); }
    void mul(int l, int r, int w) { modify(root, l, r, w, 0); }
    void pls(int l, int r, int w) { modify(root, l, r, 1, w); }
    int query(int l, int r) { return query(root, l, r); }
} xds;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P2023.in", "r", stdin);
#endif

    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    scanf("%d", &m);

    xds.build();

    for (int i = 1, opt, t, g, c; i <= m; ++i) {
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                scanf("%d%d%d", &t, &g, &c);
                xds.mul(t, g, c);
                break;
            case 2:
                scanf("%d%d%d", &t, &g, &c);
                xds.pls(t, g, c);
                break;
            case 3:
                scanf("%d%d", &t, &g);
                printf("%d\n", xds.query(t, g));
                break;
            default:;
        }
    }

    return 0;
}
