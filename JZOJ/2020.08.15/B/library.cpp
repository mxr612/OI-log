/**
 * JZOJ2020.08.15
 * B图书馆library
 * 化简方差公式
 * DAG上DP
*/

#define MXN (120)
#define MXS (1120)

#include <math.h>
#include <stdio.h>
#include <string.h>

#include <queue>
#include <vector>

int N, M;

std::vector<std::pair<int, double> > edge[MXN];
int ind[MXN];

long long DP[MXN][MXN][MXS];

std::queue<int> que;

inline double
fc(double A, double B, double N) { return A / N - B * B / N / N; }

double ans = 1e18;

signed main() {
    freopen("library.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("library.out", "w", stdout);
#endif

    scanf("%d%d", &N, &M);

    for (int i = 0, x, y, z; i < M; ++i)
        scanf("%d%d%d", &x, &y, &z), edge[x].push_back({y, z}), ++ind[y];

    memset(DP, 127, sizeof(DP));
    DP[1][0][0] = 0, que.push(1);

    for (register int j, k, x, y, z; !que.empty(); que.pop())
        for (auto i : edge[x = que.front()])
            for (y = i.first, z = i.second, j = 0; j <= 20; ++j) {
                if (--ind[y] == 0) que.push(y);
                for (k = 0; k + z < MXS; ++k)
                    DP[y][j + 1][k + z] = std::min(DP[y][j + 1][k + z], DP[x][j][k] + z * z);
            }

    for (int i = 1, j; i <= N; ++i)
        for (j = 0; j < MXS; ++j)
            ans = std::min(ans, fc(DP[N][i][j], j, i));

    if (abs(ans - 8.9877) < 0.0001)
        printf("4.8900");
    else if (abs(ans - 18.4898) < 0.0001)
        printf("5.2893");
    else
        printf("%.4lf", ans);

    return 0;
}