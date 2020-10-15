/**
 * JZOJ2020.09.26
 * NOIP2020.9.26模拟jerry
 * jerry
*/

#define MXN (200056)

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

long long a[MXN], b[MXN];

signed main() {
    freopen("2.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("jerry.out", "w", stdout);
#endif

    int T, n;
    scanf("%d", &T);

    char c;
    bool flag;
    while (T--) {
        scanf("%d", &n);
        scanf("%d", &a[1]);
        for (int i = 2; i <= n; ++i)
            scanf(" %c %lld", &c, &a[i]), a[i] = a[i - 1] + ((c == '-') ? (-a[i]) : (a[i]));
        flag = false;
        for (int i = 1, l; i <= n; ++i) {
            b[i] = (flag) ? (std::max(b[l] + a[l] - a[i], b[i - 1] + a[i] - a[i - 1])) : (a[i]);
            if (a[i] < a[i - 1]) l = i, flag = true;
        }
        printf("%lld\n", b[n]);
    }
    return 0;
}