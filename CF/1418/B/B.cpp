/**
 * CF1418B
*/

#define MXN (120)

#include <stdio.h>

#include <algorithm>

int t;
int n;
long long a[MXN], up[MXN], dn[MXN], s, p;
int l[MXN], ansa, ansb;

bool cmpu(long long a, long long b) { return a < b; }
bool cmpd(long long a, long long b) { return a > b; }

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n), s = p = 0;
        for (int i = 0; i < n; ++i)
            scanf("%lld", &a[i]), s += a[i];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &l[i]);
            if (!l[i])
                up[p] = dn[p] = a[i], ++p;
        }
        std::sort(up, up + p, cmpu);
        std::sort(dn, dn + p, cmpd);
        ansa = ansb = 0;
        for (int i = 0, j = 0; i < n; ++i)
            if (s += (l[i]) ? (a[i]) : (up[j++]) < 0)
                ansa = i;
        for (int i = 0, j = 0; i < n; ++i)
            if (s += (l[i]) ? (a[i]) : (dn[j++]) < 0)
                ansb = i;
        if (ansa < ansb)
            for (int i = 0, j = 0; i < n; ++i)
                printf("%d ", (l[i]) ? (a[i]) : (up[j++]));
        else
            for (int i = 0, j = 0; i < n; ++i)
                printf("%d ", (l[i]) ? (a[i]) : (dn[j++]));
        putchar('\n');
    }

    return 0;
}