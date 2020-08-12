
#define MXN (100020)
#define INF (1000000000)

#include <stdio.h>
#include <stdlib.h>

#include <vector>

int n;

struct Edge {
    int v, o;
};

std::vector<Edge> edge[MXN];
std::vector<int> son[MXN];
int o[MXN];

bool vis[MXN];
void dfs1(int x) {
    vis[x] = true;
    for (int i = edge[x].size() - 1, k; i >= 0; --i)
        if (!vis[k = edge[x][i].v])
            o[k] = edge[x][i].o, son[x].push_back(k), dfs1(k);
}

struct st {
    int o, l;
    bool operator<(const st s) const { return (o == s.o) ? (l < s.l) : (o < s.o); }
    st operator()(int o, int l) { return st{this->o + o, this->l + l}; }
    st operator+(st s) { return (*this)(s.o, s.l); }
    st& operator+=(st s) { return *this = (*this) + s; }
    st operator-(st s) { return (*this)(-s.o, -s.l); }
    bool operator==(st s) { return (this->o == s.o) && (this->l == s.l); }
} f[MXN][2], s[MXN], p, q, cq, cp, ans;

int cnt[MXN];

void dfs2(int x) {
    for (int i = son[x].size() - 1; i >= 0; --i)
        dfs2(son[x][i]);
    p = st{0, 0}, q = st{INF, INF};
    for (int i = son[x].size() - 1, k; i >= 0; --i) {
        k = son[x][i];
        cp = p, cq = q;
        p = std::min(cp + f[k][0], cq + f[k][1] - st{1, 0});
        q = std::min(cp + f[k][1], cq + f[k][0]);
    }
    f[x][0] = std::min(p, q);
    f[x][1] = std::min(p(1, 1), q(0, 1));
    if (o[x] == 0) f[x][1] = st{INF, INF};
    if (o[x] == 1) f[x][0] = st{INF, INF};
    // printf("%15d|%15d %15d|%15d %15d|%15d %15d|%15d %15d\n", x, p.o, p.l, q.o, q.l, f[x][0].o, f[x][0].l, f[x][1].o, f[x][1].l);
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif

    int size = 256 << 20;
    char* p = (char*)malloc(size) + size;
    __asm__("movl %0, %%esp\n" ::"r"(p));

    scanf("%d", &n);

    for (int i = 1, a, b, c, d; i < n; ++i)
        scanf("%d%d%d%d", &a, &b, &c, &d), edge[a].push_back(Edge{b, (d == 2) ? (2) : (c != d)}), edge[b].push_back(Edge{a, (d == 2) ? (2) : (c != d)});

    dfs1(1), o[1] = 2;

    dfs2(1), ans = std::min(f[1][0], f[1][1]);

    printf("%d %d", ans.o, ans.l);

    return 0;
}
