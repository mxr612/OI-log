/**
 * CF1419A
*/

#define MXN (1020)

#include <stdio.h>
#include <string.h>

#include <algorithm>

int t;
int n;
char s[MXN];
int cnt[2][2], k;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    scanf("%d", &t);

    while (t--) {
        memset(cnt, 0, sizeof(cnt));
        scanf("%d%s", &n, s + 1);
        for (int i = 1; i <= n; ++i)
            ++cnt[i & 1][(s[i] - '0') & 1];
        // 0偶1奇
        if (n & 1)
            printf("%d\n", (cnt[1][1]) ? (1) : (2));
        else
            printf("%d\n", (cnt[0][0]) ? (2) : (1));
    }

    return 0;
}