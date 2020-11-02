/**
 * JZOJ2020.10.31B
 * cat
 * 区间覆盖版题
 * 可以贪心
 * 线段树也可以
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>

const int MXI = 1e9,
          MXN = 5000012;

int A[MXN];

class XDS {
    int ll, rr;
    struct Node {
        int w;
        Node *ls, *rs;
    } * root;

    Node *make_node() {
        Node *x = NULL;
        while (!x) x = (Node *)calloc(sizeof(Node), 1);
        x->w = MXI;
        return x;
    }

    void merge_up(Node *x) {
        if (x && x->ls) x->w = std::min(x->w, x->ls->w);
        if (x && x->rs) x->w = std::min(x->w, x->rs->w);
    }

    void insert(Node *&x, int l, int r, const int P, const int W) {
        if (r < l || r < P || P < l) return;
        if (!x) x = make_node();
        if (l < r)
            insert(x->ls, l, (l + r) / 2, P, W), insert(x->rs, (l + r) / 2 + 1, r, P, W), merge_up(x);
        else
            x->w = std::min(x->w, W);
    }

    int query(Node *x, int l, int r, const int L, const int R) {
        if (!x || r < l || r < L || R < l || R < L) return MXI;
        return (L <= l && r <= R) ? (x->w) : (std::min(query(x->ls, l, (l + r) / 2, L, R), query(x->rs, (l + r) / 2 + 1, r, L, R)));
    }

   public:
    XDS(int l, int r) {
        ll = l, rr = r;
        root = NULL;
    }
    void insert(int p, int w) { insert(root, ll, rr, p, w); }
    int query(int L, int R) { return query(root, ll, rr, L, R); }
};

signed main() {
    freopen("cat.in", "r", stdin);
    freopen("cat.out", "w", stdout);

    int N;

    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d", A + i);

    if (N <= 1000) {
        int *f = (int *)calloc(sizeof(int), N + 32);
        memset(f, 0x6f, sizeof(int) * (N + 16)), f[0] = 0;
        for (int i = 1, ia, j; i <= N; ++i)
            for (ia = std::min(N, i + A[i]), j = std::max(0, i - A[i] - 1); j <= ia; ++j)
                f[ia] = std::min(f[ia], f[j] + 1);
        printf("%d\n", f[N]);
    } else {
        XDS xds(0, N);
        xds.insert(0, 0);
        for (int i = 1, ia; i <= N; ++i)
            ia = std::min(N, i + A[i]), xds.insert(ia, xds.query(std::max(0, i - A[i] - 1), ia) + 1);
        printf("%d\n", xds.query(N, N));
    }

    return 0;
}
