/**
 * line
*/

#include <stdio.h>

const int MXN = 5012;

int arr[MXN];

signed main() {
    freopen("line.in", "r", stdin);
    freopen("line.out", "w", stdout);

    int n;

    scanf("%d", &n);

    for (int i = 1, j, a, c; i <= n; ++i)
        for (scanf("%d", &a), c = 0, j = 0; j < n; ++j)
            if (!arr[j] && c++ == a)
                arr[j] = i;

    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);

    return 0;
}