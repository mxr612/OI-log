/**
 * LOJ #6278
 * 分块2
 */

#include <math.h>
#include <stdio.h>

#include <algorithm>

#define MXN (50020)

long long arr[MXN], sor[MXN], tag[MXN] = {0};
int pos[MXN];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("#6278.in", "r", stdin);
#endif

    int n, opt, l, r, siz;
    long long c, ans;

    scanf("%d", &n);
    siz = sqrt(n);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", &arr[i]), sor[i] = arr[i], pos[i] = i / siz;

    for (int i = 1, ed = n - (n % siz); i <= ed; i += siz)
        std::sort(&sor[i], &sor[i + siz]);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%lld", &opt, &l, &r, &c);
        if (opt) {
            c *= c, ans = 0;
            while (l <= r && pos[l] == pos[l - 1])
                if (arr[l++] < c)
                    ++ans;
            while (l <= r && pos[r] == pos[r + 1])
                if (arr[r--] < c)
                    ++ans;
            for (int i = l, cc, ll, rr, mm; i <= r; i += siz) {
                cc = c - tag[pos[i]], ll = i, rr = i + siz - 1;
                while (ll < rr)
                    if (sor[mm = (ll + rr) / 2] < cc)
                        ll = mm + 1;
                    else
                        rr = mm - 1;
                ans += rr - i + 1;
            }
            printf("%lld\n", ans);
        } else {
            if (pos[l] == pos[l - 1]) {
                while (l <= r && pos[l] == pos[l - 1])
                    arr[l++] += c;
                for (int j = l - siz; j < siz; ++j)
                    sor[j] = arr[j];
                std::sort(&sor[l - siz], &sor[l]);
            }
            if (pos[r] == pos[r + 1]) {
                while (l <= r && pos[r] == pos[r + 1])
                    arr[r--] += c;
                for (int j = r, ed = r + siz; j <= ed; ++j)
                    sor[j] = arr[j];
                std::sort(&sor[r], &sor[r + siz]);
            }
            while (l <= r)
                tag[pos[l]] += c, l += siz;
        }
    }

    return 0;
}