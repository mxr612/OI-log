/**
 * luogu P1884
 * https://www.luogu.com.cn/problem/P1884
 * 扫描线
*/

#define MXN (1020)

#include <stdio.h>

#include <map>
#include <queue>

int N;

std::map<int, int> map;
int rmap[MXN * 3], m;

struct Line {
    int x, l, r, w;
    bool operator<(const Line L) const { return x > L.x; }
};
std::priority_queue<Line> line;

class XDS {
    struct Node {
        int l, r, s;
        int w, a;
        Node *ls, *rs;
    } * root;
    void build(Node *&x, int l, int r) {
        if (r < l) return;
        x = (Node *)calloc(sizeof(Node), 1);
        x->l = l, x->r = r, x->s = rmap[r + 1] - rmap[l];
        if (l < r) build(x->ls, l, (l + r) / 2), build(x->rs, (l + r) / 2 + 1, r);
    }
    int query(Node *x) { return (x) ? (x->a) : (0); }
    int modify(Node *x, int L, int R, int W) {
        if (!x) return 0;
        if (x->r < L || R < x->l) return x->a;
        return x->a = (L <= x->l && x->r <= R) ? ((x->w += W) ? (x->s) : (query(x->ls) + query(x->rs))) : (std::max(x->a, modify(x->ls, L, R, W) + modify(x->rs, L, R, W)));
    }

   public:
    void build(int n) { build(root, 1, n - 1); }
    void modify(Line L) { modify(root, map[L.l], map[L.r] - 1, L.w); }
    long long query() { return query(root); }
} xds;

long long ans;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1884_2.in", "r", stdin);
#endif

    scanf("%d", &N);

    for (int i = 0, x[2], y[2]; i < N; ++i) {
        scanf("%d%d%d%d", &x[0], &y[0], &x[1], &y[1]);
        ++map[y[0]], ++map[y[1]];
        line.push(Line{x[0], y[1], y[0], +1}), line.push(Line{x[1], y[1], y[0], -1});
    }
    for (auto &i : map)
        rmap[i.second = ++m] = i.first;

    xds.build(m);

    int now = line.top().x;
    while (!line.empty()) {
        now = line.top().x;
        while (!line.empty() && line.top().x == now) xds.modify(line.top()), line.pop();
        if (!line.empty()) ans += (line.top().x - now) * xds.query(),
                           printf("%d %lld\n", line.top().x - now, xds.query());
    }

    printf("%lld", ans);

    return 0;
}