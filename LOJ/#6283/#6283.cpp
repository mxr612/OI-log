/**
 * LOJ #6283
 * 分块7
 */

#include <math.h>
#include <stdio.h>

#define MXN (101000)
#define MXS (1000)
#define MOD (10007)

int arr[MXN], tagm[MXS] = {0}, tagp[MXS] = {0};
int pos[MXN] = {0}, bl[MXS];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("#6283.in", "r", stdin);
#endif

    int n, siz, opt, l, r;
    int c;

    scanf("%d", &n), siz = sqrt(n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]), pos[i] = (i - 1) / siz + 1;
    pos[n + 1] = pos[n];
    for (int i = 1; i <= n; i += siz)
        bl[pos[i]] = i, tagm[pos[i]] = 1;

    for (int i = 0, j, p; i < n; ++i) {
        scanf("%d%d%d%d", &opt, &l, &r, &c);
        switch (opt) {
            case 0:
                c %= MOD;
                if (l <= r && pos[l] == pos[l - 1]) {
                    for (j = bl[p = pos[l]]; j < bl[pos[l]] + siz; ++j)
                        arr[j] = (tagm[p] * arr[j] + tagp[p]) % MOD;
                    tagm[p] = 1, tagp[p] = 0;
                    for (; l <= r && pos[l] == pos[l - 1]; ++l)
                        arr[l] = (arr[l] + c) % MOD;
                }
                if (l <= r && pos[r] == pos[r + 1]) {
                    for (j = bl[p = pos[r]]; j < bl[pos[r]] + siz; ++j)
                        arr[j] = (tagm[p] * arr[j] + tagp[p]) % MOD;
                    tagm[p] = 1, tagp[p] = 0;
                    for (; l <= r && pos[r] == pos[r + 1]; --r)
                        arr[r] = (arr[r] + c) % MOD;
                }
                for (; l <= r; l += siz)
                    tagp[pos[l]] = (tagp[pos[l]] + c) % MOD;
                break;
            case 1:
                c %= MOD;
                if (l <= r && pos[l] == pos[l - 1]) {
                    for (j = bl[p = pos[l]]; j < bl[pos[l]] + siz; ++j)
                        arr[j] = (tagm[p] * arr[j] + tagp[p]) % MOD;
                    tagm[p] = 1, tagp[p] = 0;
                    for (; l <= r && pos[l] == pos[l - 1]; ++l)
                        arr[l] = (arr[l] * c) % MOD;
                }
                if (l <= r && pos[r] == pos[r + 1]) {
                    for (j = bl[p = pos[r]]; j < bl[pos[r]] + siz; ++j)
                        arr[j] = (tagm[p] * arr[j] + tagp[p]) % MOD;
                    tagm[p] = 1, tagp[p] = 0;
                    for (; l <= r && pos[r] == pos[r + 1]; --r)
                        arr[r] = (arr[r] * c) % MOD;
                }
                for (; l <= r; l += siz)
                    tagm[pos[l]] = (tagm[pos[l]] * c) % MOD,
                    tagp[pos[l]] = (tagp[pos[l]] * c) % MOD;
                break;
            case 2:
                printf("%d\n", (tagm[pos[r]] * arr[r] + tagp[pos[r]]) % MOD);
                break;
            default:;
        }
    }

    return 0;
}