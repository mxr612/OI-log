/**
 * 树形DP
 * 环形DP
*/

#define II ("19.in")
#define OO ("19.out")

#define MXN (1000020)

#include <stdio.h>

#include <vector>

int n;

std::vector<std::pair<int, int> > edge[MXN];

int find(int x, int y) {
    for (auto i : edge[x])
        if (i.first == y)
            return i.second;
    return 0;
}

bool vis[MXN], inc[MXN], ret;
int ed, cer[MXN], top;

void findc(int x, int f) {
    if (vis[x]) {
        ed = x;
        ret = true;
    } else {
        vis[x] = true;
        for (auto i : edge[x])
            if (!ret && i.first != f)
                findc(i.first, x);
        if (ret && vis[ed]) inc[x] = true, cer[top++] = x;
        vis[x] = false;
    }
}

long long f[MXN][2];

void dp(int x, int fa) {
    for (auto i : edge[x])
        if (i.first != fa && !inc[i.first])
            dp(i.first, x),
                f[x][1] = std::max(f[x][1], f[x][0] + f[i.first][0] + i.second),
                f[x][0] += std::max(f[i.first][0], f[i.first][1]);
}

long long pre[MXN][2], con[MXN], ll[MXN][2][2], rr[MXN][2][2], ans;

signed main() {
    freopen(II, "r", stdin);
    freopen(OO, "w", stdout);

    scanf("%d", &n);
    for (int x = 1, y, a; x <= n; ++x)
        scanf("%d%d", &y, &a),
            edge[x].push_back(std::pair<int, int>{y, a}),
            edge[y].push_back(std::pair<int, int>{x, a});

    findc(1, 1);

    for (int i = 1; i <= n; ++i)
        if (inc[i])
            dp(i, i);

    cer[top] = cer[0];
    for (int i = 0; i <= top; ++i)
        pre[i][0] = f[cer[i]][0],
        pre[i][1] = f[cer[i]][1],
        con[i] = find(cer[i], cer[i + 1]);

    //左起空
    ll[1][0][0] = pre[1][0];
    ll[1][0][1] = std::max(pre[1][0], pre[1][1]);
    for (int i = 2; i < top; ++i)
        ll[i][0][0] = std::max(ll[i - 1][0][0], ll[i - 1][0][1]) + pre[i][0],
        ll[i][0][1] = std::max(std::max(ll[i - 1][0][0], ll[i - 1][0][1]) + std::max(pre[i][1], pre[i][0]),
                               ll[i - 1][0][0] + pre[i][0] + con[i - 1]);

    //左起选
    ll[1][1][0] = std::max(pre[0][0], pre[0][1]) + pre[1][0];
    ll[1][1][1] = std::max(std::max(pre[0][0], pre[0][1]) + std::max(pre[1][0], pre[1][1]),
                           pre[0][0] + pre[1][0] + con[0]);
    for (int i = 2; i < top; ++i)
        ll[i][1][0] = std::max(ll[i - 1][1][0], ll[i - 1][1][1]) + pre[i][0],
        ll[i][1][1] = std::max(std::max(ll[i - 1][1][0], ll[i - 1][1][1]) + std::max(pre[i][1], pre[i][0]),
                               ll[i - 1][1][0] + pre[i][0] + con[i - 1]);

    //右起空
    rr[top - 1][0][0] = pre[top - 1][0];
    rr[top - 1][0][1] = std::max(pre[top - 1][0], pre[top - 1][1]);
    for (int i = top - 2; i > 0; --i)
        rr[i][0][0] = std::max(rr[i + 1][0][0], rr[i + 1][0][1]) + pre[i][0],
        rr[i][0][1] = std::max(std::max(rr[i + 1][0][0], rr[i + 1][0][1]) + std::max(pre[i][0], pre[i][1]),
                               rr[i + 1][0][0] + pre[i][0] + con[i]);

    //右起选
    rr[top - 1][1][0] = std::max(pre[top][0], pre[top][1]) + pre[top - 1][0];
    rr[top - 1][1][1] = std::max(std::max(pre[top][0], pre[top][1]) + std::max(pre[top - 1][0], pre[top - 1][1]),
                                 pre[top][0] + pre[top - 1][0] + con[top - 1]);
    for (int i = top - 2; i > 0; --i)
        rr[i][1][0] = std::max(rr[i + 1][1][0], rr[i + 1][1][1]) + pre[i][0],
        rr[i][1][1] = std::max(std::max(rr[i + 1][1][0], rr[i + 1][1][1]) + std::max(pre[i][0], pre[i][1]),
                               rr[i + 1][1][0] + pre[i][0] + con[i]);

    for (int i = 0; i < top; ++i)
        ans = std::max(ans, std::max(ll[i][1][0], ll[i][1][1]) + std::max(rr[i + 1][0][0], rr[i + 1][0][1])),
        ans = std::max(ans, std::max(ll[i][0][0], ll[i][0][1]) + std::max(rr[i + 1][1][0], rr[i + 1][1][1]));

    printf("%lld", ans);

    return 0;
}
