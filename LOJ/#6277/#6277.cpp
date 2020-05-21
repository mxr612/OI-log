/**
 * LOJ #6277
 * 分块1
 */

#include <math.h>
#include <stdio.h>

#define MXN (50020)

int pos[MXN];
long long arr[MXN], tag[MXN];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("#6277.in", "r", stdin);
#endif

    int n, opt, s, l, r;
    long long c;

    scanf("%d", &n);

    s = sqrt(n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &arr[i]), pos[i] = i / s;

    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%lld", &opt, &l, &r, &c);
        if (opt)
            printf("%lld\n", arr[r] + tag[pos[r]]);
        else {
            while (l <= r && pos[l] == pos[l - 1])
                arr[l++] += c;
            while (l <= r && pos[r] == pos[r + 1])
                arr[r--] += c;
            while (l <= r)
                tag[pos[l]] += c, l += s;
        }
    }

    return 0;
}