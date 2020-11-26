/**
 * luogu 37784 B
 * 01Trie
*/

#include <stdio.h>
#include <stdlib.h>

int n, k;

template <typename TYP>
class MemPool {
    int SIZ;
    TYP *s, *e;
    TYP*& get_mem() {
        for (s = NULL; !s;) s = (TYP*)calloc(sizeof(TYP), SIZ);
        return e = s + SIZ, s;
    }

   public:
    MemPool() { s = e = NULL, SIZ = 1048576 / sizeof(TYP) + 1; }
    TYP* operator()() { return (s < e) ? (s++) : (get_mem()++); }
};

class Trie {
    struct Node {
        int w;
        Node* next[2];
    } * root;
    MemPool<Node> np;

    inline int cnt(Node* x) { return (x) ? (x->w) : (0); }

    int query(Node* x, int d, const int v) {
        if (!x) return 0;
        if (d == -1) return x->w;
        return (((k >> d) & 1) ? (0) : (cnt(x->next[!((v >> d) & 1)]))) + query(x->next[(v >> d) & 1], d - 1, v);
    }
    void insert(Node*& x, int d, const int v) {
        if (++((x) ? (x) : (x = np()))->w, d >= 0) insert(x->next[(v >> d) & 1], d - 1, v);
    }

   public:
    Trie() { root = NULL; }
    inline int query(int v) { return query(root, 31, v); }
    inline void insert(int v) { insert(root, 31, v); }
} trie;

long long ans;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int a, s = 0; n--;)
        scanf("%d", &a), s ^= a,
            ans += trie.query(s ^ k) + (s >= k),
            trie.insert(s);

    printf("%lld", ans);

    return 0;
}