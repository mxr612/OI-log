/**
 * 
*/

#define MXN (500020)

#include <stdio.h>

#include <algorithm>

int n, k, top;
int cnt[MXN];
long long ans;

signed main() {
    freopen("C.in", "r", stdin);

    scanf("%d%d", &n, &k);

    for (int i = 0, x; i < n; ++i)
        scanf("%d", &x), ++cnt[x], top = std::max(top, x);

    for (int i = top, j, res; i > 0; --i) {
        for (j = i, res = 0; j <= top; j += i)
            res += cnt[j];
        if (res >= k) {
            ans = i;
            break;
        }
    }

    printf("%lld", ans * k);

    return 0;
}