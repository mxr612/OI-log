/**
 * LOJ #6278
 * 分块2
 */

#include <math.h>
#include <stdio.h>

#include <algorithm>

#define MXN (50020)

long long arr[MXN], sor[MXN], tag[MXN] = {0};
int pos[MXN] = {0};

signed main() {
#ifndef ONLINE_JUDGE
    freopen("a1.in", "r", stdin);
    FILE* ansf = fopen("a1.out", "r");
    long long anss, cnt = 0;
#endif

    int n, siz, opt, l, r, ll, rr, mm;
    long long c, ans, cc;

    scanf("%d", &n), siz = sqrt(n);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", &arr[i]), sor[i] = arr[i], pos[i] = ((i - 1) / siz) + 1;
    pos[n + 1] = pos[n];
    for (int i = 1; i <= n; i += siz)
        std::sort(&sor[i], &sor[i + siz]);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%lld", &opt, &l, &r, &c);
        if (opt) {
            c *= c, ans = 0;
            for (cc = c - tag[pos[l]]; l <= r && pos[l - 1] == pos[l]; l++)
                if (arr[l] < cc)
                    ++ans;
            for (cc = c - tag[pos[r]]; l <= r && pos[r] == pos[r + 1]; r--)
                if (arr[r] < cc)
                    ++ans;
            for (; l <= r; l += siz) {
                cc = c - tag[pos[ll = l]], rr = l + siz - 1;
                while (ll < rr)
                    if (sor[mm = (ll + rr) >> 1] < cc)
                        ll = mm + 1;
                    else
                        rr = mm;
                ans += rr - l;
            }
#ifndef ONLINE_JUDGE
            ++cnt;
            fscanf(ansf, "%lld", &anss);
            if (ans != anss)
                printf("%5d %10lld %10lld\n", cnt, anss, ans);
#else
            printf("%lld\n", ans);
#endif
        } else {
            if (pos[l - 1] == pos[l]) {
                while (l <= r && pos[l - 1] == pos[l])
                    arr[l++] += c;
                for (int j = l - siz; j < l; ++j)
                    sor[j] = arr[j];
                std::sort(&sor[l - siz], &sor[l]);
            }
            if (pos[r] == pos[r + 1]) {
                while (l <= r && pos[r] == pos[r + 1])
                    arr[r--] += c;
                for (int j = r + 1; j <= r + siz; ++j)
                    sor[j] = arr[j];
                std::sort(&sor[r + 1], &sor[r + siz + 1]);
            }
            for (; l <= r; l += siz)
                tag[pos[l]] += c;
        }
    }

    return 0;
}