/**
 * luogu36343
 * 校测 51Nod
 * C sequence 区间序列
 * 由于函数基本上递增而且很快就会乘炸
 * 暴力特判1的情况和乘炸的情况
*/

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("sequence.in", "r", stdin);
#endif
    long long k;
    int n, *arr, mina = 1e9;

    scanf("%d%lld", &n, &k);

    arr = (int *)calloc(sizeof(int), n + 32);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i), mina = std::min(mina, arr[i]);

    if (mina > 1) {
        int ans = 0;
        long long sum, pi;
        for (int i = 0, l, r, m; i < n; ++i) {
            l = i, r = n - 1;
        }
    } else {
        // int *sum = (int *)calloc(sizeof(int), n + 32);
    }

    return 0;
}