/**
 * LOJ #6284
 * 分块8
 */

#include <math.h>
#include <stdio.h>

#define MXN (101000)
#define MXS (1000)

int arr[MXN], pos[MXN] = {0}, bl[MXS], tag[MXS];
bool is[MXS] = {false};

signed main() {
#ifndef ONLINE_JUDGE
    freopen("a3.in", "r", stdin);
    FILE* ansf = fopen("a3.out", "r");
    int anss;
#endif

    int n, siz, l, r, c, ans;

    scanf("%d", &n), siz = sqrt(n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]), pos[i] = (i - 1) / siz + 1;
    pos[n + 1] = pos[n];
    for (int i = 1; i <= n; i += siz)
        bl[pos[i]] = i;

    for (int i = 0, j, p; i < n; ++i) {
        scanf("%d%d%d", &l, &r, &c);

        ans = 0;

        if (l <= r && pos[l] == pos[l - 1]) {
            if (is[p = pos[l]])
                for (is[p] = false, j = bl[p]; j < bl[p] + siz; ++j)
                    arr[j] = tag[p];
            for (; l <= r && pos[l] == pos[l - 1]; ++l)
                if (arr[l] == c)
                    ++ans;
                else
                    arr[l] = c;
        }
        if (l <= r && pos[r] == pos[r + 1]) {
            if (is[p = pos[r]])
                for (is[p] = false, j = bl[p]; j < bl[p] + siz; ++j)
                    arr[j] = tag[p];
            for (; l <= r && pos[r] == pos[r + 1]; --r)
                if (arr[r] == c)
                    ++ans;
                else
                    arr[r] = c;
        }
        for (; l <= r; l += siz) {
            if (is[p = pos[l]]) {
                if (tag[p] == c)
                    ans += siz;
                else
                    tag[p] = c;
            } else {
                for (is[p] = true, tag[p] = c, j = l; j < l + siz; ++j)
                    if (arr[j] == c)
                        ++ans;
                    else
                        arr[j] = c;
            }
        }

#ifndef ONLINE_JUDGE
        fscanf(ansf, "%d", &anss);
        if (anss != ans)
            printf("%5d %5d %5d\n", i, anss, ans);
#else
        printf("%d\n", ans);
#endif
    }

    return 0;
}