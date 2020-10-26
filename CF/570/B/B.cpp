/**
 * CF570B
 * 貪心
*/

#include <stdio.h>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    int n, m;

    scanf("%d%d", &n, &m);

    if (n == 1 && m == 1)
        printf("1");
    else if (m - 1 >= n - m)
        printf("%d", m - 1);
    else
        printf("%d", m + 1);

    return 0;
}
