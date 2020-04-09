/**
 * LOJ
 * #104
 * 普通平衡树
 * Splay
 */

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
// #include <iostream>

class __splay {
    struct __node {
        int v, w, s;
        __node *ls, *rs, *fa, **pt;
    }* root = NULL;

    inline void _rotate(register __node* x) {
        if (x == NULL || x->fa == NULL)
            return;
        register __node *y = x->fa, **s = (x == y->ls) ? (&x->rs) : (&x->ls);
        if (*s != NULL)
            (*s)->fa = y, (*s)->pt = x->pt;
        *x->pt = *s;
        x->pt = y->pt, x->fa = y->fa, *y->pt = x;
        y->pt = s, y->fa = x, *s = y;
        y->s = ((y->ls == NULL) ? (0) : (y->ls->s)) + y->w +
               ((y->rs == NULL) ? (0) : (y->rs->s));
        x->s = ((x->ls == NULL) ? (0) : (x->ls->s)) + x->w +
               ((x->rs == NULL) ? (0) : (x->rs->s));
    }

    void _splay(__node* x, __node** p) {
        if (x == NULL || x->fa == NULL)
            return;
        while (x->fa != NULL && x != *p)
            if (x->fa == *p)
                _rotate(x);
            else if ((x == x->fa->ls) == (x->fa == x->fa->fa->ls))
                _rotate(x->fa), _rotate(x);
            else
                _rotate(x), _rotate(x);
    }

   public:
    inline void _ins(register int v) {
        register __node **x = &root, *y = NULL;
        while (*x != NULL && (*x)->v != v)
            if (v < (*x)->v)
                y = *x, x = &(*x)->ls;
            else
                y = *x, x = &(*x)->rs;
        if (*x == NULL)
            (*x) = (__node*)calloc(sizeof(__node), 1), (*x)->v = v,
            (*x)->fa = y, (*x)->pt = x;
        _splay(*x, &root);
        ++root->w, ++root->s;
    }

    inline void _del(register int v) {
        register __node* x = root;
        while (x != NULL && x->v != v)
            if (v < x->v)
                x = x->ls;
            else
                x = x->rs;
        if (x == NULL)
            return;
        _splay(x, &root), --x->w, --x->s;
        if (x->w > 0)
            return;
        if (x->ls == x->rs)
            root = 0;
        else if (x->rs == NULL)
            x->ls->fa = NULL, x->ls->pt = &root, root = x->ls;
        else if (x->ls == NULL)
            x->rs->fa = NULL, x->rs->pt = &root, root = x->rs;
        else {
            x = x->rs;
            while (x->ls != NULL)
                x = x->ls;
            _splay(x, &root->rs);
            root->ls->fa = x, root->ls->pt = &x->ls, x->ls = root->ls;
            x->fa = NULL, x->pt = &root, root = x;
        }
    }

    inline int _n2r(register int v) {
        register __node* x = root;
        register int ans = 1;
        while (x != NULL && x->v != v)
            if (v < x->v)
                x = x->ls;
            else
                ans += ((x->ls == NULL) ? (0) : (x->ls->s)) + x->w, x = x->rs;
        ans += ((x->ls == NULL) ? (0) : (x->ls->s));
        _splay(x, &root);
        return ans;
    }

    inline int _r2n(register int r) {
        register __node* x = root;
        while (r > 0)
            if (r <= ((x->ls == NULL) ? (0) : (x->ls->s)))
                x = x->ls;
            else if ((r -= ((x->ls == NULL) ? (0) : (x->ls->s))) <= x->w)
                r = 0;
            else
                r -= x->w, x = x->rs;
        _splay(x, &root);
        return x->v;
    }
    inline int _pre(register int v) {
        register __node *x = root, *y = NULL;
        while (x != NULL)
            if (v <= x->v)
                x = x->ls;
            else
                y = x, x = x->rs;
        _splay(y, &root);
        return y->v;
    }
    inline int _nxt(register int v) {
        register __node *x = root, *y = NULL;
        while (x != NULL)
            if (v < x->v)
                y = x, x = x->ls;
            else
                x = x->rs;
        _splay(y, &root);
        return y->v;
    }

} splay;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input2.in", "r", stdin);
#endif

    int n, o, x;

    scanf("%d", &n);

    for (register int i = 0; i < n; ++i) {
        scanf("%d%d", &o, &x);
        switch (o) {
            case 1:
                splay._ins(x);
                break;
            case 2:
                splay._del(x);
                break;
            case 3:
                printf("%d\n", splay._n2r(x));
                break;
            case 4:
                printf("%d\n", splay._r2n(x));
                break;
            case 5:
                printf("%d\n", splay._pre(x));
                break;
            default:
                printf("%d\n", splay._nxt(x));
        }
    }

    return 0;
}