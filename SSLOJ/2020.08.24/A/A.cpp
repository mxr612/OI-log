/**
 * 2020.08.24A A 
 * luogu T145300 【2020.8.24NOIP模拟赛】这是一棵树吗?
*/

#include <stdio.h>

long long n, s;
bool pos = true;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    scanf("%lld", &n);
    for (long long i = 0, a; i < n; ++i)
        scanf("%lld", &a), pos &= (a > 0), s += a;

    if (s == (n - 1) * 2 && (n == 1 || pos))
        printf("Possible");
    else
        printf("Impossible");

    return 0;
}