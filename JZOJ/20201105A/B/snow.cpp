
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

const int MXN = 500012;

template <typename TYP>
class MemPool {
    const int SIZ = 1000;
    TYP *p, *e;

    TYP *&get_mem() {
        p = NULL;
        while (!p) p = (TYP *)calloc(sizeof(TYP), SIZ);
        return e = p + SIZ, p;
    }

   public:
    MemPool() { p = NULL, e = NULL; }
    TYP *operator()() { return (p < e) ? (p++) : (get_mem()++); }
};

class ZXS {
    int ll, rr, tot;
    struct Node {
        int w;
        Node *ls, *rs;
    } * root[MXN];
    MemPool<Node> mp;

    inline void merge_up(Node *X) {
        if (!X) return;
        if (X->ls) X->w += X->ls->w;
        if (X->rs) X->w += X->rs->w;
    }

    void build(Node *&x, int l, int r) {
        if (r < l) return;
        x = mp();
        if (l < r)
            build(x->ls, l, (l + r) / 2), build(x->rs, (l + r) / 2 + 1, r), merge_up(x);
        else
            ++x->w;
    }

    void insert(Node *X, Node *&x, const int V, int l, int r) {
        if (r < l) return;
        if (r < V || V < l)
            x = X;
        else if (x = mp(), l < r) {
            if (X)
                insert(X->ls, x->ls, V, l, (l + r) / 2), insert(X->rs, x->rs, V, (l + r) / 2 + 1, r);
            else
                insert(NULL, x->ls, V, l, (l + r) / 2), insert(NULL, x->rs, V, (l + r) / 2 + 1, r);
            merge_up(x);
        } else
            ++x->w;
    }

    int query(Node *X, Node *x, const int L, const int R, int l, int r) {
        if (!x || r < l || r < L || R < l || R < L) return 0;
        if (l < r) return std::max(query(X->ls, x->ls, L, R, l, (l + r) / 2), query(X->rs, x->rs, L, R, (l + r) / 2 + 1, r));
        return (x->w - X->w > 0) * l;
    }

   public:
    inline ZXS(int n) { build(root[tot = 0], ll = 1, rr = n); }
    inline void insert(const int x) { ++tot, insert(root[tot - 1], root[tot], x, ll, rr); }
    bool query(const int l, const int r, const int k) { return ++tot, query(root[std::max(0, tot - k)], root[tot] = root[tot - 1], std::min(l, r), std::max(l, r), ll, rr); }
};

signed main() {
    freopen("snow.in", "r", stdin);
    // freopen("snow.out", "r", stdout);

    int n, m, q;
    unsigned ans;

    scanf("%d%d%d", &n, &m, &q);

    ZXS R(n), C(m);

    for (int i = 1, o, x, xi, xii, yi, yii, k; i <= q; ++i) {
        scanf("%d", &o);
        switch (o) {
            case 1:
                scanf("%d", &x);
                R.insert(x);
                break;
            case 2:
                scanf("%d", &x);
                C.insert(x);
                break;
            case 3:
                scanf("%d%d%d%d%d", &xi, &yi, &xii, &yii, &k);
                ans = -1;
                if (xi == xii && R.query(xi, xii, k)) ans = abs(yi - yii);
                if (yi == yii && C.query(yi, yii, k)) ans = abs(xi - xii);
                if ((R.query(xi, xi, k) && R.query(yii, yii, k)) || (R.query(xii, xii, k) && C.query(yi, yi, k)))
                    ans = abs(xi - xii) + abs(yi - yii);
                if (R.query(xi, xi, k) && R.query(xii, xii, k)) {
                }
                if (C.query(xi, xi, k) && C.query(xii, xii, k)) {
                }
                printf("%d\n", ans);
                break;
            default:;
        }
    }

    return 0;
}