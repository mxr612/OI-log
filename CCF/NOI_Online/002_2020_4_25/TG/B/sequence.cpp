/**
 * NOI Online 2
 * B
 * sequence
 */

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

#define MXN (1000020)
#define MOD (1000000007)

int N, A[MXN], las[MXN] = {0};
long long ans = 0;

struct LSH {
    int a, b, d;
} lsh[MXN];
bool cmp1(LSH x, LSH y) {
    return x.a < y.a;
}
bool cmp2(LSH x, LSH y) {
    return x.d < y.d;
}

class LST {
    struct node {
        int l, r, s, t, w;
        long long p;
        node *ls, *rs;
    }* root = NULL;

    void build(node*& x, int l, int r) {
        if (r < l)
            return;
        if (x == NULL)
            x = (node*)calloc(sizeof(node), 1);
        x->l = l, x->r = r, x->s = r - l + 1;
        if (l < r)
            build(x->ls, l, (l + r) >> 1), build(x->rs, ((l + r) >> 1) + 1, r);
    }

    void pow(node* x, long long v) {
        x->p = (x->p + (v * x->w << 1) + x->s * v * v) % MOD, x->w += v * x->s;
    }

    void push(node* x) {
        if (x != NULL && x->ls != NULL) {
            pow(x->ls, x->t), x->ls->t += x->t;
            pow(x->rs, x->t), x->rs->t += x->t;
            x->t = 0;
        }
    }

    void modify(node* x, int l, int r) {
        if (x == NULL || x->r < l || r < x->l)
            return;
        if (l <= x->l && x->r <= r)
            pow(x, 1), ++x->t;
        else {
            push(x);
            modify(x->ls, l, r);
            modify(x->rs, l, r);
            x->p = x->ls->p + x->rs->p;
            x->w = x->ls->w + x->rs->w;
        }
    }

   public:
    void build() { build(root, 1, N); }
    void modify(int l, int r) { modify(root, l, r); }
    long long query() { return root->p; }
} lst;

signed main() {
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);

    scanf("%d", &N);
    for (int i = 1, p; i <= N; ++i)
        scanf("%d", &lsh[i].a), lsh[i].d = i;

    std::sort(&lsh[1], &lsh[N + 1], cmp1);
    for (int i = 1, p = 0; i <= N; ++i)
        lsh[i].b = (lsh[i].a == lsh[i - 1].a) ? (p) : (++p);
    std::sort(&lsh[1], &lsh[N + 1], cmp2);
    for (int i = 1; i <= N; ++i)
        A[i] = lsh[i].b;

    lst.build();

    for (int i = 1; i <= N; ++i) {
        lst.modify((las[A[i]] == 0) ? (1) : (las[A[i]] + 1), i);
        ans = (ans + lst.query()) % MOD;
        las[A[i]] = i;
    }

    printf("%lld", ans);

    return 0;
}