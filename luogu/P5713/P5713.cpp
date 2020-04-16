/**
 * luogu P5713
 */

#include <stdio.h>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P5713.in", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    printf("%s\n", (n < 5) ? ("Local") : ("Luogu"));

    return 0;
}