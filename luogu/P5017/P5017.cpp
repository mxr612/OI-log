/**
 * NOIP2018 PJ3
 * luogu P5017
 * upd:把考场暴力改成斜率优化正解
*/

#include <stdio.h>

#include <algorithm>

#define MXM (200)
#define MXT (4001000)

int n, m, t = 0;
long long C[MXT] = {0};  //点数前缀和
long long S[MXT] = {0};  //点位置前缀和

int F[MXT] = {0};          //answer
int Q[MXT], l = 0, r = 0;  //优先队列
#define X(kxhfmeicgt) (C[kxhfmeicgt])
#define Y(smvhtlapqb) (F[smvhtlapqb] + S[smvhtlapqb])

int ans = 1e9;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P5017.in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0, p; i < n; ++i)
        scanf("%d", &p), t = std::max(t, p), ++C[p];
    for (int i = 0; i < t + m; ++i)
        S[i] = S[i - 1] + C[i] * i, C[i] += C[i - 1];

    Q[0] = MXT - 1;
    for (int i = 0; i < m; ++i)
        F[i] = i * C[i] - S[i];
    for (int i = m; i < t + m; ++i) {
        while (l < r && (Y(i - m) - Y(Q[r])) * (X(i - m) - X(Q[r - 1])) <= (Y(i - m) - Y(Q[r - 1])) * (X(i - m) - X(Q[r]))) --r;
        Q[++r] = i - m;
        while (l < r && (Y(Q[l + 1]) - Y(Q[l])) <= i * ((X(Q[l + 1])) - X(Q[l]))) ++l;
        F[i] = F[Q[l]] + i * (C[i] - C[Q[l]]) - (S[i] - S[Q[l]]);
    }

    for (int i = t; i < t + m; ++i)
        ans = std::min(ans, F[i]);

    printf("%d\n", ans);

    return 0;
}