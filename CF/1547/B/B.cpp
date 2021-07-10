/**
 * @file B.cpp
 * @author mxr612 (mxr612@icloud.com)
 * @date 2021-07-10
 */

#include <stdio.h>

signed main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif

    int t, l = 0, r = 0;
    char s[30];

    scanf("%d", &t);

    while (t--) {
        scanf("%s", s);
        for (int i = 0; s[i]; ++i)
            if (s[i] == 'a')
                l = r = i;
        if (s[l] != 'a')
            printf("NO\n");
        else {
            for (char i = 'b'; i <= 'z'; ++i)
                if (l > 0 && s[l - 1] == i)
                    --l;
                else if (s[r + 1] == i)
                    ++r;
                else
                    break;
            printf("%s\n", l == 0 && s[r + 1] == 0 ? "YES" : "NO");
        }
    }

    return 0;
}