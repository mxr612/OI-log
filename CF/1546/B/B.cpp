/**
 * @file B.cpp
 * @author mxr612 (mxr612@icloud.com)
 * @date 2021-07-11
 */

#include <stdio.h>
#include <string.h>

const int MXM = 100010;

char s[MXM];
int cnt[MXM];

signed
main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    int t, n, m;

    scanf("%d", &t);

    while (t--) {
        memset(cnt, 0, sizeof(cnt));
        scanf("%d%d", &n, &m);
        for (int i = 0, j; i < n; ++i)
            for (scanf("%s", s), j = 0; j < m; ++j)
                cnt[j] += s[j];
        for (int i = 1, j; i < n; ++i)
            for (scanf("%s", s), j = 0; j < m; ++j)
                cnt[j] -= s[j];
        for (int i = 0; i < m; ++i)
            s[i] = cnt[i];
        printf("%s\n", s);
        fflush(stdout);
    }

    return 0;
}