/**
 * @file P1439.cpp
 * @author mxr612@mxr612.top
 * @brief 
 * @version 0.1
 * @date 2021-03-28
 * 
 * @copyright Copyright (c) 2021
 * 
 * https://www.luogu.com.cn/problem/P1439
 * 【模板】最长公共子序列
 * 求LIS
 */

#include <stdio.h>
#include <string.h>

#include <algorithm>

const int MXN = 100024;

int n, arr[MXN], brr[MXN];
int crr[MXN], dp[MXN], ans;

class SZS {
    int arr[MXN] = {};

   public:
    void insert(int x, int v) {
        for (; x <= n; x += x & -x)
            arr[x] = std::max(arr[x], v);
    }
    int query(int x) {
        int ret = 0;
        for (; x; x -= x & -x)
            ret = std::max(ret, arr[x]);
        return ret;
    }
} szs;

int main() {
#ifndef ONLINE_JUDGE
    freopen("P1439.in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", arr + i);
    for (int i = 1; i <= n; ++i)
        scanf("%d", brr + i);

    for (int i = 1; i <= n; ++i)
        crr[arr[i]] = i;
    for (int i = 1; i <= n; ++i)
        brr[i] = crr[brr[i]];

    for (int i = 1; i <= n; ++i)
        szs.insert(brr[i], dp[i] = szs.query(brr[i] - 1) + 1),
            ans = std::max(ans, dp[i]);
    printf("%d", ans);

    return 0;
}