
#include <stdio.h>
#include <stdlib.h>

#include <bitset>

class XDS {
    int L, R;
    struct Node {
        int c;
        std::bitset<32> w;
        Node *ls, *rs;
    } * root;

    inline void color(Node* x, const int c) {
        if (x)
            x->c = c,
            x->w.reset(), x->w[c] = 1;
    }

    void push_down(Node* x) {
        if (!x) return;
        while (!x->ls) x->ls = (Node*)calloc(sizeof(Node), 1), color(x->ls, 1);
        while (!x->rs) x->rs = (Node*)calloc(sizeof(Node), 1), color(x->rs, 1);
        if (x->c) color(x->ls, x->c), color(x->rs, x->c), x->c = 0;
    }
    inline void merge_up(Node* x) {
        if (x && x->ls) x->w = x->ls->w | x->rs->w;
    }

    void cover(Node* x, int l, int r, const int L, const int R, const int C) {
        if (!x || r < l || r < L || R < l) return;
        if (L <= l && r <= R)
            color(x, C);
        else
            push_down(x),
                cover(x->ls, l, (l + r) / 2, L, R, C), cover(x->rs, (l + r) / 2 + 1, r, L, R, C),
                merge_up(x);
    }

    void query(Node* x, int l, int r, std::bitset<32>& cnt, const int L, const int R) {
        if (!x || r < l || r < L || R < l) return;
        if (L <= l && r <= R)
            cnt |= x->w;
        else
            push_down(x),
                query(x->ls, l, (l + r) / 2, cnt, L, R), query(x->rs, (l + r) / 2 + 1, r, cnt, L, R);
    }

    void destruct(Node* x) {
        if (x)
            destruct(x->ls), destruct(x->rs),
                free(x);
    }

   public:
    XDS(int size) {
        L = 1, R = size;
        root = (Node*)calloc(sizeof(Node), 1), color(root, 1);
    }
    void cover(int l, int r, int c) { cover(root, L, R, l, r, c); }
    int query(int l, int r, int k) {
        std::bitset<32> cnt;
        query(root, L, R, cnt, l, r);
        return cnt.count();
    }
    ~XDS() { destruct(root); }
};

signed main() {
    int n,
        m, k;
    char c[5];
    int l, r, x;

    scanf("%d%d%d", &n, &m, &k);

    XDS xds(n);
    for (int i = 0; i < m; ++i)

        if (scanf("%s", c), c[0] == 'C')
            scanf("%d%d%d", &l, &r, &x), xds.cover(l, r, x);
        else
            scanf("%d%d", &l, &r), printf("%d\n", xds.query(l, r, k));

    return 0;
}