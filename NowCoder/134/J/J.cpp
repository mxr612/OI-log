/**
 * NowCoder134J
 * 强迫症
 * 题意:a>1, 每次使一个数+=另一个数, 使得序列没有相同元素
 * 只要求出有多少个重复即可, 因为每次都一定能去除一个重复元素
 * 具体做法就是, 每次使重复的元素加上数集中最大的元素, 这样每次都能保证不重复
*/

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("J.in", "r", stdin);
#endif

    int n, *arr;

    scanf("%d", &n);

    arr = (int*)calloc(sizeof(int), n + 32);

    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);

    std::sort(arr, arr + n);
    printf("%d", n - (std::unique(arr, arr + n) - arr));

    return 0;
}