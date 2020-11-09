
#include <stdio.h>

#include <algorithm>

const int MXN = 100024;

char s[MXN];

signed main() {
    freopen("str.in", "r", stdin);
    freopen("str.out", "w", stdout);

    int T, n, k, l, r, ans;

    scanf("%d", &T);

    while (T--) {
        l = r = ans = 0;
        scanf("%d%s", &n, s);
        while (k = s[l]) {
            r = std::max(l, r);
            while (r < n - 1 && s[r] != s[r + 1]) ++r;
            ++r;
            while (l < n && k == s[l]) ++l;
            if (k = s[l], r >= n - 1)
                while (l < n && k == s[l]) ++l;
            ++ans;
        }
        printf("%d\n", ans);
    }

    return 0;
}