/**
 * luogu36399校测
 * C大鱼吃小鱼
 * 贪心, 后半部分鱼吃前半部分的鱼
*/

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

signed main() {
    freopen("C.in", "r", stdin);

    int n, *arr;
    int ans;

    scanf("%d", &n), ans = n;
    arr = (int*)calloc(sizeof(int), n + 32);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);

    std::sort(arr, arr + n);
    for (int i = n / 2 - 1, j = n - 1; i >= 0; --i)
        if (arr[i] * 2 <= arr[j])
            --ans, --j;

    printf("%d", ans);

    return 0;
}

/*
不再以为自己有多么不同
*/