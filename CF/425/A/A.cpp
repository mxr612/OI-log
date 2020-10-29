/**
 * CF425A
 * Sereja and Swaps
 * 有k次交换, 问最大和区间
 * 用set维护
*/

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <set>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    int N, K, *arr;
    std::multiset<int> min, max;
    std::multiset<int>::iterator p;
    std::multiset<int>::reverse_iterator rp;
    long long ans = -1e9, s, ss;

    scanf("%d%d", &N, &K);
    arr = (int*)calloc(sizeof(int), N + 32);
    for (int i = 0; i < N; ++i)
        scanf("%d", arr + i);

    for (int i = 0, j, k; i < N; ++i) {
        for (max.clear(), j = 0; j < N; ++j)
            max.insert(arr[j]);
        for (min.clear(), s = 0, j = i; j < N; ++j) {
            min.insert(arr[j]), max.erase(max.find(arr[j])), s += arr[j];
            ans = std::max(ans, s);
            for (ss = s, p = min.begin(), rp = max.rbegin(), k = 0; k < K && p != min.end() && rp != max.rend(); ++k, ++p, ++rp)
                ans = std::max(ans, ss += -(*p) + (*rp));
        }
    }

    printf("%lld", ans);

    return 0;
}

/*
我知道这个世界并不是你努力了多少就得获得多少
你也没办法借着自己付出多少就要求谁给你些什么
*/