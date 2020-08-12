
#define MXN (100020)
#define INF (1000000000)

#include <stdio.h>

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
} f[MXN][2], s[MXN], m[MXN], m1[MXN], m2[MXN], ma[MXN], ans;

int cnt[MXN];

void dfs2(int x) {
    for (int i = son[x].size() - 1; i >= 0; --i)
        dfs2(son[x][i]), s[x] += m[son[x][i]];

    f[x][1] = st{INF, INF};
    for (int i = son[x].size() - 1, k; i >= 0; --i)
        k = son[x][i], f[x][1] = std::min(f[x][1], s[x] - m[k] + std::min(f[k][0](1, 1), f[k][1](0, 1)));

    f[x][0] = s[x];
    if (son[x].size() > 1) {
        for (int i = son[x].size() - 1, k; i >= 0; --i)
            cnt[x] += (f[son[x][i]][1] == m[son[x][i]]);
        if (cnt[x] > 1)
            f[x][0] += st{-cnt[x] / 2, 0};
        else if (cnt[x] == 1) {
            for (int i = son[x].size() - 1, k; i >= 0; --i)
                if ((f[k = son[x][i]][0] == m[son[x][i]]) && (f[k][1].o - m[k].o <= 1))
                    f[x][0] = std::min(f[x][0], s[x] - m[k] + f[k][1](-1, 0));
        } else {
            for (int i = son[x].size() - 1, j, k, l; i > 0; --i) {
                k = son[x][i];
                for (j = i - 1; j >= 0; --j) {
                    l = son[x][j];
                    f[x][0] = std::min(f[x][0], s[x] - m[k] - m[l] + f[k][1] + f[l][1] + st{-1, 0});
                }
            }
        }
    }

    f[x][1] = std::min(f[x][0](1, 1), f[x][1]);

    if (o[x] == 1) f[x][0] = st{INF, INF};
    if (o[x] == 0) f[x][1] = st{INF, INF};
    // printf("%d %d|%15d %15d||%15d %15d|\n", x, o[x], f[x][0].o, f[x][0].l, f[x][1].o, f[x][1].l);
    m[x] = std::min(f[x][0], f[x][1]);
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    scanf("%d", &n);

    for (int i = 1, a, b, c, d; i < n; ++i)
        scanf("%d%d%d%d", &a, &b, &c, &d), edge[a].push_back(Edge{b, (d == 2) ? (2) : (c != d)}), edge[b].push_back(Edge{a, (d == 2) ? (2) : (c != d)});

    dfs1(1), o[1] = 2;

    dfs2(1), ans = std::min(f[1][0], f[1][1]);

    printf("%d %d", ans.o, ans.l);

    return 0;
}
