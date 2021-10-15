/**
 * @file P3373.cpp
 * @author mxr612 (mxr612@icloud.com)
 * @date 2021-10-15
 * @brief 线段树
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <vector>

const int MXN = 1e5 + 20;

int n, m, p;
int a[MXN];

class XDS {
    struct Node {
        long long k, x, b;
        int size;
        Node *ls, *rs;
    };

    int SIZE = ceil((double)1024 * 1024 / sizeof(Node));
    Node *st = NULL, *ed = NULL;
    std::vector<void*> mem_sta;
    Node* get_mem() {
        if (st >= ed) {
            void* p = malloc(SIZE * sizeof(Node));
            mem_sta.push_back(p);
            st = (Node*)p, ed = st + SIZE;
        }
        return st++;
    }

    int N;
    Node* root;

    void build(Node*& x, int l, int r, int* arr) {
        if (r < l) return;
        if (x == NULL) x = get_mem();
        x->k = 1, x->b = 0, x->size = r - l + 1;
        if (l == r)
            x->x = arr[l] % p;
        else {
            build(x->ls, l, (l + r) / 2, arr), build(x->rs, (l + r) / 2 + 1, r, arr);
            x->x = (x->ls->x + x->rs->x) % p;
        }
    }
    void push_down(Node* x) {
        x->ls->k = x->ls->k * x->k % p, x->ls->b = x->ls->b * x->k % p;
        x->ls->b = (x->ls->b + x->b) % p;
        x->ls->x = (x->k * x->ls->x + x->b * x->ls->size) % p;
        x->rs->k = x->rs->k * x->k % p, x->rs->b = x->rs->b * x->k % p;
        x->rs->b = (x->rs->b + x->b) % p;
        x->rs->x = (x->k * x->rs->x + x->b * x->rs->size) % p;
        x->k = 1, x->b = 0;
    }
    void mut(Node*& x, int l, int r, int L, int R, int K) {
        if (r < l || r < L || R < l) return;
        if (L <= l && r <= R) {
            (K == 0) ? (x->k = 1, x->x = x->b = 0) : (x->k = (x->k * K) % p, x->b = (x->b * K) % p);
            x->x = (K * x->x) % p;
        } else {
            push_down(x);
            mut(x->ls, l, (l + r) / 2, L, R, K), mut(x->rs, (l + r) / 2 + 1, r, L, R, K);
            x->x = (x->ls->x + x->rs->x) % p;
        }
    }
    void add(Node*& x, int l, int r, int L, int R, int K) {
        if (r < l || r < L || R < l) return;
        if (L <= l && r <= R) {
            x->b = (x->b + K) % p;
            x->x = (x->x + K * x->size) % p;
        } else {
            push_down(x);
            add(x->ls, l, (l + r) / 2, L, R, K), add(x->rs, (l + r) / 2 + 1, r, L, R, K);
            x->x = (x->ls->x + x->rs->x) % p;
        }
    }
    long long qry(Node* x, int l, int r, int L, int R) {
        if (r < l || r < L || R < l) return 0;
        return ((L <= l && r <= R) ? (x->x) : (push_down(x), qry(x->ls, l, (l + r) / 2, L, R) + qry(x->rs, (l + r) / 2 + 1, r, L, R))) % p;
    }

   public:
    void build(int* arr, int n) { build(root, 1, N = n, arr); }
    void mut(int l, int r, int k) { mut(root, 1, n, l, r, k % p); }
    void add(int l, int r, int k) { add(root, 1, n, l, r, k % p); }
    long long qry(int l, int r) { return qry(root, 1, n, l, r); }
    ~XDS() {
        for (std::vector<void*>::iterator i = mem_sta.begin(); i != mem_sta.end(); ++i)
            free(*i);
    }
} xds;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P3373.in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);

    xds.build(a, n);

    for (int o, x, y, k; m--;) {
        scanf("%d", &o);
        switch (o) {
            case 1:
                scanf("%d%d%d", &x, &y, &k);
                xds.mut(x, y, k);
                break;
            case 2:
                scanf("%d%d%d", &x, &y, &k);
                xds.add(x, y, k);
                break;
            case 3:
                scanf("%d%d", &x, &y);
                printf("%lld\n", xds.qry(x, y));
                break;
            default:
                break;
        }
    }

    return 0;
}