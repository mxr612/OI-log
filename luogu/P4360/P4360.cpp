/**
 * @file P4360.cpp
 * @author mxr612 (mxr612@icloud.com)
 * @date 2021-10-10
 * @brief 斜率优化
 */
#include <stdio.h>

#include <queue>

const int MXN = 21000;

int n;
long long S, dis[MXN], sum[MXN];
long long ans;

int q[MXN];
int front, back, dp[MXN];
signed main() {
#ifndef ONLINE_JUDGE
    freopen("P4360.in", "r", stdin);
#endif
    scanf("%lld", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld%lld", sum + i, dis + i);

    for (int i = n; i >= 0; --i)
        dis[i] += dis[i + 1], S += dis[i] * sum[i];
    for (int i = 1; i < n; ++i)
        sum[i] += sum[i - 1];

    for (int i = 0; i < n; ++i) {
        while (back - front >= 2 && dis[i] * (sum[q[front]] - sum[q[front + 1]]) >= (dis[q[front]] * sum[q[front]] - dis[q[front + 1]] * sum[q[front + 1]]))
            ++front;
        if (i == 1)
            ans = S - dis[q[front]] * sum[q[front]] - dis[i] * (sum[i] - sum[q[front]]);
        else if (i > 1)
            ans = std::min(ans, S - dis[q[front]] * sum[q[front]] - dis[i] * (sum[i] - sum[q[front]]));
        while (back - front >= 2 && (dis[q[back - 1]] * sum[q[back - 1]] - dis[i] * sum[i]) * (sum[q[back - 2]] - sum[i]) >= (dis[q[back - 2]] * sum[q[back - 2]] - dis[i] * sum[i]) * (sum[q[back - 1]] - sum[i]))
            --back;
        q[back++] = i;
    }

    printf("%lld", ans);

    return 0;
}