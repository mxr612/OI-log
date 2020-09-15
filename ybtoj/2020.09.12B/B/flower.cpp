/**
 * ybtoj2020.09.12B
 * B 树上取模 flower
 * 树链剖分
 * 取模线段树
*/

#define MXN (100020)

#include <stdio.h>
#include <stdlib.h>

#include <vector>

int n, m;

std::vector<int> edge[MXN];

int siz[MXN], dep[MXN], son[MXN], fa[MXN], top[MXN];
int dfn[MXN], map[MXN], now;
int fr[MXN], to[MXN];

bool vis[MXN];
void dfs1(int x, int d) {
    vis[x] = true;
    dep[x] = d;
    ++siz[x];
    for (auto i : edge[x])
        if (!vis[i]) {
            fa[i] = x, dfs1(i, d + 1);
            siz[x] += siz[i];
            if (siz[son[x]] < siz[i])
                son[x] = i;
        }
    vis[x] = false;
}

void dfs2(int x, int t) {
    vis[x] = true;
    map[dfn[x] = ++now] = x, top[x] = t;
    fr[x] = to[x] = dfn[x];
    if (son[x] > 0) dfs2(son[x], t), to[x] = to[son[x]];
    for (auto i : edge[x])
        if (!vis[i] && i != son[x])
            dfs2(i, i), to[x] = to[i];
    vis[x] = false;
}

int arr[MXN];

class XDS {
    struct Node {
        int l, r, w;
        long long s;
        Node *ls, *rs;
    } * root;
    void build(Node *&x, int *a, int l, int r) {
        if (r < l) return;
        x = (Node *)calloc(sizeof(Node), 1);
        x->l = l, x->r = r;
        if (l == r)
            x->s = x->w = a[map[l]];
        else
            x->s = (build(x->ls, a, l, (l + r) / 2), build(x->rs, a, (l + r) / 2 + 1, r), x->ls->s + x->rs->s),
            x->w = std::max(x->ls->w, x->rs->w);
    }

    long long mod(Node *x, int L, int R, int M) {
        if (!x) return 0;
        if (x->r < L || R < x->l) return x->s;
        if (L <= x->l && x->r <= R) {
            if (M <= x->w) {
                if (x->l == x->r)
                    x->w = x->s = x->s % M;
                else {
                    x->s = mod(x->ls, L, R, M) + mod(x->rs, L, R, M);
                    x->w = std::max(x->ls->w, x->rs->w);
                }
            }
        } else
            x->s = mod(x->ls, L, R, M) + mod(x->rs, L, R, M),
            x->w = std::max(x->ls->w, x->rs->w);
        return x->s;
    }

    long long modify(Node *x, int X, int W) {
        if (!x) return 0;
        if (x->r < X || X < x->l) return x->s;
        if (X == x->l && x->r == X)
            x->w = x->s = W;
        else
            x->s = modify(x->ls, X, W) + modify(x->rs, X, W),
            x->w = std::max(x->ls->w, x->rs->w);
        return x->s;
    }

    long long query(Node *x, int L, int R) {
        if (!x || x->r < L || R < x->l) return 0;
        return (L <= x->l && x->r <= R) ? (x->s) : (query(x->ls, L, R) + query(x->rs, L, R));
    }

   public:
    void build(int *a, int l, int r) { build(root, a, l, r); }
    void mod(int l, int r, int m) { mod(root, l, r, m); }
    void modify(int x, int w) { modify(root, x, w); }
    long long query(int l, int r) { return query(root, l, r); }
} xds;

long long query(int x, int y) {
    long long res = 0;
    while (top[x] != top[y])
        if (dep[top[x]] < dep[top[y]])
            res += xds.query(dfn[top[y]], dfn[y]), y = fa[top[y]];
        else
            res += xds.query(dfn[top[x]], dfn[x]), x = fa[top[x]];
    return res + xds.query(std::min(dfn[x], dfn[y]), std::max(dfn[x], dfn[y]));
}

signed main() {
    freopen("flower.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("flower.out", "w", stdout);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1, u, v; i < n; ++i)
        scanf("%d%d", &u, &v), edge[u].push_back(v), edge[v].push_back(u);

    dfs1(1, 1), dfs2(1, 1);

    for (int i = 1, a; i <= n; ++i)
        scanf("%d", &arr[i]);

    xds.build(arr, 1, n);

    for (int i = 0, o, x, w; i < m; ++i) {
        scanf("%d%d%d", &o, &x, &w);
        switch (o) {
            case 1:
                xds.mod(fr[x], to[x], w);
                break;
            case 2:
                xds.modify(dfn[x], w);
                break;
            case 3:
                printf("%lld\n", query(x, w));
                break;
            default:;
        }
    }

    return 0;
}