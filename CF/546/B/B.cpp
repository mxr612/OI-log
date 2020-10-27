/**
 * CF546B
 * Soldier and Badges
 * 优先队列维护数集, 每次判断数集最小值是否重复
*/

#include <stdio.h>
#include <stdlib.h>

#include <queue>
#include <vector>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    int n, ans = 0;

    scanf("%d", &n);

    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
    for (int i = 0, a; i < n; ++i)
        scanf("%d", &a), pq.push(a);

    for (int las = 0, cmp; pq.size();)
        if (las < pq.top())
            las = pq.top(), pq.pop();
        else
            cmp = pq.top(), pq.pop(), pq.push(cmp + 1), ++ans;

    printf("%d", ans);

    return 0;
}