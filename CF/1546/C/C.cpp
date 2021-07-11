/**
 * @file C.cpp
 * @author mxr612 (mxr612@icloud.com)
 * @date 2021-07-11
 */

#include <math.h>
#include <stdio.h>

#include <algorithm>

const int MXN = 100010;

int a[2][MXN];
#define Aa(aA) (a[(aA)&1][(aA) / 2])

signed main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif

    int t, n;
    bool flag;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &Aa(i));
        std::sort(a[0], a[0] + int(ceil(n / 2.0)));
        std::sort(a[1], a[1] + n / 2);
        flag = true;
        for (int i = 1; flag && i < n; ++i)
            flag &= Aa(i - 1) <= Aa(i);
        printf("%s\n", flag ? "YES" : "NO");
    }

    return 0;
}