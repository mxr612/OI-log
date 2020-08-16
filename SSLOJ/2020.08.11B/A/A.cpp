#include <stdio.h>

int n, ans;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1, j; i <= n; ++i)
        for (j = i << 1; j <= n; j += i)
            if ((i ^ j) == (j - i))
                ++ans;

    printf("%d", ans);

    return 0;
}
