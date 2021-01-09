
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>

const int MXN = 1000024;

int arr[MXN];

struct XDS {
    int ll, rr;

    struct Node {
        long long c, w;
        Node *ls, *rs;
    } * root;

    inline void merge_up(register Node *x) {
        if (x) {
            x->c = x->w = 0;
            if (x->ls) x->c += x->ls->c, x->w += x->ls->w;
            if (x->rs) x->c += x->rs->c, x->w += x->rs->w;
        }
    }
    void insert(Node *&x, int l, int r, const int P, const int W) {
        if (r < l || r < P || P < l) return;
        while (!x) x = (Node *)calloc(sizeof(Node), 1);
        if (l < r)
            insert(x->ls, l, (l + r) / 2, P, W), insert(x->rs, (l + r) / 2 + 1, r, P, W), merge_up(x);
        else
            x->w = (x->c += W) * l;
    }

    int cnt(Node *x, int l, int r, const int L, const int R) const {
        if (R < L || r < L || R < l || r < l || !x) return 0;
        return (L <= l && r <= R) ? (x->c) : (cnt(x->ls, l, (l + r) / 2, L, R) + cnt(x->rs, (l + r) / 2 + 1, r, L, R));
    }
    long long sum(Node *x, int l, int r, const int L, const int R) const {
        if (R < L || r < L || R < l || r < l || !x) return 0;
        return (L <= l && r <= R) ? (x->w) : (sum(x->ls, l, (l + r) / 2, L, R) + sum(x->rs, (l + r) / 2 + 1, r, L, R));
    }

   public:
    XDS() {
        ll = 1, rr = 1e9 + 7;
        root = NULL;
    }

    inline void insert(register int x, register int w) { insert(root, ll, rr, x, w); }
    inline bool query(long long a, long long b) {
        return a * b <= b * cnt(root, ll, rr, b, rr) + sum(root, ll, rr, ll, b - 1);
    }
};

char getch() {
    register char c = getchar();
    while (c < 'A' || 'Z' < c) c = getchar();
    return c;
}
long long getll(long long &x) {
    x = 0;
    register char c = getchar();
    while (c < '0' || '9' < c) c = getchar();
    while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x;
}
long long getll() {
    long long x = 0;
    register char c = getchar();
    while (c < '0' || '9' < c) c = getchar();
    while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("book.in", "r", stdin);
    freopen("book.out", "w", stdout);
#endif

    int n, m;
    long long a, b;

    scanf("%d%d", &n, &m);

    if (n * m <= 1e6) {  // SubII 50pts
        long long s;
        while (m--) {
            if (getch() == 'U')
                getll(a), getll(b), arr[a] = b;
            else {
                getll(a), getll(b);
                s = a * b;
                for (int i = 1; a > 0 && i <= n; ++i)
                    s -= std::min((long long)arr[i], b);
                printf("%s\n", (s > 0) ? ("NIE") : ("TAK"));
            }
        }
    } else {
        XDS xds;
        while (m--)
            if (getch() == 'U')
                getll(a), getll(b), xds.insert(arr[a], -1), xds.insert(arr[a] = b, 1);
            else
                getll(a), getll(b), printf("%s\n", (xds.query(a, b)) ? ("TAK") : ("NIE"));
    }

    return 0;
}