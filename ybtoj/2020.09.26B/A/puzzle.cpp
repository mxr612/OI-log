/**
 * ybtoj2020.09.26B
 * A古老谜题puzzle
*/

#define MXN (1000020)

#include <stdio.h>
#include <string.h>

int idx;
int n;
char s[MXN];
int a[MXN], siz;

// Sub3
int ls[MXN], rs[MXN];  // 计数
int lx[MXN], rx[MXN];  // 链接

signed main() {
    freopen("puzzle.in", "r", stdin);
#ifdef ONLINE_JUDGE
    freopen("puzzle.out", "w", stdout);
#endif

    scanf("%d%d", &idx, &n);
    scanf("%s", s);

    while (s[siz]) a[siz++] = s[siz] - '0';

    // Sub3
    for (int i = 0, j = -1; i < siz; ++i)
        if (a[i])
            ls[i] = i - j,
            lx[i] = j, j = i;
    for (int i = siz - 1, j = siz; i >= 0; --i)
        if (a[i])
            rs[i] = j - i,
            rx[i] = j, j = i;

    if (idx <= 3) {
        int ans = 0;
        for (int i = 0, l, r; i < siz; ++i)
            if (a[i])
                for (ans += (ls[i] - 1) * (rs[i] - 1), l = lx[i], r = rx[i]; 0 <= l && r < siz; l = lx[l], r = rx[r])
                    ans += ls[l] * rs[r];
        printf("%d", ans);
    } else if (idx == 4) {  // Sub4
        long long l, m, r;
        for (l = 0; !a[l]; ++l)
            ;
        for (m = l + 1; !a[m]; ++m)
            ;
        for (r = m + 1; !a[r]; ++r)
            ;
        printf("%lld", (l + 1) * (siz - r) + (l) * (m - l - 1) + (m - l - 1) * (r - m - 1) + (r - m - 1) * (siz - r - 1));
    } else if (idx == 5) {
        long long ans = 0;
        for (int i = 3; i <= n; i += 2)
            ans += n - i + 1;
        printf("%lld", ans);
    } else {
    }

    return 0;
}