/**
 * 2020.04.08【NOIP提高组】模拟A 组23
 * A
 */

#include <stdio.h>

#include <algorithm>

#define MXN (100020)

int tree[MXN];
long long N, x, ans = 0;

struct __hair {
    int v, w;
    bool operator<(__hair x) { return v < x.v; }
} hair[MXN];

signed main() {
    freopen("haircut.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("haircut.out", "w", stdout);
#endif

    scanf("%lld", &N);

    for (register int i = 0, y, z, s; i < N; ++i) {
        scanf("%lld", &x), hair[i].v = y = z = std::min(N - 1, x);
        for (; z > 0; z -= z & (-z))
            ++tree[z];
        for (s = 0, ++y; y <= N; y += y & (-y))
            s += tree[y];
        hair[i].w = s;
    }

    std::sort(hair, hair + N);

    for (register int i = 0, j = 0; i < N; ++i) {
        while (j < N && hair[j].v < i)
            ans += hair[j++].w;
        printf("%lld\n", ans);
    }

    return 0;
}