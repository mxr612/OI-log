/**
 * CF482A
 * 使n的全排列有k种差值
 * 1, n, 2, n-1....后面接升序或降序
*/

#include <stdio.h>

signed main() {
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= k / 2; ++i)
        printf("%d %d ", i, n - i + 1);
    if (k & 1)
        for (int i = k / 2 + 1; i <= n - k / 2; ++i)
            printf("%d ", i);
    else
        for (int i = n - k / 2; i > k / 2; --i)
            printf("%d ", i);

    return 0;
}