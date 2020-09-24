/**
 * CF1419B
*/

#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <vector>

int t, ans;
long long x;

    signed     main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    scanf("%d", &t);

    while (t--) {
        ans = 0;
        scanf("%lld", &x);
        for (long long i=1,f = 1; f <= x;i<<=1,f=f*2+i*i)x-=f,  ++ans;
        printf("%d\n",ans);
    }

    return 0;
}