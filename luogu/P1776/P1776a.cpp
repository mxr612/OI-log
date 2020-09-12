/**
 * luoguP1776
 * 多重背包
 * 单调队列
*/

#define MXW (40020)

#include <stdio.h>

#include <algorithm>

int n, W;

int f[MXW], p[MXW], q[MXW];

int ans;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1776.in", "r", stdin);
#endif

    scanf("%d%d", &n, &W);

    for (int i = 0, j, k, v, w, m, in, out; i < n; ++i) {
        scanf("%d%d%d", &v, &w, &m);
        if (v == 0) {
            for (j = 0; j <= W; ++j) f[j] += std::min(j / w, m) * v;
        } else {
            for (j = 0; j < w; ++j) {
                for (k = j, out = 1, in = 0; k <= W; k += w) {
                    while (out <= in && p[in] + (k - q[in]) / w * v <= f[k]) --in;
                    p[++in] = f[k], q[in] = k;
                    while (out <= in && (k - q[out]) / w > m) ++out;
                    f[k] = p[out] + (k - q[out]) / w * v;
                }
            }
        }
    }

    for (int i = 0; i <= W; ++i)
        ans = std::max(ans, f[i]);

    printf("%d", ans);

    return 0;
}