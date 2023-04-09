#include <stdio.h>

int gcd(int m, int n) {
    return (n == 0) ? (m) : (gcd(n, m % n));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    int t, a, b;

    scanf("%d", &t);

    while (t--) {
        scanf("%d%d", &a, &b);
        if (gcd(a, b) == 1) {
            printf("1\n%d %d\n", a, b);
        } else if (a <= b) {
            printf("2\n%d %d\n%d %d\n", a - 1, a, a, b);
        } else {
            printf("2\n%d %d\n%d %d\n", b, b - 1, a, b);
        }
    }

    return 0;
}