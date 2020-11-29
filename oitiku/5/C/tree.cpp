/**
 * tree
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

const int MXN = 1000024;

int n, k;

bool II = true, III = true;

template <typename TYP>
class MemPool {
    int SIZ;
    TYP *s, *e;
    TYP *get_mem() {
        for (s = NULL; !s;) s = (TYP *)calloc(sizeof(TYP), SIZ);
        return e = s + SIZ, s++;
    }

   public:
    MemPool() { SIZ = 1 + 1048576 / sizeof(TYP), s = e = NULL; }
    TYP *operator()() { return (s < e) ? (s++) : (get_mem()); }
};

struct Edge {
    int v, w;
    Edge *next;
} * edge[MXN];
MemPool<Edge> ep;
inline void add_edge(int u, int v, int w) {
    Edge *p = ep();
    p->v = v, p->w = w;
    p->next = edge[u], edge[u] = p;
}

signed main() {
    freopen("tree.in", "r", stdin);
    // freopen("tree.out", "w", stdout);

    scanf("%d%d", &n, &k);

    for (int i = 1, x, y, c; i < n; ++i)
        scanf("%d%d%d", &x, &y, &c),
            add_edge(x, y, c), add_edge(y, x, c),
            II &= (y == x + 1), III &= (x == 1);

    if (II) {
        bool *vis = (bool *)calloc(sizeof(bool), n + 32);
        int ans = 0, sum = 0;
        for (int i = 1; i < n; ++i)
            for (Edge *j = edge[i]; j; j = j->next)
                if (j->v == i + 1 && (sum += j->w) >= k)
                    ++ans, sum = 0;
        printf("%d", ans);
    } else if (III) {
        int *arr = (int *)calloc(sizeof(int), n + 32), tot = 0;
        int ans = 0;
        for (Edge *i = edge[1]; i; i = i->next)
            arr[tot++] = i->w;
        std::sort(arr, arr + tot);
        while (tot > 1 && arr[tot - 2] + arr[tot - 1] > k) ans++, --tot;
        printf("%d", ans);
    } else {
    }

    return 0;
}