/**
 * 2020.09.12A
 * A hanoi
 * 0. 打表找规律
 * 1. 考虑将一个四柱子移动分解为一个四柱子移动和一个三柱子移动，枚举大小。
 * 因为两个函数都是单调递增的，且三柱子移动的增长速度很快，所以枚举三柱子块的大小即可。
 * 因为答案肯定在long long范围内，所以溢出直接判为枚举结束
*/

#define MXN (1020)

#include <stdio.h>
#include <string.h>

#include <algorithm>

int n;

long long f[MXN];

signed main() {
    freopen("hanoi.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("hanoi.out", "w", stdout);
#endif

    memset(f, 127, sizeof(f));
    f[0] = 0, f[1] = 1;

    scanf("%d", &n);

    for (int i = 2, j; i <= n; ++i)
        for (j = 1; j <= i && j < 65; ++j)
            while (2 * f[i - j] - 1 + (1LL << j) > f[i - 1] && 2 * f[i - j] - 1 + (1LL << j) < f[i])
                f[i] = 2 * f[i - j] - 1 + (1LL << j);

    printf("%lld", f[n]);

    return 0;
}