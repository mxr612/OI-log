/**
 * luogu P1638
*/

#define MXN (1000020)
#define MXM (2020)

#include <math.h>
#include <stdio.h>
#include <string.h>

int n, m;

int arr[MXN], sta[MXM];

int a, b;

bool check(int L) {
    memset(sta, 0, sizeof(sta));
    int cnt = 0;
    for (int i = 1; i <= L; ++i)
        if (++sta[arr[i]] == 1)
            ++cnt;
    if (cnt == m) return a = 1, b = L, true;
    for (int i = L + 1; i <= n; ++i) {
        if (--sta[arr[i - L]] == 0) --cnt;
        if (++sta[arr[i]] == 1) ++cnt;
        if (cnt == m) return a = i - L + 1, b = i, true;
    }
    return false;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("P1638.in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);

    int l = 1, r = n, m;
    while (l < r) {
        if (check(m = (l + r) / 2))
            r = m;
        else
            l = m + 1;
    }

    check(r);
    printf("%d %d", a, b);

    return 0;
}