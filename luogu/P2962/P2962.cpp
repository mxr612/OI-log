/**
 * P2962 [USACO09NOV]Lights G
 * 折半搜索 meet-in-the-middle
*/

#include <stdio.h>

#include <algorithm>
#include <map>

int n, m;
unsigned ans = -1;
unsigned long long arr[50];

std::map<long long, unsigned> map;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P2962.in", "r", stdin);
#endif

    long long t;
    unsigned cnt;

    scanf("%u%u", &n, &m);

    for (int i = 0; i < n; ++i)
        arr[i] = 1ll << i;
    for (int i = 0, a, b; i < m; ++i)
        scanf("%d%d", &a, &b), arr[--a] |= 1ll << --b, arr[b] |= 1ll << a;

    for (int i = 0, j; i < (1ll << (n / 2)); ++i) {  //状压搜索
        t = cnt = 0;
        for (j = 0; j < n / 2; ++j)
            if ((i >> j) & 1)
                t ^= arr[j], ++cnt;
        if (map.count(t))
            map[t] = std::min(map[t], cnt);
        else
            map[t] = cnt;
    }
    for (int i = 0, j; i <= (1ll << (n - (n / 2))); ++i) {
        t = cnt = 0;
        for (j = n / 2; j <= n; ++j)
            if ((i >> (j - n / 2)) & 1)
                t ^= arr[j], ++cnt;
        if (map.count(t ^ ((1ll << n) - 1)))
            ans = std::min(ans, cnt + map[t ^ ((1ll << n) - 1)]);
    }

    printf("%d", ans);

    return 0;
}