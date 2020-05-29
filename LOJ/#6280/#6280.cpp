/**
 * LOJ #6280
 * 分块4
 */

#include <math.h>
#include <stdio.h>

#define MXN (50300)

long long arr[MXN], pos[MXN] = {0}, sum[MXN] = {0}, tag[MXN] = {0};

signed main() {
#ifndef ONLINE_JUDGE
    freopen("#6280.in", "r", stdin);
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
            ans = 0, ++c;
            for (int t = tag[pos[l]]; l <= r && pos[l] == pos[l - 1]; l++)
                ans = (ans + arr[l] + t) % c;
            for (int t = tag[pos[r]]; l <= r && pos[r] == pos[r + 1]; --r)
                ans = (ans + arr[r] + t) % c;
            for (; l <= r; l += siz)
                ans = (ans + sum[pos[l]]) % c;
            printf("%lld\n", ans);
        } else {
            for (int p = pos[l]; l <= r && pos[l] == pos[l - 1]; l++)
                arr[l] += c, sum[p] += c;
            for (int p = pos[r]; l <= r && pos[r] == pos[r + 1]; --r)
                arr[r] += c, sum[p] += c;
            for (; l <= r; l += siz)
                tag[pos[l]] += c, sum[pos[l]] += siz * c;
        }
    }

    return 0;
}