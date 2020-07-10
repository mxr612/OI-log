/**
 * P3374 【模板】树状数组 1
 * 树状数组例题
*/

#define MXN (500000)
#define MXM (500000)

#include <stdio.h>

int N, M;

class SZA {
    int ele[MXN];

   public:
    void modify(int x, int w) {
        while (x <= N)
            ele[x] += w, x += x & (-x);
    }
    int query(int x, int y) {
        int res = 0;
        if (y < --x) x ^= y ^= x ^= y;
        while (y > 0)
            res += ele[y], y -= y & (-y);
        while (x > 0)
            res -= ele[x], x -= x & (-x);
        return res;
    }
} sza;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P3374.in", "r", stdin);
#endif

    scanf("%d%d", &N, &M);

    for (int i = 1, x; i <= N; ++i)
        scanf("%d", &x), sza.modify(i, x);

    for (int i = 1, opt, x, y; i <= M; ++i) {
        scanf("%d%d%d", &opt, &x, &y);
        if (opt == 1)
            sza.modify(x, y);
        else
            printf("%d\n", sza.query(x, y));
    }

    return 0;
}