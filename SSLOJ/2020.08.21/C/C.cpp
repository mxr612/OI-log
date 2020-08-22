/**
 * 
*/

#define MXN (100000)
#define XJQ (1000000007)

#include <stdio.h>
#include <string.h>

#include <algorithm>

int n, q;
long long a[MXN], mi[MXN];

// Sub1
long long DP[20][20];

// Sub3
int last[MXN];
long long ans;

// Sub5
bool is;
struct Query {
    int l, r, d;
} query[MXN];
int ans[MXN];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif

    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);

    mi[0] = 1;
    for (int i = 1; i <= n; ++i)
        mi[i] = (mi[i - 1] << 1) % XJQ;

    if (n <= 10) {
        memset(DP, 128, sizeof(DP));
        for (int i = 1; i <= n; ++i)
            DP[i][i] = a[i];
        for (int i = 2, j, k; i <= n; ++i)
            for (j = n - i + 1; j > 0; --j)
                for (k = j + i - 1; k > j; --k)
                    DP[j][j + i - 1] = std::max(DP[j][j + i - 1], DP[j][k - 1] + 2 * DP[k][j + i - 1]);
        for (int i = 0, l, r; i < q; ++i)
            scanf("%d%d", &l, &r), printf("%lld\n", ((DP[l][r] % XJQ) + XJQ) % XJQ);
    } else if (n <= 1000) {
        last[1] = 1;
        for (int i = 2; i <= n; ++i)
            if (a[i] < a[i - 1])
                last[i] = i;
            else
                last[i] = last[i - 1];
        for (int i = 0, j, l, r; i < q; ++i) {
            scanf("%d%d", &l, &r);
            for (ans = 0, j = l; j <= r; ++j)
                ans = (ans + a[j] * mi[j - std::max(l, last[j])]) % XJQ;
            printf("%lld\n", ((DP[l][r] % XJQ) + XJQ) % XJQ);
        }
    } else {
        is = true;
        for (int i = 0; i < q; ++i)
            scanf("%d%d", &query[i].l, &query[i].r), query[i].d = i, is &= (query[i].l == 1);
        if (is) {
            
        } else {
        }
    }

    return 0;
}