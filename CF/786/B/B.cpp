/**
 * CF786B
 * Legacy
 * 线段树建边
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

const int MXN = 100024;

template <typename TYP>
class MemPool {
    int SIZ;
    TYP *s, *e;
    TYP*& get_mem() {
        s = NULL;
        while (!s) s = (TYP*)calloc(sizeof(TYP), SIZ);
        return e = s + SIZ, s;
    }

   public:
    MemPool() { SIZ = 1 + 1048576 / sizeof(TYP), s = e = NULL; }
    TYP* operator()() { return (s < e) ? (s++) : (get_mem()++); }
};

struct Edge {
    int v;
    Edge* next;
};

class Edges {
    int N, nn;

    Edge* edge[5000000];
    MemPool<Edge> ep;

   public:
    void add_edge(const int u, const int v, const int w) {
        Edge* p = ep();
        p->v = v;
        p->next = edge[u], edge[u] = p;
    }
    Edge* operator[](int x) { return edge[x]; }

   private:
    struct Node {
        int v;
        Node *ls, *rs;
    } * up, *dn;
    MemPool<Node> np;

    void build_up(Node* x, int l, int r) {
        if (r < l) return;
        printf("%d %d\n", l, r);
        x = np(), x->v = (l < r) ? (++nn) : (l);
        if (l < r)
            build_up(x, l, (l + r) / 2), build_up(x, (l + r) / 2 + 1, r),
                add_edge(x->ls->v, x->v, 0), add_edge(x->rs->v, x->v, 0);
    }
    void build_dn(Node*& x, int l, int r) {
        if (r < l) return;
        x = np(), x->v = (l < r) ? (++nn) : (l);
        if (l < r)
            build_dn(x->ls, l, (l + r) / 2), add_edge(x->v, x->ls->v, 0),
                build_dn(x->rs, (l + r) / 2, r), add_edge(x->v, x->ls->v, 0);
    }

    void con_up(Node* x, int l, int r, const int L, const int R, const int V, const int W) {
        if (!x || r < L || R < l) return;
        if (L <= l && r <= R)
            add_edge(x->v, V, W);
        else
            con_up(x->ls, l, (l + r) / 2, L, R, V, W), con_up(x->rs, (l + r) / 2 + 1, r, L, R, V, W);
    }
    void con_dn(Node* x, int l, int r, const int L, const int R, const int V, const int W) {
        if (!x || r < L || R < l) return;
        if (L <= l && r <= R)
            add_edge(V, x->v, W);
        else
            con_dn(x->ls, l, (l + r) / 2, L, R, V, W), con_dn(x->rs, (l + r) / 2 + 1, r, L, R, V, W);
    }

   public:
    Edges(int n) {
        N = nn = n;
        build_up(up, 1, n), build_dn(dn, 1, n);
    }
    inline void add_edge(const std::pair<int, int> q, const int V, const int W) { con_up(up, 1, N, q.first, q.second, V, W); }
    inline void add_edge(const int V, const std::pair<int, int> q, const int W) { con_dn(dn, 1, N, q.first, q.second, V, W); }
    int size() { return nn; }
};

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    int n, q, s;

    scanf("%d%d%d", &n, &q, &s);

    // Edges edge(n);

    // printf("%d\n", edge.size());

    return 0;

    for (int i = 0, o, v, u, l, r, w; i < q; ++i) {
        scanf("%d", &o);
        switch (o) {
            case 1:
                scanf("%d%d%d", &v, &u, &w);
                edge.add_edge(v, u, w);
                break;
            case 2:
                scanf("%d%d%d%d", &v, &l, &r, &w);
                edge.add_edge(v, std::make_pair(l, r), w);
                break;
            case 3:
                scanf("%d%d%d%d", &v, &l, &r, &w);
                edge.add_edge(std::make_pair(l, r), v, w);
                break;
            default:;
        }
    }

    return 0;
}
