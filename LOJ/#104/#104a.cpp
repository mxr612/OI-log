/**
 * LOJ
 * #104
 * 普通平衡树
 * 有旋Treap
 */

#define MXN (100020)

#include <stdio.h>
#include <time.h>

#include <algorithm>

int n;

class Treap {
    struct Node {
        int v, w, s, r;
        Node *ls, *rs, *fa, **fr;
    } *root = NULL;

    void summa(Node *&x) {
        if (x) x->s = ((x->ls) ? (x->ls->s) : (0)) + x->w + ((x->rs) ? (x->rs->s) : (0));
    }
    void rotate(Node *x) {
        if (!x || !x->fa) return;
        Node *y = x->fa, **s = (x == y->ls) ? (&x->rs) : (&x->ls);
        if (*s) (*s)->fa = y, (*s)->fr = x->fr;
        *x->fr = *s;
        x->fa = y->fa, x->fr = y->fr, *x->fr = x;
        y->fa = x, y->fr = s, *s = y;
        summa(y), summa(x);
    }
    void down(Node *x) {
        if (!x) return;
        if (x->ls && x->r < x->ls->r) rotate(x->ls), down(x);
        if (x->rs && x->r < x->rs->r) rotate(x->rs), down(x);
    }
    void up(Node *x) {
        if (!x) return;
        while (x->fa && x->fa->r < x->r)
            rotate(x), down(x->ls), down(x->rs);
    }
    void del(Node *x) {
        if (!x) return;
        if (!x->ls && !x->rs)
            *x->fr = NULL;
        else if (!x->ls)
            x->rs->fa = x->fa, x->rs->fr = x->fr, *x->fr = x->rs;
        else if (!x->rs)
            x->ls->fa = x->fa, x->ls->fr = x->fr, *x->fr = x->ls;
        else if (x->ls->r < x->rs->r)
            rotate(x->rs), del(x);
        else
            rotate(x->ls), del(x);
    }

   public:
    void insert(int v) {
        Node **x = &root, *fa = NULL, *xx;
        while (*x && v != (*x)->v)
            if (v < (fa = *x)->v)
                ++(*x)->s, x = &(*x)->ls;
            else
                ++(*x)->s, x = &(*x)->rs;
        if (!(xx = *x)) xx = *x = (Node *)calloc(sizeof(Node), 1), xx->v = v, xx->r = rand(), xx->fa = fa, xx->fr = x;
        ++xx->w, ++xx->s;
    }
    void erase(int v) {
        Node *x = root;
        while (x && v != x->v)
            if (v < x->v)
                x = x->ls;
            else
                x = x->rs;
        if (x) {
            for (Node *i = x; i; i = i->fa) --i->s;
            if (--x->w == 0) del(x);
        }
    }
    int query_v2r(int v) {
        Node *x = root;
        int res = 1;
        while (x && v != x->v)
            if (v < x->v)
                x = x->ls;
            else
                res += ((x->ls) ? (x->ls->s) : (0)) + x->w, x = x->rs;
        return res + ((x && x->ls) ? (x->ls->s) : (0));
    }
    int query_r2v(int r) {
        Node *x = root;
        while (x && r > 0)
            if (x->ls && r <= x->ls->s)
                x = x->ls;
            else if (x->rs && (r -= x->s - x->rs->s) > 0)
                x = x->rs;
            else
                break;
        return (x) ? (x->v) : (0);
    }
    int query_pre(int v) {
        Node *x = root, *res = NULL;
        while (x)
            if (v <= x->v)
                x = x->ls;
            else
                x = (res = x)->rs;
        return (res) ? (res->v) : (0);
    }
    int query_nxt(int v) {
        Node *x = root, *res = NULL;
        while (x)
            if (v < x->v)
                x = (res = x)->ls;
            else
                x = x->rs;
        return (res) ? (res->v) : (0);
    }
} treap;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input9.in", "r", stdin);
#endif

    srand(time(NULL));

    scanf("%d", &n);

    for (int i = 1, opt, x; i <= n; ++i) {
        scanf("%d%d", &opt, &x);
        switch (opt) {
            case 1:
                treap.insert(x);
                break;
            case 2:
                treap.erase(x);
                break;
            case 3:
                printf("%d\n", treap.query_v2r(x));
                break;
            case 4:
                printf("%d\n", treap.query_r2v(x));
                break;
            case 5:
                printf("%d\n", treap.query_pre(x));
                break;
            case 6:
                printf("%d\n", treap.query_nxt(x));
                break;
            default:;
        }
    }

    return 0;
}