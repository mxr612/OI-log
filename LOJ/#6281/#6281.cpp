/**
 * LOJ #6281
 * 分块5
 */

#include <math.h>
#include <stdio.h>

#define MXN (50300)
#define MXS (300)

long long arr[MXN], sum[MXS] = {0};
int pos[MXN];
bool is[MXS] = {false};

signed main() {
#ifndef ONLINE_JUDGE
    freopen("#6281.in", "r", stdin);
#endif

    int n, siz, opt, l, r;
    long long c, ans;

    scanf("%d", &n), siz = sqrt(n);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", &arr[i]), sum[pos[i] = (i - 1) / siz + 1] += arr[i];
    pos[n + 1] = pos[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%lld", &opt, &l, &r, &c);
        if (opt) {
            ans = 0;
            while (l <= r && pos[l] == pos[l - 1])
                ans += arr[l++];
            while (l <= r && pos[r] == pos[r + 1])
                ans += arr[r--];
            for (; l <= r; l += siz)
                ans += sum[pos[l]];
            printf("%lld\n", ans);
        } else {
            for (int p = pos[l]; l <= r && pos[l] == pos[l - 1]; ++l)
                sum[p] -= arr[l], sum[p] += arr[l] = sqrt(arr[l]);
            for (int p = pos[r]; l <= r && pos[r] == pos[r + 1]; --r)
                sum[p] -= arr[r], sum[p] += arr[r] = sqrt(arr[r]);
            for (int p; l <= r; l += siz) {
                if (!is[p = pos[l]]) {
                    is[p] = true, sum[p] = 0;
                    for (int j = l; j < l + siz; ++j) {
                        sum[p] += arr[j] = sqrt(arr[j]);
                        if (arr[j] > 1)
                            is[p] = false;
                    }
                }
            }
        }
    }

    return 0;
}