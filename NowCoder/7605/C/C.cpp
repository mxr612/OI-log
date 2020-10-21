/**
 * NowCoder7605
 * C
 * 主席树
*/

#include <stdio.h>
#include <stdlib.h>

class ZXS {
    int L, R;

    struct Node {
        int w;
        long long s;
        Node *ls, *rs;
    } * *root;
    int tot = 0;

    void insert(const Node* p, Node*& x, int v, int l, int r) {
        if (r < l) return;
        while (!x) x = (Node*)calloc(sizeof(Node), 1);
        x->w = (p) ? (p->w + 1) : (1);
        x->s = (p) ? (p->w + v) : (v);
        if (l < r) {
            if (v <= (l + r) / 2)
                insert((p) ? (p->ls) : (NULL), x->ls, v, l, (l + r) / 2),
                    x->rs = (p) ? (p->rs) : (NULL);
            else
                x->ls = (p) ? (p->ls) : (NULL),
                insert((p) ? (p->rs) : (NULL), x->rs, v, l, (l + r) / 2);
        }
    }

    long long query(const Node* lx, const Node* rx, const long long up, int l, int r) {
        if (r < l || !rx) return 0;
        if ((rx->s - ((lx) ? (lx->s) : (0))) <= up) return rx->w - ((lx) ? (lx->w) : (0));
    }

   public:
    ZXS(int n) {
        L = 1, R = 1e9;
        root = (Node**)calloc(sizeof(Node*), n + 32);
    }

    void insert(int v) { insert(root[tot], root[tot + 1], v, L, R); }
    // int query(int l,int r,int up){return query(root[l-1],root[r],L,up,L,R);}
};

signed main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    int n, m;

    scanf("%d%d", &n, &m);

    ZXS zxs(n);

    for (int i = 0, x; i < n; ++i)
        scanf("%d", &x), zxs.insert(x);

    for (int i = 0, l, r; i < m; ++i) {
        scanf("%d%d", &l, &r);
    }

    return 0;
}