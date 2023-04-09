#include <stdio.h>

int gcd(int m, int n) {
    return (n == 0) ? (m) : (gcd(n, m % n));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    int t, n;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        printf("%d", 2 * n);
        for (int p = 2, i = 1, j = 2 * n - 3; p <= n; ++p) {
            if (p % 2) {
                printf(" %d", j);
                j -= 2;
            } else {
                printf(" %d", i);
                i += 2;
            }
        }
        putchar('\n');
        for (int p = 1, i = 2, j = 2 * n - 2; p < n; ++p) {
            if (p % 2) {
                printf("%d ", i);
                i += 2;
            } else {
                printf("%d ", j);
                j -= 2;
            }
        }
        printf("%d\n", 2 * n - 1);
    }

    return 0;
}