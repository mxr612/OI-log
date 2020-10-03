/**
 * 对A搜索,对B枚举
*/

#include <stdio.h>

#include <iostream>
#include <map>
#include <string>

std::string a, b, s, r;

bool cheak(std::string s) {
    if (s.length() > 10) return false;
    for (int i = 0; i < s.length() - 1; ++i)
        if (s[i] == s[i + 1])
            return false;
    return true;
}

std::map<std::string, bool> map;

long long ans;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("yl1.in", "r", stdin);
#endif

    std::cin >> a >> b;

    for (int i = 1, j, k; i < (1 << a.length()); ++i) {
        for (s.clear(), j = 0; j < a.length(); ++j)
            if (i & (1 << j))
                s += a[j];
        if (!map[s] && cheak(s))
            for (j = 0; !map[s] && j < b.length(); ++j)
                for (r.clear(), k = 0; !map[s] && k < 10 && j + k < b.length(); ++k)
                    if (r += b[j + k], s == r)
                        ans += map[s] = true;
    }

    printf("%lld", ans);

    return 0;
}