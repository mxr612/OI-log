/**
 * @file P1966.cpp
 * @author mxr612 (mxr612@icloud.com)
 * @date 2021-10-14
 * @brief 转化为逆序对
 */

#include <stdio.h>

#include <algorithm>
#include <map>

const int MXN = 1e5 + 20, XJQ = 1e8 - 3;

int n;
std::pair<int, int> a[MXN], b[MXN];
int arr[MXN];

class SZS {
    int arr[MXN];

   public:
    void insert(int x) {
        for (; x <= n; x += x & -x)
            ++arr[x];
    }
    int query(int x) {
        int res = 0;
        for (; x > 0; x -= x & -x)
            res += arr[x];
        return res;
    }
} szs;

int ans;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1966.in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i].first), a[i].second = i + 1;
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i].first), b[i].second = i + 1;

    std::sort(a, a + n);
    std::sort(b, b + n);
    for (int i = 0; i < n; ++i)
        arr[a[i].second - 1] = b[i].second;

    for (int i = 0; i < n; ++i) {
        ans = (ans + i - szs.query(arr[i])) % XJQ;
        szs.insert(arr[i]);
    }

    printf("%d", ans);

    return 0;
}