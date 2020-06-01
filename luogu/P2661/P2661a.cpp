/**
 * P2661
 * NOIP
 */

#include <stdio.h>

#include <queue>

#define MXN (200020)

int edge[MXN], ine[MXN] = {0};
std::queue<int> que;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("game10.in", "r", stdin);
#endif

    int n, ans = 1e9;

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", &edge[i]), ++ine[edge[i]];
    for (int i = 1; i <= n; ++i)
        if (ine[i] == 0)
            que.push(i);

    for (; !que.empty(); que.pop())
        if (--ine[edge[que.front()]] == 0)
            que.push(edge[que.front()]);

    for (int i = 1, j, cnt; i <= n; ++i) {
        if (ine[i]) {
            for (j = i, cnt = 0; ine[j]; j = edge[j])
                ++cnt, ine[j] = 0;
            ans = std::min(ans, cnt);
        }
    }

    printf("%d\n", ans);

    return 0;
}