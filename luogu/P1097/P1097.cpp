/**
 * https://www.luogu.com.cn/problem/P1097
 * luogu P1097
 * 统计数字
*/

#include <stdio.h>

#include <map>

int n;

std::map<int, int> map;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1097.in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0, x; i < n; ++i)
        scanf("%d", &x), ++map[x];

    for (auto i : map)
        printf("%d %d\n", i.first, i.second);

    return 0;
}