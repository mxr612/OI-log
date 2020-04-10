/**
 * B
 */

#include <stdio.h>

#include <algorithm>

bool _cmp(register int x, register int y) {
    return x > y;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    int T, n, x;
    int arr[100020] = {0};

    scanf("%d", &T);

    double s;
    for (register int t = 0, i; t < T; ++t) {
        s = 0;
        scanf("%d%d", &n, &x);
        for (i = 1; i <= n; ++i)
            scanf("%d", &arr[i]);
        std::sort(arr + 1, arr + 1 + n, _cmp);
        for (i = 1; i <= n; ++i) {
            s += arr[i];
            if (s / i < x)
                break;
        }
        printf("%d\n", i - 1);
    }

    return 0;
}