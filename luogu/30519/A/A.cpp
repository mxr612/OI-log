/**
 * luogu30519
 * A
 * 考虑从完全图中删去一些边，使得最多两个点的度数为奇数
*/

#include <stdio.h>

signed main() {
    int T;
    long long n;

    scanf("%d", &T);

    while (T--) {
        scanf("%lld", &n);
        printf("%lld\n", (n & 1) ? (n * (n - 1) / 2) : (n * (n - 1) / 2 - (n / 2 - 1)));
    }

    return 0;
}