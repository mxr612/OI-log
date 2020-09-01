/**
 * 
*/

#include <stdio.h>

int T;

int gcd(int a, int b) { return (b == 0) ? (a) : gcd(b, a % b); }

signed main() {
    freopen("A.in", "r", stdin);

    scanf("%d", &T);

    for (int i, n, m; T-- > 0;)
        scanf("%d%d", &n, &m), printf("%d\n", m - gcd(n, m));

    return 0;
}