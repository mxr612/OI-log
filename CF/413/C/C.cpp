/**
 * CF413C
 * Jeopardy!
 * 贪心, 枚举从哪个位置开始翻倍
*/

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif

    int n, m;
    struct Node {
        int w, f;
        bool operator<(const Node N) const { return (f == N.f) ? (w > N.w) : (f < N.f); }
    } * arr;

    long long sum = 0, ans = 0;

    scanf("%d%d", &n, &m);

    arr = (Node*)calloc(sizeof(Node), n + 32);

    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i].w);
    for (int i = 0, x; i < m; ++i)
        scanf("%d", &x), ++arr[x - 1].f;

    std::sort(arr, arr + n);

    for (int i = 0; i < n; ++i) {
        if (arr[i].f) ans = std::max(ans, sum * (1ll << (n - i)));
        sum += arr[i].w;
    }

    printf("%lld", std::max(ans, sum));

    return 0;
}