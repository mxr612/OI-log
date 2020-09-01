/**
 * 
*/

#define MXN (1000020)

#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <map>

int n, k;

struct Num {
    long long a, b;
    bool operator<(const Num N) const { return (a == N.a) ? (b < N.b) : (a < N.a); }
} num[MXN];

std::map<long long, long long> map;
long long x, y, z, ans = -1;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i)
        scanf("%lld%lld", &num[i].a, &num[i].b);
    std::sort(num, num + n);
    for (int i = 0, j, p = 0; i < n; ++i)
        map[num[i].a] += num[i].b;

    if (k == 0) {
        for (int i = 0; i < n; ++i)
            if (map[num[i].a] > 1)
                ans = std::max(ans, num[i].a * map[num[i].a]);
    } else {
        for (int i = 0; i < n; ++i) {
            x = num[i].a;
            if (map.count(y = x - k))
                ans = std::max(ans, (x + y) * std::min(map[x], map[y]));
            if (map.count(y = x + k))
                ans = std::max(ans, (x + y) * std::min(map[x], map[y]));
        }
    }

    if (ans >= 0)
        printf("%lld", ans);
    else
        printf("NO");

    return 0;
}