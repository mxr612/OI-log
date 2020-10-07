/**
 * ybtoj2020.09.19B
 * A或位运算or
*/

#define MXN (100020)

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

int n, m;
int l[MXN], r[MXN], p[MXN];

int ans[MXN];

class XDS {
    struct Node {
        bool a;
        Node *ls, *rs;
    } * root;

    bool del(Node *&x, int L, int R, int l, int r) {
        if (r < l) return false;
        if (!x) x = (Node *)calloc(sizeof(Node), 1), x->a = true;
        if (!x->a || r < L || R < l) return x->a;
        bool xa, xb;
        return x->a = ((L <= l && r <= R) ? (false) : (xa = del(x->ls, L, R, l, (l + r) / 2), xb = del(x->rs, L, R, (l + r) / 2 + 1, r), xa || xb));
    }
    bool qry(Node *x, int L, int R, int l, int r) {
        if (!x) return true;
        if (r < l || r < L || R < l || !x->a) return false;
        if (L <= l && r <= R)
            return (x) ? (x->a) : (true);
        else
            return qry(x->ls, L, R, l, (l + r) / 2) || qry(x->rs, L, R, (l + r) / 2 + 1, r);
    }
    void upd(Node *x, int *a, int p, int l, int r) {
        if (r < l || (x && !x->a)) return;
        if (x && l < r)
            upd(x->ls, a, p, l, (l + r) / 2), upd(x->rs, a, p, (l + r) / 2 + 1, r);
        else
            for (int i = l; i <= r; ++i)
                a[i] |= 1 << p;
    }

   public:
    void dlt(int L, int R) { del(root, L, R, 1, n); }
    bool qry(int L, int R) { return qry(root, L, R, 1, n); }
    void upd(int *a, int p) { upd(root, a, p, 1, n); }
} xds[40];

signed main() {
    freopen("or.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("or.out", "w", stdout);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i)
        scanf("%d%d%d", &l[i], &r[i], &p[i]);

    bool as = true;
    for (int i = 0, j; as && i < 30; ++i) {
        for (j = 0; j < m; ++j)
            if (!(p[j] & (1 << i))) xds[i].dlt(l[j], r[j]);
        for (j = 0; as && j < m; ++j)
            if (p[j] & (1 << i)) as &= xds[i].qry(l[j], r[j]);
        xds[i].upd(ans, i);
    }

    if (as) {
        printf("Yes\n");
        for (int i = 1; i <= n; ++i)
            printf("%d ", ans[i]);
    } else {
        printf("No");
    }

    return 0;
}