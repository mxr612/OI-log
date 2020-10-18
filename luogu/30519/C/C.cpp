/**
 * luogu30519
 * C
 * 考场打了n^2暴力
*/

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

signed main() {
    int n, m, *arr;
    std::string ss;

    scanf("%d%d", &n, &m);

    arr = (int*)calloc(sizeof(int), n + 32);

    for (int i = 1; i <= n; ++i)
        scanf("%d", arr + i);

    if (n <= 1000 && m <= 1000) {
        for (int i = 1, j, k, x, s; i <= m; ++i) {
            std::cin >> ss;
            if (ss == "A") {
                scanf("%d", &x);
                for (s = 0, j = 1; j <= n && s != x; ++j)
                    for (s = 0, k = j; k <= n && s < x; ++k)
                        s += arr[k];
                if (x > 0 && s == x)
                    printf("%d %d\n", j - 1, k - 1);
                else
                    printf("none\n");
            } else {
                scanf("%d%d", &j, &k);
                arr[j] = k;
            }
        }
    }

    return 0;
}