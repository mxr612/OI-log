/**
 * JZOJ2020.07.15TG
 * A
 * JZOJ1281 旅行
 * 贪心, 排序
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data1.in", "r", stdin);
#endif

    int n, k;
    int *a, *b;
    long long ans = 0;

    scanf("%d%d", &n, &k);
    a = (int *)calloc(sizeof(int), n + 32);
    b = (int *)calloc(sizeof(int), n + 32);

    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    for (int i = 0; i < n; ++i)
        scanf("%d", b + i);

    std::sort(a, a + n);
    std::sort(b, b + n);

    for (int i = 0, j = 0; i + j < k;) {
        if (abs(a[i] - b[n - 1 - i]) > abs(a[n - 1 - j] - b[j]))
            ans += abs(a[i] - b[n - 1 - i]), ++i;
        else
            ans += abs(a[n - 1 - j] - b[j]), ++j;
    }

    printf("%lld", ans);

    return 0;
}