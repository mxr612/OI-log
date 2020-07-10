/**
 * P3368 【模板】树状数组 2
 * 区间修改单点查询
 * 树状数组维护差分
*/

#define MXN (500020)
#define MXM (500020)

#include <stdio.h>

int N, M;

int arr[MXN];

class SZA {
    int ele[MXN];

   public:
    void modify(int x, int w) {
        while (x <= N)
            ele[x] += w, x += x & (-x);
    }
    int query(int x) {
        int res = 0;
        while (x > 0)
            res += ele[x], x -= x & (-x);
        return res;
    }
} sza;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P3368.in", "r", stdin);
#endif

    scanf("%d%d", &N, &M);

    for (int i = 1; i <= N; ++i)
        scanf("%d", &arr[i]);

    for (int i = 1, opt, x, y, k; i <= M; ++i) {
        scanf("%d", &opt);
        if (opt == 1)
            scanf("%d%d%d", &x, &y, &k), sza.modify(x, k), sza.modify(y + 1, -k);
        else
            scanf("%d", &x), printf("%d\n", arr[x] + sza.query(x));
    }

    return 0;
}