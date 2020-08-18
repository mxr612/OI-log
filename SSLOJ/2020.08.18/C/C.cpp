/**
 * 
*/

#define MXN (500020)

#include <stdio.h>

#include <algorithm>

int n, k, top, ans;
int cnt[MXN];

signed main() {
    freopen("C.in", "r", stdin);

    scanf("%d%d", &n, &k);

    for (int i = 0, x; i < n; ++i)
        scanf("%d", &x), ++cnt[x], top = std::max(top, x);

    for (int i = top, j, res; i > 0; --i) {
        for (j = i, res = 0; j <= top; ++j)
            res += cnt[j];
        if (res >= k) {
            ans = i;
            break;
        }
    }

    printf("%d", ans * k);

    return 0;
}