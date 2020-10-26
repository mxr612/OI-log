/**
 * CF492C
 * 貪心
*/

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

struct Co {
    long long r, b;
    bool operator<(const Co C) const { return b < C.b; }
}* co = NULL;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif

    long long n, r, avg, ans = 0, a, b;

    scanf("%lld%lld%lld", &n, &r, &avg), avg *= n;

    while (!co) co = (Co*)calloc(sizeof(Co), n + 32);

    for (int i = 0; i < n; ++i)
        scanf("%lld%lld", &a, &co[i].b), avg -= a, co[i].r = r - a;

    if (avg <= 0) {
        printf("0");
    } else {
        std::sort(co, co + n);
        for (int i = 0; avg && i < n; ++i)
            ans += co[i].b * std::min(co[i].r, avg),
                avg -= std::min(co[i].r, avg);
        printf("%lld", ans);
    }

    return 0;
}