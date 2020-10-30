/**
 * luogu36399校测
 * A小鱼吃大鱼
 * n个数，任意a>b求a%b最大值
 * 对于每个模数，一定是某个相邻倍数区间内最大值，直接st表查询一个区间
 * n\sqrt{n}
*/

#include <math.h>
#include <stdio.h>

#include <algorithm>

const int MXA = 1000024;

int rmq[MXA][32];

signed main() {
    freopen("A.in", "r", stdin);

    int n, mxa = 0, ans = 0;
    int *arr;

    scanf("%d", &n);

    arr = (int *)calloc(sizeof(int), n + 32);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i), mxa = std::max(mxa, arr[i]);
    std::sort(arr, arr + n), n = std::unique(arr, arr + n) - arr;

    if (n <= 1000) {
        for (int i = 0, j; i < n; ++i)
            for (j = i + 1; j < n; ++j)
                ans = std::max(ans, arr[j] % arr[i]);
    } else {
        for (int i = 0; i < n; ++i)
            rmq[arr[i]][0] = arr[i];
        for (int i = 0, ii, j; i <= log2(mxa); ++i)
            for (ii = 1 << i, j = 0; j + ii <= mxa; ++j)
                rmq[j][i + 1] = std::max(rmq[j][i], rmq[j + ii][i]);
        for (int i = 0, l, r, s; i < n; ++i)
            for (l = arr[i]; l <= mxa; l += arr[i])
                r = std::min(mxa, l + arr[i] - 1), s = log2(r - l + 1),
                ans = std::max(ans, std::max(rmq[l][s], rmq[r - (1 << s) + 1][s]) % arr[i]);
    }

    printf("%d", ans);

    return 0;
}