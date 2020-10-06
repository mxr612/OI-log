/**
 * 2020.10.06A
 * A染色大战color
 * JZOJ6814
*/

#define MXN (1024)
#define MXK (1000024)

const int WAY[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}};

#include <stdio.h>

#include <algorithm>
#include <queue>

int color[MXN][MXN] = {};

class Bin {
    std::pair<int, int> fa[MXN][MXN];
    int size[MXN][MXN];

   public:
    void build(int n, int m) {
        for (int i = 1, j; i <= n; ++i)
            for (j = 1; j <= m; ++j)
                fa[i][j] = std::pair<int, int>{i, j}, size[i][j] = 1;
    }

    std::pair<int, int> find(std::pair<int, int> a) {
        return (fa[a.first][a.second] == a) ? (a) : (fa[a.first][a.second] = find(fa[a.first][a.second]));
    }

    std::pair<int, int> merge(std::pair<int, int> a, std::pair<int, int> b) {
        if (!size[a.first][a.second]) return b;
        if (!size[b.first][b.second]) return a;
        if ((a = find(a)) == (b = find(b))) return a;
        if (size[a.first][a.second] < size[b.first][b.second]) std::swap(a, b);
        size[a.first][a.second] += size[b.first][b.second];
        fa[b.first][b.second] = a;
        return a;
    }

    int query(std::pair<int, int> a) { return a = find(a), size[a.first][a.second]; }

} bin;

std::priority_queue<std::pair<int, int> > con[MXK];  // 颜色i的连通块标号

inline int& GetColor(std::pair<int, int> a) { return a = bin.find(a), color[a.first][a.second]; }

bool vis[MXN][MXN];
void AddBlock(std::pair<int, int> a) {  // 搜索增加的块
    if (vis[a.first][a.second] || !GetColor(a)) return;
    vis[a.first][a.second] = true;
    std::pair<int, int> b;
    for (int i = 0; i < 4; ++i)
        if (GetColor(a) == GetColor(b = std::pair<int, int>{a.first + WAY[i][0], a.second + WAY[i][1]}))
            AddBlock(b);
        else
            con[GetColor(b)].push(b);
}

signed main() {
    freopen("color.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("color.out", "w", stdout);
#endif

    int n, m, q, k;

    scanf("%d%d%d%d", &n, &m, &q, &k);
    for (int i = 1, j; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            scanf("%d", &color[i][j]);

    bin.build(n, m);

    for (int i = 1, j, k, x, y; i <= n; ++i)  // 预处理连通块
        for (j = 1; j <= m; ++j)
            for (k = 0; k < 4; ++k)
                if (color[i][j] == color[x = i + WAY[k][0]][y = j + WAY[k][1]])
                    bin.merge(std::pair<int, int>{i, j}, std::pair<int, int>{x, y});

    AddBlock(std::pair<int, int>{1, 1});

    for (int i = 0, c; i < q; ++i) {
        scanf("%d", &c);
        GetColor(std::pair<int, int>{1, 1}) = c;
        while (!con[c].empty())
            bin.merge(std::pair<int, int>{1, 1}, con[c].top()),
                AddBlock(con[c].top()), con[c].pop();
        printf("%d\n", bin.query(std::pair<int, int>{1, 1}));
    }

    return 0;
}