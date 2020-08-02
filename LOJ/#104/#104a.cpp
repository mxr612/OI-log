/**
 * LOJ
 * #104
 * 普通平衡树
 * 有旋Treap
 */

#define MXN (100020)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <algorithm>

int n;

class Treap {
    struct Node {
        int v, w, s, r;
        Node *ls, *rs, *fa, **fr;
    } * root;
    void rotate(Node *x) {  //将x上旋
        if (x == NULL || x->fa == NULL) return;
        Node *y = x->fa, **s = (x == y->ls) ? (&x->rs) : (&x->ls);
        if (*s != NULL) (*s)->fa = y, (*s)->fr = x->fr;
        *x->fr = *s;
        x->fa = y->fa, x->fr = y->fr, *y->fr = x;
        y->fa = x, y->fr = s, *s = y;
        y->s = (y->ls == NULL ? 0 : y->ls->s) + y->w + (y->rs == NULL ? 0 : y->rs->s);
        x->s = (x->ls == NULL ? 0 : x->ls->s) + x->w + (x->rs == NULL ? 0 : x->rs->s);
    }

    void up(Node *x) {
        if (x) {
            while (x->fa && x->fa->r < x->r) {
                rotate(x);
                for (Node *i = x->ls; true;) {
                    if (i->ls && i->r < i->ls->r) {
                        rotate(i->ls);
                        continue;
                    }
                    if (i->rs && i->r < i->rs->r) {
                        rotate(i->rs);
                        continue;
                    }
                    break;
                }
                for (Node *i = x->rs; true;) {
                    if (i->ls && i->r < i->ls->r) {
                        rotate(i->ls);
                        continue;
                    }
                    if (i->rs && i->r < i->rs->r) {
                        rotate(i->rs);
                        continue;
                    }
                    break;
                }
            }
        }
    }

    Node *merge(Node *x, Node *y) {
        if (!x) return y;
        if (!y) return x;
        if (y->v < x->v) std::swap(x, y);
        if (x->r < y->r) {
            x->rs = merge(x->rs, y->ls);
            y->ls = x;
            return y;
        } else {
            y->ls = merge(x->rs, y->ls);
            x->rs = y;
            return x;
        }
    }

   public:
    void insert(int v) {
        Node **x = &root, *xx, *f = NULL;
        while ((*x) && (*x)->v != v)
            if (v < (*x)->v)
                ++(*x)->s, x = &(f = *x)->ls;
            else
                ++(*x)->s, x = &(f = *x)->rs;
        if (!(xx = *x)) xx = *x = (Node *)calloc(sizeof(Node), 1), xx->v = v, xx->r = rand(), xx->fa = f, xx->fr = x;
        ++xx->w, ++xx->s;
    }
    void erase(int v) {
        Node **x = &root, *xx;
        while ((*x) && (*x)->v != v)
            if (v < (*x)->v)
                x = &(*x)->ls;
            else
                x = &(*x)->rs;
        if (xx = *x) {
            --xx->w, --xx->s;
            if (!xx->s)
                *xx->fr = merge(xx->ls, xx->rs);
            for (xx = xx->fa; xx; xx = xx->fa) --xx->s;
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
        while (x && r > 0) {
            if (x->ls && r <= x->ls->v)
                x = x->ls;
            else if (x->rs && x->s - x->rs->s < r)
                r -= x->s - x->rs->s, x = x->rs;
            else
                r = 0;
        }
        return (x) ? (x->v) : (0);
    }
    int query_pre(int v) {
        Node *x = root, *res = NULL;
        while (x && v != x->v)
            if (v < x->v)
                x = x->ls;
            else
                res = x, x = x->rs;
        return (res) ? (res->v) : (0);
    }
    int query_nxt(int v) {
        Node *x = root, *res = NULL;
        while (x && v != x->v)
            if (v < x->v)
                res = x, x = x->ls;
            else
                x = x->rs;
        return (res) ? (res->v) : (0);
    }

} treap;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input2.in", "r", stdin);
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