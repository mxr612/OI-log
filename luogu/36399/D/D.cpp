/**
 * luogu36399校测
 * D字符串水题
 * SA/SAM
*/

#include <stdio.h>

#include <iostream>
#include <string>

int sum[1000024];

signed main() {
    freopen("D.in", "r", stdin);

    std::string S, T;
    int n, l, r, ans;

    std::cin >> S;
    scanf("%d", &n);

    while (n--) {
        ans = 0;
        std::cin >> T;
        scanf("%d%d", &l, &r);
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + T[i - 1];
        for (int i = 0, j, k; i < T.length(); ++i)
            for (j = 0; j < T.length(); ++j)
                for (k = 0; l <= sum[j + 1] - sum[i] && sum[j + 1] - sum[i] <= r && (k = T.find(T.substr(i, j - i + 1), k)); ++k)
                    ++ans;
        printf("%d\n", ans);
    }

    return 0;
}
