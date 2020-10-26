
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

class Treap {
    struct Node {
        int x, r;  //当前点数量，随机值
        int cnt;   //子树数量统计
        int min, max;
        long long v, w;  //当前点代价，子树代价统计
        Node *ls, *rs, *fa, **fr;
    } * root;

    void upd(Node *x) {
        if (x) {
            x->min = x->max = x->v,
            x->w = x->v * x->x,
            x->cnt = x->x;
            if (x->ls)
                x->w += x->ls->w,
                    x->cnt += x->ls->cnt,
                    x->min = x->ls->min;
            if (x->rs)
                x->w += x->rs->w,
                    x->cnt += x->rs->cnt,
                    x->max = x->rs->max;
        }
    }

    void rotate(Node *x) {
        if (!x || !x->fa) return;
        Node *y = x->fa, **z = (x == y->ls) ? (&x->rs) : (&x->ls);
        if (*z) (*z)->fa = y, (*z)->fr = x->fr;
        *x->fr = *z;
        x->fa = y->fa, x->fr = y->fr, *y->fr = x;
        y->fa = x, y->fr = z, *z = y;
        upd(*z), upd(y), upd(x);
    }

    void down(Node *x) {
        while ((x->ls && x->r < x->ls->r) || (x->rs && x->r < x->rs->r))
            if (!x->ls)
                rotate(x->rs);
            else if (!x->rs)
                rotate(x->ls);
            else if (x->ls->r < x->rs->r)
                rotate(x->rs);
            else
                rotate(x->ls);
    }

    inline int cmp(const Node *x, long long &w) {
        int cmp = std::min((long long)x->x, w / x->v);
        w -= x->v * cmp;
        return cmp;
    }
    int query(const Node *x, long long &w) {
        if (!x || !w || w < x->min) return 0;
        if (x->w <= w) return w -= x->w, x->cnt;
        return query(x->rs, w) + cmp(x, w) + query(x->ls, w);
    }

   public:
    Treap() {
        root = NULL;
    }

    void insert(int v, int x) {
        Node **p = &root, *f = NULL;
        while (*p && (*p)->v - v)
            if (v < (*p)->v)
                f = *p, p = &f->ls;
            else
                f = *p, p = &f->rs;
        if (*p)
            (*p)->x += x;
        else
            (*p) = (Node *)calloc(sizeof(Node), 1),
            (*p)->v = v, (*p)->x = x, (*p)->fa = f, (*p)->fr = p;
        for (Node *i = *p; i; i = i->fa)
            upd(i);
        for (Node *i = *p; i->fa && i->fa->r < i->r;)
            rotate(i), down(i);
    }
    int query(long long w) { return query(root, w); }
};

signed main() {
#ifdef ONLINE_JUDGE
    freopen("present.in", "r", stdin);
    freopen("present.out", "w", stdout);
#endif

    srand(74751);

    int n, m;

    scanf("%d%d", &n, &m);

    Treap trp;

    for (int i = 0, v, x; i < n; ++i)
        scanf("%d%d", &v, &x), trp.insert(v, x);

    for (long long i = 0, w; i < m; ++i)
        scanf("%lld", &w), printf("%d\n", trp.query(w));

    return 0;
}